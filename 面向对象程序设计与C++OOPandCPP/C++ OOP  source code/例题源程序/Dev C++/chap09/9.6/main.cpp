#include<iostream>
#include"expt.h"
using namespace std;

int main()
{
	MyString s;
	//cout << &s << endl;
	try
	{
		MyString str;
		//cout << &str << endl;
		throw Expt();
	}
	catch(Expt e)
	{ 
		//int i = 0;
		//cout << &i << endl;
		cout << /*&e <<*/ e.message() << endl;
	}
	catch(...)
	{
		cout << "���񵽲��������쳣..." << endl;
	}

	cout << "����ִ�г���..." << endl;

	return 0;
}
