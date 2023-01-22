#pragma once
#include "bird.h"


class CSparrow : public CBird
{
public:
	CSparrow(const char * s = "Sparrow", int span = 3, int h = 30);
	void speak();
};
