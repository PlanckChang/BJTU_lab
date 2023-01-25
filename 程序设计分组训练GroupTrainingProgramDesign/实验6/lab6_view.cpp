//
// Created by Planck Chang on 2021/12/20.
//

#include "lab6_view.h"
#include "stdio.h"
void showarray(int **a, int record_num) {
    for(int i=0; i<record_num; ++i)
    {
        printf("%d, %d, %d\n", a[i][0], a[i][1], a[i][2]);
    }
}

void showstructarray(DATAITEM *a, int record_num) {
    for(int i=0 ; i<record_num; ++i)
    {
        printf("%d, %d, %d\n", a[i].item1, a[i].item2, a[i].item3);
    }
}

void showpointerarray(DATAITEM **a, int record_num) {
    for(int i =0; i<record_num; ++i)
    {
        printf("%d, %d, %d", a[i]->item1, a[i]->item2, a[i]->item3);
    }
}

void showlink(Node  *pHead) {
    Node * p = pHead;
    while(!p)
    {
        printf("%d, %d, %d\n", p->data[0], p->data[1], p->data[2]);
        p = p->next;
    }
}
