[(null) (keyword)] @keyword
[(type) (literal) ] @type
[(integer) (float)] @number
(string) @string
(bool) @constant

(attribute) @tag
(attribute name: (identifier) @type) @tag
(import_statement name: (identifier) @type)
(package_statement name: (identifier) @type)
(class_declaration name: (identifier) @type)

(function_declaration name: (identifier) @function)

; (variable_declaration name: (identifier) @number)
; (variable_declaration (type) @type)
; (increment_operator) @keyword
; (decrement_operator) @keyword
; (decrement_unop (identifier) (decrement_operator))
; (decrement_unop (identifier) (decrement_operator))
