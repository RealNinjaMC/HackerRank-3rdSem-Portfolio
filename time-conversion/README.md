# Time Conversion

Problem: https://www.hackerrank.com/challenges/time-conversion/problem

## Summary
Reduce the parsed hour modulo 12, then add 12 for PM. Replace the two hour digits and return the first eight characters.

## Complexity
- Time: O(1), fixed ten-character input.
- Space: O(1), fixed-size strings.

## Edge cases and assumptions
12AM becomes 00 while 12PM stays 12. Noon, midnight, leading zeroes and the last second of the day are tested.

## Testing
5 local function checks plus 3 full stdin/stdout cases. Run `python run_tests.py` from the repository root. `solution.cpp` is a complete program: paste the entire file into HackerRank using C++11; LOCAL_TEST is not defined by the judge.

## Online result
Awaiting verified submission.
