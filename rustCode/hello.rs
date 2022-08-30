use std::io;


fn main(){
    myfunc();
    println!("Hello Rust!");


    println!("Enter the no.: ");
    let mut input_string = String::new();
    io::stdin().read_line(&mut input_string).expect("Failed to read line");

    let n : i32 = input_string.trim().parse().expect("Failed to parse as integer");

    println!("val: {} ", n + 5);
}

fn myfunc(){
    println!("New function");
}
