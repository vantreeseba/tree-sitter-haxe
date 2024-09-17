interface TestInterface {}
// <- keyword
//        ^ type.definition

interface Main<T,Y> {}
// <- keyword
//        ^  type.definition
//             ^ type
//               ^ type

interface TestInterface extends IAnother {}
// <- keyword
//        ^ type.definition
//                      ^ keyword
//                              ^ type


