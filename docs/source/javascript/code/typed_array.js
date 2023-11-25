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
