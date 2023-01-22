                                                                                                                                                                                                           #ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char * p);
    MyString(const MyString & s);
    ~MyString();
    MyString & operator=(const MyString & s);

    const char * get_string() const { return m_pbuf; }
    const char * set_string(const char * p = NULL);
    const char * append(const char * p = NULL);
    MyString & append(MyString & s);
    int get_length() const { return strlen(m_pbuf); }
    static int get_total() { return total; }

    MyString&  operator=(const char* p);
    MyString operator+(const MyString &s) const;
    MyString operator+(const char*s) const;
    char & operator[](const int idx);
    char operator[](const int idx) const;
    MyString & operator()(const char*p);
    MyString & operator()(const char*p, int n);
    operator const char* () {return m_pbuf;};
    int operator>(const MyString&s);
    int operator<(const MyString&s);
    int operator<=(const MyString&s);
    int operator>=(const MyString&s);

    friend ostream & operator << (ostream &out, const MyString& str);
    friend istream & operator >> (istream &in, MyString& str);

    MyString & read(ifstream & in);

private:
    char * m_pbuf;
    static int total;
};

inline MyString::~MyString()
{
    delete [] m_pbuf;
}

inline MyString::MyString(const MyString & s)
{
    int len = strlen(s.m_pbuf) + 1;
    m_pbuf = new char[len];
    strcpy(m_pbuf, s.m_pbuf);
}

inline MyString::MyString(const char * p)
{
    if (NULL == p)
        m_pbuf = new char('\0');
    else
    {
        int len = strlen(p) + 1;
        m_pbuf = new char[len];
        strcpy(m_pbuf, p);
    }
}

inline MyString::MyString()
{
    m_pbuf = new char('\0');
}



#endif