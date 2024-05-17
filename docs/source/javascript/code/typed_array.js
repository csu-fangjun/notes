// https://nodejs.org/api/assert.html
const assert = require('node:assert');

assert.equal(Int8Array.BYTES_PER_ELEMENT, 1);
assert.equal(Uint8Array.BYTES_PER_ELEMENT, 1);

assert.equal(Int16Array.BYTES_PER_ELEMENT, 2);
assert.equal(Uint16Array.BYTES_PER_ELEMENT, 2);

assert.equal(Int32Array.BYTES_PER_ELEMENT, 4);
assert.equal(Uint32Array.BYTES_PER_ELEMENT, 4);

assert.equal(Float32Array.BYTES_PER_ELEMENT, 4);
assert.equal(Float64Array.BYTES_PER_ELEMENT, 8);

function test_uint32_array() {
  let a = new Uint32Array(2);
  assert.equal(a.length, 2);
  assert.equal(a[1], 0);
  a[0] = 0x12345678
  assert.equal(a[0], 0x12345678);

  // type of buf: ArrayBuffer
  let buf = a.buffer;
  assert.equal(buf.byteLength, a.length * Uint32Array.BYTES_PER_ELEMENT);
  let b = new Uint8Array(buf)
  assert.equal(b[0], 0x78); // little endian
  b[1] = 0x23;              // also changes a
  assert.equal(a[0], 0x12342378);
}

function test_int32_array() {
  let a = new Int32Array(2);
  // all typed arrays are 0 initialized
  assert.equal(a[0], 0);
  assert.equal(a[1], 0);

  let b = new Int32Array(a); // copy
  b[0] = 10;
  assert.equal(a[0], 0);

  let c = Int32Array.from(a);
  c[0] = 1;
  assert.equal(a[0], 0);

  let d = Int32Array.of(1, 2, 3);
  assert.equal(d.length, 3);
  assert.equal(d[0], 1);
  assert.equal(d[1], 2);
  assert.equal(d[2], 3);

  let e = new Int32Array(a.buffer); // share the underlying buffer
  e[0] = 11;
  assert.equal(a[0], 11);

  // the from method always copys
  let f = Int32Array.from(a.buffer); // copy!
  f[0] = 0;
  assert.equal(a[0], 11); // a is not changed

  let i = [ 5, 1 ];
  let g = Int32Array.from(i); // from() always copy
  assert.equal(g.length, 2);
  assert.equal(g[0], 5);
  i[0] = 10; // g is not changed
  assert.equal(g[0], 5);
}

function test_int32_array2() {
  let a = new Int32Array(10);
  let b = [ 1, 2, 3 ];
  a.set(b); // copy b to a, start from offset 0
  assert.equal(a[0], b[0]);
  assert.equal(a[1], b[1]);
  assert.equal(a[2], b[2]);

  a.set(b, 2); // copy b to a, start from offset 2
  assert.equal(a[2], b[0]);
  assert.equal(a[3], b[1]);
  assert.equal(a[4], b[2]);

  let c = Int32Array.of(100, 200);
  a.set(c); // copy c to a, at offset 0
  assert.equal(a[0], c[0]);
  assert.equal(a[1], c[1]);

  a = Int32Array.of(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  b = a.slice(1, 3); // copy. start index 1 (included), stop index 3 (excluded)
  assert.equal(b.length, 2);
  assert.equal(b[0], a[1]);
  assert.equal(b[1], a[2]);
  b[0] = 100;
  assert.equal(a[1], 1); // a is not changed

  // share memory. start index 1 (included), stop index 3 (excluded)
  c = a.subarray(1, 3);
  assert.equal(c.length, 2);
  assert.equal(c[0], a[1]);
  assert.equal(c[1], a[2]);
  c[0] = 100;
  assert.equal(a[1], 100);

  // slice() copies data!
  let d = a.slice(1, 3);
  assert.equal(d.length, 2);
  assert.equal(d[0], a[1]);
  assert.equal(d[1], a[2]);
  d[0] = 1000;
  assert.equal(a[1], 100); // a is not changed
}

test_uint32_array();
test_int32_array();
test_int32_array2();
