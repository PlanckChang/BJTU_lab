//
// Created by Planck Chang on 2021/12/2.
//

#include "MyString.h"

MyString & MyString::operator=(const MyString & s)
{
    if(this != &s)
    {
        delete [] m_pbuf;
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
    int len = strlen(m_pbuf) + s.get_length() + 1;
    char * tmp = new char[len];
    sprintf(tmp, "%s%s", m_pbuf, s.m_pbuf);
    delete[] m_pbuf;
    m_pbuf = tmp;

    return *this;
}



MyString& MyString::operator=(const char *p){
    this->set_string(p);
    return *this;
}

MyString MyString:: operator+(const MyString &s) const
{
    MyString temp(*this);
    temp.append(s.m_pbuf);
    return temp;
}

MyString MyString:: operator+(const char *s) const
{
    MyString temp(*this);
    temp.append(s);
    return temp;
}
char &MyString::operator[](const int idx) {
    if(idx> strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}
char MyString::operator[](const int idx) const{
    if(idx> strlen(m_pbuf)) exit(1);
    return m_pbuf[idx];
}

MyString& MyString::operator()(const char *p) {
    this->set_string(p);
    return *this;
}

MyString& MyString::operator()(const char*p, int n){
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

int MyString :: operator>(const MyString&s){
    if(strcmp(this->get_string(), s.get_string())>0)
        return 1;
    return 0;
}
int MyString :: operator<(const MyString&s){
    if(strcmp(this->get_string(), s.get_string()) <0)
        return 1;
    return  0;
}
int MyString:: operator<=(const MyString&s){
    int tem = strcmp(this->get_string(), s.get_string());
    if(tem<=0) return 1;
    return 0;
}
int MyString:: operator>=(const MyString&s){
    int tem = strcmp(this->get_string(), s.get_string());
    if(tem >= 0) return  1;
    return 0;
}




istream & operator >>(istream &in, MyString &str)
{
    delete [] str.m_pbuf;
    int len;
    in >> len;
    in.get();
    str.m_pbuf = new char[len+1];
    in.read(str.m_pbuf, len);
    str.m_pbuf[len] = '\0';
    return in;
}

ostream & operator << (ostream &out, const MyString& str)
{
    out << str.m_pbuf;
    return out;
}

//void MyString::write_binary(ofstream &out) const {
//    int len= strlen(m_pbuf);
//    out.write((char *)&len, sizeof (int ));
//    out.write(m_pbuf, len+1);
//}

//MyString & MyString::read_binary(ifstream &in) {
//    delete []m_pbuf;
//    int len;
//    in.read((char*)&len, sizeof (int ));
//    m_pbuf = new char[len+1];
//    in.read(m_pbuf, len+1);
//    return *this;
//}