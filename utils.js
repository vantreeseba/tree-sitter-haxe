// Took these from
// https://github.com/tree-sitter/tree-sitter-javascript/blob/master/grammar.js
function commaSep(rule) {
  return optional(seperated(rule, ','));
}

function dotSep1(rule) {
  return seperated(rule, '.');
}

function seperated(rule, seperator) {
  return seq(rule, repeat(seq(seperator, rule)));
}

function seperatedSkipLast(rule, seperator) {
  return repeat1(seq(rule, seperator));
}

module.exports = {
  commaSep,
  dotSep1,
  seperated,
  seperatedSkipLast
}
