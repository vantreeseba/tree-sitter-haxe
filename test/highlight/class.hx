class Main {}
// <- keyword
//    ^ variable 

class Main<T,Y> {}
// <- keyword
//    ^  variable
//         ^ variable
//           ^ variable

class Main implements ITest {}
// <- keyword
//    ^ variable 
//         ^ keyword 
//                    ^ variable 

class Main implements ITest implements IAnother {}
// <- keyword
//    ^ variable 
//         ^ keyword 
//                    ^ variable 
//                          ^ keyword 
//                                     ^ variable 
