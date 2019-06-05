/**
 * LabSD 3
 * lab3.cpp
 * Purpose: Driver program to run lab3 tasks.
 *
 * @author Gabriel Bercaru
 */

#include <iostream>

#include "DoublyLinkedList.h"
#include "ResizableArray.h"
#include "SlidingWindow.h"
#include "PascalTriangle.h"

void checkDoublyLinkedList() {
	DoublyLinkedList<int> dll;

	dll.addLast(4);
    dll.addLast(3);
    dll.addLast(2);
    dll.addLast(1);

    dll.addFirst(-1);
    dll.addFirst(-2);
    dll.addFirst(-3);
    dll.addFirst(-4);

    std::cout << "Linked list after adding some elements: " << dll << std::endl;

    dll.removeFirst();
    dll.removeLast();
    std::cout << "Linked list after removing the first element: " << dll << std::endl;
}

void checkResizableArray() {
	ResizableArray<int> ra;

	ra.addLast(1);
    ra.addLast(100);
    ra.addLast(110);
    ra.addLast(51);
    ra.addFirst(2);
    ra.addFirst(17);
    ra.addFirst(5);

    std::cout << "Resizable array after adding some elements: " << ra << std::endl;

    ra.removeFirst();
    ra.removeLast();

    std::cout << "Resizable array after removing some elements: " << ra << std::endl;
}

void checkSlidingWindow() {
    std::vector<int> container;
    for (int i = 0; i < 5; i++) {
        container.push_back(i + 1);
    }
    SlidingWindow<int> window(container, 3);

    std::cout << "Container: [ ";
    for (int i = 0; i < 5; i++) {
        std::cout << container[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Window: " << window << std::endl;

    for (int i = 0; i < 10; i++) {
        window.advance();
        std::cout << i + 1 << " / Window: " << window << std::endl;
    }
}

void checkPascalTriangle() {
    int n;
    std::cin >> n;
    PascalTriangle<int> triangle(n);
    std::cout << triangle;

}

int main() {
    //checkDoublyLinkedList();
    //checkResizableArray();
    //checkSlidingWindow();
    checkPascalTriangle();

    return 0;
}
