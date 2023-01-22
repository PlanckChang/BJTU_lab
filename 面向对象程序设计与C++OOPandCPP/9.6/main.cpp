#include <iostream>
using namespace std;
class A
{
public:
    A(){cout << "A()" << endl;}
    A(const A&e) {cout << "A(const A &" << endl;}
    virtual ~A() {cout<< "~A() " << endl;}
};
class B : public A
{
public:
    B() {cout << "B()" << endl;}
    B(const B& e) {cout << "B(const B&)" << endl;}
    ~B() {cout << "~B()" << endl;}
};

class C: public B
{
public:
    C() {cout << "Expt2()" << endl;}
    C(const C & E) {cout << "C(const C&)" << endl;}
    ~C() { cout << "~C()" << endl;}
};

void func(){ B e; throw e;}

int main() {
    try {
        try
        {
            B e;
            func();
            }
        catch (B &e) {cout << "B error" << endl;}
        catch (C e) {cout << "C error" << endl;}
        }
    catch (A e) {cout << "A error" << endl;}
    catch (B e) {cout << "B error" << endl;}
    catch (C e) {cout << "C error" << endl;}


}


