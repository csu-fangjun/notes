let s = "abcdefg";
console.log(s.length);    // 7
console.log(`s is ${s}`); // s is abcdefg

// start 1 (inclusive)
// end 4 (exclusive)
console.log(s.substring(1, 4)); // bcd
console.log(s.slice(1, 4));     // bcd

// last 3 characters
console.log(s.slice(-3)); // efg

// start 3 (inclusive)
// to the end of the string
console.log(s.slice(3)); // defg

// split using delimiter 'd'
console.log(s.split('d')) // ['abc', 'efg']

// split using delimiter 'de'
console.log(s.split('de')) // ['abc', 'fg']

s = "1232526314";
// note: the delimiter is the whole string '23`
console.log(s.split('23')) // ['1', '2526314']

console.log(s.split('2')) // ['1', '3', '5', '6314']

s = "abcdefga";
console.log(s.indexOf('a'));    // 0, only the first occurrence
console.log(s.indexOf('a', 2)); // 7, search starting from the 2nd position
console.log(s.indexOf('c'));    // 2
console.log(s.indexOf('c', 1)); // 2
console.log(s.indexOf('c', 2)); // 2
console.log(s.indexOf('c', 3)); // -1, not found
console.log(s.indexOf('x'));    // -1

console.log(s.lastIndexOf('a')); // 7
console.log(s.indexOf('bc'));    // 1

console.log(s.startsWith('a'));  // true
console.log(s.startsWith('ab')); // true
console.log(s.startsWith('ac')); // false

console.log(s.endsWith('a'));  // true
console.log(s.endsWith('ga')); // true
console.log(s.endsWith('da')); // false

// include a substring
console.log(s.includes('de'));  // true
console.log(s.includes('ded')); // false

// s is not changed. It return a new string
console.log(s.replace('ab', 'AB')); // ABcdefga
console.log(s.toUpperCase());       // ABCDEFGA
console.log(s.toLowerCase());       // abcdefga

console.log(s[0]);        // a
console.log(s[1]);        // b
console.log(s.charAt(0)); // a
console.log(s.charAt(1)); // b

// pad spaces to the left to make the length 3
console.log('a' +
            'x'.padStart(3)) // "a  x"

console.log('a' +
            'x'.padStart(3, '-')) // "a--x"

// pad with '-' to the left to make the total length 5
console.log('a' +
            'xy'.padStart(5, '-')) // "a---xy"

console.log('a' +
            '  b  '.trim() + 'c'); // abc

console.log('a' +
            '  b  '.trimStart() + 'c'); // ab  c

console.log('a' +
            '  b  '.trimEnd() + 'c'); // a  bc

console.log('ab'.repeat(3)); // ababab

console.log(String(123) === "123"); // true, a number to a string

let k = 20
console.log(k.toString() === "20"); // true
console.log("0x" + k.toString(16)); // 0x14, hexadecimal

k = 12.3456;
console.log(k.toFixed(0)); // 12

k = 12.5;
console.log(k.toFixed(0)); // 13, note that it performs rounding

k = 12.3456;
console.log(k.toFixed(1)); // 12.3
console.log(k.toFixed(2)); // 12.35, note that it performs rounding
console.log(k.toFixed(5)); // 12.34560

console.log(k.toExponential(1)); // 1.2e+1
console.log(k.toExponential(2)); // 1.23e+1
console.log(k.toExponential(3)); // 1.235e+1

console.log(k.toPrecision(1)); // 1e+1
console.log(k.toPrecision(2)); // 12
console.log(k.toPrecision(3)); // 12.3
console.log(k.toPrecision(4)); // 12.35
console.log(k.toPrecision(5)); // 12.346
