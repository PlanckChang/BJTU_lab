#include<iostream>
#include"expt.h"
using namespace std;

int main()
{
	try
	{
		MyString str;
		//cout << &str << endl;
		throw Expt();
	}
	catch(Expt e)
	{
		//cout << &e << endl;
		cout << e.message() << endl;
	}
	catch(...)
	{
		cout << "���񵽲��������쳣..." << endl;
	}

	cout << "����ִ�г���..." << endl;

	return 0;
}
