#include <iostream>
#include "student.h"
#include "studentlist.h"
int main() {
    int code = 0;
    CNode * p = NULL;
    CStudentList stuList;
    CStudent * pstu1, *pstu2, *pstu3, *pstu4;
    MyString s1("Zhang"), s2("computer");
    pstu1 = new CStudent(1, s1, s2, double(100));
    s1.set_string("Wang");
    pstu2 = new CStudent(2, s1, s2, 90);
    s1.set_string("Zhao");
    pstu3 = new CStudent(3, s1, s2, 80);
    s1.set_string("Li");
    pstu4 = new CStudent(4, s1, s2, 70);
    stuList.add(pstu1);
    stuList.add(pstu2);
    stuList.add(pstu3);
    stuList.add(pstu4);

    cout << "列出所有学生" << endl;
    stuList.show();

    ofstream out("cstudentlist.txt");
    stuList.write_txt(out);
    out.close();

    CStudentList stulist2;
    ifstream in("cstudentlist.txt");
    stulist2.read_txt(in);
    in.close();
    cout << "all the students are following by txt" << endl;
    stulist2.show();

    //dat
    ofstream out2("cstudentlist.dat", ios_base::binary);
    stuList.write_binary(out2);
    out2.close();

    CStudentList stulist3;
    ifstream in2("cstudentlist.dat", ios_base::binary);
    stulist3.read_binary(in2);
    in2.close();
    cout <<"all the students are following by dat"<< endl;
    stulist3.show();



    return 0;

}
