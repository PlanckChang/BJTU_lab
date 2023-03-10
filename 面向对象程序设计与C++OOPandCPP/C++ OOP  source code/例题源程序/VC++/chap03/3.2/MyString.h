// file: MyString.h
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
using namespace std;

class MyString
{
public:
	//MyString();
	const char * get_string() { return m_pbuf; }	// 取得字符串的首地址
	const char * set_string(const char * p = NULL);	// 将 p 指向的字符串保存在MyString类中
	const char * append(const char * p = NULL);		// 将 p 指向的字符串追加到原有字符串之后
	MyString & append(MyString & s);				// 将 s 对象中的字符串追加到当前对象的字符串之后并返回对象
	int get_length() { return strlen(m_pbuf); }		// 取得保存的字符串的长度
private:
	char * m_pbuf;
};

#endif