/*******************************************************
作者信息：
    姓名：张芝玮 学号：20271259 班级：计科2005 学院：计算机与信息技术学院
Email：
    20271259@bjtu.edu.cn     电话：13286338544
摘要：
    实验五，本模块实现指定格式的数据记录文件生成功能
模块历史：
    张芝玮于2021年12月10日创建本模块
********************************************************/
#include "lab6_main.h"
#include "stdlib.h"
#include "lab6_cmp.h"
/* 函数名称：main
 * 函数功能：调用run（）,实现lab5全部功能
 * 输入参数：无
 * 返回值：int 本程序中返回值无特殊作用
 * 版本信息：create by planck chang on 2021/12/10
 */
int main() {
    system("chcp 65001");
    run();


//
    printf("please enter the record count\n");
    int num;
    scanf("%d", &num);
//    int a[num][3];
//    for (int i = 0; i < num; ++i) {
//        a[i][0] = rand();
//        a[i][1] = rand();
//        a[i][2] = rand();
//    }
//
//    printf("before sort\n");
//    show_array(a, num);
//    qsort(a, num, sizeof(int), cmparray);
//    printf("\nafter sort\n");
//    show_array(a, num);
//

//    DATAITEM data[num];
//    for(int i = 0; i<num ; ++i){
//        data[i].item1 = rand();
//        data[i].item2 = rand();
//        data[i].item3 = rand();
//    }
//    printf("before sort\n");
//    show_structarray(data, num);
//
//    qsort(data, num, sizeof (DATAITEM), cmpstructarray);
//    printf("\nafter sort\n");
//    show_structarray(data, num);


//    DATAITEM *data [num];
//    for(int i = 0; i<num; ++i){
//        data[i] = (DATAITEM*) malloc(sizeof (DATAITEM));
//        data[i]->item1 = rand();
//        data[i]->item2 = rand();
//        data[i]->item3 = rand();
//    }
//    printf("before sort\n");
//    show_pointerarry(data, num) ;
//    qsort(data, num, sizeof (DATAITEM*), cmppionterarray);
//    printf("\nafter sort\n");
//    show_pointerarry(data, num);

    Link * head = (Link *) malloc(sizeof(Link));
    Node *p = (Node*) malloc(sizeof (Node));
    p->data[0] = rand();
    p->data[1] = rand();
    p->data[2] = rand();
    head->next = p;
    head->totaldatanum = num;
    for(int i=0 ;i<num-1 ; ++i){
        Node *tem = (Node*) malloc(sizeof (Node));
        tem->data[0] = rand();
        tem->data[1] = rand();
        tem->data[2] = rand();
        p->next = tem;
        p = tem;
    }
    p->next = NULL;
    printf("before sort\n");
    show_link(head);
    printf("\nafter sort\n");
    bubblesortlink(head);
    show_link(head);
}
