#include "Fish.h"

CFish::CFish(const char * s, int span, int h) : CAnimal(s, span), depth(h)
{
}

void CFish::print()
{
	cout << "CFish::print()函数被调用..." << endl;
	CAnimal::print();
	cout << "水的深度（米，-1表示未知）:  " << depth << endl;
}

void CFish::breathe()
{
	cout << "我在水中呼吸..." << endl;
}

