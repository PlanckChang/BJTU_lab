//
// Created by Planck Chang on 2021/12/2.
//

#include "Lab5_conf.h"
#include <stdio.h>
#include <stdlib.h>


void changemode(){
    printf("please choose one operating mode\n");
    printf("1 auto mode\n");
    printf("2 interactive mode\n");
    printf("please enter the choice\n");
    int choice;
    scanf("%d", &choice);
    FILE *pf = fopen("mode.ini", "w");
    if(pf==NULL){
        printf("file open error\n");
        exit(1);
    }
    fprintf(pf, "%d", choice);
    fclose(pf);
    printf("change success\n");
}

void changeconf(int line)
{
    FILE *pf = fopen("conf.ini", "r");
    if(!pf)
    {
        printf("file open error\n");
        exit(1);
    }

    char command[8][30];
    for(int i=0; i<8; ++i)
    {
        fscanf(pf, "%s", command[i]);
    }
    fclose(pf);

    if(line>=1 && line <=8)
    {
        if(line == 1)
            printf("please enter new file save path\n");
        else if(line == 2)
            printf("please enter new file name\n");
        else if(line == 3)
            printf("enter fist, second elements' max\n");
        else if(line == 4)
            printf("enter fist, second elements' min\n");
        else if(line == 5)
            printf("enter third element's max\n");
        else if(line == 6)
            printf("enter third element's min\n");
        else if(line == 7)
            printf("enter the max of record count number\n");
        else if(line == 8)
            printf("enter the min of record count number\n");
        scanf("%s",command[line-1]);
    }
    pf = fopen("conf.ini", "w");
    if(!pf)
    {
        printf("file open error\n");
        exit(1);
    }
    for(int i=0; i<8; ++i)
    {
        fprintf(pf, "%s\n", command[i]);
    }
    fclose(pf);
    printf("change success\n");
}

void selfcheck(){
    FILE *pf1 = fopen("conf.ini", "r");
    if(!pf1)
    {
        printf("file open error\n");
        exit(1);
    }
    FILE *pf2 = fopen("mode.ini","r");
    if(!pf2)
    {
        printf("file open error\n");
        exit(1);
    }

    int choice;
    fscanf(pf2,"%d", &choice);
    if(choice!=1 && choice != 2)
    {
        printf("the mode.ini file error\n");
        exit(0);
    }
    fclose(pf2);
    fclose(pf1);
}