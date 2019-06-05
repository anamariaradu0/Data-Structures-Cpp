/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * Modificari: Cosmin Petrisor
  * Echipa SD, 2015
  *
  * Modificari: Cristian Creteanu
  * Echipa SD, 2017
  * 
  * Modificari: Ioana Stefan
  * Echipa SD, 2018
  * License: LGPL
  */

#ifndef HEAP_H
#define HEAP_H

#include<iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int numberOfElemets;
    int capacity;
public:
    Heap(int capacity) {
        // TODO BONUS
      this->values = new <T>[capacity];
    }
    ~Heap() {
        // TODO BONUS
      delete[] values;
    }

    int parent(int poz) {
        // TODO BONUS
      if (poz == 0) {
        return -1;
      } else {
        if (poz % 2 == 0) {
          return poz / 2 - 1;
        } else {
          return poz / 2;
        }
      }
     }
 
    int leftSubtree(int poz) {
        // TODO BONUS
      int leftPoz = 2 * poz + 1;
      if (leftPoz < capacity) {
        return leftPoz;
      }
      return -1;
    }
 
    int rightSubtree(int poz) {
        // TODO BONUS
      int rightPoz = 2 * poz + 2;
      if (rightPoz < capacity) {
        return rightPoz;
      }
      return -1;
    }
 
    void pushUp(int poz) {
        // TODO BONUS
      if (values[parent(poz)] > values[poz]) {
        swap
      }
    }
 
    void pushDown(int poz) {
        // TODO BONUS
    }
 
    void insert(T x) {
        // TODO BONUS
    }
 
    T peek() {
        // TODO BONUS
        return T();
    }
 
    T extractMin() {
        // TODO BONUS
        return T();
    }
};

#endif // HEAP_H
