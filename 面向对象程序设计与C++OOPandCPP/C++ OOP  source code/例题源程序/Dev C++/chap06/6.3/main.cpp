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
		cout << "class Base的构造函数被调用..." << endl; 
	}

	/*virtual*/ ~Base()
	{
		delete [] p;
		cout << "class Base的析构函数被调用..." << endl; 
	}

	Base(const Base & base)
	{	
		p = new int[1024];
		for (int i = 0; i < 1024; i++)
			p[i] = base.p[i];
		cout << "class Base的复制构造函数被调用..." << endl;
	}

	Base & operator= (const Base & base)
	{
		if (this != &base)
		{	//由于p指向的内存大小不变，因此不必像MyString类的赋值运算符那样先回收内存再申请内存
			for (int i = 0; i < 1024; i++)
				p[i] = base.p[i];
		}
		cout << "class Base的赋值运算符函数被调用..." << endl;
		return *this;
	}
};

class Derived : public Base
{
	int * p;
	int num;
public:
	Derived(int n)  //要求n大于等于1
	{
		num = n * n;
		p = new int[num];
		for (int i = 0; i < num; i++)
			p[i] = i + n;
		cout << "class Derived的构造函数被调用..." << endl; 
	}

	~Derived()
	{
		delete [] p;
		cout << "class Derived的析构函数被调用..." << endl; 
	}

	Derived(const Derived & derived) : Base(derived)
	{	
		num = derived.num;
		p = new int[num];
		for (int i = 0; i < num; i++)
			p[i] = derived.p[i];
		cout << "class Derived的复制构造函数被调用..." << endl;
	}

	Derived & operator= (const Derived & derived)
	{
		if (this != &derived)
		{
			Base::operator=(derived);		//基类的数据由基类的赋值运算符负责复制
			delete [] p;
			num = derived.num;
			p = new int[num];
			for (int i = 0; i < num; i++)
				p[i] = derived.p[i];
		}
		cout << "class Derived的赋值运算符函数被调用..." << endl;
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
