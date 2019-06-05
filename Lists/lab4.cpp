#include <iostream>

#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Quetack.h"

int main() {


    /*

    Stack<int, 100> stiva;
    std::cout << stiva.isEmpty() << '\n';
    stiva.push(10);
    std::cout << stiva.peek() << '\n' << stiva.isEmpty() << " " << stiva.size() << '\n';
    stiva.pop();
    std::cout << stiva.peek();

    */


    Quetack<int, 100> coada;
    std::cout << coada.isEmpty() << '\n';
    coada.enqueue(10);
    coada.enqueue(5);
    std::cout << coada.front() << '\n' << coada.isEmpty() << '\n' ;
    coada.dequeue();
    std::cout << coada.front();

    return 0;
}
