# Diagonal Difference

Problem: https://www.hackerrank.com/challenges/diagonal-difference/problem

## Summary
Read only the two diagonal entries in each row and subtract their sums. Take the absolute value so the result is independent of which diagonal is larger.

## Complexity
- Time: O(n) function time; O(n^2) including reading the matrix.
- Space: O(1) auxiliary; O(n^2) input matrix.

## Edge cases and assumptions
A shared middle element contributes to both sums and cancels. Negative values and equal diagonal sums are tested.

## Testing
4 local function checks plus 2 full stdin/stdout cases. Run `python run_tests.py` from the repository root. `solution.cpp` is a complete program: paste the entire file into HackerRank using C++11; LOCAL_TEST is not defined by the judge.

## Online result
Full score: 10 points. All 11 displayed test cases passed on 7 November 2026.

- [Verified submission](https://www.hackerrank.com/challenges/diagonal-difference/submissions/code/486762075)
- [Genuine success screenshot](accepted.jpg)
