#include "Fish.h"

CFish::CFish(const char * s, int span, int h) : CAnimal(s, span), depth(h)
{
}

void CFish::print()
{
	cout << "CFish::print()����������..." << endl;
	CAnimal::print();
	cout << "ˮ����ȣ��ף�-1��ʾδ֪��:  " << depth << endl;
}

void CFish::breathe()
{
	cout << "����ˮ�к���..." << endl;
}

