pub fn validate_module_name(name: &str) -> Result<(), String> {
    if name.chars().all(|c| c.is_alphanumeric() || c == '_') {
        return Ok(());
    }
    Err("Module name must be alphanumeric".to_string())
}
