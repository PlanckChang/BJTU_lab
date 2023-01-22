#include "MyString.h"

int MyString::total = 0;

inline int MyString::get_length() const { return strlen(m_pbuf); }

MyString::MyString()
{
	total++;
	m_pbuf = new char('\0');
	//cout << "MyString��Ĭ�Ϲ��캯��������" << endl;
}

MyString::MyString(const char * p)
{
	total++;
	if (NULL == p)
		m_pbuf = new char('\0');
	else
	{
		int len = strlen(p) + 1;
		m_pbuf = new char[len];
		strcpy_s(m_pbuf, len, p);
	}

	//cout << "MyString���вι��캯��������" << endl;
}

MyString::MyString(const MyString & s)
{
	total++;
	int len = strlen(s.m_pbuf) + 1;
	m_pbuf = new char[len];
	strcpy_s(m_pbuf, len, s.m_pbuf);
	//cout << "MyString�ĸ��ƹ��캯��������" << endl;
}

MyString::~MyString()
{
	total--;
	delete [] m_pbuf;
	//cout << "MyString����������������" << endl;
}

MyString & MyString::operator=(const MyString & s)
{
    if(this != &s)  // ��ֹ�Ը�ֵ
    {
        delete [] m_pbuf;
		int len = strlen(s.m_pbuf) + 1;
        m_pbuf = new char[len];
        strcpy_s(m_pbuf, len, s.m_pbuf);
    }
	//cout << "MyString�ĸ�ֵ���������������" << endl;
    return *this;
}

const char * MyString::set_string(const char * p)
{
	delete[] m_pbuf;

	if (NULL == p)
		m_pbuf = new char('\0');
	else
	{
		int len = strlen(p) + 1;
		m_pbuf = new char[len];
		strcpy_s(m_pbuf, len, p);
	}

	return m_pbuf;
}

const char * MyString::append(const char * p)
{
	if (NULL != p)
	{
		int len = strlen(m_pbuf) + strlen(p) + 1;
		char * tmp = new char[len];
		sprintf_s(tmp, len, "%s%s", m_pbuf, p);
		delete[] m_pbuf;
		m_pbuf = tmp;
	}

	return m_pbuf;
}

MyString & MyString::append(MyString & s)
{
	int len = strlen(m_pbuf) + s.get_length() + 1;
	char * tmp = new char[len];
	sprintf_s(tmp, len, "%s%s", m_pbuf, s.m_pbuf);
	delete[] m_pbuf;
	m_pbuf = tmp;

	return *this;
}