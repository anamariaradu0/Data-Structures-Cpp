/**
 * Lab6 SD
 * Algorithms.h
 * Purpose: Wrapper class for Lab6 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include <vector>

#include "ListGraph.h"
#include "MatrixGraph.h"

class Algorithms {
public:
    /**
     * Check whether there is a path between the two given words, where
     * each word differs by exactly one letter from the previous one.
     *
     * @param words A set containing all the possible words.
     * @param sourceWord The word to start from.
     * @param targetWord The word to search for.
     * @return True or False, meaning that a path from sourceWord to
     * targetWord (according to the given conditions) exists or not.
     */
    static bool wordLadder(const std::set<std::string>& words, std::string sourceWord, std::string targetWord) {
        // TODO: TASK 2
        return false;
    }
};

#endif // __ALGORITHMS_H__
