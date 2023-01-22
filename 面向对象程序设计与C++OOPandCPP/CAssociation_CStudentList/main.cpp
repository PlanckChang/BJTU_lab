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

    cout << "�г�����ѧ��" << endl;
    stuList.show();





    {
        MyString name("�׷�־Ը��");
        CAssociation association(name);
        cout << "���ν�ѧ��Ϊ1��2��3��ѧ������Э�ᣬ�г�Э�ᵱǰ��ѧ��" << endl;
        p = stuList.get(1);
        association.add(p);

        p = stuList.get(2);
        association.add(p);

        p = stuList.get(3);
        association.add(p);
        association.add(p);

        association.show();

        cout << "��ѧ��Ϊ5��ѧ������Э�ᣬ�г�Э�ᵱǰ��ѧ��" << endl;
        p = stuList.get(5);	//ѧ��Ϊ5��ѧ�������ڣ���pΪNULL
        if (NULL != p)
            association.add(p);
        else
        {
            cout << "ѧ��Ϊ5��ѧ����";
            showError(1);
        }

        cout << "��ͼɾ��ѧ��Ϊ3��ѧ�����г�ʣ���ѧ��" << endl;
        code = stuList.del(3);
        if (code > 0)
        {
            cout << "ɾ��ѧ��Ϊ3��ѧ����";
            showError(code);
        }
        stuList.show();

        cout << "��ͼ��ѧ��Ϊ4��ѧ���Ƴ�Э�ᣬ�г�Э�ᵱǰ��ѧ��" << endl;
        p = stuList.get(4);
        if (NULL != p)
        {
            code = association.del(p);
            if (code > 0)
            {
                cout << "��ѧ��Ϊ4��ѧ���Ƴ�Э�᣺";
                showError(code);
            }
        }
        else
        {
            cout << "��ѧ��Ϊ4��ѧ���Ƴ�Э�᣺";
            showError(1);
        }
        association.show();

        cout << "��ѧ��Ϊ3��ѧ���Ƴ�Э�ᣬ�г�Э�ᵱǰ��ѧ��" << endl;
        p = stuList.get(3);
        if (NULL != p)
        {
            code = association.del(p);
            if (code > 0)
            {
                cout << "��ѧ��Ϊ3��ѧ���Ƴ�Э�᣺";
                showError(code);
            }
        }
        else
        {
            cout << "��ѧ��Ϊ3��ѧ���Ƴ�Э�᣺";
            showError(1);
        }
        association.show();

        cout << "ɾ��ѧ��Ϊ3��ѧ�����г�ʣ���ѧ��" << endl;
        code = stuList.del(3);
        if (code > 0)
        {
            cout << "ɾ��ѧ��Ϊ3��ѧ����";
            showError(code);
        }
        stuList.show();
    }
    cout << "�г�����ѧ��" << endl;
    stuList.show();

    return 0;
}