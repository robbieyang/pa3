/*
 * Submit this file.
 * Implement all functions according to Dictionary.h in this file.
 */

#include "Dictionary.h"

using namespace std;

template <typename T>
Dictionary<T>::Dictionary(int _size, int(*_hashFunction)(string&)):size(_size){
	table = new SortedLinkedList<T>[_size];
	this->hashFunction = _hashFunction;
}

template <typename T>
Dictionary<T>::Dictionary(const Dictionary<T>& dictionary2){
	this->size = dictionary2.size;
	this->hashFunction = dictionary2.hashFunction;
	this->table = new T[dictionary2.size];
	for (int i = 0;i < dictionary2.size; i++)
	{
		this->table[i] = dictionary2.table[i];
	}
}

template <typename T>
Dictionary<T>::~Dictionary()
{
	delete [] table;
}

template <typename T>
void Dictionary<T>::add(string key, T* data)
{
	int hashvalue;
	hashvalue = this->hashFunction(key) % size;
	T* newData = new T(*data);
	this->table[hashvalue].add(key, newData);

}

template <typename T>
void Dictionary<T>::remove(string key){
	int hashvalue;
	hashvalue = this->hashFunction(key) % size;
	this->table[hashvalue].remove(key);
}

template <typename T>
T* Dictionary<T>::lookup(string key){
	int hashvalue;
	hashvalue = this->hashFunction(key) % size;
	if(this->table[hashvalue].get(key) != NULL)
	{
		return (this->table[hashvalue].get(key)->data);
	}
	return NULL;
}

template <typename T>
void Dictionary<T>::resize(int newSize){
	if (this->size == newSize)
		return;

	SortedLinkedList<T>* tempTable = new SortedLinkedList<T>[newSize];
	int hashvalue;
	Node<T> *p;
	for (int i = 0; i < size; i++)
	{
		p = table[i].popHead();
		while(p!=NULL){
			hashvalue = this->hashFunction(p->key) % newSize;
			T* newData = new T(*p->data);
			tempTable[hashvalue].add(p->key,newData);
			p = p->next;
		}
	}
	this->size = newSize;
	delete [] table;
	table = tempTable;





}

template <typename T>
void Dictionary<T>::changeHashFunction(int(*_hashFunction)(string&)){
	if(this->hashFunction == _hashFunction)
		return;
	this->hashFunction = _hashFunction;
	SortedLinkedList<T>* tempTable = new SortedLinkedList<T>[this->size];
	int hashvalue;
	Node<T>* p;
	for (int i = 0; i < this->size; i++)
	{
		p = table[i].popHead();
		while(p!=NULL){
			hashvalue = this->hashFunction(p->key) % size;
			T* newData = new T(*p->data);
			tempTable[hashvalue].add(p->key,newData);
			p = p->next;
		}

	}
	delete [] table;
	table = tempTable;

}

template <typename T>
void Dictionary<T>::operator+=(const Dictionary<T>& another){
	this->resize(this->size);

	for (int j = 0; j < another.size; j ++)
	{
		SortedLinkedList<T>  p = another.table[j];
		Node<T>* temp = p.popHead();
		for (; temp != NULL; temp = temp ->next){
			this->add(temp->key,temp->data);
		}
	}

}
