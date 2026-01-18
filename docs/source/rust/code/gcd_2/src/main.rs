use std::env;

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
    let args: Vec<String> = env::args().collect();
    if args.len() != 3 {
        eprintln!("Usage: {} <int1> <int2>", args[0]);
        std::process::exit(1);
    }

    // args[0] is the program name
    let num1: u64 = args[1]
        .parse()
        .expect("Please provide a valid integer for the first argument");

    let num2: u64 = args[2]
        .parse()
        .expect("Please provide a valid integer for the second argument");
    let n = gcd(num1, num2);

    println!("GCD of {} and {} is {}", num1, num2, n);
}
