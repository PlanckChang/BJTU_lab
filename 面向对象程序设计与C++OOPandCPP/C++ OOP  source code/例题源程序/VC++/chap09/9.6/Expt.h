#ifndef __EXPT_H__
#define __EXPT_H__

#include<iostream>
using namespace std;

class Expt
{
public:
	/*Expt(){ }
	~Expt(){ }*/
	const char * message() const
	{
		return "Expt类异常";
	}
};

class MyString
{
public:
	MyString(){ cout << "MyString的构造函数" << endl; }
	~MyString(){ cout << "MyString的析构函数" << endl; }
};

#endif