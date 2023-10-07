/*
null
undefined
0
-0
NaN
""

The above 6 values are automatically converted to false.

All other values are converted to true. Even empty array is converted to true
 */

console.log(true && null);      // null
console.log(true && undefined); // undefined
console.log([] && true);        // true
console.log([] || false);       // []
