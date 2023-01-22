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
		cout << "捕获到不明类型异常..." << endl;
	}

	cout << "继续执行程序..." << endl;

	return 0;
}
