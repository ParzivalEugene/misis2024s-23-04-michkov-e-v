import argparse
import os


def main():
    parser = argparse.ArgumentParser(description='This is a new module')
    parser.add_argument("module_name", help="Name of the module", type=str)
    args = parser.parse_args()  
    module_name = str(args.module_name)

    if (os.path.exists(f"prj.lab/{module_name}")):
        print(f"Module {module_name} already exists")
        return
    
    os.mkdir(f"prj.lab/{module_name}")

    with open(f"prj.lab/{module_name}/{module_name}.hpp", "w") as file:
        data = f"""#pragma once
#ifndef {module_name.upper()}_HPP
#define {module_name.upper()}_HPP

#include <iostream>

class {module_name.capitalize()} {{
 public:
 private:
}};
    
#endif // {module_name.upper()}_HPP
"""
        file.write(data)

    with open(f"prj.lab/{module_name}/{module_name}.cpp", "w") as file:
        file.write(f"#include \"{module_name}.hpp\"\n")
    
    with open(f"prj.lab/{module_name}/CMakeLists.txt", "w") as file:
        data = f"""add_library({module_name} {module_name}.cpp {module_name}.hpp)
set_property(TARGET {module_name} PROPERTY CXX_STANDARD 20)
target_include_directories({module_name} PUBLIC
  $<BUILD_INTERFACE:${{CMAKE_CURRENT_SOURCE_DIR}}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS {module_name})
""" 
        file.write(data)

    with open("prj.lab/CMakeLists.txt", "a") as file:
        file.write(f"add_subdirectory({module_name})\n")

    with open("prj.test/CMakeLists.txt", "a") as file:
        data = f"""
add_executable(test_{module_name} test_{module_name}.cpp)
target_link_libraries(test_{module_name} {module_name})
"""
        file.write(data)
    
    with open(f"prj.test/test_{module_name}.cpp", "a") as file:
        data = f"""#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "{module_name}/{module_name}.hpp"
"""
        file.write(data)
    
    print(f"Module {module_name} was successfully created")

if __name__ == '__main__':
    main()