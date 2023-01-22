//
// Created by Planck Chang on 2021/10/28.
//

#ifndef MYSTRING_V4_MYSTRING_H
#define MYSTRING_V4_MYSTRING_H
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

    const char * get_string() const { return m_pbuf;}
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

    void write(ofstream &out) const;
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

inline MyString& MyString::operator=(const char *p){
    this->set_string(p);
    return *this;
}

inline MyString MyString:: operator+(const MyString &s) const
{
    MyString temp(*this);
    temp.append(s.m_pbuf);
    return temp;
}

inline MyString MyString:: operator+(const char *s) const
{
    MyString temp(*this);
    temp.append(s);
    return temp;
}
inline char &MyString::operator[](const int idx) {
    if(idx> strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}

inline char MyString::operator[](const int idx) const{
    if(idx> strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}

inline  MyString& MyString::operator()(const char *p) {
    this->set_string(p);
    return *this;
}

inline MyString& MyString::operator()(const char*p, int n){
    delete[] m_pbuf;
    if(p==NULL|| n==0) m_pbuf = new char('\0');
    else
    {
        if(n< 0 || n> strlen(p)) exit(1);
        m_pbuf = new char[n+1];
        strncpy(m_pbuf, p, n);
        m_pbuf[n]='\0';
    }
    return *this;
}

inline int MyString :: operator>(const MyString&s){
   if(strcmp(this->get_string(), s.get_string())>0)
       return 1;
    return 0;
}
inline int MyString :: operator<(const MyString&s){
    if(strcmp(this->get_string(), s.get_string()) <0)
        return 1;
    return  0;
}
inline int MyString:: operator<=(const MyString&s){
    int tem = strcmp(this->get_string(), s.get_string());
    if(tem<=0) return 1;
    return 0;
}
inline int MyString:: operator>=(const MyString&s){
    int tem = strcmp(this->get_string(), s.get_string());
    if(tem >= 0) return  1;
    return 0;
}




#endif //MYSTRING_V4_MYSTRING_H
