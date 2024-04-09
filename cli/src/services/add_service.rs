use std::fs::{create_dir, File, OpenOptions};
use std::io::Write;
use std::process::Command;

pub fn add_module(name: &str) {
    let result = Command::new("git")
        .args(&["rev-parse", "--show-toplevel"])
        .output();
    if result.is_err() {
        eprintln!("{}", result.unwrap_err());
        return;
    }
    let path = String::from_utf8(result.unwrap().stdout)
        .unwrap()
        .trim()
        .to_string();
    create_dir(format!("{}/prj.lab/{}/", path, name))
        .expect("Failed to create, module already exists");
    let mut hpp_file = File::create(format!("{}/prj.lab/{}/{}.hpp", path, name, name))
        .expect("Failed to create hpp file");
    let hpp_content = format!(
        "#pragma once\n#ifndef {0}_HPP\n#define {0}_HPP\n\n#include <iostream>\n\nclass {0} {{\n public:\n private:\n}};\n\n#endif // {0}_HPP\n",
        name.to_uppercase()
    );
    hpp_file
        .write_all(hpp_content.as_bytes())
        .expect("Failed to write to hpp file");

    let mut cpp_file = File::create(format!("{}/prj.lab/{}/{}.cpp", path, name, name))
        .expect("Failed to create cpp file");
    let cpp_content = format!("#include \"{}.hpp\"\n", name);
    cpp_file
        .write_all(cpp_content.as_bytes())
        .expect("Failed to write to cpp file");

    let mut local_cmake = File::create(format!("{}/prj.lab/{}/CMakeLists.txt", path, name))
        .expect("Failed to open local CMakeLists.txt");
    let local_cmake_content = format!(
        "add_library({0} {0}.cpp {0}.hpp)\nset_property(TARGET {0} PROPERTY CXX_STANDARD 20)\ntarget_include_directories({0} PUBLIC\n  $<BUILD_INTERFACE:${{CMAKE_CURRENT_SOURCE_DIR}}/..>\n  $<INSTALL_INTERFACE:include>\n)\ninstall(TARGETS {0})",
        name
    );
    local_cmake
        .write_all(local_cmake_content.as_bytes())
        .expect("Failed to write to local CMakeLists.txt");

    let mut global_cmake = OpenOptions::new()
        .append(true)
        .open(format!("{}/prj.lab/CMakeLists.txt", path))
        .expect("Failed to open global CMakeLists.txt");
    let global_cmake_content = format!("add_subdirectory({})\n", name);
    global_cmake
        .write_all(global_cmake_content.as_bytes())
        .expect("Failed to write to global CMakeLists.txt");

    let mut test_cmake = OpenOptions::new()
        .append(true)
        .open(format!("{}/prj.test/CMakeLists.txt", path))
        .expect("Failed to open tests CMakeLists.txt");
    let test_cmake_content = format!(
        "\nadd_executable(test_{0} test_{0}.cpp)\ntarget_link_libraries(test_{0} {0})\nadd_test(NAME test_{0} COMMAND test_{0})\n",
        name
    );
    test_cmake
        .write_all(test_cmake_content.as_bytes())
        .expect("Failed to write to tests CMakeLists.txt");

    let mut test_cpp = File::create(format!("{}/prj.test/test_{}.cpp", path, name))
        .expect("Failed to create test cpp file");
    let test_cpp_content = format!(
        "#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN\n#include \"{0}/{0}.hpp\"\n#include \"doctest.h\"\n",
        name
    );
    test_cpp
        .write_all(test_cpp_content.as_bytes())
        .expect("Failed to write to test cpp file");

    println!("Module {} added successfully", name);
}
