const o = {
  "hello" : "world"
};
console.log(o.hello);               // world
console.log(o["hello"]);            // world
console.log('hello' in o);          // true
console.log(!('hello' in o));       // false
console.log(o.foo);                 // undefined
console.log(o.foo || 'bar');        // bar
console.log(undefined || 'foobar'); // foobar
