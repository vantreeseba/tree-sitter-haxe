// const types = require("./grammar-types");
const operators = require('./grammar-operators.js');
const literals = require('./grammar-literals.js');
const declarations = require('./grammar-declarations');
const keywords = require('./grammar-keywords');
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
    [$.call_expression, $._constructor_call],
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
      seq(alias('package', $.keyword), field('name', $._lhs_expression), $._semicolon),

    import_statement: ($) =>
      seq(alias('import', $.keyword), field('name', $._lhs_expression), $._semicolon),

    using_statement: ($) =>
      seq(alias('using', $.keyword), field('name', $._lhs_expression), $._semicolon),

    throw_statement: ($) => prec.right(seq(alias('throw', $.keyword), $.expression, $._lookback_semicolon)),

    _rhs_expression: ($) =>
      prec.right(choice($._literal, $.identifier, $.member_expression, $.call_expression)),

    _unaryExpression: ($) =>
      prec.left(
        1,
        choice(
          // unary on LHS
          seq($.operator, $._rhs_expression),
          // unary on RHS
          seq($._rhs_expression, $.operator),
        ),
      ),

    runtime_type_check_expression: ($) =>
      prec(20, seq('(', alias($.structure_type_pair, 'type_check'), ')')),
    //     runtime_type_check_expression: ($) => prec.left(10, seq('(', $.pair, ')')),

    switch_expression: ($) =>
      prec.right(
        seq(
          alias('switch', $.keyword),
          choice($.identifier, $._parenthesized_expression),
          //           optional(alias($.switch_block, $.block)),
        ),
      ),

    _closing_brace: ($) => seq($._closing_brace_marker, '}'),

    switch_block: ($) => seq('{', repeat($.case_statement), $._closing_brace),

    case_statement: ($) =>
      prec.right(
        choice(
          seq(
            alias('case', $.keyword),
            choice($._rhs_expression, alias('_', $._rhs_expression)),
            ':',
            $.statement,
          ),
          seq(alias('default', $.keyword), ':', $.statement),
        ),
      ),

    cast_expression: ($) =>
      choice(
        seq(alias('cast', $.keyword), $._rhs_expression),
        seq(
          alias('cast', $.keyword),
          '(',
          $._rhs_expression,
          optional(seq(',', field('type', $.type))),
          ')',
        ),
      ),

    type_trace_expression: ($) => seq(alias('$type', $.keyword), '(', $._rhs_expression, ')'),

    _parenthesized_expression: ($) => seq('(', repeat1(prec.left($.expression)), ')'),

    range_expression: ($) =>
      prec(
        1,
        seq(
          $.identifier,
          alias('in', $.keyword),
          choice(seq($.integer, $._rangeOperator, $.integer), $.identifier),
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
        // simple expression, or chained.
        seq($._rhs_expression, repeat(seq($.operator, $._rhs_expression))),
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

    member_expression: ($) =>
      prec.right(
        seq(
          choice(
            field('object', choice(alias('this', $.keyword), $.identifier)),
            field('literal', $._literal),
          ),
          choice(token('.'), seq(alias('?', $.operator), '.')),
          repeat1(field('member', $._lhs_expression)),
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

    conditional_statement: ($) =>
      prec.right(
        1,
        seq(
          field('name', alias('if', $.keyword)),
          field('arguments_list', $._arg_list),
          optional($.block),
          optional(seq(alias(choice('else', 'else if'), $.keyword), $.block)),
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
        optional(alias('new', $.keyword)), // for constructor calls.
        $._call,
      ),

    call_expression: ($) => choice($._call, $._constructor_call),

    ...operators,
    ...declarations,
    ...literals,

    comment: ($) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),
    keyword: ($) => prec.right(choice(...keywords)),
    identifier: ($) => /[a-zA-Z_]+[a-zA-Z0-9]*/,
    // Hidden Nodes in tree.
    _semicolon: ($) => ';',
  },
};

module.exports = grammar(haxe_grammar);
