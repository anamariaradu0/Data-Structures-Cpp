/**
 * LabSD 4
 * Algorithms.h
 * Purpose: Wrapper class for Lab4 algorithms.
 *
 * @author Gabriel Bercaru
 */

#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__

#include <fstream>
#include <string>
#include <vector>
#include <string>

#include "Queue.h"
#include "Stack.h"

class Algorithms {
public:
    /**
     * Checks if the input string represents a balanced parentheses sequence.
     *
     * @param str String representing the sequence of brackets to be checked.
     * @return True if the sequence of brackets is balanced, False otherwise.
     */
    static bool checkBalancedParentheses(std::string str) {
        // TODO: TASK 3
        return false;
    }

    /**
     * Apply radix sort on the given vector.
     * Does not return anything, the vector
     * given as parameter must contain the
     * sorted elements.
     *
     * @param v Vector of elements to be sorted.
     */
    static void radixSort(std::vector<int>& v) {
        // TODO: TASK 4
    }

    /**
     * Convert a number from base 10 to base 2
     * using a stack. Print the results in
     * the output file.
     *
     * @param n The number to be converted.
     * @param  The output file
     */
    static void toBase2(int n, std::ostream& out) {
        // TODO: TASK 5
    }

    /**
    *  Checks if a string is a palindrome
    *  using a stack.
    *
    *  @param s the string to be checked.
    *  @return True if the string is a palindrome, False otherwise.
    */

    static bool palindrome(std::string s) {
        // TODO: TASK 6
        return false;
    }

    /**
     * Reverses the given queue.
     * Does not return anything, the queue
     * given as parameeter must contain
     * the elements, in reverse order.
     *
     * @param queue Queue to be reversed.
     */
    template <typename T>
    static void reverseQueue(Queue<T, 20>& queue) {
        // TODO: BONUS 1
    }
};

#endif // __ALGORITHMS_H__
