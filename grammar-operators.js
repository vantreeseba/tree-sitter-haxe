module.exports = {
  // TODO: array, map, anonymous struct, range
  // array: ($) => "null",
  operator: ($) => choice($._binaryOperator, $._unaryOperator),

  // From: https://haxe.org/manual/expression-operators-unops.html
  _unaryOperator: ($) => prec.right(choice($._prefixUnaryOperator, $._postfixUnaryOperator)),
  _prefixUnaryOperator: ($) => choice('~', '!', '-', '++', '--'),
  _postfixUnaryOperator: ($) => choice('++', '--'),

  // From: https://haxe.org/manual/expression-operators-binops.html
  _binaryOperator: ($) =>
    prec.left(
      choice(
        $._arithmeticOperator,
        $._bitwiseOperator,
        $._logicalOperator,
        $._comparisonOperator,
        $._miscOperator,
        $._assignmentOperator,
        $._compoundAssignmentOperator,
        $._rangeOperator,
      ),
    ),
  _arithmeticOperator: ($) => choice('%', '*', '/', '+', '-'),
  _bitwiseOperator: ($) => choice('<<', '>>', '>>>', '&', '|', '^'),
  _logicalOperator: ($) => choice('&&', '||'),
  _comparisonOperator: ($) => choice('==', '!=', '<', '<=', '>', '>='),
  _miscOperator: ($) => choice('=>', '??'),
  //   _miscOperator: ($) => choice('...', '=>'),
  _assignmentOperator: ($) => '=',
  _compoundAssignmentOperator: ($) =>
    seq(choice($._arithmeticOperator, $._bitwiseOperator), $._assignmentOperator),
  _rangeOperator: ($) => '...',
};
