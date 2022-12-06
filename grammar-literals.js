// From: https://haxe.org/manual/expression-literals.html
const {commaSep} = require("./utils");

module.exports = {
  _literal: ($) => choice($.integer, $.float, $.string, $.bool, $.null, $.array),
  // Match any [42, 0xFF43]
  integer: ($) => choice(/[\d]+/, /0x[a-fA-F\d]+/),
  // Match any [0.32, 3., 2.1e5]
  float: ($) => choice(/[\d]+[\.]+[\d]*/, /[\d]+[\.]+[\d]*e[\d]*/),
  // Match either [true, false]
  bool: ($) => choice('true', 'false'),
  // Match any ["XXX", 'XXX']
  string: ($) => choice(
    seq(/\'/, repeat(choice($.interpolation, /[^\']/)), /\'/),
    /\"[^\"]*\"/
  ),
  // match only [null]
  null: ($) => 'null',

  // 
  array: ($) => seq('[', commaSep(prec.left($.expression)), ']'),

  // interplolated string.
  interpolation: ($) =>
    choice(
      $._interpolated_block,
      $._interpolated_identifier,
      //         $._interpolated_expression
    ),
  _interpolated_block: ($) => seq('${', $.expression, '}'),
  _interpolated_identifier: ($) => choice(
    seq('$', $._lhs_expression),
    seq('${', $._lhs_expression, '}')
  ),
  _interpolated_expression: ($) =>
    seq('$', seq(token.immediate('{'), $.expression, '}')),
}
