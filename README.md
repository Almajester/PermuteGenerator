Project:  PermuteGenerator
A. Thall
4/17/21

A simple container class to imitate a generator function (as in Icon or Python) for creating
integer permutations.

PermuteGen.hpp -- uses the std::next_permutation() generator to permute a vector of [0...size-1] ints
PermuteTest.cpp -- tests this using a simple print-all-iterations as well as by computing probabilities
of derangements on permutations.