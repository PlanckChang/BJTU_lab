#include <stdio.h>


struct SqQueue{
    int date[4];
    int count;
    int rear;
};

int main() {
    SqQueue q;
    q.count = 4;
    q.date[0] = q.date[1] = q.date[2] = 0;
    q.date[3]=1;
    q.rear = 0;
    int tem=0;
    printf("%5d%5d%5d%5d", 0, 0, 0, 1);
    while(tem<=200){
        tem = q.date[0] + q.date[1] + q.date[2] + q.date[3];
        q.date[q.rear]= tem;
        printf("%5d", tem);
        q.count++;
        q.rear = (q.rear+1)%4;
        if(q.count%10== 0){
            printf("\n");
        }
    }


}

