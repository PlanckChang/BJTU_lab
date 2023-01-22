#include <iostream>
#include "shape.h"
int main() {
    system("chcp 65001");
    Rectangle rectangle(10, 20);
    cout << " the square of rectangel is " <<rectangle.square() << endl;
    cout << "the circumference of rectangle is " << rectangle.circumference() << endl;
    Circle circle(5);
    cout <<"the square of circle is " << circle.square() << endl;
    cout << "the circumference of circle is " << circle.square() <<endl;
}
