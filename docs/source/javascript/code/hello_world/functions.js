// note that is supports default arguments
function hello(msg = "hi") { console.log(msg); }
// the above is a function declaration, it is hoisted to the top
// in other words, we can invoke it before seeing it.

hello();        // hi
hello('world'); // world

// this is a function expression.
const hi = function(msg = 'hi') { console.log(msg); };
hi();        // hi
hi('world'); // world

const add = function(a, b = 1) { return a + b; };
console.log(add(1, 2)); // 3
console.log(add(1));    // 2

// arrow functions
// there is no keyword `function` and no `return`.
const inc = (a, b = 1) => a + b;
console.log(inc(1, 2)); // 3
console.log(inc(1));    // 2

const dec = a => a - 1;
console.log(dec(10)); // 9

// for multiline statement, use {}
const sub = a => {
  let b = a - 1;
  return b;
};
console.log(sub(100)); // 99
