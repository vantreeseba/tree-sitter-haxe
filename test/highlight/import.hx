import Type;
// <- keyword
//     ^ type

import foo.Bar;
// <- keyword
//     ^ module
//         ^ type

import my.other.Type;
// <- keyword
//     ^ module
//        ^ module
//              ^ type

import my.other.Type.Type;
// <- keyword
//     ^ module
//        ^ module
//              ^ type
//                   ^ type

import my.other.Type.field;
// <- keyword
//     ^ module
//        ^ module
//              ^ type
//                   ^ variable
