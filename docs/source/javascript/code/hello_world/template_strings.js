let a = "a";
let b = "b";
console.log("a is " + a + ", b is " + b); // a is a, b is b

// using string interpolation
console.log(`a is ${a}, b is ${b}`); // a is a, b is b

// Note that it uses `${}`.
// It preserves spaces and line breaks

// multiline examples
let s = `
a is ${a}
b is ${b}
`
console.log(s);
