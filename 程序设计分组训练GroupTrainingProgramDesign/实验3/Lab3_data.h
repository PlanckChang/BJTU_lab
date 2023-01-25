//
// Created by Planck Chang on 2021/10/24.
//

#ifndef LAB_3_LAB3_DATA_H
#define LAB_3_LAB3_DATA_H
#define  MAX_STR_LEN 20

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

#endif //LAB_3_LAB3_DATA_H
