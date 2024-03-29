import asyncio
import os
import re
from io import open

from parse_codeforces.parse_codeforces import create_md_table, get_avg_rating, get_codeforces_data, get_solve_info

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
        data = await get_codeforces_data()
        solve_info = get_solve_info(data)

        md = f.read().decode("utf-8")
        md = re.sub(r"Решено_задач-\d+", f"Решено_задач-{len(get_files())}", md)
        md = re.sub(r"Средний_рейтинг-\d+", f"Средний_рейтинг-{get_avg_rating(solve_info)}", md)
        md = re.sub(
            r"<!--\s*Start\s*table\s*-->[\s\S]*?<!--\s*End\s*table\s*-->",
            f"<!-- Start table -->\n{create_md_table(solve_info)}\n<!-- End table -->",
            md,
        )

    with open("./README.md", "wb") as f:
        f.write(md.encode("utf-8"))


async def main():
    update_cmake()
    await update_readme()


if __name__ == "__main__":
    asyncio.run(main())
