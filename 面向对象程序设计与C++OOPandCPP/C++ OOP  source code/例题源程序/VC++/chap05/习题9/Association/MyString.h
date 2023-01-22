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

	const char * get_string() const { return m_pbuf; }	// ȡ���ַ������׵�ַ
	const char * set_string(const char * p = NULL);	// �� p ָ����ַ���������MyString����
	const char * append(const char * p = NULL);		// �� p ָ����ַ���׷�ӵ�ԭ���ַ���֮��
	MyString & append(MyString & s);				// �� s �����е��ַ���׷�ӵ���ǰ������ַ���֮�󲢷��ض���
	int get_length() const { return strlen(m_pbuf); }		// ȡ�ñ�����ַ����ĳ���

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