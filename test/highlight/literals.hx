var x = 4;
// <- keyword
//      ^ number

var x = 4.45;
// <- keyword
//      ^ number

var x = 'hello';
// <- keyword
//      ^ string

var x = 'hello $x';
// <- keyword
//      ^ string
//             ^ punctuation.special
//              ^ type

var x = 'hello ${x}';
// <- keyword
//      ^ string
//             ^ punctuation.special
//               ^ type
//                ^ punctuation.special


var x = null;
// <- keyword
//      ^ keyword
