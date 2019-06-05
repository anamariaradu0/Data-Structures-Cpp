template <typename T, int N>
class Queue {
private:
    DoublyLinkedList<T> *bot;

public:
    // Constructor
    Queue() {
        // TODO
        bot = new DoublyLinkedList<T>;
    }

    // Destructor
    ~Queue() {
        // TODO
        delete bot;
    }

    // Adauga in coada
    void enqueue(T e) {
        // TODO
        if (N != bot->size()) {
            bot->addFirst(e);
        } else {
        std::cout << "Coada e plina!\n";
        }
    }

    // Extrage din coada
    void dequeue() {
        // TODO
        if (!bot->isEmpty()) {
            bot->removeLast();
        } else {
        std::cout << "Coada e goala!\n";
        }
    }

    // Afla primul element
    T front() {
        // TODO
        if (!bot->isEmpty()) {
            return bot->getTail()->data;
        } else {
            std::cout << "Coada e goala!\n";
            return T{};
        }
    }

    bool isEmpty() {
        // TODO
        return bot->isEmpty();
    }
};
