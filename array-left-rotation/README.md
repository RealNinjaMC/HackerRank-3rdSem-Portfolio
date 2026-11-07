# Left Rotation - additional badge practice

Problem: https://www.hackerrank.com/challenges/array-left-rotation/problem

## Approach
Map each output position directly to its source index with modulo arithmetic instead of rotating one step repeatedly.

## Complexity
Time: O(n). Space: O(n) returned vector; O(1) extra beyond output.

## Notes and tests
The input is nonempty. Zero and full-length rotations leave its values unchanged.

3 function checks and 2 stdin/stdout cases are included. Run `python run_tests.py`.

## Online result
Full score: 20 points. All 10 displayed test cases passed on 7 November 2026.

- [Verified submission](https://www.hackerrank.com/challenges/array-left-rotation/submissions/code/486762323)
- [Genuine success screenshot](accepted.jpg)
