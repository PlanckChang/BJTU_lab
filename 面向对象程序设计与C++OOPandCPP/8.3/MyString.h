//
// Created by Planck Chang on 2021/12/6.
//

#ifndef INC_8_3_MYSTRING_H
#define INC_8_3_MYSTRING_H
#include<iostream>
#include<cstring>
using namespace std;

class MyString
{
public:
    MyString();
    MyString(const MyString & str);
    MyString(const char * p);
    ~MyString();

    MyString & operator=(const MyString & str);
    friend ostream & operator<<(ostream & o, const MyString & s);
    bool operator>(const MyString & s) const;
    bool operator<(const MyString & s) const;
public:
    const char * get_string() const;
    const char * set_string(const char * p);
    int get_length() const{ return strlen(m_pbuf); }

private:
    char * m_pbuf;
};

#endif //INC_8_3_MYSTRING_H
