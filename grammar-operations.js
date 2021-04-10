module.exports = {
  unary_expression: ($) =>
    prec.left(
      "unary_expression",
      choice(
        $.increment_unop,
        $.decrement_unop,
        $.not_unop,
        $.negative_unop,
        $.bitwise_negative_unop
      )
    ),

  increment_unop: ($) =>
    prec.left(
      choice(
        seq(field("operand", $.expression), field("operator", "++")),
        seq(field("operator", "++"), field("operand", $.expression))
      )
    ),

  decrement_unop: ($) =>
    prec.left(
      choice(
        seq(field("operand", $.expression), field("operator", "--")),
        seq(field("operator", "--"), field("operand", $.expression))
      )
    ),

  not_unop: ($) => prec.left("unary_expression", seq("!", $.expression)),
  negative_unop: ($) => prec.left("unary_expression", seq("-", $.expression)),
  bitwise_negative_unop: ($) =>
    prec.left("unary_expression", seq("~", $.expression)),
};
