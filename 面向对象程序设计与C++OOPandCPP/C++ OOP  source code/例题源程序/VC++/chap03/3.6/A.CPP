#include"A.h"

int A::A_fun(B b)
{
	return b.j;
}

int B::B_fun(A a)
{
	return a.i;
}