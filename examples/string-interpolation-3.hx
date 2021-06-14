package my.test.package;

@:someMacro
class Main {
	public var foo:Int;

	public static function banana()
	{}
	public static function main() {
    Main.banana();

		var y = 4;
		var x = 'this is a string: $foo this is other $y stuff.';
		var s1 = 'some string $foo and also ${foo}';
		var s2 = 'which can be ${foo + 3}';
		var s3 = 'or even ${foo.main() + 3}';
	}
}
