// const types = require("./grammar-types");
// const operations = require("./grammar-operations");
// const expressions = require("./grammar-expressions");
// const declarations = require("./grammar-declarations");
const keywords = require('./grammar-keywords');
const builtins = require('./grammar-builtins');

const preprocessor_statement_start_tokens = ['if', 'elseif'];
const preprocessor_statement_end_tokens = ['else', 'end'];

const haxe_grammar = {
  name: 'haxe',
  word: ($) => $.identifier,
  inline: ($) => [$.statement, $.expression],
  extras: ($) => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/],
  supertypes: ($) => [$.declaration],
  precedences: ($) => [[$._unaryOperator, $._binaryOperator]],
  conflicts: ($) => [
    [$.function_declaration],
    [$.function_declaration, $.variable_declaration],
    [$._prefixUnaryOperator, $._arithmeticOperator],
    [$._prefixUnaryOperator, $._postfixUnaryOperator],
  ],
  rules: {
    module: ($) => seq(repeat($.statement)),

    // Statements
    statement: ($) =>
      choice(
        $.preprocessor_statement,
        seq($.expression, choice($.block, $._semicolon)),
        seq(
          $.conditional_statement,
          choice($.block, seq($.expression, $._semicolon))
        ),
        $.import_statement,
        $.package_statement,
        $.declaration,
        seq($._lhs_expression, $.operator, optional($._semicolon)),
        seq($.operator, $._lhs_expression, optional($._semicolon)),
        seq($._lhs_expression, $.operator, optional($._semicolon))
      ),

    preprocessor_statement: ($) =>
      prec.right(
        seq(
          '#',
          choice(
            seq(
              token.immediate(choice(...preprocessor_statement_start_tokens)),
              choice(
                seq(optional($.operator), choice($._lhs_expression, $.literal)),
                seq(
                  '(',
                  repeat1(choice($._lhs_expression, $.literal, $.operator)),
                  ')'
                )
              )
            ),
            token.immediate(choice(...preprocessor_statement_end_tokens))
          )
        )
      ),

    package_statement: ($) =>
      seq(
        alias('package', $.keyword),
        field('name', $._lhs_expression),
        $._semicolon
      ),

    import_statement: ($) =>
      seq(
        alias('import', $.keyword),
        field('name', $._lhs_expression),
        $._semicolon
      ),

    // Declarations
    declaration: ($) =>
      choice(
        $.class_declaration,
        $.function_declaration,
        $.variable_declaration
      ),

    class_declaration: ($) =>
      seq(
        repeat($.metadata),
        alias('class', $.keyword),
        field('name', $._lhs_expression),
        optional($.type_params),
        field('body', $.block)
      ),

    type_param: ($) => $._lhs_expression,
    type_params: ($) =>
      prec(1,
        seq('<', repeat(seq($.type_param, ',')), $.type_param, '>')
      ),

    function_declaration: ($) =>
      seq(
        repeat($.metadata),
        repeat($.keyword),
        alias('function', $.keyword),
        choice(
          field('name', $._lhs_expression),
          field('name', alias('new', $.identifier))
        ),
        optional($.type_params),
        $._function_arg_list,
        optional(seq(':', field('return_type', $.type))),
        field('body', $.block)
      ),

    function_arg: ($) =>
      seq(
        field('name', $._lhs_expression),
        optional(seq(':', alias($._lhs_expression, $.type))),
        optional(seq($._assignmentOperator, $.literal))
      ),

    _function_arg_list: ($) => seq('(', commaSep($.function_arg), ')'),

    variable_declaration: ($) =>
      seq(
        repeat($.metadata),
        repeat($.keyword),
        choice(alias('var', $.keyword), alias('final', $.keyword)),
        field('name', $._lhs_expression),
        optional(seq(':', field('type', $.type))),
        optional(seq(alias($._assignmentOperator, $.operator), $.expression)),
        repeat(seq($.operator, $.expression)),
        $._semicolon
      ),

    // Root tokens.
    block: ($) => seq('{', repeat($.statement), '}'),

    metadata: ($) =>
      seq(
        choice('@', '@:'),
        field('name', $._lhs_expression),
        optional(seq('(', $.literal, ')'))
      ),

    // TODO: Add operators.
    _rValue: ($) => prec.right(choice($._lhs_expression, $.literal, $._constructor_call, $.call)),

    _runtime_type_check_expression: ($) =>
      seq('(', $.expression, ':', $.type, ')'),

    _cast_expression: ($) =>
      choice(
        seq(alias('cast', $.keyword), $._rValue),
        seq(
          alias('cast', $.keyword),
          '(',
          $._rValue,
          optional(seq(',', field('type', alias($._rValue, $.type)))),
          ')'
        )
      ),

    expression: ($) =>
      prec.right(
        choice(
          $._cast_expression,
          $._runtime_type_check_expression,
          repeat1(seq($._rValue, optional($.operator)))
        )
      ),

    _lhs_expression: ($) => 
      choice($.identifier, $.member_expression),

    member_expression: ($) => 
      prec.right(
        seq(
          field('object', $.identifier),
          token('.'),
          repeat1($._lhs_expression)
        )
      ),

    comment: ($) =>
      token(
        choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))
      ),

    keyword: ($) => prec.right(choice(...keywords)),

    // TODO: Think about removing the . from this.
    identifier: ($) => /[a-zA-Z_]+[a-zA-Z0-9]*/,

    // From: https://haxe.org/manual/expression-literals.html
    literal: ($) => choice($.integer, $.float, $.string, $.bool, $.null),
    // Match any [42, 0xFF43]
    integer: ($) => choice(/[\d]+/, /0x[a-fA-F\d]+/),
    // Match any [0.32, 3., 2.1e5]
    float: ($) => choice(/[\d]+[\.]+[\d]*/, /[\d]+[\.]+[\d]*e[\d]*/),
    // Match either [true, false]
    bool: ($) => choice('true', 'false'),
    // Match any ["XXX", 'XXX']
    string: ($) =>
      choice(
        seq(/\'/, repeat(choice($.interpolation, /[^\']/)), /\'/),
        /\"[^\"]*\"/
      ),
    // match only [null]
    null: ($) => 'null',

    // interplolated string.
    interpolation: ($) =>
      choice(
        $._interpolated_block,
        $._interpolated_identifier,
        //         $._interpolated_expression
      ),
    _interpolated_block: ($) => seq('${', $.expression, '}'),
    _interpolated_identifier: ($) =>
      choice(seq('$', $._lhs_expression), seq('${', $._lhs_expression, '}')),
    _interpolated_expression: ($) =>
      seq('$', seq(token.immediate('{'), $.expression, '}')),

    // TODO: array, map, anonymous struct, range
    // array: ($) => "null",
    operator: ($) => choice($._binaryOperator, $._unaryOperator),

    // From: https://haxe.org/manual/expression-operators-unops.html
    _unaryOperator: ($) =>
      prec.right(choice($._prefixUnaryOperator, $._postfixUnaryOperator)),
    _prefixUnaryOperator: ($) => choice('~', '!', '-', '++', '--'),
    _postfixUnaryOperator: ($) => choice('++', '--'),

    // From: https://haxe.org/manual/expression-operators-binops.html
    _binaryOperator: ($) =>
      prec.left(
        choice(
          $._arithmeticOperator,
          $._bitwiseOperator,
          $._logicalOperator,
          $._comparisonOperator,
          $._miscOperator,
          $._assignmentOperator,
          $._compoundAssignmentOperator
        )
      ),
    _arithmeticOperator: ($) => choice('%', '*', '/', '+', '-'),
    _bitwiseOperator: ($) => choice('<<', '>>', '>>>', '&', '|', '^'),
    _logicalOperator: ($) => choice('&&', '||'),
    _comparisonOperator: ($) => choice('==', '!=', '<', '<=', '>', '>='),
    _miscOperator: ($) => choice('...', '=>'),
    _assignmentOperator: ($) => '=',
    _compoundAssignmentOperator: ($) =>
      seq(
        choice($._arithmeticOperator, $._bitwiseOperator),
        $._assignmentOperator
      ),

    builtin_type: ($) => prec.right(choice(...builtins)),
    type: ($) => choice($._lhs_expression, $.builtin_type),

    // arg list is () with any amount of expressions followed by commas
    _call_arg_list: ($) => seq('(', commaSep($.expression), ')'),

    conditional_statement: ($) =>
      prec(
        1,
        seq(
          field('name', $.keyword),
          field('arguments_list', $._call_arg_list)
        )
      ),

    _constructor_call: ($) => 
      prec(1,
        seq(
          optional(alias('new', $.keyword)), // for constructor calls.
          $.call
        )
      ),

    call: ($) =>
      prec(
        1,
        seq(
          $._lhs_expression,
          optional($.type_params),
          field('arguments_list', $._call_arg_list)
        )
      ),

    // Hidden Nodes in tree.
    _semicolon: ($) => ';',
  },
};

// haxe_grammar.rules = Object.assign(
//   haxe_grammar.rules,
//   // types,
//   // operations,
//   // declarations,
//   // expressions,
//   {}
// );

// Took these from
// https://github.com/tree-sitter/tree-sitter-javascript/blob/master/grammar.js
function commaSep(rule) {
  return optional(seperated(rule, ','));
}

function dotSep1(rule) {
  return seperated(rule, '.');
}

function seperated(rule, seperator) {
  return seq(rule, repeat(seq(seperator, rule)));
}

function seperatedSkipLast(rule, seperator) {
  return repeat1(seq(rule, seperator));
}

module.exports = grammar(haxe_grammar);
