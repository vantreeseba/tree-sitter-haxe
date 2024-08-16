package;
// <- keyword
// (module (package_statement))

package my;
// <- keyword
//      ^ module
// (module (package_statement (package_name)))

package my.other.package;
// <- keyword
//      ^ module
//         ^ module
//               ^ module
// (module (package_statement (package_name)(package_name)(package_name)))
