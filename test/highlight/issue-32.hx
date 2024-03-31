var ch = "b";
var foo = 3;

class TSBug {
	public static function main() {
		var ch = "b".code;
		switch (ch) {
			case "b".code:
				trace("bug");
			case "s".code:
				trace("bug");
			case "x".code:
				trace("bug");
		}
	}
}
