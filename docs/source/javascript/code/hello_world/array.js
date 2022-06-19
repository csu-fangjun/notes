let a = [ 1, 2, 3 ];
function sum(arr) {
  let s = 0;
  for (let x of arr) {
    s += x;
  }
  return s;
}
// Sum of the array [1,2,3] is 6
console.log('Sum of the array [' + a + '] is ' + sum(a));

function sum2(arr) {
  let s = 0;
  for (let i = 0; i != arr.length; ++i) {
    s += arr[i];
  }
  return s;
}
console.log(sum2(a)); // 6
