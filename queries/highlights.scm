(identifier) @type ;@local.reference
(comment) @comment

; Preprocessor Statement
; --------
(preprocessor_statement) @tag
; (metadata name: (identifier) @type) @tag

; MetaData
; --------
(metadata) @tag
(metadata name: (identifier) @type) @tag

; Generic/Type Params
; --------------
(type_params
  "<" @punctuation.bracket
  ">" @punctuation.bracket)


; Declarations
; ------------
(import_statement name: (identifier) @type)
(package_statement name: (identifier) @type)
(class_declaration name: (identifier) @type.definition)
(class_declaration (type_params (type_param (identifier) @type)))
(typedef_declaration name: (identifier) @type.definition)

(function_declaration name: (identifier) @function)
(function_arg name: (identifier) @variable.parameter @local.definition)

; Expressions
; -----------
(call_expression name: (identifier) @variable.parameter)
; TODO: Figure out how to determined when "nested member call" is last ident.
(call_expression object: (identifier) @function)
(call_expression object: (_ (identifier) @function .))
(call_expression object: (_(_ (identifier) @function .)))
(call_expression object: (_(_(_ (identifier) @function .))))



; Literals
; --------
[(null) (keyword)] @keyword
[(type) (literal)] @type
(type built_in: (identifier)) @type.builtin
[(integer) (float)] @number
(string) @string
(bool) @constant
(operator) @operator

; Interpolation
; -------------
(interpolation "$" @punctuation.special)
(interpolation
  "${" @punctuation.special
  "}" @punctuation.special
) @embedded


; Tokens
; ------

(":") @punctuation.special

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
]  @punctuation.bracket
;
[
;   ";"
;   "?."
;   "."
  ","
] @punctuation.delimiter

; (variable_declaration name: (identifier) @number)
; (variable_declaration (type) @type)
; (increment_operator) @operator
; (decrement_operator) @operator
; (decrement_unop (identifier) (decrement_operator))
; (decrement_unop (identifier) (decrement_operator))
