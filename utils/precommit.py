import asyncio
import os
import re
from io import open

from parse_codeforces.parse_codeforces import create_md_table, get_codeforces_data, get_solve_info

DIR = "./prj.codeforces"


def get_files():
    return [
        ".".join(file.split(".")[:-1])
        for file in os.listdir(DIR)
        if os.path.isfile(os.path.join(DIR, file)) and file.endswith(".cpp")
    ]


def update_cmake():
    files = sorted(get_files())
    cmake = "\n".join([f"add_executable({file} {file}.cpp)" for file in files])
    with open(f"{DIR}/CMakeLists.txt", "wb") as f:
        f.write(cmake.encode("utf-8"))


async def update_readme():
    with open("./README.md", "rb") as f:
        md = f.read().decode("utf-8")
        md = re.sub(r"решено_задач-\d+-blue", f"решено_задач-{len(get_files())}-blue", md)
        data = await get_codeforces_data()
        md = re.sub(
            r"<!--\s*Start\s*table\s*-->[\s\S]*?<!--\s*End\s*table\s*-->",
            f"<!-- Start table -->\n{create_md_table(get_solve_info(data))}\n<!-- End table -->",
            md,
        )

    with open("./README.md", "wb") as f:
        f.write(md.encode("utf-8"))


async def main():
    update_cmake()
    await update_readme()


if __name__ == "__main__":
    asyncio.run(main())
