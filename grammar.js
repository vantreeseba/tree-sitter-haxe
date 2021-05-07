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
  precedences: ($) => [],
  conflicts: ($) => [
    [$.function_declaration],
    [$.function_declaration, $.variable_declaration],
  ],
  rules: {
    module: ($) => seq(repeat($.statement)),

    // Statements
    statement: ($) =>
      choice(
        seq($.expression, choice($.block, $._semicolon)),
        $.package_statement,
        $.declaration,
        seq(
          $.identifier,
          $.operator,
          choice($.identifier, $.literal),
          $._semicolon
        ),
        seq($.operator, $.identifier, optional($._semicolon)),
        seq($.identifier, $.operator, optional($._semicolon)),
      ),

    package_statement: ($) =>
      seq(
        alias("package", $.keyword),
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
        alias("class", $.keyword),
        field("name", $.identifier),
        field("body", $.block)
      ),

    function_declaration: ($) =>
      seq(
        repeat($.attribute),
        repeat($.keyword),
        alias("function", $.keyword),
        field("name", $.identifier),
        seq("(", ")"),
        field("body", $.block)
      ),

    variable_declaration: ($) =>
      seq(
        repeat($.keyword),
        alias("var", $.keyword),
        field("name", $.identifier),
        optional(seq(":", alias($.identifier, $.type))),
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

    literal: ($) => choice($.integer, $.float, $.string, $.bool, $.null),
    integer: ($) => /[\d]+/,
    float: ($) => /[\d]+[\.]+[\d]*/,
    string: ($) => choice(/\'[^\']*\'/, /\"[^\"]*\"/),
    bool: ($) => choice("true", "false"),
    null: ($) => choice("null"),

    operator: ($) => choice($._binaryOperator, $._unaryOperator),
    _binaryOperator: ($) => "=",
    _unaryOperator: ($) => "++",

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
