// const types = require("./grammar-types");
const operators = require('./grammar-operators.js');
const literals = require('./grammar-literals.js');
const declarations = require('./grammar-declarations');
const builtins = require('./grammar-builtins');

const { commaSep, commaSep1 } = require('./utils');

const haxe_grammar = {
  name: 'haxe',
  externals: ($) => [$._lookback_semicolon, $._closing_brace_marker, $._closing_brace_unmarker],
  word: ($) => $.identifier,
  inline: ($) => [$.statement, $.expression],
  extras: ($) => [$.comment, /[\s\uFEFF\u2060\u200B\u00A0]/, $._closing_brace_unmarker],
  supertypes: ($) => [$.declaration],
  conflicts: ($) => [
    [$.block, $.object],
    [$.typedef_declaration, $.type],
    [$._rhs_expression, $.pair],
    [$._literal, $.pair],
    [$.pair, $.pair],
    [$.function_declaration],
    [$.function_type, $.variable_declaration],
    [$.type, $.function_type, $.variable_declaration],
    [$.type, $._function_type_args],
    [$.structure_type_pair, $._function_type_args],
    [$.function_declaration, $.variable_declaration],
    [$._prefixUnaryOperator, $._arithmeticOperator],
    [$._prefixUnaryOperator, $._postfixUnaryOperator],
    [$.enum_abstract_declaration, $.enum_declaration],
    [$.typedef_declaration, $.structure_type],
    [$.member_expression, $._lhs_expression],
    [$.preprocessor_statement],
    [$._rhs_expression, $._lhs_expression],
    [$._rhs_expression, $.subscript_expression],
    [$._lhs_expression, $.pair],
    [$._ternary_condition, $.pair],
    [$._unaryExpression, $._ternary_condition, $.pair],
    [$._chain_term, $._ternary_condition],
    [$._rhs_expression, $.member_expression],
  ],
  rules: {
    module: ($) => seq(repeat($.statement)),

    // Statements
    statement: ($) =>
      // Use prec.left to favor rules that end SOONER
      // this means a semicolon ends the statement.
      prec.left(
        choice(
          $.preprocessor_statement,
          $.import_statement,
          $.using_statement,
          $.package_statement,
          $.declaration,
          $.switch_expression,
          seq($.expression, $._lookback_semicolon),
          $.conditional_statement,
          $.throw_statement,
          $.block,
          $.keyword,
          $.reserved_keyword,
        ),
      ),

    // `#if`/`#elseif`/`#else`/`#end` previously matched as separate,
    // unrelated $.statement siblings, with no structural link to the
    // declarations/statements they're actually guarding -- `#if (sys ||
    // nodejs)` and the `function benchmark() {...}` right after it came out
    // as two disconnected nodes in a flat list, silently discarding the
    // conditional-compilation relationship (no ERROR node; this is a
    // "wrong tree, not a broken one" bug, github.com/vantreeseba/tree-sitter-haxe/issues/36).
    // Extremely common in this depot: 534 files use `#if`/`#elseif`
    // immediately guarding a declaration-shaped line (var/function/public/etc).
    // Restructured to nest each branch's guarded statements as children of
    // one preprocessor_statement node, the same "each branch owns its own
    // condition and body" shape used for conditional_statement's
    // (`if`/`else if`/`else`) fix earlier in this fork's history. This does
    // NOT evaluate which branch is "active" -- all branches stay in the
    // tree, since a single source file compiles to multiple targets
    // (html5, flash, cpp, ...) and every variant needs to stay visible to
    // tooling built on this grammar, not just whichever one a particular
    // build's defines would keep.
    preprocessor_statement: ($) =>
      prec.right(
        seq(
          '#',
          token.immediate('if'),
          field('condition', $.expression),
          repeat($.statement),
          repeat(
            seq('#', token.immediate('elseif'), field('condition', $.expression), repeat($.statement)),
          ),
          optional(seq('#', token.immediate('else'), repeat($.statement))),
          '#',
          token.immediate('end'),
        ),
      ),

    package_statement: ($) =>
      seq(
        'package',
        optional(field('name', seq(repeat(seq($.package_name, '.')), $.package_name))),
        $._semicolon,
      ),

    package_name: ($) => $._camelCaseIdentifier,
    type_name: ($) => $._pascalCaseIdentifier,
    _type_path: ($) => seq(repeat(seq($.package_name, '.')), repeat(seq($.type_name, '.')), $.type_name),

    import_statement: ($) =>
      seq(
        'import',
        seq(
          repeat(seq($.package_name, '.')),
          repeat(seq($.type_name, '.')),
          choice(
            seq('*'),
            seq($.type_name, optional(seq('.', alias($._camelCaseIdentifier, $.identifier)))),
          )
        ),
        optional(seq(choice('as', 'in'), choice($.type_name, alias($._camelCaseIdentifier, $.identifier)))),
        $._semicolon,
      ),

    using_statement: ($) =>
      seq(
        'using',
        seq(repeat(seq($.package_name, '.')), repeat(seq($.type_name, '.')), $.type_name),
        $._semicolon,
      ),

    throw_statement: ($) => prec.right(seq('throw', $.expression, $._lookback_semicolon)),

    _rhs_expression: ($) =>
      prec(1, choice($._literal, $.identifier, $.member_expression, $.call_expression)),

    // Restricted to the actual unary operator sets (_prefixUnaryOperator/
    // _postfixUnaryOperator), not the fully generic $.operator (which also
    // includes every binary operator). The generic version let e.g. `width <`
    // match here treating '<' as a bogus "postfix unary" operator -- almost
    // never an issue on its own since it's semantically nonsensical, but it
    // created a second, equally error-free reading for comparison-conditioned
    // ternaries inside parens (`(width < height ? width : height)`, matching
    // real code in this depot): _unaryExpression could swallow "width <" as
    // one expression, leaving a second, separate ternary_expression for just
    // "height ? width : height" -- silently misparsing `a < b ? c : d` as
    // `a < (b ? c : d)` with no ERROR node to catch it. This was a
    // pre-existing latent bug, not introduced by the < vs. type_params fix
    // above; it surfaced now because it happened to share a state with the
    // newly-added ternary_expression.
    _unaryExpression: ($) =>
      prec.left(
        2,
        choice(
          // unary on LHS
          seq(alias($._prefixUnaryOperator, $.operator), $._rhs_expression),
          // unary on RHS
          seq($._rhs_expression, alias($._postfixUnaryOperator, $.operator)),
        ),
      ),

    runtime_type_check_expression: ($) =>
      prec(20, seq('(', alias($.structure_type_pair, 'type_check'), ')')),
    //     runtime_type_check_expression: ($) => prec.left(10, seq('(', $.pair, ')')),

    switch_expression: ($) =>
      prec.right(
        seq(
          'switch',
          choice($.identifier, $._parenthesized_expression),
          alias($.switch_block, $.block),
        ),
      ),

    _closing_brace: ($) => seq($._closing_brace_marker, '}'),

    switch_block: ($) => seq('{', repeat($.case_statement), $._closing_brace),

    case_statement: ($) =>
      prec.right(
        choice(
          seq('case', choice($._rhs_expression, alias('_', $._rhs_expression)), ':', $.statement),
          seq('default', ':', $.statement),
        ),
      ),

    cast_expression: ($) =>
      choice(
        seq('cast', $._rhs_expression),
        seq('cast', '(', $._rhs_expression, optional(seq(',', field('type', $.type))), ')'),
      ),

    type_trace_expression: ($) => seq('$type', '(', $._rhs_expression, ')'),

    _parenthesized_expression: ($) => seq('(', repeat1(prec.left($.expression)), ')'),

    range_expression: ($) =>
      prec(
        1,
        seq($.identifier, 'in', choice(seq($.integer, $._rangeOperator, $.integer), $.identifier)),
      ),

    // A chain term that may optionally carry a leading prefix-unary operator
    // (`!y`, `-y`, etc.), used only in a chain's TAIL positions (never as a
    // chain's head -- using this in head position reintroduces an extra
    // reduce step that collides with the head's own shift/reduce decision
    // and silently breaks even plain chains like `1 + 2`; confirmed by
    // testing, not just theorized). Restricted to tail positions, it lets
    // `a && !b`, `!a && !b`, etc. parse -- not just `!a && b`, which the
    // leading-unary `expression` alternative below already covers.
    _chain_term: ($) => seq(optional(alias($._prefixUnaryOperator, $.operator)), $._rhs_expression),

    // Deliberately excludes $.ternary_expression itself (and the statement-
    // like forms below) so a bare, unparenthesized ternary can't be used as
    // another ternary's condition -- `a ? b : c` must be wrapped in parens
    // to serve as a condition. This keeps the grammar's only self-recursion
    // on this rule in the `alternative` field, which is what gives
    // `a ? b : c ? d : e` its right-associative ("else if" chain) reading
    // instead of an ambiguous choice between two equally-valid nestings.
    // prec(1, ...) on the whole choice, not just one branch: `pair`'s value
    // slot is `$.expression`, which reaches every alternative below via
    // ternary_expression's condition field, so any of them can be mid-parse
    // when a '?' shows up. Higher precedence than `pair`'s default (0) means
    // the parser shifts (keeps parsing toward the ternary) instead of
    // reducing the pair immediately, so `x : y ? c : d` reads as
    // `x : (y ? c : d)` rather than leaving `? c : d` dangling after a
    // prematurely-closed pair.
    _ternary_condition: ($) =>
      prec(
        2,
        choice(
          $._unaryExpression,
          $.subscript_expression,
          $.cast_expression,
          $._parenthesized_expression,
          seq($._rhs_expression, repeat(seq($.operator, $._rhs_expression))),
        ),
      ),

    // https://haxe.org/manual/expression-ternary.html
    ternary_expression: ($) =>
      prec.right(
        3,
        seq(
          field('condition', $._ternary_condition),
          '?',
          field('consequence', $.expression),
          ':',
          field('alternative', $.expression),
        ),
      ),

    expression: ($) =>
      choice(
        $._unaryExpression,
        $.subscript_expression,
        $.runtime_type_check_expression,
        $.cast_expression,
        $.type_trace_expression,
        $.range_expression,
        $._parenthesized_expression,
        $.switch_expression,
        $.ternary_expression,
        // simple expression, or chained.
        seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
        // Same chain, but with a leading prefix-unary term (`!x && y`,
        // `-x + y`, etc.) -- requires repeat1 (at least one more operator/
        // term after the head) so this alternative is never reachable for a
        // solo unary term like `!x` alone; that continues to go exclusively
        // through $._unaryExpression above. Without that exclusivity this
        // would create a second, ambiguous derivation for every solo unary
        // expression. $._unaryExpression's prefix-only reach (never chained)
        // meant `!x && y` and similar always failed outright, even though
        // it's extremely common real-world code (818 files in this depot
        // use this shape).
        seq(
          alias($._prefixUnaryOperator, $.operator),
          $._rhs_expression,
          repeat1(seq($.operator, $._chain_term)),
        ),
        // $.subscript_expression as a chain HEAD -- `x[i] = y;`,
        // `x[i] * y`, etc. $.subscript_expression was only ever a complete,
        // standalone `expression` on its own (e.g. `x[i];` alone), never
        // one term of a longer chain, so any assignment or arithmetic
        // involving an array/map element on the left failed outright.
        // Extremely common (e.g. `mPieces[idx] = null;`,
        // `sPeerMap[arg] = sharedName;`, `kBonusWinCredits[i] * mult`).
        // repeat1-gated for the same reason as the leading-unary
        // alternative above: a solo `x[i]` alone must still go through
        // the plain $.subscript_expression choice, not this one.
        seq($.subscript_expression, repeat1(seq($.operator, $._chain_term))),
        // A postfix-unary term (`i--`, `i++`) as a chain HEAD -- `i-- > 0`,
        // common in `while (i-- > 0)` loops. The leading-unary alternative
        // above only covers a PREFIX unary head (`!x && y`); postfix was
        // still only reachable as the entire standalone $._unaryExpression,
        // never chained with a further operator. Same repeat1 gating and
        // same rationale as the leading-unary alternative.
        seq(
          $._rhs_expression,
          alias($._postfixUnaryOperator, $.operator),
          repeat1(seq($.operator, $._chain_term)),
        ),
        // `return`/`untyped` previously only took a single bare
        // $._rhs_expression, not a chain -- so `return a == b;` or
        // `return a = b;` (assign-and-return, common in this depot's
        // property setters, e.g. `return mKenoCardModel = kenoCardModel;`)
        // had no valid derivation covering the whole span, and would
        // hard-error. This was actually a PRE-EXISTING gap masked by a
        // separate bug: before the _unaryExpression operator-set fix
        // elsewhere in this fork's history, `a ==`/`a =` could silently
        // (and incorrectly) match as _unaryExpression's postfix form
        // (generic $.operator misread as a bogus postfix unary op),
        // giving `return` an _rhs_expression-shaped path to latch onto by
        // accident. Fixing that bug correctly closed off the accidental
        // path here too, surfacing this as a hard ERROR instead of a
        // silent misparse -- found via a depot-wide sweep combining this
        // fork's fixes, not caught by any single fix's own testing.
        // Broadened to accept the same chain shapes -- plain and
        // leading-unary -- that a bare (non-`return`) expression already
        // supports, plus a bare subscript return value (`return arr[i];`,
        // also common) which $._rhs_expression doesn't cover either.
        seq(
          'return',
          optional(
            choice(
              seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
              seq(
                alias($._prefixUnaryOperator, $.operator),
                $._rhs_expression,
                repeat(seq($.operator, $._chain_term)),
              ),
              $.subscript_expression,
            ),
          ),
        ),
        seq(
          'untyped',
          choice(
            seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
            $.subscript_expression,
            seq(
              alias($._prefixUnaryOperator, $.operator),
              $._rhs_expression,
              repeat(seq($.operator, $._chain_term)),
            ),
          ),
        ),
        'break',
        'continue',
      ),

    subscript_expression: ($) =>
      prec.left(
        1,
        seq(
          choice($.identifier, $._parenthesized_expression, $.member_expression),
          '[',
          field('index', $.expression),
          ']',
        ),
        //           seq($._parenthesized_expression, '[', field('index', $.expression), ']'),
      ),

    // Left-associative (issue #52: `a.b.c` parses as `(a.b).c`, not
    // `a.(b.c)`) via recursion on the object side -- $.member_expression is
    // itself a valid `object`, and `member` is a single non-recursive
    // $.identifier. The '?.' tokenization stays atomic (one token, no
    // space allowed) rather than '?' and '.' as two separate tokens: with
    // them separate, `identifier '?'` is ambiguous between "start of
    // safe-nav" and "start of a ternary_expression" -- resolving that
    // needs to see whether '.' follows, i.e. 2 tokens of lookahead, more
    // than LALR(1) has. Making '?.' atomic pushes that decision into the
    // lexer instead of the parser -- needed for ternary support.
    member_expression: ($) =>
      prec.left(1,
        seq(
          field('object', choice('this', $.identifier, $.member_expression, $._literal)),
          choice(token('.'), alias(token(seq('?', '.')), $.operator)),
          field('member', $.identifier),
        ),
      ),

    _lhs_expression: ($) => prec(1, choice($.identifier, $.member_expression)),

    builtin_type: ($) => prec.right(choice(...builtins)),

    _function_type_args: ($) => commaSep1(seq(optional(seq($.identifier, ':')), $.type)),

    function_type: ($) =>
      prec.right(
        choice(
          seq('(', ')', '->', $.type),
          seq($.type, '->', field('return_type', $.type)),
          seq('(', $._function_type_args, ')', '->', $.type),
        ),
      ),

    type: ($) =>
      prec.right(
        choice(
          seq(
            choice(
              field('type_name', $._lhs_expression),
              field('built_in', alias($.builtin_type, $.identifier)),
            ),
            optional($.type_params),
          ),
          $.function_type,
          seq('(', alias($.type, 'type'), ')'),
        ),
      ),

    block: ($) => seq('{', repeat($.statement), $._closing_brace),

    metadata: ($) =>
      seq(
        choice(token('@'), token('@:')),
        field('name', $._lhs_expression),
        optional(seq('(', $.expression, ')')),
      ),

    // arg list is () with any amount of expressions followed by commas
    _arg_list: ($) => seq('(', commaSep($.expression), ')'),

    conditional_statement: ($) =>
      prec.right(
        1,
        seq(
          field('name', 'if'),
          field('arguments_list', $._arg_list),
          optional($.block),
          optional(seq(choice('else', 'else if'), $.block)),
        ),
      ),

    _call: ($) =>
      prec(
        1,
        seq(
          field('object', $._lhs_expression),
          optional($.type_params),
          field('arguments_list', $._arg_list),
        ),
      ),

    _constructor_call: ($) =>
      seq(
        'new',
        seq(
          repeat(seq($.package_name, '.')),
          repeat(seq($.type_name, '.')),
          field('constructor', $.type_name),
          optional($.type_params),
          field('arguments_list', $._arg_list),
        ),
      ),

    call_expression: ($) => choice($._call, $._constructor_call),

    ...operators,
    ...declarations,
    ...literals,

    comment: ($) => token(choice(seq('//', /.*/), seq('/*', /[^*]*\*+([^/*][^*]*\*+)*/, '/'))),
    // TODO: implement the structures that use these
    keyword: ($) => choice('catch', 'do', 'for', 'try', 'while'),
    // keywords reserved by the haxe compiler that are not currently used
    reserved_keyword: ($) => choice('operator'),
    identifier: ($) => /[a-zA-Z_]+[a-zA-Z0-9]*/,
    // Hidden Nodes in tree.
    _camelCaseIdentifier: ($) => /[a-z_]+[a-zA-Z0-9_]*/,
    _pascalCaseIdentifier: ($) => /[A-Z_]+[a-zA-Z0-9_]*/,
    _semicolon: ($) => $._lookback_semicolon,
  },
};

module.exports = grammar(haxe_grammar);
