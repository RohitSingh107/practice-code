use std::process::Command;

fn os_command_examples_1() {
    let echo_cmd = if cfg!(target_os = "windows") {
        Command::new("cmd")
            .args(["/C", "echo Hello from windows!"])
            .output()
            .expect("Failed to execute command.")
    } else {
        Command::new("sh")
            .args(["-c", "echo Hello from Linux!"])
            .output()
            .expect("Failed to execute command.")
    };

    println!("\n\n");
    let cmd_output = String::from_utf8(echo_cmd.stdout).expect("Couldn't parse byte response");
    print!("{}", cmd_output);
    println!("\n\n");
}

fn os_command_examples_2(){
    println!("\n\n");

    let mut cmd_root = Command::new("exa");
    cmd_root.args(["-la", "--color=always", "--group-directories-first", "--icons"]);

    cmd_root.status().expect("Failed to execute command.");

    println!("\n\n");

    cmd_root.current_dir("src").status().expect("Failed to execute command.");
}

fn main() {
    os_command_examples_1();
    os_command_examples_2();
}

            // .args(["-al", "--color=always --group-directories-first", "--icons"])
