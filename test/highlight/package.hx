package;
// <- keyword
// (module (package_statement))

package my;
// <- keyword
//      ^ type
// (module (package_statement (identifier)))

package my.other.package;
// <- keyword
//      ^ variable
//         ^ variable
//               ^ variable
// (module (package_statement (identifier)(identifier)(identifier)))
