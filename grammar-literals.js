// From: https://haxe.org/manual/expression-literals.html
const { commaSep, commaSep1 } = require('./utils');

module.exports = {
  // Main "literal" export.
  _literal: ($) =>
    choice($.integer, $.float, $.string, $.bool, $.null, $.array, $.map, $.object, $.pair),

  // Match any [42, 0xFF43]
  integer: ($) => choice(/[\d_]+/, /0x[a-fA-F\d_]+/),
  // Match any [0.32, 2.1e5]. Requires at least one digit after the '.'
  // (`[\d_]+` not `[\d_]*`) -- deliberately drops support for a *trailing*-
  // dot float with no digits after it (`3.`, which the original comment
  // here listed as supported) to fix a much more damaging, silent bug:
  // `0...10` (an integer immediately followed by the range operator -- the
  // single most common shape for a `for` loop's iterable, e.g.
  // `for (i in 0...10)`) was being lexed as ONE token, "0.", stopping right
  // after the first '.' and silently swallowing the rest of the range
  // operator with no ERROR node (a float is a perfectly valid, complete
  // token on its own). Tree-sitter's regex engine has no lookahead, so
  // there's no way to keep `3.` valid while still telling `0.` apart from
  // `0...`; picked the fix that helps far more real code than it costs
  // (the `for (i in 0...N)` shape appears in ~2,000 files in this depot;
  // a real, code -- not comment/string -- occurrence of a genuinely bare
  // trailing-dot float is comparatively rare and easy to write as `3.0`
  // instead if it ever turns up broken).
  float: ($) => choice(/[\d_]+\.[\d_]+/, /[\d_]+\.[\d_]+e[\d_]*/),
  // Match either [true, false]
  bool: ($) => choice('true', 'false'),
  // Match any ["XXX", 'XXX']
  string: ($) =>
    choice(
      seq(/\'/, repeat(choice($.interpolation, $.escape_sequence, /[^\'\\]/)), /\'/),
      // Double-quoted strings are atomic so that "//" inside a URL cannot be
      // lexed as a comment extra by the tree-sitter extras mechanism.
      token(seq('"', /([^"\\]|\\.)*/, '"')),
    ),
  // match only [null]
  null: ($) => 'null',

  // https://haxe.org/manual/expression-array-declaration.html
  // Array comprehension (https://haxe.org/manual/lf-array-comprehension.html,
  // `[for (i in 0...10) i]` / `[while (...) ...]`) is its own alternative,
  // not folded into the plain-elements one -- it starts with a literal
  // 'for'/'while' token, so there's no overlap with a normal
  // comma-separated array literal (including the single-element case,
  // `[x]`) to disambiguate. The previous placeholder attempt here
  // (`seq('[', $.expression, $.identifier, ']')`) didn't match real Haxe
  // comprehension syntax at all.
  array: ($) =>
    choice(
      seq('[', commaSep(prec.left($.expression)), ']'),
      seq('[', choice($.comprehension_for, $.comprehension_while), ']'),
    ),

  // https://haxe.org/manual/expression-map-declaration.html
  map: ($) => prec(1, seq('[', commaSep1($.pair), ']')),

  // https://haxe.org/manual/expression-object-declaration.html
  object: ($) => prec(1, seq('{', commaSep($.pair), $._closing_brace)),

  structure_type: ($) => prec(1, seq('{', commaSep(alias($.structure_type_pair, $.pair)), $._closing_brace)),
  structure_type_pair: ($) => prec.left(seq(choice($.identifier), ':', $.type)),

  // Sub part of map and object literals.
  pair: ($) =>
    prec.right(
      1,
      choice(
        // Precedence -1, unlike the '=>' alternative below: `pair` is
        // reachable as a bare _literal outside of {}/[] too (e.g. the
        // "simple pair literal" test, `x:1;`), which is unambiguous on its
        // own, but that reachability also makes `identifier ':' expression`
        // a standing alternate reading of any ternary_expression's
        // condition/consequence/alternative slot. Without a lower
        // precedence here, that ambiguity silently resolves in favor of
        // `pair` (tree-sitter doesn't even report it as a conflict needing
        // a decision), swallowing a ternary's ':' and everything after it
        // into the pair's value instead of leaving it for the ternary. -1
        // only matters when there's an actual competing interpretation to
        // lose to; it doesn't change the unambiguous {}/[] contexts or the
        // bare `x:1;` case. Scoped to just this alternative -- an earlier
        // attempt at giving `pair` as a whole -1 also demoted the '=>'
        // alternative, which broke map literals (`[k => v]`) by letting
        // array's generic `expression` chain (which can itself represent
        // `_literal '=>' _literal` as an inline operator chain) win a
        // now-lopsided tie it used to lose fairly.
        prec(-1, seq(choice($.identifier, $.string), ':', $.expression)),
        seq(choice($.identifier, $._literal), '=>', $.expression),
      ),
    ),

  // interplolated string.
  interpolation: ($) =>
    choice(
      $._interpolated_block,
      $._interpolated_identifier,
      //         $._interpolated_expression
    ),
  _interpolated_block: ($) => seq('${', $.expression, '}'),
  _interpolated_identifier: ($) =>
    choice(seq('$', $._lhs_expression), seq('${', $._lhs_expression, '}')),
  _interpolated_expression: ($) => seq('$', seq(token.immediate('{'), $.expression, '}')),

  escape_sequence: ($) =>
    token.immediate(
      seq(
        '\\',
        choice(/[^xu0-7]/, /[0-7]{1,3}/, /x[0-9a-fA-F]{2}/, /u[0-9a-fA-F]{4}/),
        //         choice(/[^xu0-7]/, /[0-7]{1,3}/, /x[0-9a-fA-F]{2}/, /u[0-9a-fA-F]{4}/, /u{[0-9a-fA-F]+}/),
      ),
    ),
};
