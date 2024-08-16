(identifier) @variable
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
  (type_param (identifier) @type)
  ">" @punctuation.bracket
)

; Declarations
; ------------

(class_declaration name: (identifier) @type.definition)
(class_declaration super_class_name: (identifier) @type.definition)
(class_declaration interface_name: (identifier) @type.definition)
(interface_declaration name: (identifier) @type.definition)
(interface_declaration interface_name: (identifier) @type.definition)
(typedef_declaration name: (identifier) @type.definition)

(function_declaration name: (identifier) @function)
(function_arg name: (identifier) @variable.parameter)

; Expressions
; -----------
; (call_expression name: (identifier) @variable.parameter)

; TODO: Figure out how to determined when "nested member call" is last ident.
; apparently this is a known issue https://github.com/tree-sitter/tree-sitter/issues/880
(call_expression object: [
  (_) @function
  (_ (identifier) @function .)
;   (_(_ (identifier) @function .))
;   (_(_(_ (identifier) @function .)))
;   (_(_(_(_ (identifier) @function .))))
;   (_(_(_(_(_ (identifier) @function .)))))
])

; Literals
; --------
[(keyword) (null)] @keyword
; (type) @type
(type_name) @type
(package_name) @module
(type (identifier) !built_in) @type
(type built_in: (identifier)) @type.builtin
[(integer) (float)] @number
(string) @string
(bool) @constant
(operator) @operator
(escape_sequence) @punctuation


; Tokens
; ------

(":") @punctuation.special
(pair [":" "=>"] @punctuation.special)

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


; Interpolation
; -------------
(interpolation "$" @punctuation.special)
(interpolation
  "${" @punctuation.special
  "}" @punctuation.special
) @embedded

