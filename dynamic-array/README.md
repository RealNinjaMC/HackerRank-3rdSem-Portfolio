# Dynamic Array

Problem: https://www.hackerrank.com/challenges/dynamic-array/problem

## Summary
Maintain n resizable sequences and lastAnswer. Use XOR and modulo to select a sequence, append on type 1, and update lastAnswer plus the answer list on type 2.

## Complexity
- Time: O(n + q) amortized.
- Space: O(n + q) worst-case auxiliary storage.

## Edge cases and assumptions
A type-2 query is guaranteed to reference a nonempty sequence. The worksheet gives O(n) space, but up to q appended values and answers must also be stored.

## Testing
4 local function checks plus 2 full stdin/stdout cases. Run `python run_tests.py` from the repository root. `solution.cpp` is a complete program: paste the entire file into HackerRank using C++11; LOCAL_TEST is not defined by the judge.

## Online result
Full score: 15 points. All 11 displayed test cases passed on 7 November 2026.

- [Verified submission](https://www.hackerrank.com/challenges/dynamic-array/submissions/code/486762098)
- [Genuine success screenshot](accepted.jpg)
