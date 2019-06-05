#ifndef __TRIE_H
#define __TRIE_H
 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

int ALPHABET_SIZE = 26;

template <typename T>
class Trie
{
 private:
    int count;
    std::vector<Trie<T> *> children;
    T value;
    bool isEndOfWord;
  public:
    Trie() {}
    
    Trie(int capacity, T value)
      : count(0),
        children(capacity, NULL),
        value(value) { }
        
    Trie(int capacity)
      : count(0),
        children(capacity, NULL) { }
        
    ~Trie() {}
 	void insert(std::string key, T value) {
		// TODO 1 implementati functia de inserare in Trie
        int len_key = key.size();
        if (len_key == 0) {
            this->value = value;
            isEndOfWord = true;
            return;
        }

        Trie<T> *&nextNode = children[key[0] - 'a'];
        int capacity = children.size();
        if (children[key[0] - 'a'] == NULL) {
            nextNode = new Trie<T>(capacity);
            count++;
        }

        key.erase(key.begin());
        nextNode->insert(key, value);
    }
	bool search(std::string key, T &val) {
 		// TODO 1 implementati functia de cautare in Trie
        int len_key = key.size();
        if (len_key == 0) {
            val = this->value;
            return isEndOfWord;
        }
        Trie<T> *nextNode = children[key[0] - 'a'];

        int capacity = children.size();
        if (nextNode == NULL) {
            return false;
        }

        key.erase(key.begin());
        return nextNode->search(key, val);
    }

    bool remove(std::string key) {
    	// TODO 2 implementati functia de stergere din Trie
        int len_key = key.size();
        if (len_key == 0) {
            this->value = 0;
            isEndOfWord = false;
            if (count == 0) {
                return true;
            }
        }

        Trie<T> *&nextNode = children[key[0] - 'a'];
        // std::cout << "KEYUL " << key << '\n';
        if (nextNode != NULL) {
            // std::cout << "YE " << key << " " << nextNode->count <<'\n';
            if (nextNode->remove(key.substr(1, key.size() - 1))) {
                // std::cout << "ASA-> "<< key << "\n";
                delete nextNode;
                nextNode = NULL;
                count--;
                if (count == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int numWordsWithPrefix(std::string prefix) {
    	// TODO BONUS implementati gasirea numarului de cuvinte din Trie avand prefixul dat
        return 0;
    }
  
};
#endif
