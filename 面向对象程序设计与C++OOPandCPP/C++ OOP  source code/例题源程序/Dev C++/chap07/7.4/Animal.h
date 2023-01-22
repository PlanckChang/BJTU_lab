#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include"MyString.h"

using namespace std;

class CAnimal
{
public:
	CAnimal(const char * s = "Animal", int span = -1);
	virtual void print() = 0;
	virtual void speak() = 0;
	virtual void breathe() = 0;
private:
	MyString name;
	int lifespan;
};

#endif