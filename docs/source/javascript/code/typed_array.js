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
test_uint32_array()
