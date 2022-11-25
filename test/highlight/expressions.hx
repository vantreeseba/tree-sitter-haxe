//conditional

if (true) {
// <- keyword
// ^ @punctuation.bracket
//  ^ constant  
//      ^ @punctuation.bracket
//        ^ @punctuation.bracket
  a = 1;
//^ type
//    ^ number
}
// <- @punctuation.bracket

// parenthesis

a = (1+1);
// <- type 
//  ^ @punctuation.bracket
//   ^ number  
//     ^ number 
//      ^ @punctuation.bracket

// unsafe cast
cast x;
// <- keyword 
//   ^ type 

// safe cast
cast (x, Int);
// <- keyword 
//    ^ type
//       ^ @type.builtin

// runtime type check
(x : Int);

// preprocessor macro
#if !condition
trace(x);
#elseif (condition > 2)
trace(y);
#else
trace(z);
#end
