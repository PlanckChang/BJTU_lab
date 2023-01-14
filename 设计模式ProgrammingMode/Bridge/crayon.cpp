//
// Created by Planck Chang on 2022/10/9.
//

#include <iostream>
#include <string>
using namespace std;

class Crayon{
protected:
    string size;
    string color;
public:
    void paint(){
        cout << size << " " << color << " is painting\n";
    }
    virtual void setConfig() = 0;
};

class RedBigCrayon:public Crayon{
public:
    void setConfig() override{
        size = "big";
        color = "red";
    }
    RedBigCrayon(){
        setConfig();
    }
};

class BlueSmallCrayon:public Crayon{
public:
    void setConfig(){
        size = "small";
        color = "blue";
    }
    BlueSmallCrayon(){
        setConfig();
    }
};

int main(){
    Crayon * smallblue = new BlueSmallCrayon();
    smallblue->paint();
    Crayon * bigred = new RedBigCrayon();
    bigred->paint();
}