// https://nodejs.org/api/assert.html
const assert = require('node:assert');

// 8 bytes buffer
let buffer = new ArrayBuffer(8);

let a = new Int32Array(buffer);
assert.equal(a.length, 2);     // 2 ints
assert.equal(a.byteLength, 8); // 8 bytes
assert.equal(a.byteOffset, 0);

// a and b share the same buffer
let b = new Int8Array(buffer);

a[0] = 0x12345678;
assert.equal(b[0], 0x78); // little endian
assert.equal(b[1], 0x56); // little endian
assert.equal(b[2], 0x34); // little endian
assert.equal(b[3], 0x12); // little endian

// subarray(start, end) -> No copy
let c = b.subarray(1, 3); // view to the same buffer, no copy
assert.equal(c.length, 2);
assert.equal(c.byteOffset, 1);
b[1] = 0x23;
b[2] = 0x32;
assert.equal(c[0], 0x23);
assert.equal(c[1], 0x32);

// slice(start, end) -> copy
let d = b.slice(1, 3); // copy
assert.equal(d.length, 2);
assert.equal(d[0], 0x23);
assert.equal(d[1], 0x32);
b[0] = 0x11;
b[1] = 0x22;
assert.equal(d[0], 0x23);
assert.equal(d[1], 0x32);

// share the same buffer
let e = new Int8Array(b.buffer);
b[0] = 0x30;
assert.equal(e[0], 0x30);
