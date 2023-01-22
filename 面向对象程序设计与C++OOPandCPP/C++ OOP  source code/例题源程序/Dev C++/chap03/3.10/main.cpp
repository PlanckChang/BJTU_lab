#include<iostream>
#include"student.h"
#include"studentlist.h"
using namespace std;

int main()
{
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
	
	{
		MyString name("雷锋志愿者");
		CAssociation association(name);
		cout << "依次将学号为1、2、3的学生加入协会，列出协会当前的学生" << endl;
		p = stuList.get(1);
		association.add(p);

		p = stuList.get(2);
		association.add(p);

		p = stuList.get(3);
		association.add(p);
		association.add(p);		//学生3已在社团，不会重复加入

		association.show();		//协会中有三名学生

		cout << "试图将学号为5的学生加入协会，列出协会当前的学生" << endl;
		p = stuList.get(5);	//学号为5的学生不存在，故p为NULL
		if (NULL != p)
			association.add(p);
		else
		{
			cout << "学号为5的学生：";
			showError(1);
		}

		cout << "试图删除学号为3的学生，列出剩余的学生" << endl;
		code = stuList.del(3);	//由于学生3在协会中，因此引用计数不为0，故无法删除
		if (code > 0)
		{
			cout << "删除学号为3的学生：";
			showError(code);
		}
		stuList.show();

		cout << "试图将学号为4的学生移出协会，列出协会当前的学生" << endl;
		p = stuList.get(4);	//学号为4的学生是存在的，故p不为NULL
		if (NULL != p)
		{
			code = association.del(p);	//由于学号为4的学生不在协会中，故移除失败
			if (code > 0)
			{
				cout << "将学号为4的学生移出协会：";
				showError(code);
			}
		}
		else
		{
			cout << "将学号为4的学生移出协会：";
			showError(1);
		}
		association.show();

		cout << "将学号为3的学生移出协会，列出协会当前的学生" << endl;
		p = stuList.get(3);	//学号为3的学生是存在的，故p不为NULL
		if (NULL != p)
		{
			code = association.del(p);	//学号为3的学生在协会中，故删除成功
			if (code > 0)
			{
				cout << "将学号为3的学生移出协会：";
				showError(code);
			}
		}
		else
		{
			cout << "将学号为3的学生移出协会：";
			showError(1);
		}
		association.show();

		cout << "删除学号为3的学生，列出剩余的学生" << endl;
		code = stuList.del(3);	//此时学号为3的学生的引用计数为0，可以删除
		if (code > 0)
		{
			cout << "删除学号为3的学生：";
			showError(code);
		}
		stuList.show();
	}
	cout << "列出所有学生" << endl;
	stuList.show();		//由于社团对象已析构，故所有学生的引用计数为0

	return 0;
}
