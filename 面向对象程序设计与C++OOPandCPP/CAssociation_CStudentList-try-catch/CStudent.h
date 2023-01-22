#pragma once
#include"MyString.h"
#include <iostream>
#include <fstream>
class CStudent
{
public:
    CStudent() : number(0), score(0) {}
    CStudent(int num, MyString & name, MyString & major, double score);
    CStudent(const CStudent & stu);
    void set_number(int num) { number = num; }
    int get_number() const { return number; }
    MyString & set_name(const MyString & name);
    MyString & get_name() { return name; }
    MyString get_name() const { return name; }
    MyString & set_major(const MyString & major);
    MyString & get_major() { return major; }
    MyString get_major() const { return major; }
    void set_score(double score) { this->score = score; }
    double get_score() const { return score; }
    CStudent & operator=(const CStudent & stu)
    {
        if (this != &stu)
        {
            number = stu.number;
            name = stu.name;
            major = stu.major;
            score = stu.score;
        }
        return *this;
    }



private:
    int  number;
    MyString name;
    MyString major;
    double score;
};