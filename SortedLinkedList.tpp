/*
 * Submit this file.
 * Implement all functions according to SortedLinkedList.h in this file.
 */
#include "SortedLinkedList.h"

using namespace std;

template <typename T>
SortedLinkedList<T>::SortedLinkedList(){
		head = NULL;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList(){
	delete head;
}

template <typename T>
void SortedLinkedList<T>::add(string key, T* data){
	Node<T>* newNode = new Node<T>(key,data, NULL);
	Node<T>* p = head;
	for(head; p->next != NULL; p = p->next ){
		if(newNode->key > p -> key)
		{

		}
	}
}

template <typename T>
void SortedLinkedList<T>::remove(string key){

}

template <typename T>
Node<T>* SortedLinkedList<T>::get(string key){

}

template <typename T>
Node<T>* SortedLinkedList<T>::popHead(){

}

template <typename T>
void SortedLinkedList<T>::operator+=(const SortedLinkedList<T>& another){
}

template <typename S>
ostream& operator<<(ostream& os, const SortedLinkedList<S>& list)
{

}
