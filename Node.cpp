/*
 * Submit this file.
 * Implement all functions according to Node.h in this file.
 */

#include "Node.h"
using namespace std;

template <typename T>
Node<T>::Node(string _key, T* _data, Node<T>* _next):key(_key), data(_data), next(_next){
}

template <typename T>
Node<T>::~Node()
{
	delete data;
	data = NULL;
}
template <typename T>
ostream& operator<< (ostream& os, const SortedLinkedList<T>& list)
{
	Node<T>* p = list.head;
	for (;p != NULL; p = p->next){
		os << *p->data << endl;
	}
	return os;
}
