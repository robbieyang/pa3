/*
 * Submit this file.
 * Implement all functions according to Inventor.h in this file.
 */

#include "Inventor.h"
#include <cmath>
using namespace std;

Inventor::Inventor(string _firstName, string _lastName, string _invention):firstName(_firstName),lastName(_lastName),invention(_invention){

}

Inventor::Inventor(const Inventor& another)
{
	this->firstName = another.firstName;
	this->lastName = another.lastName;
	this->invention = another.invention;
}

int Inventor::hashFunction(string& key)
{
	int hashvalue;
	int temp;
	int cnt = 0;
	int size = key.size();

	int j;
	for (int i = 2; i < 100; i++)
	{
		temp = 0;
		for (j = 2; j <= sqrt(i); j ++)
		{
			if (i % j == 0)
			{
				temp ++;
			}
			if (temp == 1)
			{
				break;
			}
		}
		if (temp == 0)
		{
			cnt ++;
		}
		if (cnt == size){
			hashvalue = i;
			break;
		}

	}
	return hashvalue;

}

ostream& operator<<(ostream& os, const Inventor& inventor)
{
	os << inventor.firstName << " " << inventor.lastName << " invented " << inventor.invention << "!";
	return os;
}
