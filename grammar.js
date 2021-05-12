// const types = require("./grammar-types");
// const operations = require("./grammar-operations");
// const expressions = require("./grammar-expressions");
// const declarations = require("./grammar-declarations");
const keywords = require("./grammar-keywords");

const haxe_grammar = {
  name: "haxe",
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
        seq($.expression, choice($.block, $._semicolon)),
        $.import_statement,
        $.package_statement,
        $.declaration,
        seq(
          $.identifier,
          $.operator,
          choice($.identifier, $.literal),
          $._semicolon
        ),
        seq($.operator, $.identifier, optional($._semicolon)),
        seq($.identifier, $.operator, optional($._semicolon))
      ),

    package_statement: ($) =>
      seq(
        alias("package", $.keyword),
        field("name", $.identifier),
        $._semicolon
      ),

    import_statement: ($) =>
      seq(
        alias("import", $.keyword),
        field("name", $.identifier),
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
        repeat($.attribute),
        alias("class", $.keyword),
        field("name", $.identifier),
        field("body", $.block)
      ),

    function_declaration: ($) =>
      seq(
        repeat($.attribute),
        repeat($.keyword),
        alias("function", $.keyword),
        choice(
          field("name", $.identifier),
          field("name", alias("new", $.identifier))
        ),
        seq("(", repeat(seq($.function_arg, optional(","))), ")"),
        field("body", $.block)
      ),

    function_arg: ($) =>
      seq(
        field("name", $.identifier),
        optional(seq(":", alias($.identifier, $.type))),
        optional(seq($._assignmentOperator, $.literal))
      ),

    variable_declaration: ($) =>
      seq(
        repeat($.keyword),
        alias("var", $.keyword),
        field("name", $.identifier),
        optional(seq(":", field("type", alias($.identifier, $.type)))),
        optional(seq($.operator, $.literal)),
        $._semicolon
      ),
    // Root tokens.
    block: ($) => seq("{", repeat($.statement), "}"),

    attribute: ($) =>
      seq(
        choice("@", "@:"),
        field("name", $.identifier),
        optional(seq("(", $.literal, ")"))
      ),

    // TODO: Add operators.
    expression: ($) => prec.right(repeat1(choice($.keyword, $.identifier))),
    // statement: ($) => seq($.expression, choice($.block, $._semicolon)),
    comment: ($) =>
      token(
        choice(seq("//", /.*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"))
      ),

    keyword: ($) => prec.right(choice(...keywords)),

    // TODO: Think about removing the . from this.
    identifier: ($) => /[a-zA-Z_]+[a-zA-Z0-9\.]*/,

    // From: https://haxe.org/manual/expression-literals.html
    literal: ($) => choice($.integer, $.float, $.string, $.bool, $.null),
    // Match any [42, 0xFF43]
    integer: ($) => choice(/[\d]+/, /0x[a-fA-F\d]+/),
    // Match any [0.32, 3., 2.1e5]
    float: ($) => choice(/[\d]+[\.]+[\d]*/, /[\d]+[\.]+[\d]*e[\d]*/),
    // Match either [true, false]
    bool: ($) => choice("true", "false"),
    // Match any ["XXX", 'XXX']
    string: ($) => choice(/\'[^\']*\'/, /\"[^\"]*\"/),
    // match only [null]
    null: ($) => "null",

    // TODO: array, map, anonymous struct, range
    // array: ($) => "null",

    operator: ($) => choice($._binaryOperator, $._unaryOperator),

    // From: https://haxe.org/manual/expression-operators-unops.html
    _unaryOperator: ($) =>
      prec.right(choice($._prefixUnaryOperator, $._postfixUnaryOperator)),
    _prefixUnaryOperator: ($) => choice("~", "!", "-", "++", "--"),
    _postfixUnaryOperator: ($) => choice("++", "--"),

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
    _arithmeticOperator: ($) => choice("%", "*", "/", "+", "-"),
    _bitwiseOperator: ($) => choice("<<", ">>", ">>>", "&", "|", "^"),
    _logicalOperator: ($) => choice("&&", "||"),
    _comparisonOperator: ($) => choice("==", "!=", "<", "<=", ">", ">="),
    _miscOperator: ($) => choice("...", "=>"),
    _assignmentOperator: ($) => "=",
    _compoundAssignmentOperator: ($) =>
      seq(
        choice($._arithmeticOperator, $._bitwiseOperator),
        $._assignmentOperator
      ),

    type: ($) => $.identifier,

    // Hidden Nodes in tree.
    _semicolon: ($) => ";",
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
function commaSep1(rule) {
  return seq(rule, repeat(seq(",", rule)));
}

function commaSep(rule) {
  return optional(commaSep1(rule));
}

module.exports = grammar(haxe_grammar);
