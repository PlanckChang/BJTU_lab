//
// Created by Planck Chang on 2021/11/12.
//

#ifndef CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENT_H
#define CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENT_H

#pragma once
#include"MyString.h"

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

    ofstream & write_txt(ofstream &out)
    {
        out << number << " ";
        name.write_txt(out);
        major.write_txt(out);
        out << score << " ";
        return out;
    }

    ifstream  &read_txt(ifstream &in)
    {
        in >> number;
        in.get();
        name.read_txt(in);
        major.read_txt(in);
        in >> score;
        in.get();
        return in;
    }

    ofstream &write_binary(ofstream &out)
    {
        out.write((char *)&number, sizeof (int));
        name.write_binary(out);
        major.write_binary(out);
        out.write((char *)&score, sizeof(double ));
        return out;
    }
    ifstream &read_binary(ifstream &in)
    {
        in.read((char*)&number, sizeof(int ));
        name.read_binary(in);
        major.read_binary(in);

        in.read((char*)&score, sizeof(double));
        return in;
    }

private:
    int  number;
    MyString name;
    MyString major;
    double score;
};
#endif //CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENT_H
