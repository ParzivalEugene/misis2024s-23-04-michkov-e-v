use std::path::PathBuf;
use std::process::Command;

fn validate_cpp(file: &PathBuf) -> Result<(), String> {
    if file.extension().map_or(false, |e| e == "cpp") {
        return Ok(());
    }
    Err("File must have a .cpp extension".to_string())
}

fn validate_existing_file(file: &PathBuf) -> Result<(), String> {
    let result = Command::new("git")
        .args(&["rev-parse", "--show-toplevel"])
        .output();
    if result.is_err() {
        return Err(result.unwrap_err().to_string());
    }
    let dir = String::from_utf8(result.unwrap().stdout)
        .unwrap()
        .trim()
        .to_string();
    let path = format!("{}/prj.codeforces/{}", dir, file.to_str().unwrap());
    if PathBuf::from(path).exists() {
        return Ok(());
    }
    Err("File does not exist".to_string())
}

pub fn file_validator(file: &PathBuf) -> Result<(), String> {
    validate_cpp(file)?;
    validate_existing_file(file)
}
