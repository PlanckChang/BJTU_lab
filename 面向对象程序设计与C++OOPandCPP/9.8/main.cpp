#include<iostream>
using namespace std;

class Base
{
public:
    Base() { cout << /*this <<*/ "Base()" << endl; }
    Base(const Base & ) { cout << /*this <<*/ "Base(const Base &)" << endl; }
    ~Base() { cout << /*this <<*/ "~Base()" << endl; }
    /*virtual*/ void what(){ cout << /*this <<*/ "class Base." << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << /*this <<*/ "Derived()" << endl; }
    Derived(const Derived & d) : Base(d) { cout << /*this <<*/ "Derived(const Derived &)" << endl; }
    ~Derived() { cout << /*this <<*/ "~Derived()" << endl; }
    void what(){ cout << /*this <<*/ "class Derived." << endl; }
};

int main()
{
    try
    {
        throw Derived();
    }
    catch(Base b)
    {
        //cout << &b;
        b.what();
    }
    catch (Derived d)
    {
        //cout << &d;
        d.what();
    }

    cout << endl;

    try
    {
        Derived e;
        //cout << &e << endl;
        throw e;
    }
    catch(Base & b)
    {
        //cout << &b;
        b.what();
    }

    cout << endl;

    try
    {
        throw Derived();
    }
    catch (Derived & d)
    {
        //cout << &d;
        d.what();
    }
    catch (Base & b)
    {
        b.what();
    }

    return 0;
}
