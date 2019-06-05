/**
 * LabSD 4
 * DoubleQueueStack.h
 * Purpose: Skeleton code for the double queue stack.
 *
 * @author Stefan Hermeniuc
 */

#ifndef __DOUBLESTACKQUEUE_H__
#define __DOUBLESTACKQUEUE_H__

#include <iostream>

template <typename T, int N>
class DoubleStackQueue {
private:
    int numElements;

    Stack<T, N> *s1;
    Stack<T, N> *s2;

public:
    // Constructor
    DoubleStackQueue() {
        // TODO: initializations
    }

    // Destructor
    ~DoubleStackQueue() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Adds the given element to the front of the queue.
     *
     * @param element Element to be added to the queue.
     */
    void enqueue(T element) {
        // TODO: BONUS 3
    }

    /**
     * Removes the front element of the queue.
     */
    T dequeue() {
        // TODO: BONUS 3
        return 0;
    }

    /**
     * Returns the front element.
     *
     * @return Value of the element stored on top of the queue.
     */
    T front() {
        // TODO: BONUS 3
        return 0;
    }

    /**
     * Checks if the queue contains any elements.
     *
     * @return True if the queue contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: BONUS 3
        return true;
    }

    /**
     * Returns the number of elements currently stored in the queue.
     *
     * @return The number of elements stored in the queue.
     */
    int size() {
        // TODO: BONUS 3
        return 0;
    }

    // Getters
    Stack<T, N> *getS1() {
        return s1;
    }

    Stack<T, N> *getS2() {
        return s2;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os,
            DoubleQueueStack<U, M>& stack);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, DoubleStackQueue<T, N>& queue) {
    os << "Front to end: ";
    Stack<T, 10> *s1 = queue.getS1();
    Stack<T, 10> auxStack;

    while (!s1->isEmpty()) {
        auxStack.push(s1->peek());
        s1->pop();
    }

    while (!auxStack.isEmpty()) {
        os << auxStack.peek() << " ";
        s1->push(auxStack.peek());
        auxStack.pop();
    }

    return os;
}

#endif // __DOUBLEQUEUESTACK_H__
