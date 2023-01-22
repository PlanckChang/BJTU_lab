//
// Created by Planck Chang on 2021/10/2.
//for chapter3 assignment1 of the oop&cpp instructed by Prof.Dong

#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <string.h>
using namespace std;

class MyString{
public:
    char* get_string();
    const char* set_string(const char*p);
    const char * append(const char *p);
    const char* append(const MyString&s);
    MyString();
    MyString(const char *p);
    MyString(const MyString &s);
    ~MyString();
    MyString &operator=(const MyString &s);
    int get_length();

    static int get_total(){
        return total;
    }
    const char* get_string() const{
        int len = strlen(m_pbuf) + 1;
        char* tem = new char[len];
        tem = strcpy(tem, m_pbuf);
        return tem;
    }
    int get_length() const{
        return strlen(m_pbuf);
    }

private:
    char* m_pbuf;
    static int total;
};



inline int MyString::get_length(){
    int tem = strlen(m_pbuf);
    return  tem;
}

inline char* MyString::get_string() {
    int len = strlen(m_pbuf) + 1;
    char* tem = new char[len];
    tem = strcpy(tem, m_pbuf);
    return tem;
}

inline MyString::MyString(const char *p) {

    if (p == NULL)
        m_pbuf = new char('\0');
    else {
        m_pbuf = new char[strlen(p) + 1];
        strcpy(m_pbuf, p);

    }
    cout << "MyString类的有参构造函数被调用，当前字符串为：";
    cout << m_pbuf  << endl;
}

inline MyString::MyString(const MyString &s) {
    int len = strlen(s.m_pbuf) + 1;
    m_pbuf = new char[len];
    strcpy(m_pbuf, s.m_pbuf);
    cout << "MyString类的复制构造函数被调用，当前字符串为：";
    cout << m_pbuf  << endl;
    ++total;
}

inline MyString::~MyString() {
    cout << "MyString类的析构函数被调用，当前字符串为："<< m_pbuf << endl;
    delete [] m_pbuf;
    --total;
}

inline MyString::MyString() {
    m_pbuf = new char('\0');
    ++total;
    cout << "MyString类的默认构造函数被调用" << endl;
}

inline MyString & MyString::operator=(const MyString &s) {
    if(this!=&s){
        delete[]m_pbuf;
        int len =strlen(s.m_pbuf)+1;
        m_pbuf = new char[len];
        strcpy(m_pbuf, s.m_pbuf);
    }
    cout << "MyString类的赋值运算符被调用，当前字符串为：" << m_pbuf << endl;
    return *this;
}


#endif //_MYSTRING_H_
