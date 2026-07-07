// const types = require("./grammar-types");
const operators = require('./grammar-operators.js');
const literals = require('./grammar-literals.js');
const declarations = require('./grammar-declarations');
const builtins = require('./grammar-builtins');

const { commaSep, commaSep1 } = require('./utils');

const preprocessor_statement_start_tokens = ['if', 'elseif'];
const preprocessor_statement_end_tokens = ['else', 'end'];

const haxe_grammar = {
  name: 'haxe',
  externals: ($) => [$._lookback_semicolon, $._closing_brace_marker, $._closing_brace_unmarker],
  word: ($) => $.identifier,
  inline: ($) => [$.statement, $.expression],
  extras: ($) => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/, $._closing_brace_unmarker],
  supertypes: ($) => [$.declaration],
  conflicts: ($) => [
    [$.block, $.object],
    [$.typedef_declaration, $.type],
    [$._rhs_expression, $.pair],
    [$._literal, $.pair],
    [$.pair, $.pair],
    [$.function_declaration],
    [$.function_type, $.variable_declaration],
    [$.type, $.function_type, $.variable_declaration],
    [$.type, $._function_type_args],
    [$.structure_type_pair, $._function_type_args],
    [$.function_declaration, $.variable_declaration],
    [$._prefixUnaryOperator, $._arithmeticOperator],
    [$._prefixUnaryOperator, $._postfixUnaryOperator],
    [$.enum_abstract_declaration, $.enum_declaration],
    [$.typedef_declaration, $.structure_type],
    [$.member_expression, $._lhs_expression],
    [$._rhs_expression, $._lhs_expression],
    [$._rhs_expression, $.subscript_expression],
    [$._lhs_expression, $.pair],
    [$._ternary_condition, $.pair],
    [$._unaryExpression, $._ternary_condition, $.pair],
    [$._chain_term, $._ternary_condition],
    [$._rhs_expression, $.member_expression],
  ],
  rules: {
    module: ($) => seq(repeat($.statement)),

    // Statements
    statement: ($) =>
      // Use prec.left to favor rules that end SOONER
      // this means a semicolon ends the statement.
      prec.left(
        choice(
          $.preprocessor_statement,
          $.import_statement,
          $.using_statement,
          $.package_statement,
          $.declaration,
          $.switch_expression,
          seq($.expression, $._lookback_semicolon),
          $.conditional_statement,
          $.throw_statement,
          $.block,
          $.keyword,
          $.reserved_keyword,
        ),
      ),

    preprocessor_statement: ($) =>
      prec.right(
        seq(
          '#',
          choice(
            seq(token.immediate(choice(...preprocessor_statement_start_tokens)), $.expression),
            token.immediate(choice(...preprocessor_statement_end_tokens)),
          ),
        ),
      ),

    package_statement: ($) =>
      seq(
        'package',
        optional(field('name', seq(repeat(seq($.package_name, '.')), $.package_name))),
        $._semicolon,
      ),

    package_name: ($) => $._camelCaseIdentifier,
    type_name: ($) => $._pascalCaseIdentifier,
    _type_path: ($) => seq(repeat(seq($.package_name, '.')), repeat(seq($.type_name, '.')), $.type_name),

    import_statement: ($) =>
      seq(
        'import',
        seq(
          repeat(seq($.package_name, '.')),
          repeat(seq($.type_name, '.')),
          choice(
            seq('*'),
            seq($.type_name, optional(seq('.', alias($._camelCaseIdentifier, $.identifier)))),
          )
        ),
        optional(seq(choice('as', 'in'), choice($.type_name, alias($._camelCaseIdentifier, $.identifier)))),
        $._semicolon,
      ),

    using_statement: ($) =>
      seq(
        'using',
        seq(repeat(seq($.package_name, '.')), repeat(seq($.type_name, '.')), $.type_name),
        $._semicolon,
      ),

    throw_statement: ($) => prec.right(seq('throw', $.expression, $._lookback_semicolon)),

    // 'this' is added directly here (not just reachable via member_expression's
    // object field) so bare `this` works as a standalone expression -- return
    // value, assignment RHS, call argument, etc. -- not just as the head of a
    // member-access chain (`this.foo`). Pre-existing gap, unrelated to the two
    // fixes above; found by testing against real code in this depot, where
    // bare `this` is common (589 files).
    _rhs_expression: ($) =>
      prec(1, choice($._literal, $.identifier, 'this', $.member_expression, $.call_expression)),

    _unaryExpression: ($) =>
      prec.left(
        2,
        choice(
          // unary on LHS
          seq(alias($._prefixUnaryOperator, $.operator), $._rhs_expression),
          // unary on RHS
          seq($._rhs_expression, alias($._postfixUnaryOperator, $.operator)),
        ),
      ),

    runtime_type_check_expression: ($) =>
      prec(20, seq('(', alias($.structure_type_pair, 'type_check'), ')')),
    //     runtime_type_check_expression: ($) => prec.left(10, seq('(', $.pair, ')')),

    switch_expression: ($) =>
      prec.right(
        seq(
          'switch',
          choice($.identifier, $._parenthesized_expression),
          alias($.switch_block, $.block),
        ),
      ),

    _closing_brace: ($) => seq($._closing_brace_marker, '}'),

    switch_block: ($) => seq('{', repeat($.case_statement), $._closing_brace),

    case_statement: ($) =>
      prec.right(
        choice(
          seq('case', choice($._rhs_expression, alias('_', $._rhs_expression)), ':', $.statement),
          seq('default', ':', $.statement),
        ),
      ),

    cast_expression: ($) =>
      choice(
        seq('cast', $._rhs_expression),
        seq('cast', '(', $._rhs_expression, optional(seq(',', field('type', $.type))), ')'),
      ),

    type_trace_expression: ($) => seq('$type', '(', $._rhs_expression, ')'),

    _parenthesized_expression: ($) => seq('(', repeat1(prec.left($.expression)), ')'),

    range_expression: ($) =>
      prec(
        1,
        seq($.identifier, 'in', choice(seq($.integer, $._rangeOperator, $.integer), $.identifier)),
      ),

    _chain_term: ($) => seq(optional(alias($._prefixUnaryOperator, $.operator)), $._rhs_expression),

    _ternary_condition: ($) =>
      prec(
        2,
        choice(
          $._unaryExpression,
          $.subscript_expression,
          $.cast_expression,
          $._parenthesized_expression,
          seq($._rhs_expression, repeat(seq($.operator, $._rhs_expression))),
        ),
      ),

    // https://haxe.org/manual/expression-ternary.html
    ternary_expression: ($) =>
      prec.right(
        3,
        seq(
          field('condition', $._ternary_condition),
          '?',
          field('consequence', $.expression),
          ':',
          field('alternative', $.expression),
        ),
      ),

    expression: ($) =>
      choice(
        $._unaryExpression,
        $.subscript_expression,
        $.runtime_type_check_expression,
        $.cast_expression,
        $.type_trace_expression,
        $.range_expression,
        $._parenthesized_expression,
        $.switch_expression,
        $.ternary_expression,
        // simple expression, or chained.
        seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
        seq(
          alias($._prefixUnaryOperator, $.operator),
          $._rhs_expression,
          repeat1(seq($.operator, $._chain_term)),
        ),
        seq($.subscript_expression, repeat1(seq($.operator, $._chain_term))),
        seq(
          $._rhs_expression,
          alias($._postfixUnaryOperator, $.operator),
          repeat1(seq($.operator, $._chain_term)),
        ),
        seq(
          'return',
          optional(
            choice(
              seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
              seq(
                alias($._prefixUnaryOperator, $.operator),
                $._rhs_expression,
                repeat(seq($.operator, $._chain_term)),
              ),
              $.subscript_expression,
            ),
          ),
        ),
        seq(
          'untyped',
          choice(
            seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
            $.subscript_expression,
            seq(
              alias($._prefixUnaryOperator, $.operator),
              $._rhs_expression,
              repeat(seq($.operator, $._chain_term)),
            ),
          ),
        ),
        'break',
        'continue',
      ),

    subscript_expression: ($) =>
      prec.left(
        1,
        seq(
          choice($.identifier, $._parenthesized_expression, $.member_expression),
          '[',
          field('index', $.expression),
          ']',
        ),
        //           seq($._parenthesized_expression, '[', field('index', $.expression), ']'),
      ),

    // Left-associative (issue #52: `a.b.c` parses as `(a.b).c`, not
    // `a.(b.c)`) via recursion on the object side -- $.member_expression is
    // itself a valid `object`, and `member` is a single non-recursive
    // $.identifier. The '?.' tokenization stays atomic (one token, no
    // space allowed) rather than '?' and '.' as two separate tokens: with
    // them separate, `identifier '?'` is ambiguous between "start of
    // safe-nav" and "start of a ternary_expression" -- resolving that
    // needs to see whether '.' follows, i.e. 2 tokens of lookahead, more
    // than LALR(1) has. Making '?.' atomic pushes that decision into the
    // lexer instead of the parser -- needed for ternary support.
    member_expression: ($) =>
      prec.left(1,
        seq(
          field('object', choice('this', $.identifier, $.member_expression, $._literal)),
          choice(token('.'), alias(token(seq('?', '.')), $.operator)),
          field('member', $.identifier),
        ),
      ),

    _lhs_expression: ($) => prec(1, choice($.identifier, $.member_expression)),

    builtin_type: ($) => prec.right(choice(...builtins)),

    _function_type_args: ($) => commaSep1(seq(optional(seq($.identifier, ':')), $.type)),

    function_type: ($) =>
      prec.right(
        choice(
          seq('(', ')', '->', $.type),
          seq($.type, '->', field('return_type', $.type)),
          seq('(', $._function_type_args, ')', '->', $.type),
        ),
      ),

    type: ($) =>
      prec.right(
        choice(
          seq(
            choice(
              field('type_name', $._lhs_expression),
              field('built_in', alias($.builtin_type, $.identifier)),
            ),
            optional($.type_params),
          ),
          $.function_type,
          seq('(', alias($.type, 'type'), ')'),
        ),
      ),

    block: ($) => seq('{', repeat($.statement), $._closing_brace),

    metadata: ($) =>
      seq(
        choice(token('@'), token('@:')),
        field('name', $._lhs_expression),
        optional(seq('(', $.expression, ')')),
      ),

    // arg list is () with any amount of expressions followed by commas
    _arg_list: ($) => seq('(', commaSep($.expression), ')'),

    // 'else if' was previously a single literal token with no condition of
    // its own -- `if (a) {} else if (c) {}` lost both `c` and the entire
    // second block, since matching that literal token left nothing to
    // consume `(c)` or the block after it, corrupting parse recovery for
    // the rest of the statement. Extremely common real-world shape (1,352
    // files in this depot use `else if`); pre-existing gap, unrelated to
    // the fixes above. Now: 'else' 'if' as two separate tokens, each
    // else-if branch gets its own condition/block via repeat(...), reusing
    // the same 'arguments_list' field name across branches -- same
    // convention as e.g. class_declaration's repeated 'implements' clauses.
    conditional_statement: ($) =>
      prec.right(
        1,
        seq(
          field('name', 'if'),
          field('arguments_list', $._arg_list),
          optional($.block),
          // $.block here must NOT be optional() (unlike the primary if's
          // block above, matching the original design): with it optional,
          // the parser could -- and silently did, with no ERROR node --
          // end this repeat iteration early and let a real, present block
          // become a separate top-level statement instead, splitting an
          // `else if (c) {d();} else {e();}` tail into a bogus bare
          // identifier "else" plus two unrelated floating blocks.
          repeat(seq('else', 'if', field('arguments_list', $._arg_list), $.block)),
          optional(seq('else', $.block)),
        ),
      ),

    _call: ($) =>
      prec(
        1,
        seq(
          field('object', $._lhs_expression),
          optional($.type_params),
          field('arguments_list', $._arg_list),
        ),
      ),

    _constructor_call: ($) =>
      seq(
        'new',
        seq(
          repeat(seq($.package_name, '.')),
          repeat(seq($.type_name, '.')),
          field('constructor', $.type_name),
          optional($.type_params),
          field('arguments_list', $._arg_list),
        ),
      ),

    call_expression: ($) => choice($._call, $._constructor_call),

    ...operators,
    ...declarations,
    ...literals,

    comment: ($) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),
    // TODO: implement the structures that use these
    keyword: ($) => choice('catch', 'do', 'for', 'try', 'while'),
    // keywords reserved by the haxe compiler that are not currently used
    reserved_keyword: ($) => choice('operator'),
    identifier: ($) => /[a-zA-Z_]+[a-zA-Z0-9]*/,
    // Hidden Nodes in tree.
    _camelCaseIdentifier: ($) => /[a-z_]+[a-zA-Z0-9_]*/,
    _pascalCaseIdentifier: ($) => /[A-Z_]+[a-zA-Z0-9_]*/,
    _semicolon: ($) => $._lookback_semicolon,
  },
};

module.exports = grammar(haxe_grammar);
