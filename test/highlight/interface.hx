interface TestInterface {}
// <- keyword
//        ^ variable

interface Main<T,Y> {}
// <- keyword
//        ^  variable
//             ^ variable
//               ^ variable

interface TestInterface extends IAnother {}
// <- keyword
//        ^ variable
//                      ^ keyword
//                              ^ variable


