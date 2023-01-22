#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include"MyString.h"

using namespace std;

class CAnimal
{
public:
	CAnimal(const char * s = "Animal", int span = -1);
	virtual void print();
	virtual void speak();
	virtual void breathe();
private:
	MyString name;
	int lifespan;
};

#endif