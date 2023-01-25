//
// Created by Planck Chang on 2021/10/24.
//

#include "Lab3_run.h"
#include "Lab3_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab3_fun.h"
#include <time.h>


int run(int argc, char *argv[]) {
    CONF conf;
    char num[MAX_STR_LEN];
    char filepath[MAX_STR_LEN];
    //初始化 三元组的值
    conf.recordcount2 = 100;
    conf.recordcount1 = 0;
    conf.maxvalue1 = conf.maxvalue2= 1000;
    conf.minvalue1 = conf.minvalue2 = 0;
    conf.number = 100;
    strcpy(conf.filename, "Lab3_text.txt");
    strcpy(conf.filesavepath, "Lab3_text\\");

    srand(time(0));

    switch (argc) {

        case 1:{
            printf("please enter the recording court of the random items or 'r'\n");
            scanf("%s", &num);
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

            printf("please enter file path\n");
            scanf("%s", &filepath);
            while(file_judge(filepath)==-1){
                printf("please enter the right path\n");
                scanf("%s", &filepath);
            }

            strcpy(conf.filesavepath,get_filepave(filepath));
            strcpy(conf.filename,get_filename(filepath));
            file_write(conf);

            break;
        }
        case 2:{
            if(num_judge(argv[1])!=3){
                if(num_judge(argv[1])==2)
                    conf.number = atoi(argv[1]);
                if(num_judge(argv[1])==1)
                    conf.number = random_int(conf.recordcount1, conf.recordcount2);

                printf("please enter the file pave\n");
                scanf("%s", filepath);
                while(file_judge(filepath)==-1){
                    printf("pave is error. please review\n");
                    scanf("%s", filepath);
                }
            }
            else{
                if(file_judge(argv[1])==-1){
                    printf("the file pave is error\n");
                    break;
                }
                if(file_judge(argv[1])==0){
                    strcpy(conf.filename, argv[1]);

                    printf("please enter the count of random numbers\n");
                    scanf("%s", num);
                    while(num_judge(num) == 3){
                        printf("please enter number or r\n");
                        scanf("%s", num);
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
                }
            }
            strcpy(conf.filesavepath,get_filepave(filepath));
            strcpy(conf.filename,get_filename(filepath));

            file_write(conf);
            break;
        }

        case 3:{
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
            else if((num_judge(argv[2])!=3))
            {
                if(num_judge(argv[2])==2)
                {
                    conf.number=atoi(argv[2]);
                }
                if(num_judge(argv[2])==1)
                {
                    conf.number=random_int(conf.recordcount1,conf.recordcount2);
                }
                if(file_judge(argv[1])==-1)
                {
                    printf("error\n");
                    break;
                }
                if(file_judge(argv[1])==0)
                {
                    strcpy(conf.filesavepath,get_filepave(argv[1]));
                    strcpy(conf.filename,get_filename(argv[1]));
                }
            }
            file_write(conf);
            break;
        }
        default:{
            printf("the count you inputted is too much\n");
            break;
        }

    }

    return 0;
}
