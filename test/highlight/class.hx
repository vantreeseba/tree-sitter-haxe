class Main {}
// <- keyword
//    ^ type.definition

class Main<T,Y> {}
// <- keyword
//    ^  type.definition
//         ^ type
//           ^ type

class Main<T,Other<T, Y>> {}
// <- keyword
//    ^  type.definition
//         ^ type
//                 ^ type
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
//                    ^ type

class Main implements ITest implements IAnother {}
// <- keyword
//    ^ type.definition
//         ^ keyword
//                    ^ type
//                          ^ keyword
//                                     ^ type

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
