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

	derived.print(0); // ��ʱ���õĲ����麯��
	//derived.print();  // �˵��÷Ƿ�����Ϊ����ĸú�����������

	CBase * pBase = &derived;
	pBase->print();  // ���õ����麯������Ϊͨ������ָ�뿴�����ǻ���ĺ���

	return 0;
}