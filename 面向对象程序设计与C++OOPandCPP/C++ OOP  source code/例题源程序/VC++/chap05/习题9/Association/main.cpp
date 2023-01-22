#include<iostream>
#include"student.h"
#include"studentlist.h"
using namespace std;

int main()
{
	{
		CStudentList stuList;
		CStudent * pstu1, *pstu2, *pstu3, *pstu4;
		pstu1 = new CStudent(1, MyString("Zhang"), MyString("computer"), 100);
		pstu2 = new CStudent(2, MyString("Wang"), MyString("computer"), 90);
		pstu3 = new CStudent(3, MyString("Zhao"), MyString("computer"), 80);
		pstu4 = new CStudent(4, MyString("Li"), MyString("computer"), 70);
		stuList.add(pstu1);
		stuList.add(pstu2);
		stuList.add(pstu3);
		stuList.add(pstu4);

		cout << "列出所有学生" << endl;
		stuList.show();

		ofstream out("student.txt");
		stuList.write_text(out);
		out.close();
	}

	CStudentList stuList2;
	ifstream in("student.txt");
	stuList2.read_text(in);
	in.close();
	cout << "列出所有学生" << endl;
	stuList2.show();


	return 0;
}