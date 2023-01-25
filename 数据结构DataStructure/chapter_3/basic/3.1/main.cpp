#include <stdio.h>

void test(int n){
    int i;
    i=n;
    while (i>1)
        printf("%d",i--);
}
void test_recursive(int n){
    if(n>1){
        printf("%d", n);
        test_recursive(n-1);
    }
}
int main() {
    test(10);
    printf("\n");
    test_recursive(10);

}


