assert(MemoryLayout<Bool>.size == 1)
assert(MemoryLayout<Bool>.stride == 1)
assert(MemoryLayout<Bool>.alignment == 1)

assert(MemoryLayout<Int>.size == 8)
assert(MemoryLayout<Int>.stride == 8)
assert(MemoryLayout<Int>.alignment == 8)

assert(MemoryLayout<Int32>.size == 4)
assert(MemoryLayout<Int32>.stride == 4)
assert(MemoryLayout<Int32>.alignment == 4)

// Like C/C++
struct Example {
  let foo: Int // 8
  let bar: Bool // 1
}
assert(MemoryLayout<Example>.size == 9)
assert(MemoryLayout<Example>.stride == 16)
assert(MemoryLayout<Example>.alignment == 8)

let ex = Example(foo: 10, bar: true)
assert(MemoryLayout.size(ofValue: ex) == 9)
assert(MemoryLayout.stride(ofValue: ex) == 16)
assert(MemoryLayout.alignment(ofValue: ex) == 8)


struct Example2 {
  let bar: Bool // 1
  let foo: Int // 8
}
assert(MemoryLayout<Example2>.size == 16)
assert(MemoryLayout<Example2>.stride == 16)
assert(MemoryLayout<Example2>.alignment == 8)
