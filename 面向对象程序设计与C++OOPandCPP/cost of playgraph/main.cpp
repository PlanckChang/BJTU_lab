#include <iostream>
#include <conio.h>
#include "playground.h"

int main() {
    double len, w, lane;
    while(true){
        cout << "请输入足球场的长、宽和跑到宽度：";
        cin >> len >> w >> lane;
        CPlaygraph g(len, w);
        CPlayground ground(g, lane);
        cout << "造价是：" << ground.compute_cost() << endl;
        cout << "按e 退出， 按其他键继续  " << endl;
        if( getch() == 'e') break;
    }

    return 0;
}
