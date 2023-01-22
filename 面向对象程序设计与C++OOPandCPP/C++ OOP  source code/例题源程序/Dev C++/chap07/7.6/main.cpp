#include<iostream>
#include<fstream>
#include"student.h"
#include"studentlist.h"
using namespace std;

int main()
{	
	CStudentListEx stuList;
	CStudent * pstu1, *pstu2;
	MyString s1("zhang");
	MyString s2("computer");
	MyString s3 ("wang"); 
	pstu1 = new CStudent(1, s1, s2, 100);
	pstu2 = new CGraduate(2, s2, s3, 90, MyString("Zhao"));
	stuList.add(pstu1);
	stuList.add(pstu2);

	cout << "列出所有学生" << endl;
	stuList.show();

	ofstream out("test.dat", ios_base::binary);
	stuList.write_binary(out);
	out.close();
	
	stuList.clear();
	cout << "列出所有学生" << endl;
	stuList.show();

	ifstream in("test.dat", ios_base::binary);
	stuList.read_binary(in);
	in.close();

	cout << "列出所有学生" << endl;
	stuList.show();		

	return 0;
}
