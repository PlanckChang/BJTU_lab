#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const char * p);
	//MyString(const MyString & s);
	~MyString();
	//MyString & operator=(const MyString & s);

	const char * get_string() { return m_pbuf; }	// ȡ���ַ������׵�ַ
	const char * set_string(const char * p = NULL);	// �� p ָ����ַ���������MyString����
	const char * append(const char * p = NULL);		// �� p ָ����ַ���׷�ӵ�ԭ���ַ���֮��
	MyString & append(MyString & s);				// �� s �����е��ַ���׷�ӵ���ǰ������ַ���֮�󲢷��ض���
	int get_length() { return strlen(m_pbuf); }		// ȡ�ñ�����ַ����ĳ���

private:
	char * m_pbuf;
};

#endif