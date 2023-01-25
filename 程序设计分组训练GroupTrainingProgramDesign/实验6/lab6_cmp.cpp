//
// Created by Planck Chang on 2021/12/20.
//

#include "lab6_cmp.h"
// cmp func for 2d array
int cmparray(const void *a, const void *b) {
    int *x = *(int **) a;
    int *y = *(int **) b;
    return  ((x+2) - (y+2));
}

// x[2] - y[2] can not be sorted


int cmpstructarray(const void *a, const void *b) {
    DATAITEM * x= (DATAITEM *)a;
    DATAITEM * y= (DATAITEM *)b;
    return (x->item3 - y->item3);
}


int cmppionterarray(const void *a, const void *b) {
    int x = ((DATAITEM *)a)->item3;
    int y = ((DATAITEM*) b)->item3;
    return  (x - y);
}


void bubblesortlink(Link *head) {
    int a[head->totaldatanum][3];
    Node *tem = head->next;
    int i=0;
    while(tem){
        a[i][0] = tem->data[0];
        a[i][1] = tem->data[1];
        a[i][2] = tem->data[2];
        i++;
        tem = tem->next;
    }

    for(i = 0; i<head->totaldatanum-1; ++i){
        for(int j=0; j <head->totaldatanum-i-1;++j){
            if(a[j][2] > a[j+1][2]){
                for(int k = 0 ;k<3; ++k){
                    int t = a[j][k];
                    a[j][k] = a[j+1][k];
                    a[j+1][k] = t;
                }
            }
        }
    }
    i = 0;
    tem = head->next;
    while(tem){
        tem->data[0] = a[i][0];
        tem->data[1] = a[i][1];
        tem->data[2] = a[i][2];
        i++;
        tem = tem->next;
    }
}

void show_array(int (**a), int num) {
    for (int i = 0; i < num; ++i) {
        printf("%d, %d, %d\n", a[i][0], a[i][1], a[i][2]);
    }
}



void show_link(Link *head) {
    Node *tem = head->next;
    while(tem){
        printf("%d, %d, %d\n", tem->data[0], tem->data[1], tem->data[2]);
        tem = tem->next;
    }
}

void show_pointerarry(DATAITEM *data[], int num) {
    for (int i = 0; i < num; ++i) {
        printf("%d, %d, %d\n", data[i]->item1, data[i]->item2, data[i]->item3);
    }
}

void show_structarray(DATAITEM *data, int num) {
    for(int i= 0; i<num; ++i){
        printf("%d, %d, %d\n", data[i].item1, data[i].item2, data[i].item3);
    }
}
