// Unsafe[Mutable][Raw][Buffer]Pointer[Type]
//
// Mutable: means you can change the value
// Raw: means it points to a blob of bytes
// Buffer: means it works like a collection
// Type: means generic typed pointers
//
// UnsafePointer<T>
// UnsafeMutablePointer<T>
//
// UnsafeRawPointer
// UnsafeMutableRawPointer
//
// UnsafeRawBufferPointer
// UnsafeMutableRawBufferPointer
//
// UnsafeBufferPointer<T>
// UnsafeMutableBufferPointer<T>

let count = 2
let stride = MemoryLayout<Int>.stride
let alignment = MemoryLayout<Int>.alignment
let byteCount = count * stride

let pointer = UnsafeMutableRawPointer.allocate(byteCount: byteCount, alignment: alignment)

defer {
  pointer.deallocate()
}

pointer.storeBytes(of: 30, as: Int.self)
pointer.advanced(by: stride).storeBytes(of: 3, as: Int.self)
assert(pointer.load(as: Int.self) == 30)
assert(pointer.load(fromByteOffset: stride, as: Int.self) == 3)
assert(pointer.advanced(by: stride).load(as: Int.self) == 3)

let bufferPointer = UnsafeRawBufferPointer(start: pointer, count: byteCount)
for (index, byte) in bufferPointer.enumerated() {
  print("byte \(index) -> \(byte)")
}
/*
byte 0 -> 30
byte 1 -> 0
byte 2 -> 0
byte 3 -> 0
byte 4 -> 0
byte 5 -> 0
byte 6 -> 0
byte 7 -> 0
byte 8 -> 3
byte 9 -> 0
byte 10 -> 0
byte 11 -> 0
byte 12 -> 0
byte 13 -> 0
byte 14 -> 0
byte 15 -> 0
*/
