#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<cstring> 
using namespace std;

class MyString
{
	static int total;    // �˴�����Ϊ˽�����ݳ�Ա
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
	int get_length() const;// { return strlen(m_pbuf); }		// ȡ�ñ�����ַ����ĳ���

	static int get_total() { return total; }
private:
	char * m_pbuf;
};

inline void fun() {}

#endif
