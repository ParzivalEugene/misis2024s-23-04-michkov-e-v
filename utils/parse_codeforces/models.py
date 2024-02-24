from pydantic import BaseModel


def to_camel_case(snake_str: str) -> str:
    components = snake_str.split("_")
    return components[0] + "".join(x.title() for x in components[1:])


class Problem(BaseModel):
    contest_id: int
    index: str
    name: str
    type: str
    rating: int
    tags: list[str]

    class Config:
        alias_generator = to_camel_case


class Member(BaseModel):
    handle: str


class Author(BaseModel):
    contestId: int
    members: list[Member]
    participant_type: str
    ghost: bool
    start_time_seconds: int

    class Config:
        alias_generator = to_camel_case


class Result(BaseModel):
    id: int
    contest_id: int
    creation_time_seconds: int
    relative_time_seconds: int
    problem: Problem
    programming_language: str
    verdict: str
    testset: str
    passed_test_count: int
    time_consumed_millis: int
    memory_consumed_bytes: int

    class Config:
        alias_generator = to_camel_case


class Data(BaseModel):
    status: str
    result: list[Result]


class SolveInfo(BaseModel):
    contest_id: int
    problem_index: str
    name: str
    rating: int
    tags: list[str]
