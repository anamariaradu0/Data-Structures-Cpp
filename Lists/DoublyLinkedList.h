/**
 * LabSD 3
 * DoublyLinkedList.h
 * Purpose: Skeleton code for the doubly linked list.
 *
 * @author Gabriel Bercaru
 */

#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include <assert.h>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int numElements;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        numElements = 0;
    }

    // Another constructor
    DoublyLinkedList(Node<T> *head) {
        this->head = head;
        while (head != nullptr) {
            numElements++;
            head = head->next;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        // TODO: delete previously allocated stuff (if any)
        Node<T> *temp = head;
        while(head) {
            temp = head;
            head = head->next;
            delete[] temp;
        }
    }

    /**
     * Adds a new node at the end of the list.
     *
     * @param data Data to be added at the end of the list.
     */
    void addLast(T data) {
        // TODO: TASK 1
        Node<T> *temp = new Node<T>(data);
        if (numElements) {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        } else {
            head = tail = temp;
        }
        numElements++;
    }

    /**
     * Adds a new node at the beginning of the list.
     *
     * @param data Data to be added at the beginning of the list.
     */
    void addFirst(T data) {
        // TODO: TASK 1
        Node<T> *temp = new Node<T>(data);
        if (numElements) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        } else {
            head = tail = temp;
        }
        numElements++;
    }

    /**
     * Removes the last node of the list.
     *
     * @return Value stored in the last node of the list.
     */
    T removeLast() {
        // TODO: TASK 1
        if (head == nullptr) {
            return T{};
        } else if (head == tail) {
            T val = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            numElements--;
            return val;
        } else {

            T val = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            numElements--;
            return val;
        }
    }

    /**
     * Removes the first node of the list.
     *
     * @return Value stored in the first node of the list.
     */
    T removeFirst() {
        // TODO: TASK 1

        if (numElements) {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            T val = temp->data;
            delete temp;
            numElements--;
            return  val;
        }
        return 0;
    }

    /**
     * Check if the list contains any elements.
     *
     * @return True if the list contains no elements, False otherwise.
     */
    bool isEmpty() {
        // TODO: TASK 1
        if (numElements)
            return false;
        return true;
    }

    /**
     * Get the number of nodes in the list.
     *
     * @return The number of nodes stored in the list.
     */
    int size() {
        // TODO: TASK 1
        return numElements;
    }

    // Getters & Setters
    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,
            DoublyLinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, DoublyLinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if (list.size() > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " <-> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}

#endif // __DOUBLYLINKEDLIST_H__
