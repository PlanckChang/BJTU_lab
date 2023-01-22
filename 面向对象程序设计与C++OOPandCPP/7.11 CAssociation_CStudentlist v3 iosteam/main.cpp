#include<iostream>
#include"student.h"
#include"studentlist.h"
using namespace std;

int main()
{
    system("chcp 65001");

    CStudentListEx stuList;
    CStudent * pstu1, *pstu2;
    MyString s1 = "zhang";
    MyString s2 = "computer";
    MyString s3 = "wang";
    MyString s4 = "zhao";

    pstu1 = new CStudent(1, s1, s2, 100);
    pstu2 = new CGraduate(2, s3, s2, 90, s4);
    stuList.add(pstu1);
    stuList.add(pstu2);

    cout << "all students are following" << endl;
    stuList.show();

    ofstream out("test.dat", ios_base::binary);
    stuList.write_binary(out);
    out.close();

    stuList.clear();
    cout << "all students are following" << endl;
    stuList.show();

    ifstream in("test.dat", ios_base::binary);
    stuList.read_binary(in);
    in.close();

    cout << "all students are following" << endl;
    stuList.show();

    cout << "\n" << endl;
    cout << "next is for association" << endl;
    cout << "\n" << endl;
    MyString association_name = "no name association";
    CAssociation association(association_name);

    CNode * node1 =  new CNode(pstu1);
    CNode * node2 = new CNode(pstu2);
    CStudent *pstu3 =  new CStudent(3, s1, s2, 100);
    CNode * node3 = new CNode(pstu3);
    association.add(node1);
    association.add(node3);
    association.add(node2); // graduate can't be added

    association.show();

    ofstream out1("a_test.dat", ios_base::binary);
    association.write_binary(out1);
    out1.close();

    association.clear();
    cout << "all students are following" << endl;
    association.show();

    ifstream in1("a_test.dat", ios_base::binary);
    association.read_binary(in, stuList);
    association.show();

    return 0;
}
