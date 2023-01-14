#include <iostream>

using namespace std;
class Component{
public:
    virtual void display() = 0;
};

class Window: public Component{
public:
    void display(){
        cout << "window display\n";
    }
};

class ComponentDecorator: public Component{
private:
    Component *component;
public:
    ComponentDecorator(Component *component1){
        component = component1;
    }
    void display(){
        component->display();
    }
};

class BlackBorderBorderDecorator:public ComponentDecorator{
public:

    BlackBorderBorderDecorator(Component * component1): ComponentDecorator(component1){
    }
    void setBlackBorder(){
        cout << "black border\n";
    }
    void display(){
        ComponentDecorator::display();
        setBlackBorder();
    }
};

int main() {
    Component * window = new Window();
    ComponentDecorator * decorator = new BlackBorderBorderDecorator(window);
    decorator->display();

}
