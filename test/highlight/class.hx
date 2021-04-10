class Main {}
// <- keyword
// // (module (class_declaration (identifier)))
//
// class Main {
//   function foo() {}
// }
//
// // (module
// //   (class_declaration (identifier)
// //     (function_declaration (identifier))
// //   )
// // )
//
// class Main {
//   public inline static function foo() {}
// }
//
// // (module
// //   (class_declaration (identifier)
// //     (access_modifier)
// //     (access_modifier)
// //     (access_modifier)
// //     (function_declaration (identifier))
// //   )
// // )
//
// class Main {
//   public var x;
// }
//
// // (module
// //   (class_declaration (identifier)
// //     (access_modifier)
// //     (variable_declaration (identifier))
// //   )
// // )
//
// class Main {
//   public var x:Int;
// }
//
// // (module
// //   (class_declaration (identifier)
// //     (access_modifier)
// //     (variable_declaration (identifier) (identifier))
// //   )
// // )
