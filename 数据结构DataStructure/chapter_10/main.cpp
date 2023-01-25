#include <stdio.h>

void quick_sort(int *array, int num){
    int middle = 0;
    if(num==0)return;
    int i = 1, j = num-1;int flag =0;
    while(i <= j){
        if(flag==0){
            if(array[j] < array[middle]){
            int tem = array[j];
            array[j] = array[middle];
            array[middle] = tem;
            middle = j;
            flag = 1;
            }
            j--;
        }
        else
        {
            if(array[i] > array[middle]){
                int tem = array[i];
                array[i] = array[middle];
                array[middle] = tem;
                middle = i;
                flag =0;
            }
            i++;
        }
    }
    quick_sort(array, middle);
    quick_sort(array+middle+1, num - middle-1);
}
void bubble_sort(int * array, int num){
    for(int i=0; i<num - 1; ++i){
        int flag = 0;
        for(int j=0; j< num-i-1; ++j){
            if(array[j] > array[j+1]){
                int tem = array[j];
                array[j] = array[j+1];
                array[j+1] = tem;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

void select_sort(int * array, int num){
    for(int i = 0; i< num-1; ++i){
        int index = i;
        for(int j= i+1; j<num; ++j){
            if(array[j]< array[index])
                index = j;
        }
        if(index == i)
            continue;
        int tem = array[index];
        array[index] = array[i];
        array[i] = tem;
    }
}

int main() {
    int array[5] = {5, 3, 4, 2, 1};
    int num = 5;
    for(int i= 0 ; i< num; ++i)
        printf("%d ", array[i]);
//    bubble_sort(array, num);
//    select_sort(array, num);
    printf("\n");
    quick_sort(array, 5);
    for(int i=0 ; i<num; ++i)
        printf("%d ", array[i]);
}
