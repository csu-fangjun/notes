// all numbers are of 64-bit floating point type

let a = 32;   // decimal integer
let b = 0x20; // hexadecimal integer
let c = 0X20;
console.log(a, b, c); // 32 32 32

let d = 0b00010000; // binary integer
let e = 0o20;
console.log(d, e); // 16 16

console.log(a / 5); // 6.4. Note that it is not an integer!

d = 0b1000_0000; // use _ to separate digit for readability
console.log(d);  // 128

console.log(2 ** 3); // 8, ** means power

// Note that we don't need to import Math
//
// Round to the nearest integer
console.log(Math.round(0.6)); // 1
console.log(Math.round(0.5)); // 1
console.log(Math.round(0.2)); // 0

console.log(Math.trunc(3.9)); // 3

// Round to the nearest integer
console.log(Math.round(-0.6)); // -1

console.log(Math.ceil(-0.6)); // -0
console.log(Math.ceil(0.6));  // 1
console.log(Math.random());   // uniform distribution in the range 0 <= x < 1.0

console.log(Math.PI); // 3.141592653589793
console.log(Math.E);  // 2.718281828459045

// max accepts arbirtrary number of arguments
console.log(Math.max(2, 3));          // 3
console.log(Math.max(2, 3, 10));      // 10
console.log(Math.max(2, 3, 10, 100)); // 100

console.log(Math.pow(2, 5)); // 32

// note that sin() is not in degrees
console.log(Math.sin(30));          // -0.988
console.log(Math.sin(Math.PI / 6)); // 0.4999999

// natural log. base in 2.718
console.log(Math.log(Math.E)); // 1

console.log(Math.log(100) / Math.LN10); // 2
console.log(Math.log10(100));           // 2
console.log(Math.log2(1024));           // 10

// log1p(x) == log(1 + x)
console.log(Math.log1p(3), Math.log(1 + 3)); // 1.38629, 1.38629

console.log(Math.exp(2)); // e^2, 7.38905609893065

// division by 0 is not an error!
console.log(1 / 0);               // Infinity
console.log(-1 / 0);              // -Infinity
console.log(0 / 0);               // NaN
console.log(Infinity / Infinity); // NaN
console.log(Number.isNaN(NaN));   // true

// a string to a number
console.log(Number("123") === 123); // true

console.log(parseInt("20") === 20); // true

// parseInt supports hexadecimal!
// It does not support octal or binary.
console.log(parseInt("0x20") === 32); // true

console.log(parseInt("20", 16) === 32); // true

// octal
console.log(parseInt("20", 8) === 16); // true
