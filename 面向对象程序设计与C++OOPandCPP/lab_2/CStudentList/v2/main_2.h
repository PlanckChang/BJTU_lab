//
// Created by Planck Chang on 2021/10/4.
//for chapter2 plus assignment instructed by Prof.Dong

#ifndef _20271259_2_H_
#define _20271259_2_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

namespace N20271259 {


    class MyString{
    public:
        char* get_string();
        const char* set_string(const char*p);
        const char * append(const char *p);
        const char * append(const MyString&s);
        MyString();
        MyString(const char *p);
        MyString(const MyString &s);
        ~MyString();
        MyString &operator=(const MyString &s);
        int get_length();

    private:
        char* m_pbuf;
    };


    class CStudent{
    public:
        MyString&get_name(){
            return name;
        }
        double&get_score(){
            return score;
        }
        MyString&get_major(){
            return major;
        }
        int &get_number(){
            return number;
        }
        CStudent(){
            number = 0;
            score = 0.0;
        };
        CStudent(int number_, char *name, char*major, double score_):number(number_), score(score_),
            name(name), major(major){};
        CStudent(CStudent &s): number(s.number), name(s.name), score(s.score), major(s.major){};
        CStudent& operator = (const CStudent &s){
            if(this!= &s){
                name = s.name;
                number = s.number;
                score = s.score;
                major = s.major;
            }
            return *this;

        }
        ~CStudent(){};
    private:
        int number;
        MyString name;
        MyString major;
        double score;
    };

    class CStudentList{
    #define BLOCK 10
    public:
        CStudentList();
        CStudentList(const CStudent &stu);
        CStudentList(const CStudentList &studentList);
        CStudentList &operator = (const CStudentList &studentList);
        ~CStudentList();

        void add_student(CStudent &student);
        CStudent &getByName(char *name);
        bool existByName(char *name);
        CStudent &modifyScoreByName(char *name, double score);
        void display();
        void display(char *name);
        void display(int min, int max=101);
        int delete_student(int num);

    private:
        CStudent*gStu;
        int count;
        int available;
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
    }

    inline MyString::~MyString() {
        cout << "MyString类的析构函数被调用，当前字符串为："<< m_pbuf << endl;
        delete [] m_pbuf;
    }

    inline MyString::MyString() {
        m_pbuf = new char('\0');
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

}
#endif
