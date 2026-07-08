const { commaSep, commaSep1 } = require('./utils');

module.exports = {
  // Declarations
  declaration: ($) =>
    choice(
      $.interface_declaration,
      $.class_declaration,
      $.enum_abstract_declaration,
      $.enum_declaration,
      $.typedef_declaration,
      $.function_declaration,
      $.variable_declaration,
    ),
  _access_identifier: ($) => choice('default', 'null', 'get', 'set', 'dynamic', 'never'),
  access_identifiers: ($) =>
    seq('(', $._access_identifier, optional(seq(',', $._access_identifier)), ')'),
  type_params: ($) => prec.right(1, seq('<', commaSep1($.type), '>')),

  _modifier: ($) =>
    choice(
      'macro',
      'abstract',
      'static',
      'public',
      'private',
      'extern',
      'inline',
      'overload',
      'override',
      'final',
    ),

  class_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'class',
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        seq('extends', field('super_class_name', $._type_path), optional($.type_params)),
      ),
      optional(
        repeat(
          seq('implements', field('interface_name', $._type_path), optional($.type_params)),
        ),
      ),
      field('body', $.block),
    ),

  interface_declaration: ($) =>
    seq(
      repeat($._modifier),
      'interface',
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        repeat(seq('extends', field('interface_name', $._type_path), optional($.type_params))),
      ),
      field('body', $.block),
    ),

  // Haxe's "class-like" anonymous structure syntax
  // (`typedef Point = { var x:Int; function bar():Void; }`) needs a body
  // that can hold var/function member declarations, so this used to just
  // reuse $.block directly. That collided with $.structure_type's own
  // comma-separated-pairs syntax (`typedef X = { x:Int, y:Int }`) for a
  // single-field, no-trailing-comma struct (`typedef X = { f:T }`): a bare
  // 'identifier : expression' is ALSO a valid one-statement $.block (via
  // $.pair's low-precedence bare-literal alternative, see its comment in
  // grammar-literals.js), so $.block and $.structure_type both matched
  // that exact token sequence. This is the same class of GLR table-
  // construction merge as the documented block-vs-object empty-body
  // ambiguity above ($.block's own comment) -- tree-sitter's conflict
  // analysis calls [$.typedef_declaration, $.structure_type] an
  // "unnecessary conflict" (no static ambiguity to resolve) yet the
  // single-item-no-comma case still hard-errors at runtime, and neither
  // declaring the conflict explicitly, nor bumping either rule's static
  // OR dynamic precedence, changes that -- it is not a real tie to break,
  // the same not-fixable-via-prec class as the earlier case. Two or more
  // fields, or a trailing comma, dodge it because a ',' forces an early
  // commit into the comma-list production, ruling out the single-bare-
  // statement reading before the ambiguous state is ever reached.
  //
  // The actual fix: this body never legitimately needs $.block's full
  // generality (arbitrary statements) -- real Haxe only ever puts
  // var/function member declarations in it, both of which start with a
  // keyword ('var'/'final'/'function', or metadata's '@'), never a bare
  // identifier, so a dedicated body rule restricted to those two
  // declaration kinds can never overlap with $.structure_type's bare
  // 'identifier : type' shape in the first place. Aliased to $.block so
  // existing consumers/tests see the same node type as before.
  _structure_class_body: ($) =>
    seq('{', repeat(choice($.variable_declaration, $.function_declaration)), $._closing_brace),

  typedef_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'typedef',
      field('name', $._lhs_expression),
      optional($.type_params),
      seq(
        '=',
        choice(
          $.structure_type,
          alias($._structure_class_body, $.block),
          $._lhs_expression,
          $.type,
        ),
      ),
      $._lookback_semicolon,
    ),

  // enum Foo { VAL1; VAL2; }
  enum_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'enum',
      field('name', $._lhs_expression),
      optional($.type_params),
      field('body', $.block),
    ),

  // enum abstract Foo(Int) from String to Int { var VAL = 0; }
  enum_abstract_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'enum',
      'abstract',
      field('name', $._lhs_expression),
      optional($.type_params),
      '(',
      field('underlying_type', $.type),
      ')',
      repeat(seq('from', field('from_type', $.type))),
      repeat(seq('to', field('to_type', $.type))),
      field('body', $.block),
    ),

  // prec(1, ...): a named function with a block, at statement position, is
  // ambiguous between this rule and $.function_expression wrapped in an
  // expression-statement (both are followed by the same
  // $._lookback_semicolon there) -- but a bare named `function foo() {}`
  // statement is always a declaration in Haxe, never a dangling expression
  // statement, so this rule should win that tie outright.
  function_declaration: ($) =>
    prec(
      1,
      seq(
        repeat($.metadata),
        repeat($._modifier),
        'function',
        field('name', choice($._lhs_expression, 'new')),
        optional($.type_params),
        $._function_arg_list,
        optional(seq(':', field('return_type', $.type))),
        optional(field('body', $.block)),
        $._lookback_semicolon,
      ),
    ),

  _function_arg_list: ($) => prec(1, seq('(', commaSep($.function_arg), ')')),
  // Haxe allows the nullable-parameter '?' marker either before the name
  // (`?x:Int`, the classic/most common form) or after it (`x?:Int`) -- only
  // the postfix form was supported here. Pre-existing gap, unrelated to the
  // ternary/type_params fixes above; found by testing against real code in
  // this depot, where the prefix form is common (176 files).
  function_arg: ($) =>
    prec(
      1,
      seq(
        optional('?'),
        field('name', $._lhs_expression),
        optional('?'),
        optional(seq(':', alias(choice($._lhs_expression, $.type, $.structure_type), $.type))),
        optional(seq($._assignmentOperator, $._literal)),
      ),
    ),

  variable_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      choice('var', 'final'),
      field('name', $._lhs_expression),
      optional($.access_identifiers),
      optional(seq(':', optional(repeat('(')), field('type', $.type), optional(repeat(')')))),
      optional(seq(($._assignmentOperator, $.operator), $.expression)),
      $._lookback_semicolon,
    ),
};
