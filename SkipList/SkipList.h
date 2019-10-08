// Copyright 2019 Ana-Maria Radu, 314CA
// SkipList.h
// Purpose: implementing a SkipList structure to sort the given input

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include "Racer.h"
#include <string>

template <typename T>
class Node {
	public:
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node<T>* below;
	Node<T>* above;
	bool isHead;

	// Constructor
	Node() {
		prev = nullptr;
		next = nullptr;
		below = nullptr;
		above = nullptr;
	}

	// Explicit constructor
	explicit Node(T data) {
		this->data = data;
		prev = nullptr;
		next = nullptr;
		below = nullptr;
		above = nullptr;
	}
};

template <typename T>
class SkipList {
	int highest_level;
	int num_of_values;
	Node<T>* head;

 public:
	// Constructor
	explicit SkipList(int highest_level) {
		this->highest_level = highest_level;
		head = new Node<T>();
		Node<T>* p = head;
		Node<T>* r = p;
		p->isHead = true;
		for (int i = highest_level; i >= 1; --i) {
			p->below = new Node<T>();
			r = p;
			p = p->below;
			p->above = r;
			r = p;
			p->isHead = true;
		}
	}

	// Destructor
	~SkipList() {
		Node<T>* h = head;
		Node<T>* r;
		Node<T>* d;

		while (h != nullptr) {
			r = h->next;
			while (r != nullptr) {
				d = r;
				r = r->next;
				delete d;
			}

			h->next = nullptr;
			h = h->below;
		}

		Node<T>* x = head;
		Node<T>* y;
		while (x->below) {
			y = x;
			x = x->below;
			delete y;
		}

		delete x;
		delete h;
	}

	// Deleting all data from a list except the column of heads
	void skip_delete() {
		Node<T>* h = head;
		Node<T>* r;
		Node<T>* d;

		while (h != nullptr) {
			r = h->next;
			while (r != nullptr) {
				d = r;
				r = r->next;
				delete d;
			}

			h->next = nullptr;
			h = h->below;
		}
	}

	// Returning the head of the list, which is the highest node to the left
	Node<T>* get_head() {
		return head;
	}

	// Returning the first element of a list, which is the first non-head node
	// from the first level
	Node<T>* get_first_element() {
		Node<T>* h = head;
		while (h->below != nullptr) {
            h = h->below;
        }

        if (h->next != nullptr) {
            h = h->next;
        }

        return h;
	}

	// Searching method
	Node<T>* skip_search(T data) {
		Node<T>* p = head;

		while (p->below != nullptr) {
			while (p->next != nullptr && data >= p->next->data) {
				p = p->next;
			}
			p = p->below;
		}
		while (p->next != nullptr && data >= p->next->data) {
			p = p->next;
		}
		return p;
	}

	// Insertion method
	Node<T>* skip_insert(T data) {
		Node<T>* p = skip_search(data);
		Node<T>* r = nullptr;

		++num_of_values;
		int level = 0;
		Node<T>* q  = skip_insert_after(data, p);

		while (coin_flip() == "Heads" && level < highest_level) {
			while(p->above == nullptr) {
				if(p->prev) {
					p = p->prev;
				}
			}
			if (p->above) {
				p = p->above;
				r = skip_insert_after(data, p);
				r->below = q;
		        q->above = r;
		        q = r;
				++level;
			}
		}

		++num_of_values;
		return q;
	}

	// Auxiliary insertion method
	Node<T>* skip_insert_after(T data, Node<T>* p) {
		Node<T>* new_node = new Node<T>(data);

		if (p->next) {
			p->next->prev = new_node;
			new_node->next = p->next;
		    p->next = new_node;
		    new_node->prev = p;
		} else {
			p->next = new_node;
			new_node->prev = p;
		}
		return new_node;
	}

	// Delete method; it deletes the entire column of nodes that contain 'data'
	void skip_delete_data(T data) {
		Node<T>* p = skip_search(data);
		Node<T>* q;

		while(p != nullptr) {
			q = p;
			p = p->above;

			if (q->prev) {
				q->prev->next = q->next;
			}

			if (q->next) {
				q->next->prev = q->prev;
			}

			delete q;
		}

		--num_of_values;
	}

	// Printing from the lowest to the highest level
	void skip_print(std::ostream &out) {
		Node<T>* a = head;

		while(a->below) {
			a = a->below;
		}

		Node<T>* p = a;

		for(int i = 0; i <= highest_level; ++i) {
			out << "Level is: " << i << " and nodes are: ";

			while (a != nullptr) {
				if (a->isHead != true) {
					out << a->data << " ";
				}
				a = a->next;
			}

			a = p->above;
			p = p->above;

			out << std::endl;
		}
	}

	// Coin flip method, with a lower probability of returning high levels
	std::string coin_flip() {
		std::random_device random_dev;
		std::mt19937 random_eng{random_dev()};
		std::bernoulli_distribution coin_probability{0.50};

		bool coin_result = coin_probability(random_eng);

		if (coin_result % 2 == 1) {
			return "Tails";
		}

		return "Heads";
	}
};

#endif  // SKIPLIST_H_
