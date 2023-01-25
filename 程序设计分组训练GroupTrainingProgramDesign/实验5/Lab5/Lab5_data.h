//
// Created by Planck Chang on 2021/12/1.
//

#ifndef LAB5_LAB5_DATA_H
#define LAB5_LAB5_DATA_H

typedef struct configinfo
{
    char filesavepath[100];
    char filename[100];
    int maxvalue1;
    int minvalue1;
    int maxvalue2;
    int minvalue2;
    int recordcount1;
    int recordcount2;
}CONF;

typedef struct{
    int item1;
    int item2;
    int item3;
}DATAITEM;

typedef struct Node{
    int data[3];
    Node *next;
};

typedef struct {
    int totaldatanum;
    Node * next;
}Link;
#endif //LAB5_LAB5_DATA_H
