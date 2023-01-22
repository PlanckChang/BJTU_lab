#include<iostream>
#include"CStudent.h"
#include"CStudentList.h"
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
        association.add(p);

        association.show();

        cout << "将学号为5的学生加入协会，列出协会当前的学生" << endl;
        p = stuList.get(5);	//学号为5的学生不存在，故p为NULL
        if (NULL != p)
            association.add(p);
        else
        {
            cout << "学号为5的学生：";
            showError(1);
        }

        cout << "试图删除学号为3的学生，列出剩余的学生" << endl;
        code = stuList.del(3);
        if (code > 0)
        {
            cout << "删除学号为3的学生：";
            showError(code);
        }
        stuList.show();

        cout << "试图将学号为4的学生移出协会，列出协会当前的学生" << endl;
        p = stuList.get(4);
        if (NULL != p)
        {
            code = association.del(p);
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
        p = stuList.get(3);
        if (NULL != p)
        {
            code = association.del(p);
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
        code = stuList.del(3);
        if (code > 0)
        {
            cout << "删除学号为3的学生：";
            showError(code);
        }
        stuList.show();
    }
    cout << "列出所有学生" << endl;
    stuList.show();

    return 0;
}