#include "stdio.h"
#include "string.h"
int main() {
    int next[10];
    int i, j;
    char *T = "*ababaaaba";
    int len = strlen(T);
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < len) // leng = T[0]
    {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;d
        } else
            j = next[j];

    }

}