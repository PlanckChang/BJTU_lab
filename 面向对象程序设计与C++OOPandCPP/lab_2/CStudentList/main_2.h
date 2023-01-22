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


    class STUDENT {
    public:
        char*get_name(){
            char *s = new char[name.get_length()];
            strcpy(s,name.get_string());
            return s;
        }
        double&get_score(){
            return score;
        }
        char*get_major(){
            char*s = new char[major.get_length()];
            strcpy(s, major.get_string());
            return s;
        }
        int get_number(){
            return number;
        }
        STUDENT(){
            number = 0;
            score = 0.0;
        };
        STUDENT(int number, char *name, char*major, double score):name(name),major(major){
            number = number;
            score = score;
        };
        STUDENT(STUDENT &s){
            number = s.number;
            name = s.name;
            score = s.score;
            major = s.major;
        };
        STUDENT& operator = (const STUDENT &s){
            name = s.name;
            number = s.number;
            score = s.score;
            major = s.major;
        }
        ~STUDENT(){};
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
