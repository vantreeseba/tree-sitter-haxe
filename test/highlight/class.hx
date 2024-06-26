class Main {}
// <- keyword
//    ^ type.definition

class Main<T,Y> {}
// <- keyword
//    ^  type.definition
//         ^ variable
//           ^ type

class Main<T,Other<T, Y>> {}
// <- keyword
//    ^  type.definition
//         ^ variable
//                 ^ variable
//                    ^ type

final class Main {}
// <- keyword
//    ^ keyword
//          ^ type.definition

abstract class Main {}
// <- keyword
//       ^ keyword
//             ^ type.definition


class Main implements ITest {}
// <- keyword
//    ^ type.definition
//         ^ keyword
//                    ^ type.definition

class Main implements ITest implements IAnother {}
// <- keyword
//    ^ type.definition
//         ^ keyword
//                    ^ type.definition
//                          ^ keyword
//                                     ^ type.definition

class foo extends Main {}

typedef foo = Array<Int>;

class Bar {
	function fn():Void {}
}

interface Foo {
	function fn(arg:Int):Void;
}

interface Foo {
	function fn(arg:Array<Int>):Void;
}
