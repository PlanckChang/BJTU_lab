//
// Created by Planck Chang on 2021/11/18.
//

#ifndef CSHAPE_SHAPE_H
#define CSHAPE_SHAPE_H
#include <iostream>
#include <cstring>
#include<cmath>
using namespace std;
#define pi 3.1415926
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
private:
    char * m_pbuf;
    static int total;
};

class Shape
{
    MyString name;
public:
    Shape():name()
    {
        cout << "class Shape 的默认构造函数被调用。。。" << endl;
    };
    Shape(const char * str)
    {
        name(str);
        cout << "class Shape 的有参构造函数被调用。。。" << endl;
    }
    Shape(const Shape& shape):name(shape.name)
    {
        cout << "class Shape 的复制构造函数被调用。。。" << endl;
    };
    Shape &operator= (const Shape &shape)
    {
        name = shape.name;
        cout << "class Shape 的赋值运算符函数被调用。。。" << endl;
    };
    virtual ~Shape()
    {
        cout << "class Shape 的析构函数被调用。。。" << endl;
    };

    double square(){};
    double circumference(){};
};

class Circle: public Shape
{
    double radium;
public:
    Circle(double r, const char * str = "circle"):Shape(str), radium(r){};
    virtual ~Circle(){};
    double square()
    {
        return radium*radium*pi;
    }
    double circumperence()
    {
        return 2*pi*radium;
    }
};
class Rectangle:public Shape
{
    double a,b;
public:
    Rectangle(double a, double b, const char* str = "rectangle"):Shape(str), a(a), b(b){};
    virtual ~Rectangle(){};
    double square()
    {
        return a*b;
    };
    double circumference()
    {
        return (a+b)*2;
    }
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
#endif //CSHAPE_SHAPE_H
