fn print_type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>());
}

fn test_type_inference() {
    let i: i32 = 10;
    let b = 2_0;
    let c: i32;
    let d;
    c = 11_000_000;
    d = i + b + c;
    print_type_of(&d); // i32
}

fn test_int() {
    let a = 43;
    println!("0x{:x}", a); // 0x2b
    println!("0x{:b}", a); // 0x101011
}

fn test_char() -> char {
    let c = 'c';
    // a char occupies 4 bytes!
    assert_eq!(std::mem::size_of::<char>(), 4);
    return c;
}

fn test_bool() {
    let t = true;
    let f = false;

    // type cast with as
    assert_eq!(t as i32, 1);
    assert_eq!(f as i32, 0);
    assert_eq!(std::mem::size_of::<bool>(), 1)
}

fn test_pointer() {
    let mut i: i32 = 10;
    let p = &mut i as *mut i32;
    unsafe {
        // rustc --explain E0133
        *p = 100;
    }
    assert_eq!(i, 100);
}

fn test_reference() {
    let i = 10;
    let r = &i;
    let b = r + 0; // automatically dereference for arithmetic operations
    let c: i32 = *r;
    assert_eq!(b, 10);
    assert_eq!(c, 10);
}

fn main() {
    test_type_inference();
    test_bool();
    test_char();
    test_int();
    test_pointer();
    test_reference();
}
