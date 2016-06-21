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
	Node<T>* p = this->head;
	Node<T>* temp = NULL;
	while(p != NULL)
	{
		temp = p->next;
		delete p;
		p = temp;
	}
}

template <typename T>
void SortedLinkedList<T>::add(string key, T* data){
	Node<T>* newNode = new Node<T>(key,data, NULL);
	Node<T>* p = this->head;
	if (head == NULL || p->key > newNode->key){
		head = newNode;
		newNode->next = p;
	}
	else{
		while ((p->next!= NULL) && (p->next->key < newNode->key))
		{
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}



}

template <typename T>
void SortedLinkedList<T>::remove(string key){
	Node<T>* prev = NULL;
	Node<T>* curr = this->head;
	if (head == NULL)
		return;
	if (head->key == key){
		head = head->next;
		return;
	}
	while(curr != NULL && curr->key != key)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr != NULL)
	{
		prev->next = curr->next;
		delete curr;
	}

}

template <typename T>
Node<T>* SortedLinkedList<T>::get(string key){

	if (head == NULL) return NULL;
	Node<T>* p = this->head;
	while(p != NULL && p->key != key)
	{
		p = p->next;
	}
	return p;
}

template <typename T>
Node<T>* SortedLinkedList<T>::popHead(){
	if (head == NULL) return NULL;
	Node<T>* temp = head;
	head = head->next;

	return temp;

}

template <typename T>
void SortedLinkedList<T>::operator+=(const SortedLinkedList<T>& another){
	Node<T>* p = another.head;
	Node<T>* newNode = new Node<T>(p->key,p->data, NULL);
	T* newData;
	if (newNode->key  < this->head->key)
	{
		newNode->next = this->head;
		this->head = newNode;
	}
	p = p->next;
	for (; p != NULL; p = p->next){
		newData = new T(*p->data);
		this->add(p->key,newData);
	}
}

/*template <typename T, typename K>
ostream& operator<< (ostream& os, const SortedLinkedList<K>& list)
{
	if(list.head == NULL){
		os << "The linked list is empty" << endl;
		return os;
	}
	Node<K>* p = list.head;
	for (;p != NULL; p = p->next){
		os << p->key;
	}

	return os;
}*/
