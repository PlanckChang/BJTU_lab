#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<cstring> 
using namespace std;

class MyString
{
public:
	MyString();
	MyString(const MyString & str); // �������캯��
	/*explicit*/ MyString(const char * p);
	~MyString(); // ��������

	MyString & operator=(const MyString & str);
	MyString & operator=(const char * str);
	friend ostream & operator<<(ostream & o, const MyString & s);
	bool operator>(const MyString & s) const;
	bool operator<(const MyString & s) const;
public:
  const char * get_string() const;          // ȡ���ַ������׵�ַ
  const char * set_string(const char * p);  // �� p ָ����ַ���������MyString����
  int get_length() const{ return strlen(m_pbuf); }  // ȡ�ñ�����ַ����ĳ���

private:
  char * m_pbuf;
};

#endif 
