#pragma once
#include"student.h"


#pragma once
#include"student.h"

void showError(int idx);

class CNode
{
    friend class CStudentList;
    friend class CAssociation;
public:

    CNode(CStudent * p) : pstu(p), ref(0), next(NULL){}

    ~CNode() { delete pstu; }
    CStudent * get_student() { return pstu; }
    int get_ref() const { return ref; }
    void set_next(CNode * p) { next = p; }
    CNode * get_next() { return next; }
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

    virtual ~CStudentList()
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
    CNode * cmpid(int num) const
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

    bool clear()
    {
        bool flag = true;
        CNode * tmp = head.next;
        while (NULL != tmp)
        {
            if (0 == tmp->ref)
            {
                head.next = tmp->next;
                delete tmp;
                tmp = head.next;
                --count;
            }
            else
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
private:
    CStudentList(const CStudentList &stuMng);
    CStudentList & operator=(const CStudentList &stuMng);

protected:
    CNode head;
    int count;
};


class CStudentListEx : public CStudentList
{
public:
    virtual void show()
    {
        cout << "id\tname\tmajor\t\tscore\tsupervisor\tref" << endl;
        CNode * tmp = head.get_next();
        while (NULL != tmp)
        {
            tmp->get_student()->display(cout);
            cout << "\t";
            if (NULL == dynamic_cast<CGraduate*>(tmp->get_student()))
                cout << "\t";

            cout << tmp->get_ref() << endl;
            tmp = tmp->get_next();
        }
    }

    virtual void write_binary(ostream & out)
    {
        int flag = 1;
        CStudent * p = NULL;
        CNode * tmp = head.get_next();
        while (NULL != tmp)
        {
            flag = 1;
            p = tmp->get_student();
            if (dynamic_cast<CGraduate*>(p))
                flag = 2;
            out.write((char*)&flag, sizeof(int));
            p->write_binary(out);
            tmp = tmp->get_next();
        }
        flag = -1;
        out.write((char*)&flag, sizeof(int));
    }

    virtual bool read_binary(istream & in)
    {
        if (!this->clear())
            return false;

        int flag;
        CStudent * p = NULL;
        in.read((char*)&flag, sizeof(int));
        while (-1 != flag)
        {
            if (1 == flag)
                p = new CStudent;
            else
                p = new CGraduate;
            p->read_binary(in);
            this->add(p);
            in.read((char*)&flag, sizeof(int));
        }
        return true;
    }
};

class CAssociation
{
public:
    CAssociation(MyString & s) : name(s), ppList(NULL), count(0) { }
    virtual ~CAssociation()
    {
        for (int i = 0; i < count; ++i)
            --ppList[i]->ref;
        delete[] ppList;
    }

    int index(CNode * p)
    {
        int i = 0;
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

    virtual void show() const
    {
        cout << name.get_string() << "  member list:" << endl;
        cout << "id\tname\tmajor\t\tscore\tsupervisor\tref" << endl;
        for(int i = 0; i < count; ++i)
        {
            ppList[i]->get_student()->display(cout);
            cout << "\t";
            if (NULL == dynamic_cast<CGraduate*>(ppList[i]->get_student()))
                cout << "\t";
            cout << ppList[i]->get_ref() << endl;
        }
    }

    void clear()
    {
        for (int i = 0; i < count; ++i)
            --ppList[i]->ref;
        delete ppList;
        ppList = NULL;
        count = 0;
    }

    virtual void write_binary(ostream & out)
    {
        int number;
        for (int i = 0; i < count; ++i)
        {
            number = ppList[i]->get_student()->get_number();
            out.write((char*)&number, sizeof(int));
        }
        number = -1;
        out.write((char*)&number, sizeof(int));
    }

    virtual bool read_binary(istream & in, const CStudentListEx & list)
    {
        this->clear();
        int number;
        in.read((char*)&number, sizeof(int));
        while (-1 != number)
        {
            CNode * p = list.cmpid(number);
            this->add(p);

            in.read((char*)&number, sizeof(int));
        }
        return true;
    }

private:
    CAssociation(const CAssociation &);
    CAssociation & operator=(const CAssociation &);

    MyString name;
    CNode ** ppList;
    int count;
};






