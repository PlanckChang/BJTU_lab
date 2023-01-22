//
// Created by Planck Chang on 2021/12/6.
//

#ifndef INC_8_2_STACK_H
#define INC_8_2_STACK_H
#include"MyString.h"
template<class T> class STACKIterator;


template<class T> class STACK
{

public:
    STACK() : head(NULL) {  }
    virtual ~STACK()
    {
        link * cur = head;
        while(NULL != head)
        {
            cur = cur->next;
            delete head->data;
            delete head;
            head = cur;
        }
    }

    void push(T * data){ head = new link(data, head); }

    T * pop()
    {
        if(NULL == head)
            return NULL;
        else
        {
            T * result = head->data;
            link * oldhead = head;
            head = head->next;
            delete oldhead;
            return result;
        }
    }
    T * peek() const { return head->data; }
public:
    friend class STACKIterator<T>;
    struct link
    {
        link * next;
        T * data;

        link(T * data, link * next)
        {
            this->data = data;
            this->next = next;
        }
    };
private:
    link * head;
};

// STACK类模板的迭代器的定义
template<class T> class STACKIterator
{
private:
    typename STACK<T>::link * p;
public:
    STACKIterator(const STACK<T> & t) : p(t.head) {  }
    STACKIterator(const STACKIterator & t) : p(t.p) {  }

    STACKIterator & operator++()
    {
        if(NULL != p->next)
            p = p->next;
        else
            p = NULL;
        return *this;
    }

    const STACKIterator operator++(int)
    {
        STACKIterator old(*this);
        if (NULL != p->next)
            p = p->next;
        else
            p = NULL;

        return old;
    }

    T * current() const
    {
        if(NULL == p)
            return NULL;
        return p->data;
    }

    operator bool() const
    {
        return NULL == p ? false : true;
    }


};


template<class T> class CNamedStack : public STACK<T>
{
public:
    CNamedStack(const MyString & s) : name(s) { }
    MyString & set_name(const MyString & s) { name = s; return name; }
    const MyString & get_name() const { return name; }

private:
    MyString name;
};


class CIntStack : public STACK<int>
{

};
#endif //INC_8_2_STACK_H
