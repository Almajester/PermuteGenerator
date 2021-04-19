/**
 * PermuteGen.hpp -- header for generator class to create permutations of an array of
 *     integers 0 to n-1.
 * A. Thall
 * 4/18/2021
 *
 * Created because I'm sick of having to reinvent this every time I need it.
 * I like the cleanness of Icon/Python generator functions but want bare-metal speed.
 * K, we'll start with just a wrapper around the std::next_permutation iterator algorithm
 */


#ifndef PERMUTATIONGENERATOR_PERMUTEGEN_HPP
#define PERMUTATIONGENERATOR_PERMUTEGEN_HPP

#include <algorithm>
#include <vector>

#include <cstdio>
#include <cstdlib>

class PermuteGen
{
    std::vector<int> numList;
    bool done;

public:
    /**,
     * Create a permutation generator for array [0, ..., size-1]
     * @param size -- must be greater than zero
     */
    explicit PermuteGen(int size) {
        if (size == 0) {
            printf("You're trying to permute 0 elements.  I quit.");
            exit(0);
        }
        for (int i = 0; i < size; i++)
            numList.push_back(i);

        done = false;
    }

    const int operator[](int index) const {
        return numList[index];
    }

    int size() {
        return numList.size();
    }

    bool hasNext() {
        return !done;
    }

    void next() {
        if (!done) {
            done = !std::next_permutation(numList.begin(), numList.end());
            return;
        }
    }


};


#endif //PERMUTATIONGENERATOR_PERMUTEGEN_HPP
