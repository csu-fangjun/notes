let count = 2
let stride = MemoryLayout<Int>.stride
let pointer = UnsafeMutablePointer<Int>.allocate(capacity: count)
pointer.initialize(repeating: 0, count: count)

defer {
  pointer.deinitialize(count: count)
  pointer.deallocate()
}

pointer.pointee = 42
pointer.advanced(by: 1).pointee = 6

let bufferPointer = UnsafeBufferPointer(start: pointer, count: count)

for (index, value) in bufferPointer.enumerated() {
  print("value \(index) -> \(value)")
}
/*
value 0 -> 42
value 1 -> 6
*/
