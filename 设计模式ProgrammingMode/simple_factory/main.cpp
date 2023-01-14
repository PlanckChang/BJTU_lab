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
public:
    Arithmetic* create(int i){
        switch (i) {
            case 1:
                return new Add;
                break;
            case 2:
                return new Subtract;
                break;
            default:
                break;
        }
    }
};

int main() {
    auto *factory_arithmetic = new Factory();
    int add = factory_arithmetic->create(1)->operation(3, 4);
    int subtract = factory_arithmetic->create(2)->operation(4, 3);
    cout << "the add result of add class by factory class is " << add << "\n";
    cout << "the subtract  result of add class by factory class is " << subtract << endl;

    return 0;
}