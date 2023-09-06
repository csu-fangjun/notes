// use const to define a constant
const pizza = true;
console.log(pizza); // true

var foo = 'foo';
if (foo) {
  var foo = 'fooz'
  console.log('foo is', foo); // foo is fooz
}

// note it outputs foo is fooz below since
// we use `var` inside the `if` statement
console.log('foo is', foo); // foo is fooz

var bar = 'bar';

if (bar) {
  let bar = 'barz'
  console.log('bar is', bar); // foo is barz
}

// note it outputs bar is bar below since
// we use `let` inside the `if` statement
console.log('bar is', bar); // foo is bar

// we should use let as much as possible
// variables defined by `let` is scoped inside a block {}

array = [];
for (var i = 0; i < 3; i++) {

  array.push(function() { console.log(i); });
}
array[0](); // 3
array[1](); // 3
array[2](); // 3
// since we are using var in the for loop, the closures capture the same i

array2 = [];
for (let k = 0; k < 3; k++) {

  array2.push(function() { console.log(k); });
}
array2[0](); // 0
array2[1](); // 1
array2[2](); // 2
