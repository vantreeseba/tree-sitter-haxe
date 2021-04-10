(type) @type

"import" @keyword
(import_statement path: (identifier) @type)

"package" @keyword
(package_statement path: (identifier) @type)

"class" @keyword
(class_declaration name: (identifier) @type)

"var" @keyword
(variable_declaration name: (identifier) @number)

"function" @keyword
(function_declaration (identifier) @function)
(access_modifier) @keyword


; (increment_operator) @keyword
; (decrement_operator) @keyword
; (decrement_unop (identifier) (decrement_operator))
; (decrement_unop (identifier) (decrement_operator))
