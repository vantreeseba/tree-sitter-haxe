#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 33
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 5

enum {
  sym_identifier = 1,
  anon_sym_package = 2,
  anon_sym_DOT = 3,
  anon_sym_SEMI = 4,
  anon_sym_import = 5,
  anon_sym_class = 6,
  anon_sym_function = 7,
  anon_sym_var = 8,
  anon_sym_LPAREN = 9,
  anon_sym_RPAREN = 10,
  anon_sym_LBRACE = 11,
  anon_sym_RBRACE = 12,
  anon_sym_private = 13,
  anon_sym_protected = 14,
  anon_sym_public = 15,
  anon_sym_static = 16,
  anon_sym_inline = 17,
  sym_module = 18,
  sym_package_statement = 19,
  sym_import_statement = 20,
  sym_class_declaration = 21,
  sym__member_declaration = 22,
  sym_function_declaration = 23,
  sym_variable_declaration = 24,
  sym__args = 25,
  sym__block = 26,
  sym_access_modifier = 27,
  sym__expression = 28,
  aux_sym_module_repeat1 = 29,
  aux_sym_package_statement_repeat1 = 30,
  aux_sym__member_declaration_repeat1 = 31,
  aux_sym__args_repeat1 = 32,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_package] = "package",
  [anon_sym_DOT] = ".",
  [anon_sym_SEMI] = ";",
  [anon_sym_import] = "import",
  [anon_sym_class] = "class",
  [anon_sym_function] = "function",
  [anon_sym_var] = "var",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_private] = "private",
  [anon_sym_protected] = "protected",
  [anon_sym_public] = "public",
  [anon_sym_static] = "static",
  [anon_sym_inline] = "inline",
  [sym_module] = "module",
  [sym_package_statement] = "package_statement",
  [sym_import_statement] = "import_statement",
  [sym_class_declaration] = "class_declaration",
  [sym__member_declaration] = "_member_declaration",
  [sym_function_declaration] = "function_declaration",
  [sym_variable_declaration] = "variable_declaration",
  [sym__args] = "_args",
  [sym__block] = "_block",
  [sym_access_modifier] = "access_modifier",
  [sym__expression] = "_expression",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_package_statement_repeat1] = "package_statement_repeat1",
  [aux_sym__member_declaration_repeat1] = "_member_declaration_repeat1",
  [aux_sym__args_repeat1] = "_args_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_import] = anon_sym_import,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_protected] = anon_sym_protected,
  [anon_sym_public] = anon_sym_public,
  [anon_sym_static] = anon_sym_static,
  [anon_sym_inline] = anon_sym_inline,
  [sym_module] = sym_module,
  [sym_package_statement] = sym_package_statement,
  [sym_import_statement] = sym_import_statement,
  [sym_class_declaration] = sym_class_declaration,
  [sym__member_declaration] = sym__member_declaration,
  [sym_function_declaration] = sym_function_declaration,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym__args] = sym__args,
  [sym__block] = sym__block,
  [sym_access_modifier] = sym_access_modifier,
  [sym__expression] = sym__expression,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_package_statement_repeat1] = aux_sym_package_statement_repeat1,
  [aux_sym__member_declaration_repeat1] = aux_sym__member_declaration_repeat1,
  [aux_sym__args_repeat1] = aux_sym__args_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_class] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_var] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_private] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_protected] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_public] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_static] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_inline] = {
    .visible = true,
    .named = false,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_package_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_import_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_class_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__member_declaration] = {
    .visible = false,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__args] = {
    .visible = false,
    .named = true,
  },
  [sym__block] = {
    .visible = false,
    .named = true,
  },
  [sym_access_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_package_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__member_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__args_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_class_name = 1,
  field_function_name = 2,
  field_package_name = 3,
  field_variable_name = 4,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_class_name] = "class_name",
  [field_function_name] = "function_name",
  [field_package_name] = "package_name",
  [field_variable_name] = "variable_name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_package_name, 1},
  [1] =
    {field_class_name, 1},
  [2] =
    {field_variable_name, 1},
  [3] =
    {field_function_name, 1},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(1);
      if (lookahead == '(') ADVANCE(4);
      if (lookahead == ')') ADVANCE(5);
      if (lookahead == '.') ADVANCE(2);
      if (lookahead == ';') ADVANCE(3);
      if (lookahead == '{') ADVANCE(6);
      if (lookahead == '}') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'c') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(2);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'p') ADVANCE(4);
      if (lookahead == 's') ADVANCE(5);
      if (lookahead == 'v') ADVANCE(6);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'l') ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == 'u') ADVANCE(8);
      END_STATE();
    case 3:
      if (lookahead == 'm') ADVANCE(9);
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(11);
      if (lookahead == 'r') ADVANCE(12);
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == 't') ADVANCE(14);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 9:
      if (lookahead == 'p') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(19);
      END_STATE();
    case 11:
      if (lookahead == 'c') ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == 'i') ADVANCE(21);
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 13:
      if (lookahead == 'b') ADVANCE(23);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 16:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(27);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(28);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 20:
      if (lookahead == 'k') ADVANCE(30);
      END_STATE();
    case 21:
      if (lookahead == 'v') ADVANCE(31);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 24:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 26:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 28:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 29:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(39);
      END_STATE();
    case 31:
      if (lookahead == 'a') ADVANCE(40);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(42);
      END_STATE();
    case 34:
      if (lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(47);
      END_STATE();
    case 40:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(49);
      END_STATE();
    case 42:
      if (lookahead == 'c') ADVANCE(50);
      END_STATE();
    case 43:
      if (lookahead == 'c') ADVANCE(51);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_inline);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_public);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_static);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(56);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    case 55:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_protected);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_protected] = ACTIONS(1),
    [anon_sym_public] = ACTIONS(1),
    [anon_sym_static] = ACTIONS(1),
    [anon_sym_inline] = ACTIONS(1),
  },
  [1] = {
    [sym_module] = STATE(36),
    [sym_package_statement] = STATE(15),
    [sym_import_statement] = STATE(17),
    [sym_class_declaration] = STATE(34),
    [aux_sym_module_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_package] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(7),
    [anon_sym_class] = ACTIONS(9),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(11), 1,
      anon_sym_function,
    ACTIONS(14), 1,
      anon_sym_var,
    ACTIONS(17), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(7), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(19), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
    STATE(2), 5,
      sym__member_declaration,
      sym_function_declaration,
      sym_variable_declaration,
      sym__expression,
      aux_sym__args_repeat1,
  [29] = 6,
    ACTIONS(22), 1,
      anon_sym_function,
    ACTIONS(24), 1,
      anon_sym_var,
    ACTIONS(26), 1,
      anon_sym_RBRACE,
    STATE(7), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(28), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
    STATE(6), 5,
      sym__member_declaration,
      sym_function_declaration,
      sym_variable_declaration,
      sym__expression,
      aux_sym__args_repeat1,
  [57] = 6,
    ACTIONS(22), 1,
      anon_sym_function,
    ACTIONS(24), 1,
      anon_sym_var,
    ACTIONS(30), 1,
      anon_sym_RPAREN,
    STATE(7), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(28), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
    STATE(2), 5,
      sym__member_declaration,
      sym_function_declaration,
      sym_variable_declaration,
      sym__expression,
      aux_sym__args_repeat1,
  [85] = 6,
    ACTIONS(22), 1,
      anon_sym_function,
    ACTIONS(24), 1,
      anon_sym_var,
    ACTIONS(32), 1,
      anon_sym_RPAREN,
    STATE(7), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(28), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
    STATE(4), 5,
      sym__member_declaration,
      sym_function_declaration,
      sym_variable_declaration,
      sym__expression,
      aux_sym__args_repeat1,
  [113] = 6,
    ACTIONS(22), 1,
      anon_sym_function,
    ACTIONS(24), 1,
      anon_sym_var,
    ACTIONS(34), 1,
      anon_sym_RBRACE,
    STATE(7), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(28), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
    STATE(2), 5,
      sym__member_declaration,
      sym_function_declaration,
      sym_variable_declaration,
      sym__expression,
      aux_sym__args_repeat1,
  [141] = 5,
    ACTIONS(22), 1,
      anon_sym_function,
    ACTIONS(24), 1,
      anon_sym_var,
    STATE(10), 2,
      sym_function_declaration,
      sym_variable_declaration,
    STATE(13), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(28), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [163] = 1,
    ACTIONS(36), 10,
      ts_builtin_sym_end,
      anon_sym_function,
      anon_sym_var,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [176] = 1,
    ACTIONS(38), 10,
      ts_builtin_sym_end,
      anon_sym_function,
      anon_sym_var,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [189] = 1,
    ACTIONS(40), 9,
      anon_sym_function,
      anon_sym_var,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [201] = 1,
    ACTIONS(42), 9,
      anon_sym_function,
      anon_sym_var,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [213] = 1,
    ACTIONS(44), 9,
      anon_sym_function,
      anon_sym_var,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [225] = 3,
    ACTIONS(46), 2,
      anon_sym_function,
      anon_sym_var,
    STATE(13), 2,
      sym_access_modifier,
      aux_sym__member_declaration_repeat1,
    ACTIONS(48), 5,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [241] = 1,
    ACTIONS(51), 7,
      anon_sym_function,
      anon_sym_var,
      anon_sym_private,
      anon_sym_protected,
      anon_sym_public,
      anon_sym_static,
      anon_sym_inline,
  [251] = 5,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(35), 1,
      sym_class_declaration,
    STATE(16), 2,
      sym_import_statement,
      aux_sym_module_repeat1,
  [268] = 5,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    STATE(42), 1,
      sym_class_declaration,
    STATE(18), 2,
      sym_import_statement,
      aux_sym_module_repeat1,
  [285] = 5,
    ACTIONS(7), 1,
      anon_sym_import,
    ACTIONS(9), 1,
      anon_sym_class,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
    STATE(35), 1,
      sym_class_declaration,
    STATE(18), 2,
      sym_import_statement,
      aux_sym_module_repeat1,
  [302] = 3,
    ACTIONS(59), 1,
      anon_sym_import,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_class,
    STATE(18), 2,
      sym_import_statement,
      aux_sym_module_repeat1,
  [314] = 1,
    ACTIONS(62), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
  [320] = 1,
    ACTIONS(64), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
  [326] = 3,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(68), 1,
      anon_sym_SEMI,
    STATE(28), 1,
      aux_sym_package_statement_repeat1,
  [336] = 3,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(70), 1,
      anon_sym_SEMI,
    STATE(24), 1,
      aux_sym_package_statement_repeat1,
  [346] = 3,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(72), 1,
      anon_sym_SEMI,
    STATE(22), 1,
      aux_sym_package_statement_repeat1,
  [356] = 3,
    ACTIONS(74), 1,
      sym_identifier,
    ACTIONS(77), 1,
      anon_sym_SEMI,
    STATE(24), 1,
      aux_sym_package_statement_repeat1,
  [366] = 2,
    ACTIONS(81), 1,
      anon_sym_DOT,
    ACTIONS(79), 2,
      anon_sym_SEMI,
      sym_identifier,
  [374] = 1,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
  [380] = 1,
    ACTIONS(85), 3,
      ts_builtin_sym_end,
      anon_sym_import,
      anon_sym_class,
  [386] = 3,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(87), 1,
      anon_sym_SEMI,
    STATE(24), 1,
      aux_sym_package_statement_repeat1,
  [396] = 1,
    ACTIONS(77), 2,
      anon_sym_SEMI,
      sym_identifier,
  [401] = 2,
    ACTIONS(89), 1,
      anon_sym_LBRACE,
    STATE(38), 1,
      sym__block,
  [408] = 2,
    ACTIONS(91), 1,
      anon_sym_LPAREN,
    STATE(32), 1,
      sym__args,
  [415] = 2,
    ACTIONS(89), 1,
      anon_sym_LBRACE,
    STATE(11), 1,
      sym__block,
  [422] = 1,
    ACTIONS(93), 1,
      sym_identifier,
  [426] = 1,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
  [430] = 1,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
  [434] = 1,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
  [438] = 1,
    ACTIONS(97), 1,
      sym_identifier,
  [442] = 1,
    ACTIONS(99), 1,
      ts_builtin_sym_end,
  [446] = 1,
    ACTIONS(101), 1,
      anon_sym_SEMI,
  [450] = 1,
    ACTIONS(103), 1,
      anon_sym_LBRACE,
  [454] = 1,
    ACTIONS(105), 1,
      sym_identifier,
  [458] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
  [462] = 1,
    ACTIONS(109), 1,
      anon_sym_LBRACE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 29,
  [SMALL_STATE(4)] = 57,
  [SMALL_STATE(5)] = 85,
  [SMALL_STATE(6)] = 113,
  [SMALL_STATE(7)] = 141,
  [SMALL_STATE(8)] = 163,
  [SMALL_STATE(9)] = 176,
  [SMALL_STATE(10)] = 189,
  [SMALL_STATE(11)] = 201,
  [SMALL_STATE(12)] = 213,
  [SMALL_STATE(13)] = 225,
  [SMALL_STATE(14)] = 241,
  [SMALL_STATE(15)] = 251,
  [SMALL_STATE(16)] = 268,
  [SMALL_STATE(17)] = 285,
  [SMALL_STATE(18)] = 302,
  [SMALL_STATE(19)] = 314,
  [SMALL_STATE(20)] = 320,
  [SMALL_STATE(21)] = 326,
  [SMALL_STATE(22)] = 336,
  [SMALL_STATE(23)] = 346,
  [SMALL_STATE(24)] = 356,
  [SMALL_STATE(25)] = 366,
  [SMALL_STATE(26)] = 374,
  [SMALL_STATE(27)] = 380,
  [SMALL_STATE(28)] = 386,
  [SMALL_STATE(29)] = 396,
  [SMALL_STATE(30)] = 401,
  [SMALL_STATE(31)] = 408,
  [SMALL_STATE(32)] = 415,
  [SMALL_STATE(33)] = 422,
  [SMALL_STATE(34)] = 426,
  [SMALL_STATE(35)] = 430,
  [SMALL_STATE(36)] = 434,
  [SMALL_STATE(37)] = 438,
  [SMALL_STATE(38)] = 442,
  [SMALL_STATE(39)] = 446,
  [SMALL_STATE(40)] = 450,
  [SMALL_STATE(41)] = 454,
  [SMALL_STATE(42)] = 458,
  [SMALL_STATE(43)] = 462,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [11] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__args_repeat1, 2), SHIFT_REPEAT(41),
  [14] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__args_repeat1, 2), SHIFT_REPEAT(33),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__args_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__args_repeat1, 2), SHIFT_REPEAT(14),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 3),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__member_declaration, 2),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 4),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 3, .production_id = 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__member_declaration_repeat1, 2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__member_declaration_repeat1, 2), SHIFT_REPEAT(14),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_access_modifier, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(23),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_statement, 3, .production_id = 1),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_package_statement_repeat1, 2), SHIFT_REPEAT(25),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_statement_repeat1, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_package_statement_repeat1, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_statement, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [95] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_declaration, 3, .production_id = 2),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 2),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 3),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__args, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_haxe(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
