#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <list>
#include <iterator>

template <typename Tkey, typename Tvalue> struct info {
  Tkey key;
  Tvalue value;
};

template <typename Tkey, typename Tvalue> class Hashtable {
private:
  

public:
  std::list<struct info<Tkey, Tvalue>> *H;
  int size;
  int capacity;
  int (*hash)(Tkey);
  
  Hashtable(int capacity, int (*h)(Tkey)) {
    /* TODO */
    size = 0;
    this->capacity = capacity;
    H = new std::list<struct info<Tkey, Tvalue>>[capacity];
    this->hash = h;
  }

  ~Hashtable() {
    /* TODO */
    delete[] H;
  }

  void put(Tkey key, Tvalue value) {
    /* TODO */
    int index = hash(key);
    index %= capacity;
    typename std::list<struct info<Tkey, Tvalue>>::iterator it;
    for (it = H[index].begin(); it != H[index].end(); ++it) {
      if (it->key == key) {
        it->value = value;
        return;
      }
    }
    struct info<Tkey, Tvalue> temp;
    temp.key = key;
    temp.value = value;
    H[index].push_back(temp);
    size++;
  }

  void remove(Tkey key) {
    /* TODO */
    int index = hash(key);
    index %= capacity;
    typename std::list<struct info<Tkey, Tvalue>>::iterator it;
    for (it = H[index].begin(); it != H[index].end(); ++it) {
      if (it->key == key) {
        it = H[index].erase(it);
        size--;
        return;
      }
    }
  }

  Tvalue get(Tkey key) {
    /* TODO */
    int index = hash(key);
    index %= capacity;
    typename std::list<struct info<Tkey, Tvalue>>::iterator it;
    for (it = H[index].begin(); it != H[index].end(); ++it) {
      if (it->key == key) {
        return it->value;
      }
    }
    return Tvalue{};
  }

  bool has_key(Tkey key) {
    /* TODO */
    int index = hash(key);
    index %= capacity;
    typename std::list<struct info<Tkey, Tvalue>>::iterator it;
    for (it = H[index].begin(); it != H[index].end(); ++it) {
      if (it->key == key) {
        return true;
      }
    }
    return false;
  }

  std::list<struct info<Tkey, Tvalue>>* getHashtable() {
    return H;
  }

  int get_size() {
    return size;
  }

  int get_capacity() {
    return capacity;
  }

  void print_hashtable() {

    for (int i = 0; i < capacity; i++) {
      std::cout << "HASH = " << i << ": ";
      typename std::list<struct info<Tkey, Tvalue>>::iterator it;

      for (it = H[i].begin(); it != H[i].end(); it++) {
        std::cout << it->value << " | ";
      }

      std::cout << "\n";
    }
  }
};

#endif
