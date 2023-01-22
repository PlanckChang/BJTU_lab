//
// Created by Planck Chang on 2021/10/4.
//

#include "20271259_2.h"
namespace N20271259 {
    CStudentList::CStudentList(){
        gStu = NULL;
        count = 0;
        available = 0;
    }

    CStudentList::CStudentList(const CStudentList &studentList){
        count = studentList.count;
        available = studentList.available;
        int num = studentList.count + studentList.available;
        if (num == 0)
            gStu = NULL;
        else {
            gStu = new CStudent[num];
            for (int i = 0; i < studentList.count; i++)
                gStu[i] = studentList.gStu[i];
        }
    }

    CStudentList::CStudentList(const CStudent & stu){
        gStu = new CStudent[BLOCK];
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
                gStu = new CStudent[num];
                for (int i = 0; i < studentList.count; i++)
                    gStu[i] = studentList.gStu[i];
            }
        }

        return *this;
    }

    CStudentList::~CStudentList() {
        delete[] gStu;
    }

    void CStudentList::add_student(CStudent &student) {
        if (available == 0) {
            CStudent *tmp = new CStudent[count + BLOCK];
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
            if (strcmp(name, gStu[i].get_name().get_string()) == 0)
                return true;
        }
    }

    CStudent &CStudentList::getByName(char *name){
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].get_name().get_string()) == 0)
                return gStu[i];
        }
        return gStu[-1];
    }

    CStudent & CStudentList::modifyScoreByName(char * name, double score){
        CStudent & stu = getByName(name);
        stu.get_score() = score;
        return stu;
    }

    void CStudentList::display(){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            cout << gStu[i].get_number() << "\t" << gStu[i].get_name().get_string() << "\t"
                 << gStu[i].get_major().get_string() << "\t" << gStu[i].get_score() << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(char * name){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            if(strcmp(gStu[i].get_name().get_string(), name) == 0)
                cout << gStu[i].get_number() << "\t" << gStu[i].get_name().get_string() << "\t"
                     << gStu[i].get_major().get_string() << "\t" << gStu[i].get_score() << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(int min, int max) {
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for(int i=0; i< count; i++){
            if(gStu[i].get_score() <max && gStu[i].get_score() > min)
                cout << gStu[i].get_number() << "\t" << gStu[i].get_name().get_string() << "\t" << gStu[i].get_major().get_string() << "\t" << gStu[i].get_score() << "\n";
        }
    }

    int CStudentList::delete_student(int num) {
        int flag;

        for(int i=0; i< count; i++){
            if(gStu[i].get_number() == num){
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
            CStudent *tmp = new CStudent[available - BLOCK];
            for (int i = 0; i < count; i++) {
                // v1中保存了 分开赋值的函数
                tmp[i]=gStu[i];
            }
            delete[] gStu;
            gStu = tmp;
            available = BLOCK;
        }

        return flag;
    }

    const char* MyString::set_string(const char*p){
        delete [] m_pbuf;
        if(p==NULL)
            m_pbuf = new char('\0');
        else{
            int len = strlen(p)+1;
            m_pbuf = new char[len];
            strcpy(m_pbuf, p);
        }
        return m_pbuf;
    }

    const char * MyString::append(const char*p){
        if(p!=NULL){
            int len =strlen(m_pbuf)+strlen(p)+1;
            char* tem = new char[len];
            strcpy(tem, m_pbuf);
            strcat(tem, p);
            delete [] m_pbuf;

            m_pbuf = tem;
        }
        return m_pbuf;
    }

    const char *MyString::append(const MyString&s) {
        if(s.m_pbuf!=NULL){
            int len = strlen(m_pbuf) +strlen(s.m_pbuf) +1;
            char* tem = new char [len];
            strcpy(tem, m_pbuf);
            strcat(tem, s.m_pbuf);
            delete [] m_pbuf;
            m_pbuf = tem;
        }
        return m_pbuf;
    }


}
