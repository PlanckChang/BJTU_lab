#include"animal.h"
#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;

CAnimal::CAnimal(const char * s, int span) : name(s), lifespan(span)
{
}

void CAnimal::print()
{
	cout << "CAnimal::print()函数被调用..." << endl;
	cout << "名字: " << name << endl;
	cout << "平均寿命（年，-1表示未知）: " << lifespan << endl;
}
