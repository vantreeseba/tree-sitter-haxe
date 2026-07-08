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
    [$.function_expression, $.function_declaration],
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
    [$.conditional_statement],
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
          $.while_statement,
          $.do_while_statement,
          $.for_statement,
          $.try_statement,
          $.throw_statement,
          $.block,
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

    // 'this' is added directly here (not just reachable via member_expression's
    // object field) so bare `this` works as a standalone expression -- return
    // value, assignment RHS, call argument, etc. -- not just as the head of a
    // member-access chain (`this.foo`). Pre-existing gap, unrelated to the two
    // fixes above; found by testing against real code in this depot, where
    // bare `this` is common (589 files).
    _rhs_expression: ($) =>
      prec(1, choice($._literal, $.identifier, 'this', $.member_expression, $.call_expression)),

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

    // Anonymous function literal used in expression position (callback
    // arguments, variable-declaration RHS, etc.) -- `doThing(function(x) {
    // ... })`. There was previously no way to write a function as an
    // expression at all: $.function_declaration is a statement-level
    // $.declaration that always ends in $._lookback_semicolon, which isn't
    // present (and shouldn't be consumed) when a function literal is nested
    // inside a call's argument list or ends right at ')'. Real-world code
    // uses this constantly (373 files in this depot pass an anonymous
    // function as a callback argument). Deliberately excludes
    // $._modifier/type_params (not valid on an anonymous function) and the
    // trailing semicolon (the function's block is the end of the
    // expression, whatever follows -- ')', ',', ';' -- belongs to the
    // enclosing construct, not this rule).
    function_expression: ($) =>
      seq(
        repeat($.metadata),
        'function',
        optional(field('name', $._lhs_expression)),
        $._function_arg_list,
        optional(seq(':', field('return_type', $.type))),
        field('body', $.block),
      ),

    _parenthesized_expression: ($) => seq('(', repeat1(prec.left($.expression)), ')'),

    // Previously baked `identifier 'in' ...` directly into this rule --
    // a workaround from when `for` itself was an unimplemented placeholder
    // keyword, using range_expression to soak up a for-loop's `(i in
    // 0...10)` content via accidental juxtaposition. Now that $.for_statement
    // provides its own real binding + 'in' + iterable structure, a dedicated
    // range_expression node turned out to be unnecessary: `$._rangeOperator`
    // is already one of `$.operator`'s choices, so the plain chain
    // alternative in `expression` below (`_rhs_expression (operator
    // _chain_term)*`) already parses `0...10`, `arr.length - 1 ...
    // arr.length + 5`, etc. correctly on its own, with no ERROR and no
    // separate rule needed. A dedicated range_expression rule (narrowing
    // the operand operator set to avoid swallowing its own '...'
    // separator) is therefore unreachable dead code -- the plain chain
    // alternative always wins over it -- so it's removed rather than kept
    // around unused.

    // A chain term that may optionally carry a leading prefix-unary operator
    // (`!y`, `-y`, etc.), used only in a chain's TAIL positions (never as a
    // chain's head -- using this in head position reintroduces an extra
    // reduce step that collides with the head's own shift/reduce decision
    // and silently breaks even plain chains like `1 + 2`). Restricted to
    // tail positions, it lets `a && !b`, `!a && !b`, etc. parse -- not just
    // `!a && b`, which the leading-unary `expression` alternative below
    // already covers.
    // $.subscript_expression is included alongside $._rhs_expression here
    // so it can appear as a chain's TAIL term too (`null != arr[id]`) --
    // not just as a chain's HEAD, which the dedicated
    // `seq($.subscript_expression, repeat1(...))` alternative in
    // `expression` below already covers.
    //
    // $._parenthesized_expression is included for the same reason: a
    // parenthesized sub-expression could previously only appear as an
    // ENTIRE standalone expression (the top-level $._parenthesized_expression
    // choice in `expression` below), never as one term of a longer chain --
    // so `0...(10)`, `a + (b)`, `total = (a + b) / 2`, etc. all hard-errored.
    // This fixes the TAIL position; see the dedicated
    // `seq($._parenthesized_expression, repeat1(...))` alternative in
    // `expression` below for the analogous HEAD-position fix.
    _chain_term: ($) =>
      seq(
        optional(alias($._prefixUnaryOperator, $.operator)),
        choice($._rhs_expression, $.subscript_expression, $._parenthesized_expression),
      ),

    _ternary_condition: ($) =>
      prec(
        2,
        choice(
          $._unaryExpression,
          $.subscript_expression,
          $.cast_expression,
          $._parenthesized_expression,
          // Tail terms use $._chain_term (not $._rhs_expression) so a
          // parenthesized tail term works here too -- `(x >= 0) && (x < 10)
          // ? a : b` previously hard-errored even though the unparenthesized
          // `x >= 0 && x < 10 ? a : b` worked fine, since $._rhs_expression
          // still excludes $._parenthesized_expression.
          seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
          // A parenthesized HEAD term followed by more chain -- `(x >= 0) &&
          // y ? a : b`. Same head/tail split as $._parenthesized_expression's
          // two fixes in $._chain_term / `expression` above; repeat1-gated so
          // a solo `(x >= 0)` alone still resolves via the standalone
          // $._parenthesized_expression choice above, not this one.
          seq($._parenthesized_expression, repeat1(seq($.operator, $._chain_term))),
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
        $._parenthesized_expression,
        $.switch_expression,
        $.function_expression,
        $.ternary_expression,
        // simple expression, or chained.
        seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
        seq(
          alias($._prefixUnaryOperator, $.operator),
          $._rhs_expression,
          repeat1(seq($.operator, $._chain_term)),
        ),
        seq($.subscript_expression, repeat1(seq($.operator, $._chain_term))),
        // $._parenthesized_expression as a chain HEAD -- `(a + b) * c`,
        // `(a + b) / 2`, etc. Same gap as $.subscript_expression above: a
        // parenthesized sub-expression could only ever be an entire
        // standalone `expression` (the top-level $._parenthesized_expression
        // choice), never the first term of a longer chain. repeat1-gated so
        // a solo `(a + b)` alone still goes through the plain
        // $._parenthesized_expression choice, not this one.
        seq($._parenthesized_expression, repeat1(seq($.operator, $._chain_term))),
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
        // $.ternary_expression and $._parenthesized_expression are ALSO
        // bare choices here for the same reason as $.subscript_expression:
        // `return a ? b : c;`, `return (a ? b : c);`, and `return (a + b);`
        // all hard-error, since neither is reachable via $._rhs_expression
        // (which deliberately excludes both to avoid ternary-condition
        // ambiguity elsewhere -- see $._ternary_condition's own comment) nor
        // via the chain alternatives above.
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
              $.ternary_expression,
              $._parenthesized_expression,
            ),
          ),
        ),
        seq(
          'untyped',
          choice(
            seq($._rhs_expression, repeat(seq($.operator, $._chain_term))),
            $.subscript_expression,
            $.ternary_expression,
            $._parenthesized_expression,
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

    // Known limitation: a genuinely EMPTY `{}` used as a control-flow body
    // (`if (cond) {}`, `while (cond) {}`, etc.) resolves to an empty
    // $.object (an object-literal expression statement), not $.block.
    // $.block is not even reachable from $.expression's own choice list,
    // so this is really "empty $.object (reached via $.statement's
    // `seq($.expression, ';')` alternative) vs. $.block (a sibling
    // alternative of that same $.statement choice) for identical input" --
    // and this isn't fixable via any of the usual levers: declaring
    // `[$.block, $.object]` in `conflicts` gets flagged as unnecessary
    // (tree-sitter's own analysis says this isn't a real, GLR-forkable
    // ambiguity), `prec`/`prec.dynamic` on either rule (even prec(1000))
    // has zero effect, an explicit `choice($.block, $.statement)` at the
    // body field doesn't change it, and neither does reordering which rule
    // is declared first in this file. This suggests tree-sitter's table
    // construction is merging the two empty-content states before
    // precedence would ever be consulted, which isn't fixable by anything
    // expressible in grammar.js alone.
    // Non-empty bodies (`if (cond) { a(); }`) are entirely unaffected --
    // $.object's content is $.pair-shaped, which can never be confused
    // with $.block's $.statement-shaped content once there's real content
    // to look at.
    block: ($) => seq('{', repeat($.statement), $._closing_brace),

    metadata: ($) =>
      seq(
        choice(token('@'), token('@:')),
        field('name', $._lhs_expression),
        optional(seq('(', $.expression, ')')),
      ),

    // arg list is () with any amount of expressions followed by commas
    _arg_list: ($) => seq('(', commaSep($.expression), ')'),

    // Bodies are $.statement, not $.block -- Haxe's `if (cond) expr;` (no
    // braces) is standard, idiomatic syntax, and was completely broken
    // here (forcing braces on every branch).
    // $.statement already covers both shapes (`{ ... }` via its own
    // $.block alternative, or a bare `expr;` via its
    // `seq($.expression, $._lookback_semicolon)` alternative), so reusing
    // it gets braceless bodies "for free" without a separate rule. Also
    // covers the earlier 'else if' fix (each branch gets its own
    // condition/body via repeat(...), reusing the same 'arguments_list'
    // field name across branches) as a strict subset -- this version adds
    // braceless bodies on top of that.
    conditional_statement: ($) =>
      prec.right(
        1,
        seq(
          field('name', 'if'),
          field('arguments_list', $._arg_list),
          field('body', $.statement),
          repeat(seq('else', 'if', field('arguments_list', $._arg_list), field('body', $.statement))),
          optional(seq('else', field('body', $.statement))),
        ),
      ),

    // https://haxe.org/manual/expression-while.html
    while_statement: ($) =>
      prec.right(
        1,
        seq('while', '(', field('condition', $.expression), ')', field('body', $.statement)),
      ),

    // https://haxe.org/manual/expression-do-while.html
    do_while_statement: ($) =>
      prec.right(
        1,
        seq(
          'do',
          field('body', $.statement),
          'while',
          '(',
          field('condition', $.expression),
          ')',
          $._lookback_semicolon,
        ),
      ),

    // https://haxe.org/manual/expression-for.html -- `binding` is either a
    // plain identifier (`for (v in arr)`) or a key/value pair (`for (k => v
    // in map)`, Haxe 4.0+); reuses $.pair rather than a dedicated rule so
    // the `=>` shape doesn't need re-deriving, even though `v` there is a
    // newly-bound loop variable, not a value expression referencing
    // something else.
    for_statement: ($) =>
      prec.right(
        1,
        seq(
          'for',
          '(',
          field('binding', choice($.identifier, $.pair)),
          'in',
          field('iterable', $.expression),
          ')',
          field('body', $.statement),
        ),
      ),

    // https://haxe.org/manual/expression-try-catch.html -- `type` is
    // optional (wildcard catch, Haxe 4.1+: `catch (e) { ... }`, defaults to
    // haxe.Exception).
    try_statement: ($) =>
      prec.right(1, seq('try', field('body', $.statement), repeat1($.catch_clause))),

    catch_clause: ($) =>
      seq(
        'catch',
        '(',
        field('name', $.identifier),
        optional(seq(':', field('type', $.type))),
        ')',
        field('body', $.statement),
      ),

    // https://haxe.org/manual/lf-array-comprehension.html -- `[for (...) e]`
    // / `[while (...) e]`, combining array declaration with a loop. Kept
    // separate from $.for_statement/$.while_statement (not reused directly)
    // because a comprehension's body is a bare $.expression with no
    // trailing semicolon (`[for (i in 0...10) i]`, not `i;`), whereas the
    // statement forms' body is $.statement specifically to get semicolon
    // handling for the common (non-comprehension) case -- unifying the two
    // would need $.statement and $.expression as competing choices for the
    // same body field, which is the same kind of GLR-fork-doesn't-reliably-
    // recover ambiguity documented on `_chain_term` above. The body can
    // recurse into another comprehension_for/while/if, matching real code
    // like nested `for (a in 1...11) for (b in 2...4) if (a % b == 0) ...`.
    _comprehension_body: ($) =>
      choice($.comprehension_for, $.comprehension_while, $.comprehension_if, $.expression),

    comprehension_for: ($) =>
      prec.right(
        seq(
          'for',
          '(',
          field('binding', choice($.identifier, $.pair)),
          'in',
          field('iterable', $.expression),
          ')',
          field('body', $._comprehension_body),
        ),
      ),

    comprehension_while: ($) =>
      prec.right(
        seq(
          'while',
          '(',
          field('condition', $.expression),
          ')',
          field('body', $._comprehension_body),
        ),
      ),

    // A bodyless-filter `if` inside a comprehension (`if (a % b == 0) ...`)
    // -- no `else`, since a filter either includes or skips an iteration.
    comprehension_if: ($) =>
      prec.right(
        seq('if', '(', field('condition', $.expression), ')', field('body', $._comprehension_body)),
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
