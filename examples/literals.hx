//int literal.

class main {
  var x = 12;
}

//int hex literal.
class main {
  var x = 0xFF42;
}

//float literal.

class main {
  var x = 4.2;
}

// float literal with no trailing number.

class main {
  var x = 4.;
}

// float literal e notation.

class main {
  var x = 4.3e5;
}

// float literal e notation error (this is not working).
class main {
  var x = 4.3e5e;
}

// string literal single quote
class main {
  var x = 'hello';
}

// string literal double quote
class main {
  var x = "hello";
}

// string literal single quote interpolated identifier
class main {
  var y = 1;
  var x = 'hello $y';
}

// string literal single quote interpolated identifier in braces
class main {
  var y = 1;
  var x = 'hello ${y}';
}

// string literal single quote interpolated expression in braces
class main {
  var y = 1;
  var x = 'hello ${y + 1}';
}
