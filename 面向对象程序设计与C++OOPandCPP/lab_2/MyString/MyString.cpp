//
// Created by Planck Chang on 2021/10/2.
//
#include "MyString.h"


int MyString::total=0;

const char* MyString::set_string(const char*p){
    delete [] m_pbuf;
    if(p==NULL)
        m_pbuf = new char('\0');
    else{
        int len = strlen(p)+1;
        m_pbuf = new char[len];
        strcpy(m_pbuf, p);
    }
    return m_pbuf;
}

const char * MyString::append(const char*p){
    if(p!=NULL){
        int len =strlen(m_pbuf)+strlen(p)+1;
        char* tem = new char[len];
        strcpy(tem, m_pbuf);
        strcat(tem, p);
        delete [] m_pbuf;

        m_pbuf = tem;
    }
    return m_pbuf;
}

const char* MyString::append(const MyString&s) {
    if(s.m_pbuf!=NULL){
        int len = strlen(m_pbuf) +strlen(s.m_pbuf) +1;
        char* tem = new char [len];
        strcpy(tem, m_pbuf);
        strcat(tem, s.m_pbuf);
        delete [] m_pbuf;
        m_pbuf = tem;
    }
    return m_pbuf;
}







