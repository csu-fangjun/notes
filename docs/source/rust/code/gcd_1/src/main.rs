fn gcd(mut m: u64, mut n: u64) -> u64 {
    assert!(m != 0 && n != 0);
    while m != 0 {
        if m < n {
            let t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    n
}

fn main() {
    println!("gcd(6, 2) is {}", gcd(6, 2));
}

#[test]
fn test_gcd() {
    assert_eq!(gcd(2, 6), 2);
    assert_eq!(gcd(3, 5), 1);
}
