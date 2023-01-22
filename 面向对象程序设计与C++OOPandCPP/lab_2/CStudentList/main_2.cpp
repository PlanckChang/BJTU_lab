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
            if (strcmp(name, gStu[i].get_name()) == 0)
                return true;
        }
    }

    STUDENT &CStudentList::getByName(char *name){
        for (int i = 0; i < count; i++) {
            if (strcmp(name, gStu[i].get_name()) == 0)
                return gStu[i];
        }
        return gStu[-1];
    }

    STUDENT & CStudentList::modifyScoreByName(char * name, double score){
        STUDENT & stu = getByName(name);
        stu.get_score() = score;
        return stu;
    }

    void CStudentList::display(){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            cout << gStu[i].get_number() << "\t" << gStu[i].get_name() << "\t"
                 << gStu[i].get_major() << "\t" << gStu[i].get_score() << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(char * name){
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for (int i = 0; i < count; i++){
            if(strcmp(gStu[i].get_name(), name) == 0)
                cout << gStu[i].get_number() << "\t" << gStu[i].get_name() << "\t"
                     << gStu[i].get_major() << "\t" << gStu[i].get_score() << "\n";
        }
        cout << endl;
    }

    void CStudentList::display(int min, int max) {
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for(int i=0; i< count; i++){
            if(gStu[i].get_score() <max && gStu[i].get_score() > min)
                cout << gStu[i].get_number() << "\t" << gStu[i].get_name() << "\t" << gStu[i].get_major() << "\t" << gStu[i].get_score() << "\n";
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
            STUDENT *tmp = new STUDENT[available-BLOCK];
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



    int MyString::get_length(){
        int tem = strlen(m_pbuf);
        return  tem;
    }

    char* MyString::get_string() {
        int len = strlen(m_pbuf) + 1;
        char* tem = new char[len];
        tem = strcpy(tem, m_pbuf);
        return tem;
    }

    MyString::MyString(const char *p) {

        if (p == NULL)
            m_pbuf = new char('\0');
        else {
            m_pbuf = new char[strlen(p) + 1];
            strcpy(m_pbuf, p);

        }
        cout << "MyString类的有参构造函数被调用，当前字符串为：";
        cout << m_pbuf  << endl;
    }


    MyString::MyString(const MyString &s) {
        int len = strlen(s.m_pbuf) + 1;
        m_pbuf = new char[len];
        strcpy(m_pbuf, s.m_pbuf);
        cout << "MyString类的复制构造函数被调用，当前字符串为：";
        cout << m_pbuf  << endl;
    }

    MyString::~MyString() {
        cout << "MyString类的析构函数被调用，当前字符串为："<< m_pbuf << endl;
        delete [] m_pbuf;
    }

    MyString::MyString() {
        m_pbuf = new char('\0');
        cout << "MyString类的默认构造函数被调用" << endl;
    }

    MyString & MyString::operator=(const MyString &s) {
        if(this!=&s){
            delete[]m_pbuf;
            int len =strlen(s.m_pbuf)+1;
            m_pbuf = new char[len];
            strcpy(m_pbuf, s.m_pbuf);
        }
        cout << "MyString类的赋值运算符被调用，当前字符串为：" << m_pbuf << endl;
        return *this;
    }
}
