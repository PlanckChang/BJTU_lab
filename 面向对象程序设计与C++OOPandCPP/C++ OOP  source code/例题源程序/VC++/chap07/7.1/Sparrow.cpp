#include "Sparrow.h"

CSparrow::CSparrow(const char * s, int span, int h) : CBird(s, span, h)
{
}

void CSparrow::speak()
{
	cout << "à±à±..." << endl;
}
