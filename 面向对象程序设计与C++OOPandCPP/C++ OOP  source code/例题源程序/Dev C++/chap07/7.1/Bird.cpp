#include "Bird.h"

CBird::CBird(const char * s, int span, int h) : CAnimal(s, span), flyheight(h)
{
}

void CBird::print()
{
	cout << "CBird::print()函数被调用..." << endl;
	CAnimal::print();
	cout << "飞行高度（米，-1表示未知）:  " << flyheight << endl;
}

void CBird::breathe()
{
	cout << "我在空中呼吸..." << endl; 
}

