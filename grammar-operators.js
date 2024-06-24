module.exports = {
  // TODO: array, map, anonymous struct, range
  // array: ($) => "null",
  operator: ($) => choice($._binaryOperator, $._unaryOperator),

  // From: https://haxe.org/manual/expression-operators-unops.html
  _unaryOperator: ($) => prec.right(choice($._prefixUnaryOperator, $._eitherUnaryOperator)),
  _prefixUnaryOperator: ($) => token(choice('~', '!', '-')),
  _eitherUnaryOperator: ($) => token(choice('++', '--')),

  // From: https://haxe.org/manual/expression-operators-binops.html
  _binaryOperator: ($) =>
    prec.left(
      choice(
        $._arithmetic_operator,
        $._bitwise_operator,
        $._logical_operator,
        $._comparison_operator,
        $._map_operator,
        $._null_colalese_operator,
        $._assignment_operator,
        $._compound_assignment_operator,
        $._range_operator,
      ),
    ),
  _arithmetic_operator: ($) => token(choice('%', '*', '/', '+', '-')),
  _bitwise_operator: ($) => token(choice('<<', '>>', '>>>', '&', '|', '^')),
  _logical_operator: ($) => token(choice('&&', '||')),
  _comparison_operator: ($) => token(choice('==', '!=', '<', '<=', '>', '>=')),
  _map_operator: ($) => token(choice('=>')),
  _null_colalese_operator: ($) => token(choice('??')),
  _assignment_operator: ($) => token('='),
  _compound_assignment_operator: ($) =>
    seq(choice($._arithmetic_operator, $._bitwise_operator), $._assignment_operator),
  _range_operator: ($) => token('...'),
};
