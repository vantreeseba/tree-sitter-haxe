class Main {}
// <- keyword
//    ^ variable

class Main<T,Y> {}
// <- keyword
//    ^  variable
//         ^ variable
//           ^ variable

final class Main {}
// <- keyword
//    ^ keyword
//          ^ variable

abstract class Main {}
// <- keyword
//       ^ keyword
//             ^ variable


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

typedef foo = Array<Int>;

class Bar {
	function fn():Void {}
}

interface Foo {
	function fn(arg:Int):Void {};
}

interface Foo {
	function fn(arg:Array<Int>):Void {};
}
