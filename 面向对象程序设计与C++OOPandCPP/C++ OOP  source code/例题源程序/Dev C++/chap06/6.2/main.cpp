#include<iostream>

using namespace std;

class A1
{
public:
	A1(){ cout << "class A1�Ĺ��캯��������..." << endl; }
};

class A2
{
public:
	A2() { cout << "class A2�Ĺ��캯��������..." << endl; }
};

class Base
{
public:
	Base(){ cout << "class Base�Ĺ��캯��������..." << endl; }
};

class Derived : public Base
{
	A1	 a1;
	A2   a2;
	Base base;
public:
	Derived() { cout << "class Derived�Ĺ��캯��������..." << endl; }
};

int main()
{
	Derived derived;
	return 0;
}