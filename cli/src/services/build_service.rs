use std::io::BufRead;
use std::process::{Command, Stdio};

pub fn build() {
    let mut cmake = Command::new("sh")
        .arg("-c")
        .arg("cd $(git rev-parse --show-toplevel) && mkdir -p build && cd build && cmake .. && make")
        .stdout(Stdio::piped())
        .stderr(Stdio::inherit())
        .spawn()
        .expect("Failed to build project");
    let stdout = cmake.stdout.take().unwrap();
    let reader = std::io::BufReader::new(stdout);

    for line in reader.lines() {
        println!("{}", line.unwrap());
    }

    let status = cmake.wait().expect("Failed to build project");
    if !status.success() {
        eprintln!("Failed to build project");
    } else {
        println!("Project built successfully");
    }
}
