//
// Created by Planck Chang on 2022/10/9.
//

#include <iostream>

using namespace std;

class Target{
public:
    virtual void request() = 0;
};

class Adaptee{
public:
    void specificRequest(){
       cout << "Adaptee specificRequest func is called\n";
    }
};

class Adapter:public Target{
public:
    void request(){
        adaptee.specificRequest();
    }
private:
    Adaptee adaptee;
};

int main(){
    Target * interface = new Adapter();
    interface->request();
}
