const First = require("../lib/binding.js");
const assert = require("assert");

assert(First, "The expected function is undefined");

function testBasic() {
  const result = First.First("hello");
  assert.strictEqual(result, "world2", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log(First.First("hello"));
console.log(First.add(2, 3));
First.runCallback(function(msg) { console.log("Msg is", msg); });
First.runCallback((msg) => { console.log("Msg2 is", msg); });

console.log("Tests passed- everything looks OK!");
