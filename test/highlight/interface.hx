interface TestInterface {}
// <- keyword
//        ^ type.definition

interface Main<T,Y> {}
// <- keyword
//        ^  type.definition
//             ^ variable
//               ^ type

interface TestInterface extends IAnother {}
// <- keyword
//        ^ type.definition
//                      ^ keyword
//                              ^ type.definition


