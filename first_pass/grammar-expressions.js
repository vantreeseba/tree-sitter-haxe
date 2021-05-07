module.exports = {
  identifier: ($) => /[a-zA-Z_]*[a-zA-Z0-9\.]+/,
  expression: ($) => choice($.primary_expression, $.unary_expression),

  primary_expression: ($) =>
    choice($.subscript_expression, $.member_expression, $.identifier),

  subscript_expression: ($) =>
    prec.right(
      "member",
      seq(
        field("object", choice($.expression, $.primary_expression)),
        "[",
        field("index", $.expression),
        "]"
      )
    ),
  member_expression: ($) =>
    prec(
      "member",
      seq(
        field("object", choice($.expression, $.primary_expression)),
        choice(".", "?."),
        field("property", $.identifier)
        // field("property", alias($.identifier, $.property_identifier))
      )
    ),
};
