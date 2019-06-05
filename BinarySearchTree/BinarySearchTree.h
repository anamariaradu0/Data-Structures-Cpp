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

#ifndef __BINARY_SEARCH_TREE__H
#define __BINARY_SEARCH_TREE__H

#include <iostream> 

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() {
        // TODO 1.1
      leftNode = nullptr;
      rightNode = nullptr;
      parent = nullptr;
      pData = nullptr;
    }
    ~BinarySearchTree() {
        // TODO 1.2
      if (pData != nullptr) {
        delete pData;
        pData = nullptr;
      }
      if (leftNode != nullptr) {
        delete leftNode;
        leftNode = nullptr;
      }
      if (rightNode != nullptr) {
        delete rightNode;
        rightNode = nullptr;
      }
      if (parent != nullptr) {
        delete parent;
        parent = nullptr;
      }
    }
    
    bool isEmpty() {
        return (pData == nullptr);
    }
 
    void insertKey(T x) {
        // TODO 1.3
      if (pData == nullptr) {
        pData = new T{};
        *(pData) = x;
      }  else {
        if (x < *(this->pData)) {
          if (this->leftNode != nullptr) {
            this->leftNode->insertKey(x);
          } else {
            this->leftNode = new BinarySearchTree<T>{};
            this->leftNode->pData = new T{};
            *(this->leftNode->pData) = x;
            this->leftNode->parent = this;
          }
        } else {
          if (rightNode != nullptr) {
            this->rightNode->insertKey(x);
          } else {
            this->rightNode = new BinarySearchTree<T>{};
            this->rightNode->pData = new T{};
            *(this->rightNode->pData) = x;
            this->rightNode->parent = this;
          }
        }
      }
    }
    
    BinarySearchTree<T>* searchKey(T x) {
        // TODO 1.4
      std::cout << '\n';
      if (pData != nullptr) {
        std::cout << *(pData) << " " << x <<  '\n';
        if (x == *(pData)) {
          std::cout << "-->DAAAA<--\n";
          return this;
        } else if (x < *(this->pData)) {
          if (this->leftNode != nullptr) {
            return this->leftNode->searchKey(x); 
          }
        } else {
          if (this->rightNode != nullptr) {
            return this->rightNode->searchKey(x);
          }
        }
      }
      return nullptr;
    }
    
    std::vector<T> inOrderDisplay() {
        // TODO 1.5
        std::vector<T> res;
        inOrderAdd(res);
        return res;
    }
    
    void inOrderAdd(std::vector<T> &v) {
      if (pData == nullptr) {
        return;
      } else {
        if (this->leftNode != nullptr) {
          this->leftNode->inOrderAdd(v);
        }
        v.push_back(*(this->pData));
        if (this->rightNode != nullptr) {
          this->rightNode->inOrderAdd(v);
        }
      }
    }

    T findMin() {
        // TODO 2
        return T();
    }
    
    T findMax() {
        // TODO 2
        return T();
    }

    int findLevels() {
        // TODO 3
        return 0;
    }
    
    std::vector<T> displayLevel(int level) {
        // TODO 3
        std::vector<T> res;
        return res;
    }
    
    BinarySearchTree<T>* removeKey(T x) {
        // TODO 4
        return nullptr;
    }
 
private:
    BinarySearchTree<T> *leftNode;
    BinarySearchTree<T> *rightNode;
    BinarySearchTree<T> *parent;
    T *pData;
};
 
#endif // __BINARY_SEARCH_TREE_H

