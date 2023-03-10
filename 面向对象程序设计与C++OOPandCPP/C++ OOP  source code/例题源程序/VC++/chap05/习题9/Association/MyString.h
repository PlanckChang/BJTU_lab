#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<fstream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const char * p);
	MyString(const MyString & s);
	~MyString();
	MyString & operator=(const MyString & s);

	const char * get_string() const { return m_pbuf; }	// 取得字符串的首地址
	const char * set_string(const char * p = NULL);	// 将 p 指向的字符串保存在MyString类中
	const char * append(const char * p = NULL);		// 将 p 指向的字符串追加到原有字符串之后
	MyString & append(MyString & s);				// 将 s 对象中的字符串追加到当前对象的字符串之后并返回对象
	int get_length() const { return strlen(m_pbuf); }		// 取得保存的字符串的长度

	ofstream & write_text(ofstream & out)
	{
		out << strlen(m_pbuf) << " " << m_pbuf;
		return out;
	}

	ifstream & read_text(ifstream & in)
	{
		delete[] m_pbuf;
		int len;
		in >> len;
		in.get();
		m_pbuf = new char[len + 1];
		in.read(m_pbuf, len);
		m_pbuf[len] = '\0';
		return in;
	}
private:
	char * m_pbuf;
};

#endif