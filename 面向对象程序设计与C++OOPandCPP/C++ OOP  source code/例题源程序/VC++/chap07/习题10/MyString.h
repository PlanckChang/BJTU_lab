#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include<iostream>
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
	const char * set_string(const char * p = NULL);		// �� p ָ����ַ���������MyString����
	const char * append(const char * p = NULL);			// �� p ָ����ַ���׷�ӵ�ԭ���ַ���֮��
	MyString & append(MyString & s);					// �� s �����е��ַ���׷�ӵ���ǰ������ַ���֮�󲢷��ض���
	int get_length() const { return strlen(m_pbuf); }	// ȡ�ñ�����ַ����ĳ���

	static int get_total() { return total; }

	char & operator[](const int idx) 
	{
		return m_pbuf[idx];
	}

	char operator[](const int idx) const
	{
		return m_pbuf[idx];
	}

	MyString & MyString::operator()(
		const char * p)
	{
		set_string(p);
		return *this;
	}

	operator const char * ()
	{
		return m_pbuf;
	}

	MyString & read_text(istream & in);		// �ı�ģʽ��ȡ����
	MyString & read_binary(istream & in);	// ������ģʽ��ȡ����
	void write_text(ostream & o);			// �ı�ģʽ�������
	void write_binary(ostream & o);			// ������ģʽ�������
	friend ostream & operator<< (ostream & o, const MyString & s);	// ��������ı�ģʽ
private:
	char * m_pbuf;
	static int count;
};

#endif
