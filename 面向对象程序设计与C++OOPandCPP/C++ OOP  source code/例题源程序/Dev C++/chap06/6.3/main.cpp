#include<iostream>

using namespace std;

class Base
{
	int * p;
public:
	Base()
	{
		p = new int[1024];
		for (int i = 0; i < 1024; i++)
			p[i] = i;
		cout << "class Base�Ĺ��캯��������..." << endl; 
	}

	/*virtual*/ ~Base()
	{
		delete [] p;
		cout << "class Base����������������..." << endl; 
	}

	Base(const Base & base)
	{	
		p = new int[1024];
		for (int i = 0; i < 1024; i++)
			p[i] = base.p[i];
		cout << "class Base�ĸ��ƹ��캯��������..." << endl;
	}

	Base & operator= (const Base & base)
	{
		if (this != &base)
		{	//����pָ����ڴ��С���䣬��˲�����MyString��ĸ�ֵ����������Ȼ����ڴ��������ڴ�
			for (int i = 0; i < 1024; i++)
				p[i] = base.p[i];
		}
		cout << "class Base�ĸ�ֵ���������������..." << endl;
		return *this;
	}
};

class Derived : public Base
{
	int * p;
	int num;
public:
	Derived(int n)  //Ҫ��n���ڵ���1
	{
		num = n * n;
		p = new int[num];
		for (int i = 0; i < num; i++)
			p[i] = i + n;
		cout << "class Derived�Ĺ��캯��������..." << endl; 
	}

	~Derived()
	{
		delete [] p;
		cout << "class Derived����������������..." << endl; 
	}

	Derived(const Derived & derived) : Base(derived)
	{	
		num = derived.num;
		p = new int[num];
		for (int i = 0; i < num; i++)
			p[i] = derived.p[i];
		cout << "class Derived�ĸ��ƹ��캯��������..." << endl;
	}

	Derived & operator= (const Derived & derived)
	{
		if (this != &derived)
		{
			Base::operator=(derived);		//����������ɻ���ĸ�ֵ�����������
			delete [] p;
			num = derived.num;
			p = new int[num];
			for (int i = 0; i < num; i++)
				p[i] = derived.p[i];
		}
		cout << "class Derived�ĸ�ֵ���������������..." << endl;
		return *this;
	}
};

int main()
{
	{
		Derived derived1(1);
	}
	Base * p_Base = new Derived(1);
	delete p_Base;

	return 0;
}
