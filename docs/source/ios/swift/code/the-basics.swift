// swiftc -suppress-warnings ./the-basics.swift

if true {
    let maximumNumberOfLoginAttempts = 10 // a constant
    var currentLoginAttemp = 0 // a variable
}

if true {
    var environment = "development"
    let maximumNumberOfLoginAttempts: Int

    if environment == "development" {
        maximumNumberOfLoginAttempts = 100
    } else {
        maximumNumberOfLoginAttempts = 10
    }

    // We don't need to initialze the const variable on declaration.
    // Before accessing it , we need to initialize it

    precondition(maximumNumberOfLoginAttempts == 100)
}

if true {
    // declare multiple variables in the same line
    var x = 0.0, y = 0.0, z = 0.0

    var welcomeMessage: String

    var red, green, blue: Int
}

if true {
    print() // output a new line
    print(1, 2, 3) // output: 1 2 3
    print(1, 2, 3, separator: "-") // output: 1-2-3
}

if true {
    let minValue = UInt8.min
    let maxValue = UInt8.max
    precondition(minValue == 0)
    precondition(maxValue == 255)

    let a: Int16 = 100
    let b: Int = Int(a) // need explicit conversion
}

if true {
    // type alias
    typealias AudioSample = Int16
    var a: AudioSample = 10
    var b: Int16 = a
}

if true {
    // boolean
    var a = true
    var b = false
}

if true {
    // tuples
    var a = (1, "ok")
    precondition(a.0 == 1)
    precondition(a.1 == "ok")
    a.0 = 10 // since a is defined using var, not let, we can change its elements

    let (i, s) = a
    precondition(i == 10)
    precondition(s == "ok")
    print(a) // (1, "ok")

    let (k, _) = a // ignore the second entry
    precondition(k == 10)

    let (_, s1) = a // ignore the first entry
    precondition(s1 == "ok")

    let b = (index: 11, msg: "hello") // name the elements
    precondition(b.0 == 11)
    precondition(b.index == 11)

    precondition(b.1 == "hello")
    precondition(b.msg == "hello")
}

if true {
    // note that i is of type Int?
    let i = Int("hello")
    precondition(i == nil)

    // write it explicitly
    let b: Int? = Int("hello")

    let c: Int = Int("10")! // unwrap with !

}

if true {
    let a = Int("1");
    let b = Int("2");
    let c = Int("10");

    if let a {
        print("a \(a) is an integer")
    }

    // we can also use var which means we can change a inside if
    if var a {
        a += 1
        print("a is an integer \(a)")
    }

    // true if and only if all conditions hold
    if let a, let b, let c, c > 2 {
        print("here")
    }
}
