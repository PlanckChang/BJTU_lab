//
// Created by Planck Chang on 2021/11/18.
//

#ifndef BASE_DERIVE_BASE_DERIVE_H
#define BASE_DERIVE_BASE_DERIVE_H

#include <iostream>
using namespace std;

class Base
{
    int *p;
public:
    Base()
    {
        p = new int[1024];
        for(int i =0; i<1024; ++i)
            p[i] = i;
        cout << "class Base 的构造函数被调用。。。" << endl;
    }

    virtual ~Base()
    {
        delete [] p;
        cout << "class Base 的析构函数被调用。。。"  << endl;
    }

    Base(const Base &base)
    {
        p = new int [1024];
        for(int i=0; i<1024; ++i)
            p[i] = base.p[i];
        cout << "class Base 的复制构造函数被调用。。。 " << endl;
    }

    Base &operator = (const Base &base)
    {
        if(this != &base)
        {
            for(int i=0; i<1024; ++i)
                p[i] = base.p[i];
        }

        cout << "class Base 的赋值运算符函数被调用。。。 " << endl;
        return *this;
    }
};

class Derived: public Base{
    int *p;
    int num;
public:
    Derived(int n) {
        num = n * n;
        p = new int[num];
        for (int i = 0; i < num; ++i) {
            p[i] = i + n;
        }
        cout << "class Derived 的构造函数被调用。。。" << endl;
    }

    virtual ~Derived()
    {
        delete []p;
        cout << "class Derived 的析构函数被调用。。。" << endl;
    }

    Derived(const Derived& derived): Base(derived)
    {
        num = derived.num;
        p = new int[num];
        for(int i=0; i<num; ++i)
            p[i] = derived.p[i];
        cout << "class Derived 的复制构造函数被调用。。。" << endl;
    }

    Derived &operator = (const Derived& derived)
    {
        if(this != &derived)
        {
            Base::operator=(derived);
            delete [] p;
            num = derived.num;
            p = new int[num];
            for(int i=0; i<num; ++i)
                p[i] = derived.p[i];
        }
        cout << "class Derived 的赋值运算符函数被调用。。。 " << endl;
        return *this;
    }

};

#endif //BASE_DERIVE_BASE_DERIVE_H
