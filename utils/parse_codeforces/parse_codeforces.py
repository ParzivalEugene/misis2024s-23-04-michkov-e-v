import asyncio
from typing import List

import aiohttp

from .models import Data, SolveInfo


def get_codeforces_id() -> str:
    with open("./codeforces.id", "r", encoding="utf-8") as f:
        codeforces_id = f.read().strip()
        if not codeforces_id:
            raise ValueError("Codeforces ID is not set. Please set it in 'codeforces.id' file.")
        return codeforces_id


async def get_codeforces_data() -> Data:
    codeforces_id = get_codeforces_id()
    url = f"https://codeforces.com/api/user.status?handle={codeforces_id}"

    async with aiohttp.ClientSession() as session:
        async with session.get(url) as response:
            if response.status != 200:
                raise ValueError(f"Failed to fetch data from Codeforces API. Status code: {response.status}")

            data = await response.json()
            return Data(**data)


def get_solve_info(data: Data) -> List[SolveInfo]:
    return sorted(
        [
            SolveInfo(
                contest_id=result.contest_id,
                problem_index=result.problem.index,
                name=result.problem.name,
                rating=result.problem.rating,
                tags=result.problem.tags,
            )
            for result in data.result
            if result.verdict == "OK" and result.programming_language == "GNU C++17"
        ],
        key=lambda x: x.rating,
        reverse=True,
    )

def get_avg_rating(solve_info: List[SolveInfo]) -> int:
    return sum(solve.rating for solve in solve_info) // len(solve_info)


def create_md_table(solve_info: List[SolveInfo]) -> str:
    headers = ["Problem", "Solution", "Rating", "Tags"]
    table = [f"| {' | '.join(headers)} |", f"| {' | '.join(['---'] * len(headers))} |"]

    for solve in solve_info:
        tags = ", ".join(solve.tags)
        name = f"[{solve.contest_id}{solve.problem_index} {solve.name}](https://codeforces.com/problemset/problem/{solve.contest_id}/{solve.problem_index})"
        solution = f"[Solution](https://github.com/ParzivalEugene/misis2024s-23-04-michkov-e-v/blob/master/prj.codeforces/{solve.contest_id:04}{solve.problem_index.lower()}.cpp)"
        table.append(f"| {name} | {solution} | {solve.rating} | {tags} |")

    return "\n".join(table)


async def main():
    data = await get_codeforces_data()
    print(create_md_table(get_solve_info(data)))


if __name__ == "__main__":
    asyncio.run(main())
