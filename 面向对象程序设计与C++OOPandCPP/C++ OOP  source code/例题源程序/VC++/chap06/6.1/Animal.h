#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include"MyString.h"

using namespace std;

class CAnimal
{
public:
	CAnimal(const char * s = "Animal", int span = -1);
	//~CAnimal() { cout << "CAnimal的析构函数被调用..." << endl; }
	/*virtual*/ void print();
	/*virtual*/ void speak();
	/*virtual*/ void breathe();
private:
	MyString name;
	int lifespan;
};

#endif