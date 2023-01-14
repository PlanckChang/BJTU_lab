#include <iostream>
using namespace std;

class Component{
public:
    void operation(){
        cout << "base Component \n";
    }
};

class Decorator:public Component{
private:
    Component * component;
public:

    Decorator(Component &component1){
        component = &component1;
    }


    void operation(){
        component->operation();
        cout << "decorator \n";
    }
};

class ConcreteDecorator:public Decorator{
public:
    ConcreteDecorator(Component &component): Decorator(component){
    }
    void operation(){
        Decorator::operation();
        cout << "concreteDecorator\n";
    }
};

class A:public ConcreteDecorator{
public:
    A(Component &component1): ConcreteDecorator(component1){

    }
    void operation(){
        ConcreteDecorator::operation();
//        ConcreteDecorator::Decorator::Component::operation();
        cout << "A op\n";
    }
};
int main() {
    Component component;
    A *p = new A(component);
    p->operation();
}
