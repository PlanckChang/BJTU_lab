#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
using namespace std;

class MyString
{
	static int total;
public:
	MyString();
	MyString(const char * p);
	MyString(const MyString & s);
	~MyString();
	MyString & operator=(const MyString & s);

	const char * get_string() const { return m_pbuf; }     // ȡ���ַ������׵�ַ
    const char * set_string(const char * p = NULL); // �� p ָ����ַ���������MyString����
    const char * append(const char * p = NULL);     // �� p ָ����ַ���׷�ӵ�ԭ���ַ���֮��
    MyString & append(MyString & s);  // �� s �����е��ַ���׷�ӵ���ǰ������ַ���֮�󲢷��ض���
	int get_length() const { return strlen(m_pbuf); }  // ȡ�ñ�����ַ����ĳ���

	static int get_total() { return total; }

	// ���������
	MyString operator+(const MyString & s) const;
	//MyString & operator=(const char * p);
	char & operator [] (const int idx);
	char operator[] (const int idx) const;
	MyString & operator() (const char * p);
	MyString & operator() (const char * p, int n);
	operator const char * () const { return m_pbuf; }

	friend MyString operator+(const MyString & str, char * s/* = NULL*/);
	//friend MyString operator+(const MyString & s, const MyString & str);
private:
    char * m_pbuf;
};

#endif 
