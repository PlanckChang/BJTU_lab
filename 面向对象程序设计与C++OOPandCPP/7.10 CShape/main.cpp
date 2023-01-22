#include <iostream>
#include "column.h"
#include "shape.h"
int main() {
    int choice;


    while(true)
    {
        cout << "please enter the shape of column you want" <<
             " 1 rectangle 2 triangle 3 circle" << endl;
        cin >> choice;

        if(choice ==1 ){
            cout << "please enter the length, width and height" << endl;
            double len, w, h;
            cin >> len >>w >> h;

            CRectangle * rectangle = new CRectangle(len, w);
            CColumn column(rectangle, h);
            cout << "the volume is " << column.volume() << endl;
        }
        else if(choice ==2) {
            cout << "please enter the three sides of triangle and height " << endl;
            double s1, s2, s3, h;
            cin >> s1 >> s2 >> s3 >> h;
            while((s1+s2)<=s3 || (s2+s3)<=s1 || (s1+s3)<= s2)
            {
                cout << "triangle's parameters error, try again " << endl;
                cin >> s1 >> s2 >> s3;
            }
            CTriangle *triangle = new CTriangle(s1, s2, s3);

            CColumn column(triangle, h);
            cout << "the volume is " << column.volume() << endl;
        }
        else if(choice == 3){
            cout << "please enter the radius and height " <<endl;
            double r, h;
            cin >> r >> h;

            CCircle * circle = new CCircle(r);
            CColumn column(circle, h);
            cout << "the volume is " << column.volume() << endl;
        }


        cout << "enter 0 to exit, others to to continues" << endl;
        cin >> choice;
        if(choice == 0) break;
    }
}



