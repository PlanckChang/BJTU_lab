//
// Created by Planck Chang on 2021/11/12.
//

#ifndef CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_MYSTRING_H
#define CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_MYSTRING_H
#include<iostream>
#include<fstream>
#include<cstring>

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

    ofstream  & write_txt(ofstream &out)
    {
        out << strlen(m_pbuf) << " " << m_pbuf;
        return out;
    }


    ifstream & read_txt(ifstream & in)
    {
        delete [] m_pbuf;
        int len;
        in >> len;
        in.get();
        m_pbuf= new char[len+1];
        in.read(m_pbuf, len);
        m_pbuf[len] = '\0';
        return in;
    }

    void write_binary(ofstream &out) const;
    MyString &read_binary(ifstream &in);
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




#endif //CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_MYSTRING_H
