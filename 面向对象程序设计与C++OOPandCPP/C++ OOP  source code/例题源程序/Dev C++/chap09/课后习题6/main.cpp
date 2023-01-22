#include<iostream>
#include<iomanip>
using namespace std;
class A
{
public:
	A() { cout << this << " A()" << endl; }
	A(const A & e) { cout << this << " A(const A &)" << endl; }
	virtual~A() { cout << this << " ~A()" << endl; }
};
class B : public A
{
public:
	B() { cout << this << " B()" << endl; }
	B(const B & e)
	{
		cout << this << " B(const B &)" << endl;
	}
	~B() { cout << this << " ~B()" << endl; }
};
class C : public B
{
public:
	C() { cout << "Expt2()" << endl; }
	C(const C & e) { cout << "C(const C &)" << endl; }
	~C() { cout << "~C()" << endl; }
};

void func() { 
	B e;	
	//cout << &e << endl;  
	throw e; 
}

int main() 
{	cout.setf(ios::uppercase);   
	try
	{
		try
		{
			B e;
			func();
		}
		catch (B e) 
		{ 
			cout << &e << "B�����쳣" << endl; 
			throw e; 
		}
		catch (C e) { cout << "C�����쳣" << endl; }
	}
	catch (A e) 
	{ 
		cout << &e << " A�����쳣" << endl; 
	}
	catch (B e) { cout << &e << " B�����쳣" << endl; }
	catch (C e) { cout << &e << " C�����쳣" << endl; }

	return 0;
}
