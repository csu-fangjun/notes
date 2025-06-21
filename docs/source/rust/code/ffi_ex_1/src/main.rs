use std::os::raw::c_int;
unsafe extern "C" {
    fn my_add(a: c_int, b: c_int) -> c_int;
}
fn main() {
    let a: i32;
    unsafe {
        a = my_add(10, 20);
    }
    println!("my_add returns {a}");
}
