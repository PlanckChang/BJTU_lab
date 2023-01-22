#include "MyString.h"

ostream & operator << (ostream & out, const MyString & str)
{
	out << str.m_pbuf;
	return out;
}

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
		strcpy(m_pbuf, p);
	}
}

MyString::MyString(const MyString & s)
{
	total++;
	int len = strlen(s.m_pbuf) + 1;
	m_pbuf = new char[len];
	strcpy(m_pbuf, s.m_pbuf);
}

MyString::~MyString()
{
	total--;
	delete[] m_pbuf;
}

MyString & MyString::operator=(const MyString & s)
{
	if (this != &s)  // ·ÀÖ¹×Ô¸³Öµ
	{
		delete[] m_pbuf;
		int len = strlen(s.m_pbuf) + 1;
		m_pbuf = new char[len];
		strcpy(m_pbuf, s.m_pbuf);
	}
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
		strcpy(m_pbuf, p);
	}

	return m_pbuf;
}

const char * MyString::append(const char * p)
{
	if (NULL != p)
	{
		int len = strlen(m_pbuf) + strlen(p) + 1;
		char * tmp = new char[len];
		sprintf(tmp, "%s%s", m_pbuf, p);
		delete[] m_pbuf;
		m_pbuf = tmp;
	}

	return m_pbuf;
}

MyString & MyString::append(MyString & s)
{
	int len = strlen(m_pbuf) + strlen(s.m_pbuf) + 1;
	char * tmp = new char[len];
	sprintf(tmp, "%s%s", m_pbuf, s.m_pbuf);
	delete[] m_pbuf;
	m_pbuf = tmp;

	return *this;
}

MyString MyString::operator+(const MyString & str)
{
	MyString tmp(*this);
	tmp.append(str);
	return tmp;
}

MyString & MyString::operator=(const char * p)
{
	this->set_string(p);
	return *this;
}

char & MyString::operator [] (const unsigned int idx)
{
	if (idx >= strlen(m_pbuf))
		exit(1);
	return m_pbuf[idx];
}

char MyString::operator[] (const unsigned int idx) const
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

ofstream & MyString::write(ofstream & o)
{
	int len = strlen(m_pbuf);
	o.write((char *)&len, sizeof(int));
	o.write(m_pbuf, len + 1);
	return o;
}

ifstream & MyString::read(ifstream & in)
{
	delete[] m_pbuf;
	int len;
	in.read((char *)&len, sizeof(int));
	m_pbuf = new char[len + 1];
	in.read(m_pbuf, len + 1);
	return in;
}
