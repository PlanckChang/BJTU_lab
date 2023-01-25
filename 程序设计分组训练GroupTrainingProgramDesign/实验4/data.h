//
// Created by Planck Chang on 2021/10/29.
//

#ifndef LAB4_DATA_H
#define LAB4_DATA_H

#define  MAX_STR_LEN 100

typedef struct configinfo{
    char filesavepath[MAX_STR_LEN];
    char filename[MAX_STR_LEN];
    int number;
    int maxvalue1;
    int minvalue1;
    int maxvalue2;
    int minvalue2;
    int recordcount1;
    int recordcount2;
}CONF;

typedef struct DataItem{
    int item1; //���ݼ�¼��Ԫ���һ��Ԫ��
    int item2; //���ݼ�¼��Ԫ��ڶ���Ԫ��
    int item3; //���ݼ�¼��Ԫ�������Ԫ��
}DATAITEM;

#endif //LAB4_DATA_H
