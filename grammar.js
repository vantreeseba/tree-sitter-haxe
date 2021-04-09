module.exports = grammar({
  name: "haxe",
  word: ($) => $.identifier,
  rules: {
    // source_file: ($) => "hello",
    module: ($) =>
      seq(
        optional($.package_statement),
        repeat($.import_statement),
        optional($.class_declaration)
      ),

    package_statement: ($) =>
      seq(
        "package",
        field("package_name", repeat(seq($.identifier, optional(".")))),
        ";"
      ),

    import_statement: ($) =>
      seq("import", repeat(seq($.identifier, optional("."))), ";"),

    class_declaration: ($) =>
      seq("class", field("class_name", $.identifier), $._block),

    _member_declaration: ($) =>
      seq(
        repeat($.access_modifier),
        choice($.function_declaration, $.variable_declaration)
      ),

    function_declaration: ($) =>
      seq("function", field("function_name", $.identifier), $._args, $._block),

    variable_declaration: ($) =>
      seq("var", field("variable_name", $.identifier), ";"),

    _args: ($) => seq("(", repeat($._expression), ")"),
    _block: ($) => seq("{", repeat($._expression), "}"),

    access_modifier: ($) =>
      choice("private", "protected", "public", "static", "inline"),

    _expression: ($) => choice($._member_declaration),
    identifier: ($) => /[a-zA-Z0-9]+/,
    // number: ($) => /\d+/,
  },
});
