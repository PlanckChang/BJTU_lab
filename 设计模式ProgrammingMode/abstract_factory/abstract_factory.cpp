//
// Created by Planck Chang on 2022/9/23.
//

#include <iostream>

using namespace std;

class Arithmetic{
public:
    virtual int operation(int a, int b) = 0;
};

class Add:public Arithmetic{
public:
    int operation(int a, int b){
        return a+b;
    }
};

class Subtract: public Arithmetic{
public:
    int operation(int a, int b){
        return a-b;
    }
};

class Factory{
// notice: here two method couldn't be set virtual func, otherwise the subclass has to implement the whole func, which is
// not we want.
// prior to notice is wrong
public:
    virtual Arithmetic* create()=0;
};

class Factory_Add: public Factory{
public:
    Arithmetic* create(){
        return new Add();
    }
};

class Factory_Subtract: public Factory{
public:
    Arithmetic* create(){
        return new Subtract();
    }
};


int main() {
    Factory_Add *factoryAdd = new Factory_Add();
    Factory_Subtract *factorySubtract = new Factory_Subtract();

    int add = factoryAdd->create()->operation(3, 4);
    int subtract = factorySubtract->create()->operation(4, 3);
    cout << "the add result of add class by factory class is " << add << "\n";
    cout << "the subtract  result of add class by factory class is " << subtract << endl;

    return 0;
}
