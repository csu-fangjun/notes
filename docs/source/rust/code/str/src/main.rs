use std::ffi::{CStr, CString};

fn test_1() {
    let _a: &[u8] = b"hi";

    let b: &str = "hi"; // &str
    assert_eq!(b.len(), 2);

    let c: &str = r"hi\n"; // raw string literal
    assert_eq!(c.len(), 4);

    let d: &str = "hi\n";
    assert_eq!(d.len(), 3);

    let i: u8 = b'0';
    assert_eq!(i, 0x30);

    let k: &[u8; 2] = b"\x30\x31"; // byte string literal
    assert_eq!(k, &[48, 49]);

    let r: &str = r###"hi\n"###; // raw string literal
    assert_eq!(r, "hi\\n");

    let c1: &CStr = c"01";
    let c1_bytes_slice :&[u8] = c1.to_bytes();
    assert_eq!(c1_bytes_slice.len(), 2);
    // to_bytes() does not contain the trailing 0
    assert_eq!(c1.to_bytes(), &[0x30, 0x31]);
    println!("{:?}", c1.count_bytes()); // 2, like strlen()
}

fn test_2() {
    let a: &CStr = c"01";
    let b: CString = CString::from(a);
    let c: CString = CString::new("hi").unwrap();

    let d: &str = a.to_str().unwrap();
    let e: String = String::from(d);
    let f: String = c.into_string().unwrap();
    assert_eq!(&e, "01");
    assert_eq!(&f, "01");

    let h: CString = CString::new(f).unwrap();
    assert_eq!(h.as_c_str(), a);
}

fn main() {
    test_1();
    test_2();
}
