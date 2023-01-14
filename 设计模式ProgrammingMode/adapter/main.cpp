#include <iostream>

using namespace std;
class CarController{
public:
    void move(){
        cout << "this is a car move \n";
    };
    virtual void phonate() = 0;
    virtual void twinkle() = 0;
};

class PoliceSound{
public:
    void alarmSound(){
        cout << "this is police sound\n";
    }
};

class PoliceLamp{
public:
    void alarmLamp(){
        cout << "this is police lamp\n";
    }
};

class PoliceCarAdater:public CarController{
private:
    PoliceSound * sound;
    PoliceLamp * lamp;
public:
    PoliceCarAdater(){
        sound = new PoliceSound();
        lamp = new PoliceLamp();
    }
    void phonate(){
        sound->alarmSound();
    }
    void twinkle(){
        lamp->alarmLamp();
    }
};
int main() {
    PoliceCarAdater *adater = new PoliceCarAdater();
    adater->phonate();
    adater->twinkle();
}
