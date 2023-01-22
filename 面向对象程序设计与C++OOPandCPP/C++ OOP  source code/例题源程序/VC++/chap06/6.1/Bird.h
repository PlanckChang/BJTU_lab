#pragma once
#include "animal.h"

class CBird : public CAnimal
{
public:
	CBird(const char * s = "Bird", int span = -1, int h = -1);
	void print();
	void breathe();
	//void speak(int i);
private:
	int flyheight;  //飞行的高度
};
