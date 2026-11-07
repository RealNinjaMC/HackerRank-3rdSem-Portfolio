# Array Manipulation - additional badge practice

Problem: https://www.hackerrank.com/challenges/crush/problem

## Approach
Record each range update only at its start and just after its end, then recover final values with one prefix-sum pass.

## Complexity
Time: O(n + m). Space: O(n) auxiliary, excluding m input queries.

## Notes and tests
A 64-bit accumulator prevents overflow. This replaces the O(n*m) worst-case repeated range-update approach.

3 function checks and 2 stdin/stdout cases are included. Run `python run_tests.py`.

## Online result
Full score: 60 points. All 16 displayed test cases passed on 7 November 2026.

- [Verified submission](https://www.hackerrank.com/challenges/crush/submissions/code/486762358)
- [Genuine success screenshot](accepted.jpg)
