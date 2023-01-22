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


    struct STUDENT {
        long int number;
        char name[20];
        char major[20];
        double score;
    };

    class CStudentList{
        #define BLOCK 10
    public:
        CStudentList();
        CStudentList(const STUDENT &stu);
        CStudentList(const CStudentList &studentList);
        CStudentList &operator = (const CStudentList &studentList);
        ~CStudentList();

        void add_student(STUDENT &student);
        STUDENT &getByName(char *name);
        bool existByName(char *name);
        STUDENT &modifyScoreByName(char *name, double score);
        void display();
        void display(char *name);
        void display(int min, int max=101);
        int delete_student(int num);

    private:
        STUDENT*gStu;
        int count;
        int available;
    };

}
#endif
