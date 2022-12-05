; locals.scm

; (method) @local.scope
; (do_block) @local.scope
;
; (method_parameters (identifier) @local.definition)
; (block_parameters (identifier) @local.definition)
;
; (assignment left:(identifier) @local.definition)

(function_arg name: (identifier) @local.definition)
(identifier) @local.reference
