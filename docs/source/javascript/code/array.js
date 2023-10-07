let a = [ 1, 2, 3 ];
let b = a; // a reference
b[0] = 100;
console.log(a[0] === 100); // true

a = [ 1, 2, 3 ];
let c = [];
for (let i = 0; i < a.length; ++i) {
  c[i] = a[i]; // note: no need to pre-allocate space for c
}
console.log(c); // [1, 2, 3]

c[10] = 20;
console.log(c);        // [1, 2, 3, <7 empty items>, 20]
console.log(c[4]);     // undefined
console.log(c[5]);     // undefined
console.log(c.length); // 11, note is is 1 larger than 10

let s = "";
for (let i in c) {
  s += ` ${i}`;
}
// note that indexes with undefined are not printed
console.log(s); // 0 1 2 10

s = "";
for (let i of c) {
  s += ` ${i}`;
}

// there are seven undefined below
console.log(s); // 1 2 3 undefined undefined .... 20

a = [ 1, 2, 3 ]
c = Array.from(a); // return a copy of the array a
c[0] = 100;
console.log(a[0] == 1); // true

function equalArrays(a, b) {
  if (a === b) {
    return true;
  }

  if (a.length != b.length) {
    return false;
  }

  for (let i = 0; i < a.length; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

console.log(equalArrays(a, c));           // false
console.log(equalArrays(a, a));           // true
console.log(equalArrays(a, [ 1, 2, 3 ])); // true
c[0] = 1;
console.log(equalArrays(a, c)); // true

a = [ 1, 2, 3 ];
a.push(4); // use push to append()
a.push(5);
console.log(a);   // [1, 2, 3, 4, 5]
a.push(6, 'ten'); // push two elements
console.log(a);   // [1, 2, 3, 4, 5, 6, 'ten']
