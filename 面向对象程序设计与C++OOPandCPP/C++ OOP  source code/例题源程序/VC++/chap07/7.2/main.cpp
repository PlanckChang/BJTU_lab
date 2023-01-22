#include<iostream>
using namespace std;

class CBase
{
public:
	virtual void print(){ cout << "CBase::print()" << endl; } 
};

class CDerived : public CBase
{
public:
	//void print(){ cout << "CDerived::print()" << endl; }
	void print(int i){ cout << i << endl; }	
};

int main()
{
	CDerived derived;

	derived.print(0); // 此时调用的不是虚函数
	//derived.print();  // 此调用非法，因为基类的该函数被隐藏了

	CBase * pBase = &derived;
	pBase->print();  // 调用的是虚函数，因为通过基类指针看到的是基类的函数

	return 0;
}