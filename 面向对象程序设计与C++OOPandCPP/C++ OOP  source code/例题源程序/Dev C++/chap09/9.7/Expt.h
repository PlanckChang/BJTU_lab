#ifndef __EXPT_H__
#define __EXPT_H__

#include<iostream>
using namespace std;

class Expt
{
public:
	const char * message() const
	{
		return "Expt���쳣";
	}
};

class MyString
{
public:
	MyString(){ cout << "MyString�Ĺ��캯��" << endl; throw Expt(); }
	~MyString(){ cout << "MyString����������" << endl; }
};

#endif