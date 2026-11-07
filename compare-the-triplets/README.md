# Compare the Triplets

Problem: https://www.hackerrank.com/challenges/compare-the-triplets/problem

## Summary
Compare the three corresponding positions once. Increment Alice or Bob only for a strict win; ties award neither side a point.

## Complexity
- Time: O(1), exactly three comparisons.
- Space: O(1).

## Edge cases and assumptions
The return order is Alice then Bob. The tests distinguish a tie from a win and include both all-win cases.

## Testing
5 local function checks plus 2 full stdin/stdout cases. Run `python run_tests.py` from the repository root. `solution.cpp` is a complete program: paste the entire file into HackerRank using C++11; LOCAL_TEST is not defined by the judge.

## Online result
Full score: 10 points. All 8 displayed test cases passed on 7 November 2026.

- [Verified submission](https://www.hackerrank.com/challenges/compare-the-triplets/submissions/code/486762189)
- [Genuine success screenshot](accepted.jpg)
