// https://nodejs.org/api/assert.html
const assert = require('node:assert');

// From an array
let a = [ 1, 2, 3 ];
let b = new Int8Array(a); // copy a into b
b[0] = 10
assert.equal(a[0], 1);
assert.equal(b[0], 10);
assert(b.length, 3);

// From a length. 0 initialized
c = new Int8Array(2);
assert.equal(c.length, 2);
for (let i of c) {
  assert.equal(i, 0);
}

assert.equal(c.BYTES_PER_ELEMENT, 1);
