// Took these from
// https://github.com/tree-sitter/tree-sitter-javascript/blob/master/grammar.js

const separated = (rule, separator) => seq(rule, repeat(seq(separator, rule)));
const separatedSkipLast = (rule, separator) => repeat1(seq(rule, separator));

// Haxe allows (and this codebase idiomatically uses) a trailing comma before
// the closing delimiter in array/object/call/param lists -- `[1, 2,]` is
// valid, unlike a trailing `.` in a dotted path. So comma-lists get their own
// trailing-separator-tolerant variant rather than changing `separated` itself
// (which `dotSep`/`dotSep1` below also share, and a trailing dot is never
// valid there).
const separatedTrailing = (rule, separator) =>
  seq(rule, repeat(seq(separator, rule)), optional(separator));

const commaSep = (rule) => optional(separatedTrailing(rule, ','));
const commaSep1 = (rule) => separatedTrailing(rule, ',');

const dotSep = (rule) => optional(separated(rule, '.'));
const dotSep1 = (rule) => separated(rule, '.');

module.exports = {
  commaSep,
  commaSep1,
  dotSep1,
  separated,
  separatedSkipLast,
};
