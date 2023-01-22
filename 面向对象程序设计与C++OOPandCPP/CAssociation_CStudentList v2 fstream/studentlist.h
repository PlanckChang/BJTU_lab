//
// Created by Planck Chang on 2021/11/12.
//

#ifndef CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENTLIST_H
#define CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENTLIST_H
#pragma once
#include"student.h"

void showError(int idx);

class CNode
{
    friend class CStudentList;
    friend class CAssociation;
public:

    CNode(CStudent * p) : pstu(p), ref(0), next(NULL)
    {}

    ~CNode() { delete pstu; }

private:
    CNode(const CNode &);
    CNode & operator=(const CNode &);

    CStudent * pstu;
    int ref;
    CNode * next;
};

class CStudentList
{
public:
    CStudentList() : head(NULL), count(0) {}

    ~CStudentList()
    {
        CNode * tmp = head.next;
        while (NULL != tmp) {
            head.next = tmp->next;
            delete tmp;
            tmp = head.next;
        }
    }

    void add(CStudent * p)
    {
        CNode * tmp = new CNode(p);
        tmp->next = head.next;
        head.next = tmp;
        ++count;
    }


    int del(int num)
    {
        CNode * tmp = head.next, *pre = NULL;
        while (NULL != tmp)
        {
            if (tmp->pstu->get_number() != num)
            {
                pre = tmp;
                tmp = tmp->next;
            }
            else
                break;
        }
        if (NULL == tmp)
            return 1;
        else if(tmp->ref > 0)
            return 2;
        else
        {
            pre->next = tmp->next;
            delete tmp;
            --count;
            return 0;
        }
    }
    CNode * get(int num) const
    {
        CNode * tmp = head.next;
        while (NULL != tmp)
        {
            if (tmp->pstu->get_number() != num)
                tmp = tmp->next;
            else
                break;
        }
        if (NULL == tmp)
            return NULL;
        else
            return tmp;
    }

    int get_count() const { return count; }

    void show() const
    {
        cout << "学号\t姓名\t专业\t成绩\t引用计数" << endl;
        CNode * tmp = head.next;
        while (NULL != tmp)
        {
            cout << tmp->pstu->get_number() << "\t"
                 << tmp->pstu->get_name().get_string() << "\t"
                 << tmp->pstu->get_major().get_string() << "\t"
                 << tmp->pstu->get_score() << "\t"
                 << tmp->ref << endl;
            tmp = tmp->next;
        }
    }

    ofstream & write_txt(ofstream &out) const
    {
        CNode *tmp = head.next;
        while(tmp != NULL)
        {
            tmp->pstu->write_txt(out);
            tmp= tmp->next;
        }
        return out;
    }
    ifstream & read_txt(ifstream &in)
    {
        CStudent *p;
        in.get();
        while(!in.eof())
        {
            in.seekg(-1, ios_base::cur);
            p = new CStudent;
            p->read_txt(in);
            add(p);
            in.get();
        }
        return in;
    }
    ofstream &write_binary(ofstream &out) const
    {
        CNode *tem = head.next;
        while(tem !=NULL)
        {
            tem->pstu->write_binary(out);
            tem = tem->next;
        }
        return out;
    }

    ifstream  &read_binary(ifstream &in)
    {
        CStudent *p;
        in.get();
        while(!in.eof())
        {
            in.seekg(-1, ios_base::cur);
            p = new CStudent;
            p->read_binary(in);
            add(p);
            in.get();
        }
        return in;
    }
private:
    CStudentList(const CStudentList &);
    CStudentList & operator=(const CStudentList &);

    CNode head;
    int count;
};

class CAssociation
{
public:
    CAssociation(MyString & s) : name(s), ppList(NULL), count(0) { }
    ~CAssociation()
    {
        for (int i = 0; i < count; ++i)
            --ppList[i]->ref;
        delete[] ppList;
    }

    int index(CNode * p)
    {
        int i;
        for (i = 0; i < count; ++i)
            if (p == ppList[i])
                return i;
        return -1;
    }

    void add(CNode * p)
    {
        if (NULL == p || index(p) >= 0)
            return;
        else
        {
            CNode ** tmp = new CNode*[count + 1];
            for (int i = 0; i < count; i++)
                tmp[i] = ppList[i];
            tmp[count] = p;
            ++tmp[count]->ref;
            delete[] ppList;
            ppList = tmp;
            ++count;
        }

    }

    int del(CNode * p)
    {
        int i = index(p);
        if (i < 0)
            return 3;
        else
        {
            --ppList[i]->ref;
            CNode ** tmp = NULL;
            if(count > 1)
                tmp = new CNode*[count - 1];

            for (int j = 0; j < count; j++)
            {
                if (j == i)
                    continue;
                if (j < i)
                    tmp[j] = ppList[j];
                else
                    tmp[j - 1] = ppList[j];
            }
            delete[] ppList;
            ppList = tmp;
            --count;

            return 0;
        }
    }

    void show() const
    {
        cout << name.get_string() << "成员名单：" << endl;
        cout << "学号\t姓名\t专业\t成绩" << endl;
        for(int i = 0; i < count; i++)
        {
            cout << ppList[i]->pstu->get_number() << "\t"
                 << ppList[i]->pstu->get_name().get_string() << "\t"
                 << ppList[i]->pstu->get_major().get_string() << "\t"
                 << ppList[i]->pstu->get_score() << endl;
        }
    }

    CNode* operator[](const int idx)
    {
        if(idx<0)
            exit(1);
        for(int i=0; i<count; ++i)
        {
            if(ppList[i]->pstu->get_number()==idx)
                return ppList[i];
        }
        return NULL;
    }

    const CNode* operator[](const int idx) const
    {
        if(idx<0)
            exit(1);
        for(int i=0; i<count; ++i)
        {
            if(ppList[i]->pstu->get_number()==idx)
                return ppList[i];
        }
        return NULL;
    }

    void operator+(CAssociation &c2)
    {
        if(c2.count=0)
            return;
        for(int i=0; i<c2.count; ++i)
        {
            add(c2.ppList[i]);
        }
    }


private:
    CAssociation(const CAssociation &);
    CAssociation & operator=(const CAssociation &);

    MyString name;
    CNode ** ppList;
    int count;
};
#endif //CASSOCIATION_CSTUDENTLIST_V2_FSTREAM_STUDENTLIST_H
