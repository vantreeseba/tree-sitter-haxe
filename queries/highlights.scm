(identifier) @type

(comment) @comment
[(null) (keyword)] @keyword
[(type) (literal) ] @type
[(integer) (float)] @number
(string) @string
(bool) @constant
(interpolation "$" @punctuation.special)
(interpolation
  "${" @punctuation.special
  "}" @punctuation.special
) @injection.content

(attribute) @tag
(attribute name: (identifier) @type) @tag
(import_statement name: (identifier) @type)
(package_statement name: (identifier) @type)
(class_declaration name: (identifier) @type)
(class_declaration (type_param (identifier)) @type)

(function_declaration name: (identifier) @function)

; (variable_declaration name: (identifier) @number)
; (variable_declaration (type) @type)
; (increment_operator) @operator
; (decrement_operator) @operator
; (decrement_unop (identifier) (decrement_operator))
; (decrement_unop (identifier) (decrement_operator))
