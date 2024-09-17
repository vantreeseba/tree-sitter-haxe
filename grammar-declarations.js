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
  _access_identifier: ($) => choice('default', 'null', 'get', 'set', 'dynamic', 'never'),
  access_identifiers: ($) =>
    seq('(', $._access_identifier, optional(seq(',', $._access_identifier)), ')'),
  type_params: ($) => prec.right(1, seq('<', commaSep1($.type), '>')),

  _modifier: ($) =>
    choice(
      'macro',
      'abstract',
      'static',
      'public',
      'private',
      'extern',
      'inline',
      'overload',
      'override',
      'final',
    ),

  class_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'class',
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        seq('extends', field('super_class_name', $._type_path), optional($.type_params)),
      ),
      optional(
        repeat(
          seq('implements', field('interface_name', $._type_path), optional($.type_params)),
        ),
      ),
      field('body', $.block),
    ),

  interface_declaration: ($) =>
    seq(
      repeat($._modifier),
      'interface',
      field('name', $._lhs_expression),
      optional($.type_params),
      optional(
        repeat(seq('extends', field('interface_name', $._type_path), optional($.type_params))),
      ),
      field('body', $.block),
    ),

  typedef_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'typedef',
      field('name', $._lhs_expression),
      optional($.type_params),
      seq('=', choice($.block, $._lhs_expression, $.type)),
      $._lookback_semicolon,
    ),

  function_declaration: ($) =>
    seq(
      repeat($.metadata),
      repeat($._modifier),
      'function',
      field('name', choice($._lhs_expression, 'new')),
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
      repeat($._modifier),
      choice('var', 'final'),
      field('name', $._lhs_expression),
      optional($.access_identifiers),
      optional(seq(':', optional(repeat('(')), field('type', $.type), optional(repeat(')')))),
      optional(seq(($._assignmentOperator, $.operator), $.expression)),
      $._lookback_semicolon,
    ),
};
