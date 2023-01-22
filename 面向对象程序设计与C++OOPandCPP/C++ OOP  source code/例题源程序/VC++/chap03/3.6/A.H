#ifndef __A_H__
#define __A_H__

class B;
class A
{
public:
	int A_fun(B b){ return b.j; }
public:
	int i;
};

class B
{
public:
	int B_fun(A a);
public:
	int j;
};

#endif