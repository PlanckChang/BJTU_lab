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
	cout << "CAnimal::print()����������..." << endl;
	cout << "����: " << name << endl;
	cout << "ƽ���������꣬-1��ʾδ֪��: " << lifespan << endl;
}
