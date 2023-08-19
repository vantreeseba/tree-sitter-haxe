const { commaSep } = require('./utils');

module.exports = {
  // Declarations
  declaration: ($) =>
    choice(
      $.interface_declaration,
      $.class_declaration,
      $.typedef_declaration,
      $.function_declaration,
      $.variable_declaration,
    ),

  class_declaration: ($) =>
    seq(
      repeat($.metadata),
      optional(choice(alias('final', $.keyword), alias('abstract', $.keyword))),
      alias('class', $.keyword),
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        repeat(seq(alias('implements', $.keyword), field('interface_name', $._lhs_expression))),
      ),
      field('body', $.block),
    ),

  interface_declaration: ($) =>
    seq(
      //       repeat($.metadata),
      optional(alias('final', $.keyword)),
      alias('interface', $.keyword),
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        repeat(seq(alias('extends', $.keyword), field('interface_name', $._lhs_expression))),
      ),
      field('body', $.block),
    ),

  typedef_declaration: ($) =>
    seq(
      repeat($.metadata),
      alias('typedef', $.keyword),
      field('name', $._lhs_expression),
      optional($.type_params),
      seq('=', choice($.block, $._lhs_expression, $.type)),
    ),

  type_param: ($) => $._lhs_expression,
  type_params: ($) => prec(1, seq('<', repeat(seq($.type_param, ',')), $.type_param, '>')),

  function_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($.keyword),
      alias('function', $.keyword),
      choice(field('name', $._lhs_expression), field('name', alias('new', $.identifier))),
      optional($.type_params),
      $._function_arg_list,
      optional(seq(':', field('return_type', $.type))),
      field('body', $.block),
    ),

  function_arg: ($) =>
    prec(
      1,
      seq(
        field('name', $._lhs_expression),
        optional('?'),
        optional(seq(':', alias(choice($._lhs_expression, $.type, $.structure_type), $.type))),
        optional(seq($._assignmentOperator, $._literal)),
      ),
    ),

  _function_arg_list: ($) => seq('(', commaSep($.function_arg), ')'),

  variable_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($.keyword),
      choice(alias('var', $.keyword), alias('final', $.keyword)),
      field('name', $._lhs_expression),
      optional(seq(':', field('type', $.type), optional($.type_params))),
      optional(seq(($._assignmentOperator, $.operator), $.expression)),
      $._semicolon,
    ),
};
