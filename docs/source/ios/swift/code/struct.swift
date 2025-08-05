struct Resolution {
    var width = 0
    var height = 0
}

let r = Resolution()
// r.width = 100 // since r is a constant, we cannot change its members
print(r)

// we can pass initial values
var r2 = Resolution(width: 20, height: 10)
print(r2)

// we can pass initial values
r2 = Resolution(width: 20)
print(r2) // r2.height is default to 0

r2 = Resolution(height: 20)
print(r2) // r2.width is default to 0

