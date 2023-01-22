#pragma once
#include "Animal.h"
class CFish : public CAnimal
{
public:
	CFish(const char * s = "Fish", int span = -1, int h = -1);
	void print();
	void breathe();
private:
	int depth;  //水的深度
};

