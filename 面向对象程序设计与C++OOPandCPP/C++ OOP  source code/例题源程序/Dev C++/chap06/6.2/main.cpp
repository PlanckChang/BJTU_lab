#include<iostream>

using namespace std;

class A1
{
public:
	A1(){ cout << "class A1的构造函数被调用..." << endl; }
};

class A2
{
public:
	A2() { cout << "class A2的构造函数被调用..." << endl; }
};

class Base
{
public:
	Base(){ cout << "class Base的构造函数被调用..." << endl; }
};

class Derived : public Base
{
	A1	 a1;
	A2   a2;
	Base base;
public:
	Derived() { cout << "class Derived的构造函数被调用..." << endl; }
};

int main()
{
	Derived derived;
	return 0;
}