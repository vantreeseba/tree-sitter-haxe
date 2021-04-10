#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 77
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 60
#define ALIAS_COUNT 0
#define TOKEN_COUNT 32
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 11
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 18

enum {
  sym_identifier = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_package = 4,
  anon_sym_import = 5,
  sym_comment = 6,
  anon_sym_Int = 7,
  anon_sym_Float = 8,
  anon_sym_Bool = 9,
  anon_sym_Void = 10,
  anon_sym_public = 11,
  anon_sym_protected = 12,
  anon_sym_private = 13,
  anon_sym_static = 14,
  anon_sym_inline = 15,
  anon_sym_PLUS_PLUS = 16,
  anon_sym_DASH_DASH = 17,
  anon_sym_BANG = 18,
  anon_sym_DASH = 19,
  anon_sym_TILDE = 20,
  anon_sym_class = 21,
  anon_sym_LPAREN = 22,
  anon_sym_RPAREN = 23,
  anon_sym_function = 24,
  anon_sym_var = 25,
  anon_sym_COLON = 26,
  anon_sym_LBRACK = 27,
  anon_sym_RBRACK = 28,
  anon_sym_DOT = 29,
  anon_sym_QMARK_DOT = 30,
  sym__semicolon = 31,
  sym_module = 32,
  sym_expression_statement = 33,
  sym_statement_block = 34,
  sym_package_statement = 35,
  sym_import_statement = 36,
  sym_type = 37,
  sym__basic_type = 38,
  sym_access_modifier = 39,
  sym_unary_expression = 40,
  sym_increment_unop = 41,
  sym_decrement_unop = 42,
  sym_not_unop = 43,
  sym_negative_unop = 44,
  sym_bitwise_negative_unop = 45,
  sym_declaration = 46,
  sym_class_body = 47,
  sym_class_declaration = 48,
  sym__call_signature = 49,
  sym_function_declaration = 50,
  sym_variable_declaration = 51,
  sym_expression = 52,
  sym_primary_expression = 53,
  sym_subscript_expression = 54,
  sym_member_expression = 55,
  aux_sym_module_repeat1 = 56,
  aux_sym_class_body_repeat1 = 57,
  aux_sym__call_signature_repeat1 = 58,
  aux_sym_function_declaration_repeat1 = 59,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_package] = "package",
  [anon_sym_import] = "import",
  [sym_comment] = "comment",
  [anon_sym_Int] = "identifier",
  [anon_sym_Float] = "identifier",
  [anon_sym_Bool] = "identifier",
  [anon_sym_Void] = "identifier",
  [anon_sym_public] = "public",
  [anon_sym_protected] = "protected",
  [anon_sym_private] = "private",
  [anon_sym_static] = "static",
  [anon_sym_inline] = "inline",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH] = "-",
  [anon_sym_TILDE] = "~",
  [anon_sym_class] = "class",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_function] = "function",
  [anon_sym_var] = "var",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DOT] = ".",
  [anon_sym_QMARK_DOT] = "\?.",
  [sym__semicolon] = "_semicolon",
  [sym_module] = "module",
  [sym_expression_statement] = "expression_statement",
  [sym_statement_block] = "statement_block",
  [sym_package_statement] = "package_statement",
  [sym_import_statement] = "import_statement",
  [sym_type] = "type",
  [sym__basic_type] = "_basic_type",
  [sym_access_modifier] = "access_modifier",
  [sym_unary_expression] = "unary_expression",
  [sym_increment_unop] = "increment_unop",
  [sym_decrement_unop] = "decrement_unop",
  [sym_not_unop] = "not_unop",
  [sym_negative_unop] = "negative_unop",
  [sym_bitwise_negative_unop] = "bitwise_negative_unop",
  [sym_declaration] = "declaration",
  [sym_class_body] = "class_body",
  [sym_class_declaration] = "class_declaration",
  [sym__call_signature] = "_call_signature",
  [sym_function_declaration] = "function_declaration",
  [sym_variable_declaration] = "variable_declaration",
  [sym_expression] = "expression",
  [sym_primary_expression] = "primary_expression",
  [sym_subscript_expression] = "subscript_expression",
  [sym_member_expression] = "member_expression",
  [aux_sym_module_repeat1] = "module_repeat1",
  [aux_sym_class_body_repeat1] = "class_body_repeat1",
  [aux_sym__call_signature_repeat1] = "_call_signature_repeat1",
  [aux_sym_function_declaration_repeat1] = "function_declaration_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_import] = anon_sym_import,
  [sym_comment] = sym_comment,
  [anon_sym_Int] = sym_identifier,
  [anon_sym_Float] = sym_identifier,
  [anon_sym_Bool] = sym_identifier,
  [anon_sym_Void] = sym_identifier,
  [anon_sym_public] = anon_sym_public,
  [anon_sym_protected] = anon_sym_protected,
  [anon_sym_private] = anon_sym_private,
  [anon_sym_static] = anon_sym_static,
  [anon_sym_inline] = anon_sym_inline,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_class] = anon_sym_class,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_function] = anon_sym_function,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_QMARK_DOT] = anon_sym_QMARK_DOT,
  [sym__semicolon] = sym__semicolon,
  [sym_module] = sym_module,
  [sym_expression_statement] = sym_expression_statement,
  [sym_statement_block] = sym_statement_block,
  [sym_package_statement] = sym_package_statement,
  [sym_import_statement] = sym_import_statement,
  [sym_type] = sym_type,
  [sym__basic_type] = sym__basic_type,
  [sym_access_modifier] = sym_access_modifier,
  [sym_unary_expression] = sym_unary_expression,
  [sym_increment_unop] = sym_increment_unop,
  [sym_decrement_unop] = sym_decrement_unop,
  [sym_not_unop] = sym_not_unop,
  [sym_negative_unop] = sym_negative_unop,
  [sym_bitwise_negative_unop] = sym_bitwise_negative_unop,
  [sym_declaration] = sym_declaration,
  [sym_class_body] = sym_class_body,
  [sym_class_declaration] = sym_class_declaration,
  [sym__call_signature] = sym__call_signature,
  [sym_function_declaration] = sym_function_declaration,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym_expression] = sym_expression,
  [sym_primary_expression] = sym_primary_expression,
  [sym_subscript_expression] = sym_subscript_expression,
  [sym_member_expression] = sym_member_expression,
  [aux_sym_module_repeat1] = aux_sym_module_repeat1,
  [aux_sym_class_body_repeat1] = aux_sym_class_body_repeat1,
  [aux_sym__call_signature_repeat1] = aux_sym__call_signature_repeat1,
  [aux_sym_function_declaration_repeat1] = aux_sym_function_declaration_repeat1,
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
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Int] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Float] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Bool] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_Void] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_public] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_protected] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_private] = {
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
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_class] = {
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
  [anon_sym_function] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_var] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym__semicolon] = {
    .visible = false,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_statement_block] = {
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
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__basic_type] = {
    .visible = false,
    .named = true,
  },
  [sym_access_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_increment_unop] = {
    .visible = true,
    .named = true,
  },
  [sym_decrement_unop] = {
    .visible = true,
    .named = true,
  },
  [sym_not_unop] = {
    .visible = true,
    .named = true,
  },
  [sym_negative_unop] = {
    .visible = true,
    .named = true,
  },
  [sym_bitwise_negative_unop] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_class_body] = {
    .visible = true,
    .named = true,
  },
  [sym_class_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym__call_signature] = {
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
  [sym_expression] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_primary_expression] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_subscript_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_member_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_module_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_class_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__call_signature_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_index = 2,
  field_member = 3,
  field_name = 4,
  field_object = 5,
  field_operand = 6,
  field_operator = 7,
  field_parameters = 8,
  field_path = 9,
  field_property = 10,
  field_type = 11,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_index] = "index",
  [field_member] = "member",
  [field_name] = "name",
  [field_object] = "object",
  [field_operand] = "operand",
  [field_operator] = "operator",
  [field_parameters] = "parameters",
  [field_path] = "path",
  [field_property] = "property",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 1},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 1},
  [6] = {.index = 8, .length = 2},
  [7] = {.index = 10, .length = 1},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 3},
  [10] = {.index = 16, .length = 2},
  [11] = {.index = 18, .length = 1},
  [12] = {.index = 19, .length = 1},
  [13] = {.index = 20, .length = 2},
  [14] = {.index = 22, .length = 3},
  [15] = {.index = 25, .length = 3},
  [16] = {.index = 28, .length = 3},
  [17] = {.index = 31, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_operand, 1},
    {field_operator, 0},
  [2] =
    {field_operand, 0},
    {field_operator, 1},
  [4] =
    {field_path, 1},
  [5] =
    {field_body, 2},
    {field_name, 1},
  [7] =
    {field_name, 1},
  [8] =
    {field_object, 0},
    {field_property, 2},
  [10] =
    {field_member, 0},
  [11] =
    {field_parameters, 0},
    {field_parameters, 1},
  [13] =
    {field_body, 3},
    {field_name, 1},
    {field_parameters, 2, .inherited = true},
  [16] =
    {field_index, 2},
    {field_object, 0},
  [18] =
    {field_name, 2},
  [19] =
    {field_member, 1, .inherited = true},
  [20] =
    {field_member, 0, .inherited = true},
    {field_member, 1, .inherited = true},
  [22] =
    {field_parameters, 0},
    {field_parameters, 1},
    {field_parameters, 2},
  [25] =
    {field_name, 1},
    {field_type, 2},
    {field_type, 3},
  [28] =
    {field_body, 4},
    {field_name, 2},
    {field_parameters, 3, .inherited = true},
  [31] =
    {field_name, 2},
    {field_type, 3},
    {field_type, 4},
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
      if (eof) ADVANCE(10);
      if (lookahead == '!') ADVANCE(17);
      if (lookahead == '(') ADVANCE(20);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == '+') ADVANCE(5);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == ':') ADVANCE(22);
      if (lookahead == ';') ADVANCE(30);
      if (lookahead == '?') ADVANCE(7);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == ']') ADVANCE(26);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '{') ADVANCE(11);
      if (lookahead == '}') ADVANCE(12);
      if (lookahead == '~') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(3);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '*') ADVANCE(2);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '+') ADVANCE(5);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == ';') ADVANCE(30);
      if (lookahead == '?') ADVANCE(7);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead == ']') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(4)
      END_STATE();
    case 5:
      if (lookahead == '+') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == '-') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(29);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '!') ADVANCE(17);
      if (lookahead == ')') ADVANCE(21);
      if (lookahead == '+') ADVANCE(5);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '{') ADVANCE(11);
      if (lookahead == '}') ADVANCE(12);
      if (lookahead == '~') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(9)
      if (('.' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(16);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(24);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_QMARK_DOT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__semicolon);
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
      if (lookahead == 'B') ADVANCE(1);
      if (lookahead == 'F') ADVANCE(2);
      if (lookahead == 'I') ADVANCE(3);
      if (lookahead == 'V') ADVANCE(4);
      if (lookahead == 'c') ADVANCE(5);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'i') ADVANCE(7);
      if (lookahead == 'p') ADVANCE(8);
      if (lookahead == 's') ADVANCE(9);
      if (lookahead == 'v') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 8203 ||
          lookahead == 8288 ||
          lookahead == 65279) SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 3:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == 'u') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == 'm') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(19);
      if (lookahead == 'r') ADVANCE(20);
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 9:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(23);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 12:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 13:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 14:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(28);
      END_STATE();
    case 16:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 17:
      if (lookahead == 'p') ADVANCE(30);
      END_STATE();
    case 18:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(32);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(35);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 23:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(38);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(39);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_Int);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(40);
      END_STATE();
    case 28:
      if (lookahead == 's') ADVANCE(41);
      END_STATE();
    case 29:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(43);
      END_STATE();
    case 31:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 32:
      if (lookahead == 'k') ADVANCE(45);
      END_STATE();
    case 33:
      if (lookahead == 'v') ADVANCE(46);
      END_STATE();
    case 34:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(48);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_Bool);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_Void);
      END_STATE();
    case 41:
      if (lookahead == 's') ADVANCE(51);
      END_STATE();
    case 42:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 46:
      if (lookahead == 'a') ADVANCE(56);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(59);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_Float);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_class);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(61);
      END_STATE();
    case 54:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 55:
      if (lookahead == 'g') ADVANCE(63);
      END_STATE();
    case 56:
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 57:
      if (lookahead == 'c') ADVANCE(65);
      END_STATE();
    case 58:
      if (lookahead == 'c') ADVANCE(66);
      END_STATE();
    case 59:
      if (lookahead == 'c') ADVANCE(67);
      END_STATE();
    case 60:
      if (lookahead == 'o') ADVANCE(68);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_inline);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_public);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_static);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_private);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_function);
      END_STATE();
    case 73:
      if (lookahead == 'd') ADVANCE(74);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_protected);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 9},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 9},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 9},
  [13] = {.lex_state = 9},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 9},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 9},
  [23] = {.lex_state = 9},
  [24] = {.lex_state = 9},
  [25] = {.lex_state = 9},
  [26] = {.lex_state = 9},
  [27] = {.lex_state = 9},
  [28] = {.lex_state = 9},
  [29] = {.lex_state = 9},
  [30] = {.lex_state = 9},
  [31] = {.lex_state = 9},
  [32] = {.lex_state = 9},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 9},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 4},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 9},
  [44] = {.lex_state = 4},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 4},
  [47] = {.lex_state = 9},
  [48] = {.lex_state = 4},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 4},
  [51] = {.lex_state = 9},
  [52] = {.lex_state = 9},
  [53] = {.lex_state = 9},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 9},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 9},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 9},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 9},
  [74] = {.lex_state = 9},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 9},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_import] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_Int] = ACTIONS(1),
    [anon_sym_Float] = ACTIONS(1),
    [anon_sym_Bool] = ACTIONS(1),
    [anon_sym_Void] = ACTIONS(1),
    [anon_sym_public] = ACTIONS(1),
    [anon_sym_protected] = ACTIONS(1),
    [anon_sym_private] = ACTIONS(1),
    [anon_sym_static] = ACTIONS(1),
    [anon_sym_inline] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_class] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_function] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_QMARK_DOT] = ACTIONS(1),
    [sym__semicolon] = ACTIONS(1),
  },
  [1] = {
    [sym_module] = STATE(62),
    [sym_expression_statement] = STATE(5),
    [sym_statement_block] = STATE(5),
    [sym_package_statement] = STATE(5),
    [sym_import_statement] = STATE(5),
    [sym_access_modifier] = STATE(32),
    [sym_unary_expression] = STATE(35),
    [sym_increment_unop] = STATE(45),
    [sym_decrement_unop] = STATE(45),
    [sym_not_unop] = STATE(45),
    [sym_negative_unop] = STATE(45),
    [sym_bitwise_negative_unop] = STATE(45),
    [sym_declaration] = STATE(5),
    [sym_class_declaration] = STATE(18),
    [sym_function_declaration] = STATE(18),
    [sym_variable_declaration] = STATE(18),
    [sym_expression] = STATE(50),
    [sym_primary_expression] = STATE(34),
    [sym_subscript_expression] = STATE(41),
    [sym_member_expression] = STATE(41),
    [aux_sym_module_repeat1] = STATE(5),
    [aux_sym_function_declaration_repeat1] = STATE(32),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
    [anon_sym_package] = ACTIONS(11),
    [anon_sym_import] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [anon_sym_public] = ACTIONS(15),
    [anon_sym_protected] = ACTIONS(15),
    [anon_sym_private] = ACTIONS(15),
    [anon_sym_static] = ACTIONS(15),
    [anon_sym_inline] = ACTIONS(15),
    [anon_sym_PLUS_PLUS] = ACTIONS(17),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
    [anon_sym_DASH] = ACTIONS(23),
    [anon_sym_TILDE] = ACTIONS(25),
    [anon_sym_class] = ACTIONS(27),
    [anon_sym_function] = ACTIONS(29),
    [anon_sym_var] = ACTIONS(31),
  },
  [2] = {
    [sym_expression_statement] = STATE(2),
    [sym_statement_block] = STATE(2),
    [sym_package_statement] = STATE(2),
    [sym_import_statement] = STATE(2),
    [sym_access_modifier] = STATE(32),
    [sym_unary_expression] = STATE(35),
    [sym_increment_unop] = STATE(45),
    [sym_decrement_unop] = STATE(45),
    [sym_not_unop] = STATE(45),
    [sym_negative_unop] = STATE(45),
    [sym_bitwise_negative_unop] = STATE(45),
    [sym_declaration] = STATE(2),
    [sym_class_declaration] = STATE(18),
    [sym_function_declaration] = STATE(18),
    [sym_variable_declaration] = STATE(18),
    [sym_expression] = STATE(50),
    [sym_primary_expression] = STATE(34),
    [sym_subscript_expression] = STATE(41),
    [sym_member_expression] = STATE(41),
    [aux_sym_module_repeat1] = STATE(2),
    [aux_sym_function_declaration_repeat1] = STATE(32),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_identifier] = ACTIONS(35),
    [anon_sym_LBRACE] = ACTIONS(38),
    [anon_sym_RBRACE] = ACTIONS(33),
    [anon_sym_package] = ACTIONS(41),
    [anon_sym_import] = ACTIONS(44),
    [sym_comment] = ACTIONS(3),
    [anon_sym_public] = ACTIONS(47),
    [anon_sym_protected] = ACTIONS(47),
    [anon_sym_private] = ACTIONS(47),
    [anon_sym_static] = ACTIONS(47),
    [anon_sym_inline] = ACTIONS(47),
    [anon_sym_PLUS_PLUS] = ACTIONS(50),
    [anon_sym_DASH_DASH] = ACTIONS(53),
    [anon_sym_BANG] = ACTIONS(56),
    [anon_sym_DASH] = ACTIONS(59),
    [anon_sym_TILDE] = ACTIONS(62),
    [anon_sym_class] = ACTIONS(65),
    [anon_sym_function] = ACTIONS(68),
    [anon_sym_var] = ACTIONS(71),
  },
  [3] = {
    [sym_expression_statement] = STATE(4),
    [sym_statement_block] = STATE(4),
    [sym_package_statement] = STATE(4),
    [sym_import_statement] = STATE(4),
    [sym_access_modifier] = STATE(32),
    [sym_unary_expression] = STATE(35),
    [sym_increment_unop] = STATE(45),
    [sym_decrement_unop] = STATE(45),
    [sym_not_unop] = STATE(45),
    [sym_negative_unop] = STATE(45),
    [sym_bitwise_negative_unop] = STATE(45),
    [sym_declaration] = STATE(4),
    [sym_class_declaration] = STATE(18),
    [sym_function_declaration] = STATE(18),
    [sym_variable_declaration] = STATE(18),
    [sym_expression] = STATE(50),
    [sym_primary_expression] = STATE(34),
    [sym_subscript_expression] = STATE(41),
    [sym_member_expression] = STATE(41),
    [aux_sym_module_repeat1] = STATE(4),
    [aux_sym_function_declaration_repeat1] = STATE(32),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
    [anon_sym_RBRACE] = ACTIONS(74),
    [anon_sym_package] = ACTIONS(11),
    [anon_sym_import] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [anon_sym_public] = ACTIONS(15),
    [anon_sym_protected] = ACTIONS(15),
    [anon_sym_private] = ACTIONS(15),
    [anon_sym_static] = ACTIONS(15),
    [anon_sym_inline] = ACTIONS(15),
    [anon_sym_PLUS_PLUS] = ACTIONS(17),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
    [anon_sym_DASH] = ACTIONS(23),
    [anon_sym_TILDE] = ACTIONS(25),
    [anon_sym_class] = ACTIONS(27),
    [anon_sym_function] = ACTIONS(29),
    [anon_sym_var] = ACTIONS(31),
  },
  [4] = {
    [sym_expression_statement] = STATE(2),
    [sym_statement_block] = STATE(2),
    [sym_package_statement] = STATE(2),
    [sym_import_statement] = STATE(2),
    [sym_access_modifier] = STATE(32),
    [sym_unary_expression] = STATE(35),
    [sym_increment_unop] = STATE(45),
    [sym_decrement_unop] = STATE(45),
    [sym_not_unop] = STATE(45),
    [sym_negative_unop] = STATE(45),
    [sym_bitwise_negative_unop] = STATE(45),
    [sym_declaration] = STATE(2),
    [sym_class_declaration] = STATE(18),
    [sym_function_declaration] = STATE(18),
    [sym_variable_declaration] = STATE(18),
    [sym_expression] = STATE(50),
    [sym_primary_expression] = STATE(34),
    [sym_subscript_expression] = STATE(41),
    [sym_member_expression] = STATE(41),
    [aux_sym_module_repeat1] = STATE(2),
    [aux_sym_function_declaration_repeat1] = STATE(32),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
    [anon_sym_RBRACE] = ACTIONS(76),
    [anon_sym_package] = ACTIONS(11),
    [anon_sym_import] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [anon_sym_public] = ACTIONS(15),
    [anon_sym_protected] = ACTIONS(15),
    [anon_sym_private] = ACTIONS(15),
    [anon_sym_static] = ACTIONS(15),
    [anon_sym_inline] = ACTIONS(15),
    [anon_sym_PLUS_PLUS] = ACTIONS(17),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
    [anon_sym_DASH] = ACTIONS(23),
    [anon_sym_TILDE] = ACTIONS(25),
    [anon_sym_class] = ACTIONS(27),
    [anon_sym_function] = ACTIONS(29),
    [anon_sym_var] = ACTIONS(31),
  },
  [5] = {
    [sym_expression_statement] = STATE(2),
    [sym_statement_block] = STATE(2),
    [sym_package_statement] = STATE(2),
    [sym_import_statement] = STATE(2),
    [sym_access_modifier] = STATE(32),
    [sym_unary_expression] = STATE(35),
    [sym_increment_unop] = STATE(45),
    [sym_decrement_unop] = STATE(45),
    [sym_not_unop] = STATE(45),
    [sym_negative_unop] = STATE(45),
    [sym_bitwise_negative_unop] = STATE(45),
    [sym_declaration] = STATE(2),
    [sym_class_declaration] = STATE(18),
    [sym_function_declaration] = STATE(18),
    [sym_variable_declaration] = STATE(18),
    [sym_expression] = STATE(50),
    [sym_primary_expression] = STATE(34),
    [sym_subscript_expression] = STATE(41),
    [sym_member_expression] = STATE(41),
    [aux_sym_module_repeat1] = STATE(2),
    [aux_sym_function_declaration_repeat1] = STATE(32),
    [ts_builtin_sym_end] = ACTIONS(78),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
    [anon_sym_package] = ACTIONS(11),
    [anon_sym_import] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [anon_sym_public] = ACTIONS(15),
    [anon_sym_protected] = ACTIONS(15),
    [anon_sym_private] = ACTIONS(15),
    [anon_sym_static] = ACTIONS(15),
    [anon_sym_inline] = ACTIONS(15),
    [anon_sym_PLUS_PLUS] = ACTIONS(17),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
    [anon_sym_DASH] = ACTIONS(23),
    [anon_sym_TILDE] = ACTIONS(25),
    [anon_sym_class] = ACTIONS(27),
    [anon_sym_function] = ACTIONS(29),
    [anon_sym_var] = ACTIONS(31),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(80), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(82), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [27] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(84), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(86), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [54] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(88), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(90), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [81] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(92), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(94), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [108] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(96), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(98), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [135] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(100), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(102), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [162] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(104), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(106), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [189] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(108), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(110), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [216] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(112), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(114), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [243] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(116), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(118), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [270] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(120), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(122), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [297] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(124), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(126), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [324] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(128), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(130), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [351] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(132), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(134), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [378] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(136), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_BANG,
      anon_sym_TILDE,
    ACTIONS(138), 12,
      anon_sym_package,
      anon_sym_import,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_DASH,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
      sym_identifier,
  [405] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(33), 1,
      sym_expression,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [447] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(142), 1,
      anon_sym_RBRACE,
    ACTIONS(146), 1,
      anon_sym_class,
    ACTIONS(148), 1,
      anon_sym_function,
    ACTIONS(150), 1,
      anon_sym_var,
    STATE(24), 1,
      aux_sym_class_body_repeat1,
    STATE(30), 1,
      sym_declaration,
    STATE(32), 2,
      sym_access_modifier,
      aux_sym_function_declaration_repeat1,
    STATE(18), 3,
      sym_class_declaration,
      sym_function_declaration,
      sym_variable_declaration,
    ACTIONS(144), 5,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
  [485] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(44), 1,
      sym_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [527] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(146), 1,
      anon_sym_class,
    ACTIONS(148), 1,
      anon_sym_function,
    ACTIONS(150), 1,
      anon_sym_var,
    ACTIONS(152), 1,
      anon_sym_RBRACE,
    STATE(25), 1,
      aux_sym_class_body_repeat1,
    STATE(30), 1,
      sym_declaration,
    STATE(32), 2,
      sym_access_modifier,
      aux_sym_function_declaration_repeat1,
    STATE(18), 3,
      sym_class_declaration,
      sym_function_declaration,
      sym_variable_declaration,
    ACTIONS(144), 5,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
  [565] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(154), 1,
      anon_sym_RBRACE,
    ACTIONS(159), 1,
      anon_sym_class,
    ACTIONS(162), 1,
      anon_sym_function,
    ACTIONS(165), 1,
      anon_sym_var,
    STATE(25), 1,
      aux_sym_class_body_repeat1,
    STATE(30), 1,
      sym_declaration,
    STATE(32), 2,
      sym_access_modifier,
      aux_sym_function_declaration_repeat1,
    STATE(18), 3,
      sym_class_declaration,
      sym_function_declaration,
      sym_variable_declaration,
    ACTIONS(156), 5,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
  [603] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(48), 1,
      sym_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [645] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(46), 1,
      sym_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [687] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(42), 1,
      sym_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [729] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(19), 1,
      anon_sym_DASH_DASH,
    ACTIONS(21), 1,
      anon_sym_BANG,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_TILDE,
    ACTIONS(140), 1,
      sym_identifier,
    STATE(34), 1,
      sym_primary_expression,
    STATE(35), 1,
      sym_unary_expression,
    STATE(49), 1,
      sym_expression,
    STATE(41), 2,
      sym_subscript_expression,
      sym_member_expression,
    STATE(45), 5,
      sym_increment_unop,
      sym_decrement_unop,
      sym_not_unop,
      sym_negative_unop,
      sym_bitwise_negative_unop,
  [771] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(168), 9,
      anon_sym_RBRACE,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_class,
      anon_sym_function,
      anon_sym_var,
  [786] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(173), 2,
      anon_sym_function,
      anon_sym_var,
    STATE(31), 2,
      sym_access_modifier,
      aux_sym_function_declaration_repeat1,
    ACTIONS(170), 5,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
  [805] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(175), 1,
      anon_sym_function,
    ACTIONS(177), 1,
      anon_sym_var,
    STATE(31), 2,
      sym_access_modifier,
      aux_sym_function_declaration_repeat1,
    ACTIONS(144), 5,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
  [826] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [839] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
    ACTIONS(181), 4,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_RBRACK,
      sym__semicolon,
  [856] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(181), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [869] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(187), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [882] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(189), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [895] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [908] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(193), 7,
      anon_sym_public,
      anon_sym_protected,
      anon_sym_private,
      anon_sym_static,
      anon_sym_inline,
      anon_sym_function,
      anon_sym_var,
  [921] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [934] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(197), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [947] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
    ACTIONS(199), 4,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_RBRACK,
      sym__semicolon,
  [964] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(63), 1,
      sym__basic_type,
    STATE(75), 1,
      sym_type,
    ACTIONS(201), 5,
      anon_sym_Int,
      anon_sym_Float,
      anon_sym_Bool,
      anon_sym_Void,
      sym_identifier,
  [981] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [994] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(205), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
      sym__semicolon,
  [1007] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
    ACTIONS(207), 4,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_RBRACK,
      sym__semicolon,
  [1024] = 4,
    ACTIONS(3), 1,
      sym_comment,
    STATE(63), 1,
      sym__basic_type,
    STATE(64), 1,
      sym_type,
    ACTIONS(201), 5,
      anon_sym_Int,
      anon_sym_Float,
      anon_sym_Bool,
      anon_sym_Void,
      sym_identifier,
  [1041] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
    ACTIONS(209), 4,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_RBRACK,
      sym__semicolon,
  [1058] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(211), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(213), 1,
      anon_sym_DASH_DASH,
    ACTIONS(215), 1,
      anon_sym_RBRACK,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
  [1078] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 1,
      anon_sym_LBRACK,
    ACTIONS(211), 1,
      anon_sym_PLUS_PLUS,
    ACTIONS(213), 1,
      anon_sym_DASH_DASH,
    ACTIONS(217), 1,
      sym__semicolon,
    ACTIONS(185), 2,
      anon_sym_DOT,
      anon_sym_QMARK_DOT,
  [1098] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      sym_identifier,
    ACTIONS(221), 1,
      anon_sym_RPAREN,
    STATE(53), 1,
      aux_sym__call_signature_repeat1,
  [1111] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      sym_identifier,
    ACTIONS(226), 1,
      anon_sym_RPAREN,
    STATE(52), 1,
      aux_sym__call_signature_repeat1,
  [1124] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(228), 1,
      sym_identifier,
    ACTIONS(230), 1,
      anon_sym_RPAREN,
    STATE(52), 1,
      aux_sym__call_signature_repeat1,
  [1137] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(6), 1,
      sym_statement_block,
  [1147] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(232), 1,
      anon_sym_LBRACE,
    STATE(20), 1,
      sym_class_body,
  [1157] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(8), 1,
      sym_statement_block,
  [1167] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_LPAREN,
    STATE(56), 1,
      sym__call_signature,
  [1177] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(236), 1,
      anon_sym_COLON,
    ACTIONS(238), 1,
      sym__semicolon,
  [1187] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(240), 1,
      anon_sym_COLON,
    ACTIONS(242), 1,
      sym__semicolon,
  [1197] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(234), 1,
      anon_sym_LPAREN,
    STATE(54), 1,
      sym__call_signature,
  [1207] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(244), 1,
      sym_identifier,
  [1214] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(246), 1,
      ts_builtin_sym_end,
  [1221] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(248), 1,
      sym__semicolon,
  [1228] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(250), 1,
      sym__semicolon,
  [1235] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(252), 1,
      anon_sym_LBRACE,
  [1242] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      sym_identifier,
  [1249] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(256), 1,
      sym__semicolon,
  [1256] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(258), 1,
      sym__semicolon,
  [1263] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(260), 1,
      sym_identifier,
  [1270] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(262), 1,
      sym_identifier,
  [1277] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(264), 1,
      anon_sym_LBRACE,
  [1284] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(266), 1,
      sym_identifier,
  [1291] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(268), 1,
      sym_identifier,
  [1298] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 1,
      sym_identifier,
  [1305] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(272), 1,
      sym__semicolon,
  [1312] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(274), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 27,
  [SMALL_STATE(8)] = 54,
  [SMALL_STATE(9)] = 81,
  [SMALL_STATE(10)] = 108,
  [SMALL_STATE(11)] = 135,
  [SMALL_STATE(12)] = 162,
  [SMALL_STATE(13)] = 189,
  [SMALL_STATE(14)] = 216,
  [SMALL_STATE(15)] = 243,
  [SMALL_STATE(16)] = 270,
  [SMALL_STATE(17)] = 297,
  [SMALL_STATE(18)] = 324,
  [SMALL_STATE(19)] = 351,
  [SMALL_STATE(20)] = 378,
  [SMALL_STATE(21)] = 405,
  [SMALL_STATE(22)] = 447,
  [SMALL_STATE(23)] = 485,
  [SMALL_STATE(24)] = 527,
  [SMALL_STATE(25)] = 565,
  [SMALL_STATE(26)] = 603,
  [SMALL_STATE(27)] = 645,
  [SMALL_STATE(28)] = 687,
  [SMALL_STATE(29)] = 729,
  [SMALL_STATE(30)] = 771,
  [SMALL_STATE(31)] = 786,
  [SMALL_STATE(32)] = 805,
  [SMALL_STATE(33)] = 826,
  [SMALL_STATE(34)] = 839,
  [SMALL_STATE(35)] = 856,
  [SMALL_STATE(36)] = 869,
  [SMALL_STATE(37)] = 882,
  [SMALL_STATE(38)] = 895,
  [SMALL_STATE(39)] = 908,
  [SMALL_STATE(40)] = 921,
  [SMALL_STATE(41)] = 934,
  [SMALL_STATE(42)] = 947,
  [SMALL_STATE(43)] = 964,
  [SMALL_STATE(44)] = 981,
  [SMALL_STATE(45)] = 994,
  [SMALL_STATE(46)] = 1007,
  [SMALL_STATE(47)] = 1024,
  [SMALL_STATE(48)] = 1041,
  [SMALL_STATE(49)] = 1058,
  [SMALL_STATE(50)] = 1078,
  [SMALL_STATE(51)] = 1098,
  [SMALL_STATE(52)] = 1111,
  [SMALL_STATE(53)] = 1124,
  [SMALL_STATE(54)] = 1137,
  [SMALL_STATE(55)] = 1147,
  [SMALL_STATE(56)] = 1157,
  [SMALL_STATE(57)] = 1167,
  [SMALL_STATE(58)] = 1177,
  [SMALL_STATE(59)] = 1187,
  [SMALL_STATE(60)] = 1197,
  [SMALL_STATE(61)] = 1207,
  [SMALL_STATE(62)] = 1214,
  [SMALL_STATE(63)] = 1221,
  [SMALL_STATE(64)] = 1228,
  [SMALL_STATE(65)] = 1235,
  [SMALL_STATE(66)] = 1242,
  [SMALL_STATE(67)] = 1249,
  [SMALL_STATE(68)] = 1256,
  [SMALL_STATE(69)] = 1263,
  [SMALL_STATE(70)] = 1270,
  [SMALL_STATE(71)] = 1277,
  [SMALL_STATE(72)] = 1284,
  [SMALL_STATE(73)] = 1291,
  [SMALL_STATE(74)] = 1298,
  [SMALL_STATE(75)] = 1305,
  [SMALL_STATE(76)] = 1312,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(41),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(3),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(74),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(76),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(39),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(21),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(23),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(28),
  [59] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(27),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(26),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(73),
  [68] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(70),
  [71] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_module_repeat1, 2), SHIFT_REPEAT(69),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 9),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 4, .production_id = 9),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_body, 2),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_body, 2),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 5, .production_id = 16),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_declaration, 5, .production_id = 16),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_block, 3),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement_block, 3),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_package_statement, 3, .production_id = 3),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_package_statement, 3, .production_id = 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_statement, 3, .production_id = 3),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_import_statement, 3, .production_id = 3),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_body, 3, .production_id = 12),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_body, 3, .production_id = 12),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, .production_id = 11),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, .production_id = 11),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 2),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 5, .production_id = 15),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 5, .production_id = 15),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 6, .production_id = 17),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 6, .production_id = 17),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_block, 2),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement_block, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 1),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 3, .production_id = 5),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 3, .production_id = 5),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_class_declaration, 3, .production_id = 4),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_class_declaration, 3, .production_id = 4),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 2, .production_id = 13),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 2, .production_id = 13), SHIFT_REPEAT(39),
  [159] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 2, .production_id = 13), SHIFT_REPEAT(73),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 2, .production_id = 13), SHIFT_REPEAT(70),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 2, .production_id = 13), SHIFT_REPEAT(69),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_class_body_repeat1, 1, .production_id = 7),
  [170] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_declaration_repeat1, 2), SHIFT_REPEAT(39),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_declaration_repeat1, 2),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_increment_unop, 2, .production_id = 1),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subscript_expression, 4, .production_id = 10),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_increment_unop, 2, .production_id = 2),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decrement_unop, 2, .production_id = 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_access_modifier, 1),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_member_expression, 3, .production_id = 6),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_primary_expression, 1),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_not_unop, 2),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decrement_unop, 2, .production_id = 1),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 1),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_negative_unop, 2),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bitwise_negative_unop, 2),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [223] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__call_signature_repeat1, 2), SHIFT_REPEAT(52),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__call_signature_repeat1, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [246] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__call_signature, 2, .production_id = 8),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__call_signature, 3, .production_id = 14),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
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
