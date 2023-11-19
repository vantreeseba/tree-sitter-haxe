// Simple lambda function type
var a:Int->Int;

// They can have optional named parameters (notice the parenthesis)
var b:((arg:Int) -> Int);

// With multiple parameters
var c:((Int, Int) -> Float);

// Named or not
var d:((Int, b:Bool) -> Float);

// Nested function types
var e:((fn:(Int->Bool), Float, sub:((Bool, Bool) -> Int))->Bool);

// Without any arguments
var f:() -> Void;

// Same as function declarations with optional arguments
var g:(?a:Int, ?b:Float) -> Int;

// With generic arguments
var h:(a:Null<Int>) -> Array<Float>;
