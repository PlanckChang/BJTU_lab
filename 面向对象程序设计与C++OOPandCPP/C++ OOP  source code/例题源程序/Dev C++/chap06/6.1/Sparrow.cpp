#include "Sparrow.h"

CSparrow::CSparrow(const char * s, int span, int h) : CBird(s, span, h)
{
	cout << "CSparrow�Ĺ��캯��������..." << endl;
}

void CSparrow::speak()
{
	cout << "��..." << endl;
}
