#include "playground.h"
#include <conio.h>
using namespace  std;
int main() {
    double len, w;
    CPlaygraph * p =NULL, *old;
    CPlayground ground;
    while(true)
    {
        bool correct = false;
        while(!correct)
        {
            cout << "please enter the type of playground: 1 football field 2 skating rink " << endl;
            int choice =0;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "please enter the length and width of football field ";
                    cin >> len >> w;
                    p = new CRectgraph(len, w);
                    old = ground.attach_graph(p);
                    delete old;
                    correct = true;
                    break;
                case 2:
                    cout << "please enter the radius of the skating rink" ;
                    cin >> len;
                    p = new CCirclegraph(len);
                    old = ground.attach_graph(p);
                    delete old;
                    correct = true;
                    break;
                default:
                    cout << "error choice, please try again" << endl;
                    cin.clear();
                    cin.ignore();

            }
        }
        cout << "the cost of manufacture is" << ground.compute_cost() << endl;
        cout << "enter e to exit, others to continues" << endl;
        if(getchar() == 'e') break;
    }
    return 0;
}
