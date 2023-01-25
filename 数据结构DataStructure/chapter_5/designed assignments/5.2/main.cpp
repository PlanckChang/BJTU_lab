#include <cstdio>
#define MAX 100

typedef struct{
    int i,j;
    int e;
}triple;

typedef struct{
    int m, n, num;
    triple data[MAX];
}TSMatrix;

TSMatrix &create_matrix(int m, int n, int t){
    TSMatrix M;
    M.m = m;
    M.n = n;
    M.num = t;
    printf("please enter the i, j, data of the matrix element\n");
    for(int i=0; i<t; ++i){
        scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
        while(M.data[i].i>m || M.data[i].j>n){
            printf("the parameter is too big! enter again\n");
            scanf("%d%d%d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
        }
    }
    return M;
}

void show_matrix_triple(TSMatrix &M){
    for(int i= 0; i<M.num; ++i){
        printf("%3d %3d %3d\n",M.data[i].i, M.data[i].j, M.data[i].e);
    }

}

TSMatrix & order_matrix(TSMatrix&M)
{
    triple tem;
    for(int i=0; i<M.num-1; ++i){
        tem = M.data[i];
        for(int j=i+1; j<M.num; ++j){
            if(tem.i> M.data[j].i)
            {
                M.data[i] = M.data[j];
                M.data[j] = tem;
                tem = M.data[i];
            }
            if(tem.i == M.data[j].i && tem.j > M.data[j].j )
            {
                M.data[i] = M.data[j];
                M.data[j] = tem;
                tem = M.data[i];
            }
        }
    }
    return M;
}


TSMatrix & transpose_matrix(TSMatrix &M){
    int tem;
    for(int k=0; k<M.num;++k) {
        tem = M.data[k].i;
        M.data[k].i = M.data[k].j;
        M.data[k].j = tem;
    }
    return M;
}

TSMatrix & swift_transpose_matrix(TSMatrix & M, TSMatrix &T)
{
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;
    int array[M.n];
    for(int i=0; i<M.num; ++i)
    {
        array[M.data[i].j-1] ++;
    }
    int location[M.n];
    location[0] = 0;
    for(int i=1; i<M.n; ++i)
    {
        location[i] =location[i-1] + array[i-1];
    }
    for(int i=0; i< M.num;++i)
    {
        int place = location[M.data[i].j-1];
        T.data[place].i = M.data[i].j;
        T.data[place].j = M.data[i].i;
        T.data[place].e = M.data[i].e;

        // location has changed, thus plus 1
        location[M.data[i].j]++;
    }
    return T;
}
int main()
{
    int m,n , num;
    printf("please enter the parameter\n");
    scanf("%d %d %d", &m, &n, &num);
    TSMatrix M = create_matrix(m, n , num);
    TSMatrix T = M;
    show_matrix_triple(M);
    order_matrix(M);
    printf("\n");
    show_matrix_triple(M);
    printf("\n");
   // transpose_matrix(M);
   // printf("\n");
    swift_transpose_matrix(M, T);
    show_matrix_triple(T);
}
