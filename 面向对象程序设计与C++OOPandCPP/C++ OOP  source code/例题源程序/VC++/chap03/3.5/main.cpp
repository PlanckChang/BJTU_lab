#include"student.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	MyString name("zhangsan"), major("computer");
	CStudent stu(1, name, major, 100), stu2;
    CStudent stu3(stu);
	stu2 = stu3;
	
	cout << stu.get_name().get_string() << endl;
	cout << stu2.get_name().get_string() << endl;
	
	return 0;
}
