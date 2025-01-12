use std::io;

fn fib(n: u32) -> u32 {

    if n <= 1 {
        return n
    }

    fib(n-1) + fib(n-2)
}

fn fib_loop(n: u32) -> u32 {
    let mut near = 1u32;
    let mut far = 0u32;

    if n <= 1 {
        return n 
    }

    for _ in 2..n {
        let curr: u32 = near + far;

        far = near;
        near = curr


    }

    near + far
}
fn is_even(n: i32) -> bool {
n % 2 == 0
}

fn main() {
    let n = 123456;
    let description = if is_even(n) {
        "even"
    } else {
        "odd"
    };
    println!("{}", description);
    let n = loop {
    break 123;
    };
    println!("{}", n);

    let item = 15;

    match item {
    0 => {},
    10 ..= 20 => {
        println!("here ")
    },
    40 | 80 => {},
    _ => {},
    };

    println!("Enter an integer:");

    let mut input = String::new(); // Create a mutable String to store the input

    io::stdin()
        .read_line(&mut input) // Read input from the user
        .expect("Failed to read line");

    // Convert the input string to an integer
    let number: u32 = input
        .trim() // Remove any trailing whitespace
        .parse() // Parse the string as an integer
        .expect("Please enter a valid integer");

    println!("Fib of {}: {}", number, fib_loop(number));
    // println!("Fib of {}: {}", number, fib(number));
}
