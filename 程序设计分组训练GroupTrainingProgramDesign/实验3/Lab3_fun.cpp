//
// Created by Planck Chang on 2021/10/24.
//

#include "Lab3_fun.h"
#include <string.h>
#include <random>
#include <unistd.h>
int num_judge(char *num) {
    int i;
    //1 auto random number
    //2 normal input
    //3 error input
    if(strcmp(num, "r")==0 ) return 1;
    for(i=0; i<strlen(num); i++){
        if(num[i]>'9' || num[i] < '0')
            break;
    }
    if(i == strlen(num)) return 2;
    return 3;
}

int random_int(int min, int max) {
    return rand()%(max-min)+min;
}

int file_judge(char *name) {
    //0 normal
    //-1 error
    int len = strlen(name);
    char tem[5];
    char *tem1 =":,?;*&^%$#@!()?><";

    if((name[len-4]=='.')&&(name[len-3]=='t')&&(name[len-2]=='x')&&(name[len-1]=='t')){
        for(int i=0; i<len; i++){
            for(int j=0; j< strlen(tem1); j++){
                if(name[i]-tem1[j] == 0)
                    return -1;
            }
        }
        return 0;
    }
    if((name[len-4]=='.')&&(name[len-3]=='d')&&(name[len-2]=='a')&&(name[len-1]=='t')){
        for(int i=0; i<len; i++){
            for(int j=0; j< strlen(tem1); j++){
                if(name[i]-tem1[j] == 0)
                    return -1;
            }
        }
        return 0;
    }
    return -1;
}

void file_write(CONF conf) {
    FILE *pf;

    if (access(conf.filesavepath,0)!=0) //等于0，文件存在 不等于0，文件不存在
    {
        mkdir(conf.filesavepath);
    }//判断文件存在与否
    strcat(conf.filesavepath, conf.filename);
    pf = fopen(conf.filesavepath, "w");
    fprintf(pf, "%d\n", conf.number );
    for(int i =0; i<conf.number; i++){
        for(int j=0; j<3; j++){
            fprintf(pf, "%d, ", random_int(conf.minvalue1, conf.maxvalue1));
        }
        fprintf(pf, "\n");
    }
    fclose(pf);
}

char *get_filepave(char * pave){
    int len = strlen(pave);
    char filepave[100];
    int flag=1;
    for(int i=len-1; i>=0; --i){
        if(pave[i]=='/'){
            for(int j=0; j<=i; ++j)
                filepave[j] = pave[j];
            flag =0;
            break;
        }
        else if(pave[i]=='\\'){
            for(int j=0; j<=0; ++j)
                filepave[j]= pave[j];
            flag =0;
            break;
        }
    }
    if(flag==1)
        strcpy(filepave,"OutPutData\\");
    return filepave;
}

char *get_filename(char *name) {
    int len =strlen(name);
    char filename[100];
    int flag=1;
    for(int i = len-1; i>=0; --i){
        if(name[i]=='/'){
            for(int j=i+1; j<=len-1; ++j){
                filename[j-i-1] = name[j];
            }
            flag=0;
            break;
        }
        else if(name[i]=='\\'){
            for(int j= i+1; j<len -1; ++j){
                filename[j-i-1] = name[j];
            }
            flag=0;
            break;
        }
    }
    if(flag==1)
        strcpy(filename, name);
    return filename;

}
