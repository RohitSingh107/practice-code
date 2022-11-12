use std::io::ErrorKind;
use std::process::Command;

fn error_handling_example(dir: &str) {
    println!("\n\n");

    let mut list_cmd = Command::new("ls");

    match list_cmd.current_dir(dir).status() {
        Ok(cmd) => Some(cmd),
        Err(err) => match err.kind() {
            ErrorKind::NotFound => {
                println!("Directory not found");
                None
            }
            _ => panic!("An unexpected error occurred!"),
        },
    };

    println!("\n\n");
}

fn main() {
    error_handling_example("src");
    error_handling_example("lib");
}
