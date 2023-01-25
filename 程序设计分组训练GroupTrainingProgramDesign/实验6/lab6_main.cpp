//
// Created by Planck Chang on 2021/12/20.
//

#include "lab6_main.h"

///
/// \param s pave/name of the file
/// \return 1 signals txt; 2 signals dat
int Judgefiletype(char *s) {
    if(s[strlen(s)-3]=='t')
        return 1;
    else
        return 2;
}

void run() {
    int num = 1, mode =2, filetype;
    char data[10];
    char *path = (char*) malloc(sizeof(char)*100);

    strcpy(path, "\0");
    char *filename = (char*) malloc(sizeof(char)*100);
    while(num){

        selfcheck();


        printf("张芝玮的实验6程序:\n"
               "1. 调用实验 4 程序生成记录文件（文本方式）\n"
               "2. 调用实验 4 程序生成记录文件（二进制方式）\n"
               "3. 读取指定数据记录文件并排序（二维数组存储方式）\n"
               "4. 读取指定数据记录文件并排序（结构体数组存储方式）\n"
               "5. 读取指定数据记录文件并排序（指针数组存储方式）\n"
               "6. 读取指定数据记录文件并排序（链表存储方式）\n"
               "7. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，二维数组方式存储）\n"
               "8. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，结构体数组方式存储）\n"
               "9. 调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，指针数组方式存储）\n"
               "10.调用实验 4 生成数据记录文件，同时读取数据记录文件（文本方式输出，链表方式存储）\n"
               "11.调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，二维数组方式存储）\n"
               "12.调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，结构体数组方式存储）\n"
               "13.调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，指针数组方式存储）\n"
               "14.调用实验 4 生成数据记录文件，同时读取数据记录文件（二进制方式输出，链表方式存储）\n"
               "15.重新设置配置参数值\n"
               "0. 退出\n"
               "请输入您要执行的程序序号：\n ");
        scanf("%d",&num);
        FILE *fp = fopen("mode.ini","r");
        fscanf(fp,"%d",&mode);
        fclose(fp);
        if(mode == 2&&num!=0&&num!=15)//交互模式的信息收取
        {
            printf("请输入数据记录文件的路径(不含文件名)：\n");
            scanf("%s",path);
            printf("请输入文件名：\n");
            scanf("%s",filename);
            printf("请输入文件记录条数：\n");
            scanf("%s",data);
            strcat(path,"\\");
            strcat(path,filename);

        }
        else if(mode == 1&&num!=0&&num!=15)//自动模式
        {
            strcpy(path,choose(path));//默认路径
            strcpy(data,"r");//数据条数随机
            num = 7;
        }
        switch(num)
        {
            case 1:
                filetype = callLab4txt(path,data);//return 1 signals txt
                break;
            case 2:
                filetype = callLab4dat(path,data);//return 2 signals dat
                break;
            case 3:
                strcpy(path,choose(path));
                filetype = Judgefiletype(path);
                loadtoarray(path, filetype);
                break;
            case 4:
                strcpy(path,choose(path));
                filetype = Judgefiletype(path);
                loadtostructarray(path, filetype);
                break;
            case 5:
                strcpy(path,choose(path));
                filetype = Judgefiletype(path);
                loadtopointerarray(path, filetype);
                break;
            case 6:
                strcpy(path,choose(path));
                filetype = Judgefiletype(path);
                loadtolink(path, filetype);
                break;
            case 7:
                filetype = callLab4txt(path,data);
                strcpy(path,choose(path));
                loadtoarray(path, filetype);
                break;
            case 8:
                filetype = callLab4txt(path,data);
                strcpy(path,choose(path));
                loadtostructarray(path, filetype);
                break;
            case 9:
                filetype = callLab4txt(path,data);
                strcpy(path,choose(path));
                loadtopointerarray(path, filetype);
                break;
            case 10:
                filetype = callLab4txt(path,data);
                strcpy(path,choose(path));
                loadtolink(path, filetype);
                break;
            case 11:
                filetype = callLab4dat(path,data);
                strcpy(path,choose(path));
                loadtoarray(path, filetype);
                break;
            case 12:
                filetype = callLab4dat(path,data);
                strcpy(path,choose(path));
                loadtostructarray(path, filetype);
                break;
            case 13:
                filetype = callLab4dat(path,data);
                strcpy(path,choose(path));
                loadtopointerarray(path, filetype);
                break;
            case 14:
                filetype = callLab4dat(path,data);
                strcpy(path,choose(path));
                loadtolink(path, filetype);
                break;
            case 15:
                printf("请选择需要改变的参数：\n"
                       "1.数据记录文件路径\n"
                       "2.数据记录文件名\n"
                       "3.数据记录三元组中第1、2个元素取值的上限\n"
                       "4.数据记录三元组中第1、2个元素取值的下限\n"
                       "5.数据记录三元组中第3个元素取值的上限\n"
                       "6.数据记录三元组中第3个元素取值的下限\n"
                       "7.记录条数时条数值的上限\n"
                       "8.记录条数时条数值的下限\n"
                       "9.工作模式（自动模式/交互模式）\n"
                       "请输入您要执行的程序序号:\n");
                int choice;
                scanf("%d",&choice);
                if(choice == 9)
                    changemode();
                else if(choice>=1&&choice<=9)
                    changeconf(choice);
                else
                    printf("输入错误\n");
        }

    }
}



