class banana {
	// <- keyword
	//    ^ type
	public function bar(?bar:Int) {}
	// ^keyword
	//       ^ keyword
	//                ^ type
}
banana();
// <- type
banana.bar(foo);
// <- type
//     ^ type
banana.foo.bar();
banana.foo.bar(apple);
