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

  typedef_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'typedef',
      field('name', $._lhs_expression),
      optional($.type_params),
      seq('=', choice($.block, $.structure_type, $._lhs_expression, $.type)),
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
  function_arg: ($) =>
    prec(
      1,
      seq(
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
