#include "MyString.h"

MyString::MyString()
{
	m_pbuf = new char('\0');
}

MyString::MyString(const MyString & str)
{
	int len = strlen(str.m_pbuf);
	m_pbuf = new char[len + 1];
	strcpy(m_pbuf, str.m_pbuf);
}

MyString::MyString(const char * p)
{
	if(NULL == p)
	{
		m_pbuf = new char('\0');
	}
	else
	{
		int len = strlen(p);
		m_pbuf = new char[len + 1];
		strcpy(m_pbuf, p);
	}
}

const char * MyString::get_string() const
{
	return m_pbuf;
}

const char * MyString::set_string(const char * p)
{
	delete [] m_pbuf;

	if(NULL == p)
	{
		m_pbuf = new char('\0');
	}
	else
	{
		int len = strlen(p);
		m_pbuf = new char[len + 1];
		strcpy(m_pbuf, p);
	}
	
	return m_pbuf;
}

MyString::~MyString()
{
	delete [] m_pbuf;
}


MyString & MyString::operator=(const MyString & str)
{
	if(this != &str)  // ·ÀÖ¹×Ô¸³Öµ
	{
		delete [] m_pbuf;
		int len = strlen(str.m_pbuf);
		m_pbuf = new char[len + 1];
		strcpy(m_pbuf, str.m_pbuf);
	}
	return *this;
}

bool MyString::operator>(const MyString & s) const
{
	return (strcmp(this->get_string(), s.get_string()) > 0) ? true : false;
}

bool MyString::operator<(const MyString & s) const
{
	return (strcmp(this->get_string(), s.get_string()) < 0) ? true : false;
}

ostream & operator<<(ostream & o, const MyString & s)
{
	o << s.get_string();
	return o;
}
