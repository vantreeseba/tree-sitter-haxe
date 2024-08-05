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
  word: ($) => $.identifier,
  inline: ($) => [$.statement, $.expression],
  extras: ($) => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/],
  supertypes: ($) => [
    $.declaration,
    //     $.expression,
    //     $.statement,
  ],
  conflicts: ($) => [
    [$.typedef_declaration, $.type],
    [$.call_expression, $._constructor_call],
    [$._literal, $.pair],
    [$.function_declaration],
    [$.type, $._function_type_args],
    [$.structure_type_pair, $._function_type_args],
  ],
  rules: {
    module: ($) => seq(repeat($.statement)),

    // Statements
    statement: ($) =>
      // Use prec.left to favor rules that end SOONER
      // this means a semicolon ends the statement.
      prec.left(
        seq(
          choice(
            $.preprocessor_statement,
            $.import_statement,
            $.using_statement,
            $.package_statement,
            $.declaration,
            $.expression,
            $.conditional_statement,
            $.case_statement,
            $.throw_statement,
            $.block,
          ),
          optional($._semicolon),
        ),
      ),

    preprocessor_statement: ($) =>
      prec.right(
        seq(
          '#',
          choice(
            seq(token.immediate(choice(...preprocessor_statement_start_tokens)), $.statement),
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

    throw_statement: ($) => prec.right(seq(alias('throw', $.keyword), $.expression)),

    _unaryExpression: ($) =>
      prec.left(
        1,
        choice(
          // unary on LHS
          seq(
            alias(choice($._prefixUnaryOperator, $._eitherUnaryOperator), $.operator),
            $._rhs_expression,
          ),
          // unary on RHS
          seq($._rhs_expression, alias($._eitherUnaryOperator, $.operator)),
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

    switch_block: ($) => seq('{', repeat($.case_statement), '}'),

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
          choice(seq($.integer, $._range_operator, $.integer), $.identifier),
        ),
      ),

    subscript_expression: ($) =>
      prec.left(
        1,
        seq(
          choice($.identifier, $._parenthesized_expression, $.member_expression),
          token('['),
          field('index', $.expression),
          token(']'),
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
          token(choice('?.', '.')),
          repeat1(field('member', $._lhs_expression)),
        ),
      ),

    _binary_expression: ($) =>
      prec.left(10, seq($.expression, alias($._binaryOperator, $.operator), $.expression)),

    ternary_expression: ($) =>
      prec.right(
        5,
        seq(
          field('condition', $.expression),
          alias('?', $.operator),
          field('true_result', $.expression),
          alias(':', $.operator),
          field('false_result', $.expression),
        ),
      ),

    _lhs_expression: ($) => prec(1, choice($.identifier, $.member_expression)),
    _rhs_expression: ($) =>
      prec.right(choice($._literal, $.identifier, $.member_expression, $.call_expression)),

    expression: ($) =>
      choice(
        $._rhs_expression,
        $._unaryExpression,
        $.subscript_expression,
        $.runtime_type_check_expression,
        $.cast_expression,
        $.type_trace_expression,
        $.range_expression,
        $._parenthesized_expression,
        $.switch_expression,
        $._binary_expression,
        $.ternary_expression,
        // simple expression, or chained.
        //         seq($._rhs_expression, repeat(seq($.operator, $._rhs_expression))),
      ),

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

    block: ($) => seq('{', repeat($.statement), '}'),

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
