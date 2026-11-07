# Optimization reflection - 200 words

Preparing these solutions helped me distinguish processing cost from input storage and input reading. Diagonal Difference needs only two entries per row, so its calculation is linear in the matrix dimension, although reading the complete matrix remains quadratic. This distinction makes complexity claims precise.

Dynamic Array showed why state matters: every query uses the previous answer when selecting a sequence. Resizable vectors make appends efficient on average, but stored values still consume memory. Therefore, its worst-case storage depends on the query count as well as the number of sequences.

For Sparse Arrays, a frequency map replaces repeated scans with expected constant-time lookups. This improves repeated queries substantially, while string lengths and hash collisions remain relevant qualifications. Time Conversion and Compare the Triplets use fixed-size inputs, so their work is constant rather than dependent on an arbitrary collection size.

Testing boundary cases exposed important details, including noon, midnight, ties, negative matrix values, and repeated strings. Additional practice reinforced direct index mapping, prefix sums, and using wide integers for large totals. Measurements supported the expected trends without proving complexity. I would next reproduce these approaches independently, explain their invariants aloud, and extend the tests before adapting them to less constrained input formats.
