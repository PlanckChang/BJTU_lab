//
// Created by Planck Chang on 2022/10/9.
//

#include <iostream>

using namespace std;

class Color{
public:
    virtual void useColor() = 0;
};

class Red:public Color{
    void useColor(){
        cout << "this is red\n";
    }
};

class Blue:public Color{
    void useColor(){
        cout << "this is blue\n";
    }
};

class Brush{
public:
    void setColor(Color* color1){
        color = color1;
    }
    virtual void paint() = 0;
    Brush(){
        color = NULL;
    }
    Color* color;
};

class BigBrush:public Brush{
public:
    void paint() override{
        cout << "big brush is painting ";
        color->useColor();
    }
};

class SmallBrush:public Brush{
public:
    void paint() override{
        cout << "small brush is painting ";
        color->useColor();
    }
};

int main(){
    Brush * brush = new BigBrush();
    brush->setColor(new Red());
    brush->paint();
}