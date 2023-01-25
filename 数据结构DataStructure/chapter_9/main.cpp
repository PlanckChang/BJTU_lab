#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//9.6

typedef struct Btree{
    int data;
    Btree * lchild;
    Btree * rchild;
};


int search_btree(Btree *&T, int target, Btree *&last_traversal, Btree *&before_last)
{
    if(!T) return 0;
    if(target == T->data){
        before_last = last_traversal;
        last_traversal = T;
        return 1;
    }
    else if(target > T->data)
    {
        before_last = last_traversal;
        last_traversal = T;
        search_btree(T->rchild, target, last_traversal, before_last);
    }
    else{
        before_last = last_traversal;
        last_traversal = T;
        search_btree(T->lchild, target, last_traversal, before_last);
    }
}

int insert_btree(Btree * &T, int target){
    Btree* last =(Btree*) malloc(sizeof (Btree));
    Btree* before =(Btree*) malloc(sizeof (Btree));

    if(!search_btree(T, target, last, before)){
        if(!T){
            T = (Btree*) malloc(sizeof (Btree));
            T->data = target;
            T->rchild = T->lchild = NULL;
            return 1;
        }

        Btree* tem = (Btree*) malloc(sizeof (Btree));
        tem->data = target;
        tem->rchild = tem->lchild = NULL;

        if(target > last->data)
            last->rchild = tem;
        else
            last->lchild = tem;
        return 1;
    }
    else
        return 0;
}
void show_btree(Btree* T)
{
    if(!T) printf("*");
    else {
        printf("%d ",T->data);
        printf("(");
        show_btree(T->lchild);
        printf(", ");
        show_btree((T->rchild));
        printf(")");
    }
}

int delete_btree(Btree *T, int target)
{
    Btree* last =(Btree*) malloc(sizeof (Btree));
    Btree* before =(Btree*) malloc(sizeof (Btree));
    last->lchild = last->rchild = before->lchild = before->rchild = NULL;

    if(!search_btree(T, target, last, before)) return 0;
    else{
        Btree * tem;
        if( !last->lchild && !last->rchild){
            if(before->data > last->data)
                before->lchild = NULL;
            else
                before->rchild = NULL;
            free(last);
        }
        else if(last->lchild == NULL)
        {
            tem = last->rchild;
            *last = *last->rchild;
            free(tem);
        }
        else if(last->rchild == NULL)
        {
            tem = last->lchild;
            *last = *last->lchild;
            free(tem);
        }
        else{
            Btree *q=last;
            tem = last->lchild;
            while(tem->rchild){
                q = tem;
                tem = tem->rchild;
            }
            last->data = tem->data;
            if(q == last){
                q->lchild = tem->lchild;
            }
            else{
                q->rchild = tem->lchild;
            }
            free(tem);
        }
    }
}


char str[12][6] = {"ZHAO", "QIAN", "SUN", "LI", "ZHOU", "WU", "ZHANG", "WANG",
                   "CHANG", "CHAO", "YANG", "JIN"};
typedef struct hash_table{
    int situation;
    char data[10];
};
int insert_hash(hash_table table[], int key, int order){
    int index = key % 16;
    int i;
    if(table[index].situation ==0 ) strcpy(table[index].data,str[order]);
    for(i= 0; table[index].situation!=0 && i <16; i++)
        index = (index + 1) % 16;
    if(i ==16) return 0;
    table[index].situation =1;
    strcpy(table[index].data, str[order]);
    return 1;
}

void show_hash(hash_table table[]){
    for(int i =0; i<16 ; ++i){
        printf("%5d", i);
    }
    printf("\n");
    for(int i =0 ; i<16; ++i){
        if(table[i].situation ==1)
            printf("%5s", table[i].data);
        else
            printf("   ");
    }
}
//int search_hash(hash_table table[], int key){
//    int index = key % 11;
////    if(table[index].situation == 0) return -1;
////    if(table[index].data == key) return index;
//    while(table[index].situation == 1 && index<11){
//        if(table[index].data == key) return index;
//        index++;
//   }
//    return -1;
//}
int main() {
//    int num_array[10] = {5, 2, 6, 1, 3, 7,};
//    Btree *T = NULL;
//
//    for (int i = 0; i < 6; ++i) {
//        insert_btree(T, num_array[i]);
//    }
//    show_btree(T);
//    printf("\n");
//    delete_btree(T, 1);
//    show_btree(T);

//    hash_table table[11];
//    for (int i = 0; i < 11; ++i) {
//        table[i].situation =0;
//    }
//    int key[11] = {111, 203, 234, 343, 1 ,5, 8, 4, 39, 10, 9};
//    for (int i = 0; i < 11; ++i) {
//        insert_hash(table, key[i]);
//    }
//    show_hash(table);
//    printf("\n%d", search_hash(table, 203));



hash_table table[16];
    for (int i = 0; i < 16; ++i) {
        table[i].situation = 0;
    }
int num[12];
int s= 0;
for(int i= 0; i<12; ++i){
    num[i] = 10 * s + str[i][0]-'A';
    s = num[i];
}
for(int i = 0; i<16; ++i){
    insert_hash(table, num[i], i);
}
    show_hash(table);



}
