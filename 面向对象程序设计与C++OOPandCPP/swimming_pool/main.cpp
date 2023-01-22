#include <iostream>
#include <conio.h>
#include "circle.h"
#include "swimmingpool.h"
int main() {
    double r;
    while (1) {
        cout << "please enter the radius of the swimming poll you want to build\n";
        cin >> r;
        CCircle circle(r);
        CSwimmingPool swimmingPool(circle);
        cout << "the cost of the fence is " << swimmingPool.fence_cost() << " yuan" <<endl;
        cout << "the cost of the passageway is " << swimmingPool.passageway_cost() << " yuan" << endl;
        cout << "if you want to exit. please enter e\n";
        if (_getch() == 'e')
            break;
    }
}
