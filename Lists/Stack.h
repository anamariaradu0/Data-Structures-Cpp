#ifndef __STACK__H__
#define __STACK__H__

// Primul argument al template-ului este tipul de date T
// Al doilea argument este dimensiunea maxima a stivei N
template<typename T, int N>
class Stack {
private:
    // Vectorul de stocare
    DoublyLinkedList<T> *top;
public:
    // Constructor
    Stack() {
        // TODO: initializari
        top = new DoublyLinkedList<T>;
    }

    // Destructor
    ~Stack() {
        // TODO: eliberare resurse, daca este cazul
        delete top;
    }

    // Operator de adaugare
    void push(T x) {
        // TODO: verificari, implementare
        if (N != top->size()) {
            top->addLast(x);
        }

    }

    // Operatorul de stergere
    void pop() {
        // TODO: verificari, implementare
        if (!top->isEmpty()) {
            top->removeLast();
        }
    }

    // Operatorul de consultare
    T peek() {
        // TODO: verificari, implementare
        if (!top->isEmpty()) {
            return top->getTail()->data;
        }
        return T{};
    }
    int size() {
        return top->size();
    }

    // Operatorul de verificare dimensiune
    bool isEmpty() {
        // TODO: implementare
        if (!top->size())
            return 1;
        return 0;
    }
};

#endif //__STACK__H__
