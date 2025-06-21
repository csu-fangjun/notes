use std::ffi::{CStr, CString};

#[repr(C)]
#[derive(Debug)]
struct MyStruct1 {
    a: i32,
    b: i8,
    c: f32,
    p: *const i8,
    d: f64,
}

#[repr(C)]
#[derive(Debug)]
struct MyStruct2 {
    s1: *const i8,
    s2: MyStruct1,
    i: i32,
}

unsafe extern "C" {
    fn sum_float_arr(v: *const f32, n: i32) -> f32;
    fn add_one_vec(v: *mut i32, n: i32);
    fn add_one_scalar(i: *mut i32);
    fn return_i32_array(n: *mut i32) -> *mut i32;
    fn free_i32_array(v: *mut i32);
    fn my_str_len(v: *const i8) -> i32;
    fn my_upper_str(v: *mut i8);
    fn my_str_array() -> *const *const i8;
    fn compute_struct1_sum(p: *const MyStruct1) -> f32;
    fn compute_struct2_sum(p: *const MyStruct2) -> f32;
}

fn test_sum_float_arr() {
    println!("---test_sum_float_arr---");
    let v: Vec<f32> = vec![1., 2., 3.];
    let sum: f32;
    unsafe {
        sum = sum_float_arr((&v).as_ptr(), v.len() as i32);
    }
    println!("Sum of {v:?} is {sum}");
}

fn test_add_one_vec() {
    println!("---test_add_one_vec---");
    let mut v: Vec<i32> = vec![1, 2, 3];
    println!("Before add one: {v:?}");
    unsafe {
        add_one_vec((&mut v).as_mut_ptr(), v.len() as i32);
    }
    println!("After add one: {v:?}");
}

fn test_add_one_scalar() {
    println!("---test_add_one_scalar---");
    let mut i = 10;
    println!("Before add one scalar: {i}");
    unsafe {
        add_one_scalar(&mut i); //implicit conversion
        add_one_scalar((&mut i) as *mut i32); // explicit
    }
    println!("After add one scalar (two times): {i}");
}
fn test_return_i32_array() {
    println!("---test_return_i32_array---");
    unsafe {
        let mut i = 0;
        let p = return_i32_array(&mut i);
        println!("i is {i}, p is: {p:p}");

        let v = std::slice::from_raw_parts_mut(p, i as usize);
        println!("v is {v:?}");
        add_one_vec(v.as_mut_ptr(), v.len() as i32);
        println!("after adding one, v is {v:?}");
        free_i32_array(p);
    }
}

fn test_my_str_len() {
    println!("---test_my_str_len---");
    let a = "hi";
    unsafe {
        let b = CString::new(a).unwrap();
        let n = my_str_len(b.as_ptr());
        assert_eq!(n, 2);
    }

    unsafe {
        let n = my_str_len(std::ptr::null::<i8>());
        assert_eq!(n, 0);

        let p = std::ptr::null::<i8>();
        println!("p is {p:p}"); // p ix 0x0
    }
}

fn test_my_upper_str() {
    println!("---test_my_upper_str---");
    let mut a = String::from("hi");
    a.push('0');
    unsafe {
        my_upper_str(a.as_bytes_mut().as_mut_ptr() as *mut i8);
    }
    a.pop();
    assert_eq!(a, "HI");

    let mut a = CString::new("world").unwrap();
    unsafe {
        let p = a.into_raw();
        my_upper_str(p);

        a = CString::from_raw(p);
    }
    assert_eq!(a.as_c_str(), c"WORLD");
}

// convert an array of c strings to Vec<CString>
fn test_my_str_array() {
    let p: *const *const i8;
    unsafe {
        p = my_str_array();
        println!("{:p}", *p);
        println!("{:p}", *p.add(1));
        println!("{:p}", *p.add(2));
    }
    let mut i = 0;
    let mut v = Vec::<CString>::new();
    unsafe {
        loop {
            // if *p.add(i) == std::ptr::null() {
            if (*p.add(i)).is_null() {
                break;
            }
            let s = CStr::from_ptr(*p.add(i));
            v.push(CString::from(s));

            i += 1;
        }
    }
    assert_eq!(i, 2);
    println!("{v:?}");
}

fn test_compute_struct1_sum() {
    let c = c"hello world";
    let s = MyStruct1 {
        a: 1,
        b: 2,
        c: 3.0,
        p: c.as_ptr(),
        d: 4.0,
    };
    let sum: f32;
    unsafe {
        sum = compute_struct1_sum(&s);
    }
    assert_eq!(sum, 10.0 + c.count_bytes() as f32);
}

fn test_compute_struct2_sum() {
    let c = c"hello";
    let s = MyStruct2{
        s1: c.as_ptr().cast(),
        s2: MyStruct1 {
            a: 1,
            b: 2,
            c: 3.0,
            p: std::ptr::null(),
            d: 4.0,
        },
        i: 10,
    };
    let sum: f32;
    unsafe {
        sum = compute_struct2_sum(&s);
    }
    assert_eq!(sum, c.count_bytes() as f32 + s.s2.a as f32 + s.s2.b as f32 + s.s2.c + s.s2.d as f32+ s.i as f32);
}

fn main() {
    test_sum_float_arr();
    test_add_one_vec();
    test_add_one_scalar();
    test_return_i32_array();
    test_my_str_len();
    test_my_upper_str();
    test_my_str_array();
    test_compute_struct1_sum();
    test_compute_struct2_sum();
}
