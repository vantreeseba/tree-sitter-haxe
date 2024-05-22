public function bar() {}
// ^keyword
//       ^ keyword
//              ^ function

banana();
// <- function

banana.bar(foo);
// <- variable
//     ^ function

banana.foo.bar();
// <- variable
//     ^ variable
//     		 ^ function

banana.foo.baz.bar();
// <- variable
//     ^ variable
//     	   ^ variable
//     		     ^ function

banana.foo.bar(apple);

public function foo(bar) {
	bar = 3;
}
