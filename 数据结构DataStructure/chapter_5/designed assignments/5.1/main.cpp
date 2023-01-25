#include <stdio.h>
#define M 10
#define N 10

int main() {

    int matrix[M][N]={0};
    int m, n;
    int min[M]={0};
    int max[N]={0};
    int flag;
    printf("enter the number of line and column\n");
    scanf("%d%d", &m, &n);


    printf("enter the matrix\n");
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            scanf("%d", &matrix[i][j]);

    printf("\n");
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<m; ++i)
    {
        min[i]= matrix[i][0];
        for(int j=0; j<n; ++j)
        {
            if(matrix[i][j]<min[i])
            {
                min[i]= matrix[i][j];
            }
        }
    }
    for(int j=0; j<n; ++j)
    {
        max[j]= matrix[0][j];
        for(int i=0; i<m; ++i)
        {
            if(matrix[i][j]>max[j])
                max[j] = matrix[i][j];
        }


    }

    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(max[j]==min[i])
            {
                flag =1;
                printf("the saddle point is (%d,%d) = %d",i+1,j+1, min[i]);
            }
        }


    }
    if(flag==0)
        printf("no saddle point\n");

    return 0;

}