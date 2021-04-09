; Types

"package" @keyword
"function" @function.builtin
"class" @keyword
"var" @keyword

(package_statement package_name: (identifier) @type)
(class_declaration class_name: (identifier) @number)
(variable_declaration (identifier) @type)
(function_declaration (identifier) @function)
(access_modifier) @keyword
(identifier) @number
