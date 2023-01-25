//
// Created by Planck Chang on 2021/10/29.
//

#include "run.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <time.h>
#include <random>
int run(int argc, char *argv[]) {
    CONF conf;
    char num[MAX_STR_LEN];
    char filepath[MAX_STR_LEN];
    //初始化 conf的值
    conf = read_configinfo();

    srand(time(0));

    switch (argc) {
        case 1:
            conf.number = 100;
            file_write(conf);
            file_write2(conf);
            break;
        case 2:{
            strcpy(num, argv[1]);
            while(num_judge(num) == 3){
                printf("please enter number or r\n");
                scanf("%s", &num);
            }
            if(num_judge(num) == 2){
                conf.number = atoi(num);
                while(conf.number>conf.recordcount2){
                    printf("the value should be smaller than %d\n", conf.recordcount2);
                    scanf("%d", &conf.number);
                }
            }
            if(num_judge(num) == 1){
                conf.number = random_int(conf.recordcount1, conf.recordcount2);
            }

            file_write(conf);
            file_write2(conf);

            break;
        }
        case 3:{
            strcpy(num, argv[1]);
            strcpy(filepath, argv[2]);
            if(num_judge(num)!=3){
                if(num_judge(num)==2){
                    conf.number = atoi(argv[1]);
                    while(conf.number>conf.recordcount2){
                    printf("the value should be smaller than %d\n", conf.recordcount2);
                    scanf("%d", &conf.number);
                }}
                if(num_judge(num)==1)
                    conf.number = random_int(conf.recordcount1, conf.recordcount2);

                while(file_judge(filepath)==-1){
                    printf("pave is error. please review\n");
                    scanf("%s", filepath);
                }
            }
            else{
                printf("the number is error \n");
                break;
            }

            strcpy(conf.filesavepath,get_filepave(argv[2]));
            strcpy(conf.filename,get_filename(argv[2]));


            file_write(conf);
            file_write2(conf);
            break;
        }

        case 4:{
            if(num_judge(argv[1])!=3)
            {
                if(num_judge(argv[1])==2)
                {
                    conf.number=atoi(argv[1]);
                }
                if(num_judge(argv[1])==1)
                {
                    conf.number=random_int(conf.recordcount1,conf.recordcount2);
                }
                if(file_judge(argv[2])==-1)
                {
                    printf("error\n");
                    break;
                }
                if(file_judge(argv[2])==0)
                {
                    strcpy(conf.filesavepath,get_filepave(argv[2]));
                    strcpy(conf.filename,get_filename(argv[2]));
                }
            }
            else{
                printf("the argument is error\n");
                break;
            }
            if(strcmp(argv[3],"t")==0)
            {
                file_write(conf);
            }
            if(strcmp(argv[3],"d")==0)
            {
                file_write2(conf);
            }
            break;
        }
        default:{
            printf("the count you inputted is too much\n");
            break;
        }

    }

    return 0;
}
