// Took these from
// https://github.com/tree-sitter/tree-sitter-javascript/blob/master/grammar.js

const seperated = (rule, seperator) => seq(rule, repeat(seq(seperator, rule)));
const seperatedSkipLast = (rule, seperator) => repeat1(seq(rule, seperator));

const commaSep = (rule) => optional(seperated(rule, ','));
const commaSep1 = (rule) => seperated(rule, ',');

const dotSep = (rule) => optional(seperated(rule, '.'));
const dotSep1 = (rule) => seperated(rule, '.');

module.exports = {
  commaSep,
  commaSep1,
  dotSep1,
  seperated,
  seperatedSkipLast,
};
