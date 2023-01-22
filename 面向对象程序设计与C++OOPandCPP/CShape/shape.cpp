//
// Created by Planck Chang on 2021/11/18.
//
#include "shape.h"

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


