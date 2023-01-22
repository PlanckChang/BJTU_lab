//
// Created by Planck Chang on 2021/12/6.
//

#ifndef INC_8_2_MYSTRING_H
#define INC_8_2_MYSTRING_H
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class MyString
{
    static int total;
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


    MyString operator+(const MyString & s);
    MyString & operator=(const char * p);
    char & operator [] (const unsigned int idx);
    char operator[] (const unsigned int idx) const;
    MyString & operator() (const char * p);
    operator const char * () const { return m_pbuf; }


    friend ostream & operator << (ostream & out, const MyString & str);


    ofstream & write(ofstream & o);
    ifstream & read(ifstream & in);
private:
    char * m_pbuf;
};
#endif //INC_8_2_MYSTRING_H
