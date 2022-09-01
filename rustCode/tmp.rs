// use proconio::input;
extern crate proconio;
use proconio::input;
use std::io;

fn main() {
    println!("Give the inputs: ");
    input! {
        n: u8,
        // m: u32,
        // l: i32,
    }

    println!("Here: ");
    // now you can use n, m and l as variable.
    // println!("{} {} {}", n, m, l);
    println!("{} ", n);
}
