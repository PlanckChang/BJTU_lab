#include "Sparrow.h"

CSparrow::CSparrow(const char * s, int span, int h) : CBird(s, span, h)
{
	cout << "CSparrow的构造函数被调用..." << endl;
}

void CSparrow::speak()
{
	cout << "啾啾..." << endl;
}
