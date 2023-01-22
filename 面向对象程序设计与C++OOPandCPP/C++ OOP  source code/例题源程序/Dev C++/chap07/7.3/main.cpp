#include<iostream>
using namespace std;

class CBase
{
public:
	CBase(){ vprint(); }
	~CBase(){ vprint(); }
	virtual void vprint(){ cout << "CBase::vprint()" << endl; } 
	void print(){ vprint(); }
};

class CDerived : public CBase
{
public:
	CDerived(){ vprint(); }
	~CDerived(){ vprint(); }
	void vprint(){ cout << "CDerived::vprint()" << endl; }
};

int main()
{
	CDerived derived;
	CBase * pBase = &derived;
	pBase->vprint();
	pBase->print();

	return 0;
}