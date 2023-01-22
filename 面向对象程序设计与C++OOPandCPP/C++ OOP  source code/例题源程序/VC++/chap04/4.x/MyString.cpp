#include "MyString.h"

MyString operator+(const MyString & str, char * s) {
	MyString tmp(s);
	tmp.append(str);
	return tmp;
}

//MyString operator+(const MyString & s, const MyString & str) {
//	MyString tmp(s);
//	tmp.append(str);
//	return tmp;
//}

int MyString::total = 0;

MyString::MyString()
{
	total++;
	m_pbuf = new char('\0');
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
}

MyString::MyString(const MyString & s)
{
	total++;
	int len = strlen(s.m_pbuf) + 1;
	m_pbuf = new char[len];
	strcpy_s(m_pbuf, len, s.m_pbuf);
}

MyString::~MyString()
{
	total--;
	delete [] m_pbuf;
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
    return *this;
}

const char * MyString::set_string(const char * p)
{
	delete [] m_pbuf;

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
	if(NULL != p)
	{
		int len = strlen(m_pbuf) + strlen(p) + 1;
		char * tmp = new char[len];
		sprintf_s(tmp, len, "%s%s", m_pbuf, p);
		delete [] m_pbuf;
		m_pbuf = tmp;
	}

	return m_pbuf;
}

MyString & MyString::append(MyString & s)
{
	int len = strlen(m_pbuf) + strlen(s.m_pbuf) + 1;
	char * tmp = new char[len];
	sprintf_s(tmp, len, "%s%s", m_pbuf, s.m_pbuf);
	delete [] m_pbuf;
	m_pbuf = tmp;

	return *this;
}

MyString MyString::operator+(const MyString & str) const
{
	MyString tmp(*this);
	tmp.append(str);
	return tmp;
}

//MyString & MyString::operator=(const char * p)
//{
//   this->set_string(p);
//   return *this;
//}

char & MyString::operator [] (const int idx)
{
	if(idx >= strlen(m_pbuf))
		exit(1);
	return m_pbuf[idx];
}

char MyString::operator[] (const int idx) const
{
	if (idx >= strlen(m_pbuf))
		exit(1);
	return m_pbuf[idx];
}

MyString & MyString::operator() (const char * p)
{
	this->set_string(p);
	return *this;
}

MyString & MyString::operator() (const char * p, int n)
{
	delete[] m_pbuf;
	if (p == NULL || n == 0)
		m_pbuf = new char('\0');
	else
	{
		if (n < 0 || n > strlen(p))
			exit(1);
		m_pbuf = new char[n + 1];
		strncpy_s(m_pbuf, n + 1, p, n);
	}

	return *this;

}