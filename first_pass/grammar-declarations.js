module.exports = {
  declaration: ($) =>
    choice($.class_declaration, $.function_declaration, $.variable_declaration),

  class_body: ($) => seq("{", repeat(field("member", $.declaration)), "}"),

  class_declaration: ($) =>
    prec(
      "declaration",
      seq("class", field("name", $.identifier), field("body", $.class_body))
    ),

  _call_signature: ($) =>
    field("parameters", seq("(", repeat($.identifier), ")")),
  function_declaration: ($) =>
    prec.right(
      "declaration",
      seq(
        repeat($.access_modifier),
        "function",
        field("name", $.identifier),
        $._call_signature,
        field("body", $.statement_block)
      )
    ),

  variable_declaration: ($) =>
    prec.right(
      "declaration",
      seq(
        repeat($.access_modifier),
        "var",
        field("name", $.identifier),
        optional(field("type", seq(":", $.type))),
        $._semicolon
      )
    ),
};
