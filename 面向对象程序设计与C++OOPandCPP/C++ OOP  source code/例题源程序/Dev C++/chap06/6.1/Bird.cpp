#include "Bird.h"

CBird::CBird(const char * s, int span, int h) : CAnimal(s, span), flyheight(h)
{
	cout << "CBird�Ĺ��캯��������..." << endl;
}

void CBird::print()
{
	cout << "CBird::print()����������..." << endl;
	CAnimal::print();
	cout << "���и߶ȣ��ף�-1��ʾδ֪��:  " << flyheight << endl;
}

void CBird::breathe()
{
	cout << "���ڿ��к���..." << endl; 
}

//void CBird::speak(int num)
//{
//	for (int i = 0; i < num; i++)
//		cout << "�Ҳ�֪������ô��..." << endl;
//}
