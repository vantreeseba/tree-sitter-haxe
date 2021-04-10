const types = require("./grammar-types");
const operations = require("./grammar-operations");
const expressions = require("./grammar-expressions");
const declarations = require("./grammar-declarations");

const haxe_grammar = {
  name: "haxe",
  word: ($) => $.identifier,
  // inline: ($) => [$.statement, $._semicolon],
  inline: ($) => [$.statement],
  extras: ($) => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/],
  supertypes: ($) => [
    $.statement,
    $.declaration,
    $.expression,
    $.primary_expression,
  ],
  precedences: ($) => [
    ["member", "unary_expression", "declaration"],
    ["member", $.expression],
    ["declaration", "literal"],
  ],
  conflicts: ($) => [],
  rules: {
    module: ($) => seq(repeat($.statement)),

    statement: ($) =>
      choice(
        $.package_statement,
        $.import_statement,
        $.expression_statement,
        $.declaration,
        $.statement_block
      ),

    expression_statement: ($) => seq($.expression, $._semicolon),

    statement_block: ($) => prec.right(seq("{", repeat($.statement), "}")),

    package_statement: ($) =>
      seq("package", field("path", $.identifier), $._semicolon),

    import_statement: ($) =>
      seq("import", field("path", $.identifier), $._semicolon),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: ($) =>
      token(
        choice(seq("//", /.*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"))
      ),
  },
};

haxe_grammar.rules = Object.assign(
  haxe_grammar.rules,
  types,
  operations,
  declarations,
  expressions,
  {
    _semicolon: ($) => ";",
  }
);

module.exports = grammar(haxe_grammar);
