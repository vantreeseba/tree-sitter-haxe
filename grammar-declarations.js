const { commaSep, commaSep1 } = require('./utils');

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
  _access_identifier: ($) =>
    alias(choice('default', 'null', 'get', 'set', 'dynamic', 'never'), $.keyword),
  access_identifiers: ($) =>
    seq('(', $._access_identifier, optional(seq(',', $._access_identifier)), ')'),
  type_params: ($) => prec.right(1, seq('<', commaSep1($.type), '>')),

  class_declaration: ($) =>
    seq(
      repeat($.metadata),
      optional(choice(alias('final', $.keyword), alias('abstract', $.keyword))),
      alias('class', $.keyword),
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        seq(
          alias('extends', $.keyword),
          field('super_class_name', $._lhs_expression),
          optional($.type_params),
        ),
      ),
      optional(
        repeat(
          seq(
            alias('implements', $.keyword),
            field('interface_name', $._lhs_expression),
            optional($.type_params),
          ),
        ),
      ),
      field('body', $.block),
    ),

  interface_declaration: ($) =>
    seq(
      optional(alias('final', $.keyword)),
      alias('interface', $.keyword),
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        repeat(
          seq(
            alias('extends', $.keyword),
            field('interface_name', $._lhs_expression),
            optional($.type_params),
          ),
        ),
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
      $._lookback_semicolon,
    ),

  function_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($.keyword),
      alias('function', $.keyword),
      choice(field('name', $._lhs_expression), field('name', alias('new', $.identifier))),
      optional($.type_params),
      $._function_arg_list,
      optional(seq(':', field('return_type', $.type))),
      optional(field('body', $.block)),
      $._lookback_semicolon,
    ),

  _function_arg_list: ($) => prec(1, seq('(', commaSep($.function_arg), ')')),
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

  variable_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($.keyword),
      choice(alias('var', $.keyword), alias('final', $.keyword)),
      field('name', $._lhs_expression),
      optional($.access_identifiers),
      optional(seq(':', optional(repeat('(')), field('type', $.type), optional(repeat(')')))),
      optional(seq(($._assignmentOperator, $.operator), $.expression)),
      $._lookback_semicolon,
    ),
};
