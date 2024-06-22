// Issue with highlighting conditional ternary operators
class TernaryBug {
	public static function main() {
		var a = 123;
		var b = 123;

		var x:Int = a < b ? 1 : -1;
		var y:Int = a > b ? 1 : -1;
	}
}
