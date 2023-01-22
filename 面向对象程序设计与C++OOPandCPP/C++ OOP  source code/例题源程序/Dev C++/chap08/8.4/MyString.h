#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<cstring> 
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const MyString & str); // 拷贝构造函数
	/*explicit*/ MyString(const char * p);
	~MyString(); // 析构函数

	MyString & operator=(const MyString & str);
	MyString & operator=(const char * str);
	friend ostream & operator<<(ostream & o, const MyString & s);
	bool operator>(const MyString & s) const;
	bool operator<(const MyString & s) const;
public:
  const char * get_string() const;          // 取得字符串的首地址
  const char * set_string(const char * p);  // 将 p 指向的字符串保存在MyString类中
  int get_length() const{ return strlen(m_pbuf); }  // 取得保存的字符串的长度

private:
  char * m_pbuf;
};

#endif 
