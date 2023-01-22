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
        cout << "1 录入学生信息 \n";
        cout << "2 显示学生信息 \n";
        cout << "3 通过名字修改成绩（法一）\n";
        cout << "4 通过名字修改成绩（法二）\n";
        cout << "5 测试复制构造函数\n";
        cout << "6 测试有参构造函数\n";
        cout << "7 以学号删除学生\n";
        cout << "8 退出\n";
        cout << "请选择所需要的操作：";
        cin >> choice;

        if (choice == 1)
        {
            cout << "请依次输入学号、姓名、专业和成绩\n";
            cin >> number >> name >> major >> score;
            printf("hell");
            STUDENT s(number, name, major, score);
           printf("hell");
            printf("hell");
            studentList.add_student(s);
        }
        else if (choice == 2){
            cout << "1 全部输出\n";
            cout << "2 输入最低分最高分 按区间输出\n";
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
            cout << "请输入要查询的学生姓名：";
            char name[20];
            cin >> name;
            if (studentList.existByName(name)){
                cout << "请输入要修改的成绩：";
                double score;
                cin >> score;
                studentList.getByName(name).get_score() = score;
                studentList.display(name);
            }
            else
                cout << "查询的学生 " << name << " 不存在！\n";
        }
        else if (choice == 4){
            cout << "请输入学生的姓名和成绩：";
            char name[20];
            double score;
            cin >> name >> score;
            if (studentList.existByName(name))
                studentList.modifyScoreByName(name, score);
            else
                cout << "学生 " << name << " 不存在！\n";
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
            cout << "请输入学号\n";
            cin >> num;
            if(studentList.delete_student(num)==1)
                cout << "删除成功" << "\n";
            else
                cout << "没有这个学生的信息，请重输" << "\n" << endl;
        }
        else if(choice == 8 ) break;
        else
            cout << "你的选择有误，请重新选择！\n" << endl;
    }

    return 0;
}

