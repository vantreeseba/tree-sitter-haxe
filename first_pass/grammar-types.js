module.exports = {
  type: ($) => choice($._basic_type, $.identifier),

  _basic_type: ($) =>
    alias(choice("Int", "Float", "Bool", "Void"), $.identifier),

  access_modifier: ($) =>
    choice("public", "protected", "private", "static", "inline"),
};
