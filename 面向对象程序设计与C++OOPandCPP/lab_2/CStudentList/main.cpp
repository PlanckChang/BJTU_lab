//
// Created by Planck Chang on 2021/10/4.
//
#include "20271259_2.h"
#include "20271259_2.cpp"

using namespace N20271259;

int main()
{
    CStudentList studentList;
    int num, option;
    int choice = -1;
    int number;
	char name[10];
    char major[10];
    double score;
    
    while (choice != 0)
    {
        cout << "1 ¼��ѧ����Ϣ \n";
        cout << "2 ��ʾѧ����Ϣ \n";
        cout << "3 ͨ�������޸ĳɼ�����һ��\n";
        cout << "4 ͨ�������޸ĳɼ���������\n";
        cout << "5 ���Ը��ƹ��캯��\n";
        cout << "6 �����вι��캯��\n";
        cout << "7 ��ѧ��ɾ��ѧ��\n";
        cout << "8 �˳�\n";
        cout << "��ѡ������Ҫ�Ĳ�����";
        cin >> choice;

        if (choice == 1)
        {
            cout << "����������ѧ�š�������רҵ�ͳɼ�\n";
            cin >> number >> name >> major >> score;
            printf("hell");
            STUDENT s(number, name, major, score);
           printf("hell");
            printf("hell");
            studentList.add_student(s);
        }
        else if (choice == 2){
            cout << "1 ȫ�����\n";
            cout << "2 ������ͷ���߷� ���������\n";
            int min, max;
            cin >> option;
            if(option==1)
                studentList.display();
            if(option==2){
                cin >> min;
                cin >> max;
                studentList.display(min, max);
            }
            cout << endl;
        }
        else if ( choice == 3){
            cout << "������Ҫ��ѯ��ѧ��������";
            char name[20];
            cin >> name;
            if (studentList.existByName(name)){
                cout << "������Ҫ�޸ĵĳɼ���";
                double score;
                cin >> score;
                studentList.getByName(name).get_score() = score;
                studentList.display(name);
            }
            else
                cout << "��ѯ��ѧ�� " << name << " �����ڣ�\n";
        }
        else if (choice == 4){
            cout << "������ѧ���������ͳɼ���";
            char name[20];
            double score;
            cin >> name >> score;
            if (studentList.existByName(name))
                studentList.modifyScoreByName(name, score);
            else
                cout << "ѧ�� " << name << " �����ڣ�\n";
        }
        else if (choice == 5){
            CStudentList studentListBak(studentList);
            studentListBak.display();
        }
      //  else if (choice == 6){
       //     STUDENT stu = {1, "zhangsan", "computer", 100};
         //   CStudentList studentList1(stu);
           // studentList1.display();
       // }
        else if(choice == 7){
            cout << "������ѧ��\n";
            cin >> num;
            if(studentList.delete_student(num)==1)
                cout << "ɾ���ɹ�" << "\n";
            else
                cout << "û�����ѧ������Ϣ��������" << "\n" << endl;
        }
        else if(choice == 8 ) break;
        else
            cout << "���ѡ������������ѡ��\n" << endl;
    }

    return 0;
}

