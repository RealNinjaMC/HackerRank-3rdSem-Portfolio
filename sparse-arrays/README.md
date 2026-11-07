# Sparse Arrays

Problem: https://www.hackerrank.com/challenges/sparse-arrays/problem

## Summary
Build a hash map from complete strings to occurrence counts. Answer each query by lookup rather than rescanning the entire collection.

## Complexity
- Time: Expected O(n + q) for bounded-length strings; O((n + q)^2) hash-collision worst case.
- Space: O(u + q) entries, u distinct input strings, plus stored key characters.

## Edge cases and assumptions
Hashing must read string characters; with unbounded lengths, account for total characters hashed. Exact matches, repeated queries and absent values are tested.

## Testing
4 local function checks plus 2 full stdin/stdout cases. Run `python run_tests.py` from the repository root. `solution.cpp` is a complete program: paste the entire file into HackerRank using C++11; LOCAL_TEST is not defined by the judge.

## Online result
Awaiting verified submission.
