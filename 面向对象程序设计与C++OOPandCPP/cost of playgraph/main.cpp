#include <iostream>
#include <conio.h>
#include "playground.h"

int main() {
    double len, w, lane;
    while(true){
        cout << "���������򳡵ĳ�������ܵ���ȣ�";
        cin >> len >> w >> lane;
        CPlaygraph g(len, w);
        CPlayground ground(g, lane);
        cout << "����ǣ�" << ground.compute_cost() << endl;
        cout << "��e �˳��� ������������  " << endl;
        if( getch() == 'e') break;
    }

    return 0;
}
