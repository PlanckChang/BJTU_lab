#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<fstream>
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
	MyString operator+(const MyString & s);
	MyString & operator=(const char * p);
	char & operator [] (const unsigned int idx);
	char operator[] (const unsigned int idx) const;
	MyString & operator() (const char * p);
	operator const char * () const { return m_pbuf; }

	// ���ز��������ȡ��
	friend ostream & operator << (ostream & out, const MyString & str);

	// ��������뺯��
	ofstream & write(ofstream & o);
	ifstream & read(ifstream & in);
private:
	char * m_pbuf;
};

#endif 

