//
// Created by Planck Chang on 2021/10/4.
//

#include "20271259_2.h"
namespace N20271259 {
    CStudentList::CStudentList() {
        gStu = NULL;
        count = 0;
        available = 0;
    }

    CStudentList::CStudentList(const CStudentList &studentList) {
        count = studentList.count;
        available = studentList.available;
        int num = studentList.count + studentList.available;
        if (num == 0)
            gStu = NULL;
        else {
            gStu = new STUDENT[num];
            for (int i = 0; i < studentList.count; i++)
                gStu[i] = studentList.gStu[i];
        }
    }

    CStudentList::CStudentList(const STUDENT & stu){
        gStu = new STUDENT[BLOCK];
        gStu[0] = stu;
        count = 1;
        available = BLOCK - 1;
    }

    CStudentList &CStudentList::operator=(const CStudentList &studentList) {
        if (this != &studentList) {
            delete[] gStu;
            count = studentList.count;
            available = studentList.available;
            int num = studentList.count + studentList.available;
            if (num == 0)
                gStu = NULL;
            else {
                gStu = new STUDENT[num];
                for (int i = 0; i < studentList.count; i++)
                    gStu[i] = studentList.gStu[i];
            }
        }

        return *this;
    }

    CStudentList::~CStudentList() {
        delete[] gStu;
    }

    void CStudentList::add_student(STUDENT &student) {
        if (available == 0) {
            STUDENT *tmp = new STUDENT[count + BLOCK];
            for (int i = 0; i < count; i++)
                tmp[i] = gStu[i];

            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }
        gStu[count] = student;
        count++;
        available--;
    }

    bool CStudentList::existByName(char *name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].name) == 0)
                return true;
        }
    }

    STUDENT &CStudentList::getByName(char *name){
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].name) == 0)
                return gStu[i];
        }
        return gStu[-1];
    }

    STUDENT & CStudentList::modifyScoreByName(char * name, double score){
        STUDENT & stu = getByName(name);
        stu.score = score;
        return stu;
    }

    void CStudentList::display(){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            cout << gStu[i].number << "\t" << gStu[i].name << "\t"
                 << gStu[i].major << "\t" << gStu[i].score << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(char * name){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            if(strcmp(gStu[i].name, name) == 0)
                cout << gStu[i].number << "\t" << gStu[i].name << "\t"
                     << gStu[i].major << "\t" << gStu[i].score << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(int min, int max) {
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for(int i=0; i< count; i++){
            if(gStu[i].score <max && gStu[i].score > min)
                cout << gStu[i].number << "\t" << gStu[i].name << "\t" << gStu[i].major << "\t" << gStu[i].score << "\n";
        }
    }

    int CStudentList::delete_student(int num) {
        int flag;

        for(int i=0; i< count; i++){
            if(gStu[i].number == num){
                for(int j=i; j< count; j++)
                    gStu[j] = gStu[j+1];
                flag=1;
                count--;
                available++;
            }
            if(flag==1)
                break;
        }
        if(available>=20){
            STUDENT *tmp = new STUDENT[available-BLOCK];
            for (int i = 0; i < count; i++) {
                tmp[i].number = gStu[i].number;
                strcpy(tmp[i].name, gStu[i].name);
                strcpy(tmp[i].major, gStu[i].major);
                tmp[i].score = gStu[i].score;
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }

        return flag;
    }
}
