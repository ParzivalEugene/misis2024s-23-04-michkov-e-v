import os
import re
from io import open

DIR = "./prj.codeforces"


def get_files():
    return [
        ".".join(file.split(".")[:-1])
        for file in os.listdir(DIR)
        if os.path.isfile(os.path.join(DIR, file)) and file.endswith(".cpp")
    ]


def update_readme():
    with open("./README.md", "rb") as f:
        md = f.read().decode("utf-8")
        md = re.sub(r"решено_задач-\d+-blue", f"решено_задач-{len(get_files())}-blue", md)

    with open("./README.md", "wb") as f:
        f.write(md.encode("utf-8"))


def update_cmake():
    files = sorted(get_files())
    cmake = "\n".join([f"add_executable({file} {file}.cpp)" for file in files])
    with open("./prj.codeforces/CMakeLists.txt", "wb") as f:
        f.write(cmake.encode("utf-8"))


update_readme()
update_cmake()
