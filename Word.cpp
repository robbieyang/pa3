/*
 * Submit this file.
 * Implement all functions according to Word.h in this file.
 */
#include "Word.h"
#include <cmath>
using namespace std;

Word::Word(string _spelling, string _definition):spelling(_spelling),definition(_definition){

}

Word::Word(const Word& another){
	this->spelling = another.spelling;
	this->definition = another.definition;
}

int Word::hashFunction1(string& key){
	int hashvalue = 0;
	for (int i = 0; i < key.size(); i ++){
		hashvalue = hashvalue + key[i];
	}
	return hashvalue;
}

int Word::hashFunction2(string& key){
	int hashvalue = 0;
	for (int i = 0; i < 3; i++)
	{
		hashvalue = hashvalue + pow(27,i) * key[i];
	}
	return hashvalue;
}

int Word::hashFunction3(string& key){
	int hashvalue = 0;
	for (int i = 0; i < key.size(); i++)
	{
		hashvalue = hashvalue + pow(37,key.size()-1-i) * key[i];
	}
	return hashvalue;

}

ostream& operator<<(ostream& os, const Word& word)
{
	os << "\"" <<word.spelling << "\""<< " means "  << "\"" <<  word.definition << "\"";
	return os;
}
