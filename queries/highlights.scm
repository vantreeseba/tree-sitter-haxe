(type) @type
(keyword) @keyword
(literal) @type
(literal (string)) @string
(literal (integer)) @number
(literal (float)) @number
(literal (bool)) @constant
(literal (null)) @keyword
(operator) @operator

(attribute) @tag
; (attribute name: (identifier) @type) @tag

(package_statement name: (identifier) @type)

(class_declaration name: (identifier) @type)

; (variable_declaration name: (identifier) @number)
; (variable_declaration (type) @type)

(function_declaration (identifier) @function)

; (increment_operator) @keyword
; (decrement_operator) @keyword
; (decrement_unop (identifier) (decrement_operator))
; (decrement_unop (identifier) (decrement_operator))
