import somePackage;
// <- keyword
//     ^ type
// (module (import_statement (identifier)))
import my.other.package;
// (module (import_statement (identifier) (identifier) (identifier)))
import my.other.package;
import banana;
import test.other.SomeClass;

// (module
// (import_statement (identifier) (identifier) (identifier))
// (import_statement (identifier))
// (import_statement (identifier) (identifier) (identifier))
// )
