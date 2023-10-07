/*
/^HTML/   Matches the letters HTML at the start of a string

/^HTML/i   Matches the letters HTML (ignore cases) at the start of a string

*/

// /[0-9][0-9]*/   Match a non-zero digit, followed by any \# of digits
//
// /\bjavascript\b/i  Match "javascript" as a word, case-insensitive

console.log(/^HTML/.test("HTML ABC"));  // true
console.log(/^HTML/.test("Html ABC"));  // false
console.log(/^HTML/i.test("Html ABC")); // true, ignore cases

console.log(/[0-9][0-9]*/.test("0"));     // true
console.log(/[0-9][0-9]*/.test("01234")); // true

console.log(/\bjavascript\b/i.test("hello javascript")); // true
console.log(/\bjavascript\b/i.test("hello_javascript")); // false

let text = "testing: 1, 2, 3"
let pattern = /\d+/g // matches all instances of one or more digits

console.log(pattern.test(text)); // true, a match exists

// return the first matched position
console.log(text.search(pattern)); // 9
console.log(text.match(pattern));  // ['1', '2', '3'], array of all matches
console.log(text.replace(pattern, '#')); // testing: #, #, #

console.log(text.split(/\D+/)) // split on non-digit, ['', '1', '2', '3']
