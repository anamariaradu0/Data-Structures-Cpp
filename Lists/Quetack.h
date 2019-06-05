template <typename T, int N>
class Quetack {
private:
    Stack<T, N> *bot;
    Stack<T, N> *buff;

public:
    // Constructor
    Quetack() {
        // TODO
        bot = new Stack<T, N>;
        buff = new Stack<T, N>;
    }

    // Destructor
    ~Quetack() {
        // TODO
        delete bot;
        delete buff;
    }

    // Adauga in coada
    void enqueue(T e) {
        // TODO
        if (N != bot->size()) {
            bot->push(e);
        } else {
        std::cout << "Coada e plina!\n";
        }
    }

    // Extrage din coada
    void dequeue() {
        // TODO
        if (!bot->isEmpty()) {
            int lenbot = bot->size();
            for (int i = 0; i < lenbot; i++) {
                buff->push(bot->peek());
                bot->pop();
            }
            buff->pop();
            int lenbuff = buff->size();
            for (int i = 0; i < lenbuff; i++) {
                bot->push(buff->peek());
                buff->pop();
            }
        } else {
        std::cout << "Coada e goala!\n";
        }
    }

    // Afla primul element
    T front() {
        // TODO
        if (!bot->isEmpty()) {
            int lenbot = bot->size();
            for (int i = 0; i < lenbot; i++) {
                buff->push(bot->peek());
                bot->pop();
            }
            T val = buff->peek();
            int lenbuff = buff->size();
            for (int i = 0; i < lenbuff; i++) {
                bot->push(buff->peek());
                buff->pop();
            }
            return val;
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
