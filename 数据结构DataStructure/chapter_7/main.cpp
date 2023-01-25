#include <stdlib.h>
#include <stdio.h>
#define INFINITY 65535
typedef struct ArcNode{
    int adjvex;
    ArcNode * nextarc;
};

typedef struct VNode{
    int data;
    ArcNode *firstarc;
};

typedef struct ALGraph{
};

// 7.1

int DFS_find(int i, int j, VNode  g[], bool visted[] ){
    visted[i] = true;
    ArcNode * p;
    if(i==j)
        return 1;
    else{
        p = g[i].firstarc;
        while (p){
            if(visted[p->adjvex]) p = p->nextarc;
            else if (!(DFS_find(p->adjvex, j, g, visted))) {
                p = p->nextarc;
            }
            else
                return 1;
        }
        return 0;
    }
}
// depth first research is to reach the deepest vnode then return, instead breath first research is like level research
// one level by ont level

//7.2
int BFS_find(int i, int j, VNode g[], bool visited[]){
    int queue_index[100];
    int front, rear;
    front = rear =0;
    visited[i] = true;
    VNode tem = g[i];
    queue_index[rear++] = tem.data;
    if(i==j) return 1;

    while(front!=(rear+1)){
        tem = g[queue_index[front++]];
        ArcNode * p = tem.firstarc;
//        while(p&& !visited[p->adjvex]) {  the wrong method, thus divided into two steps,
        while(p){
            if(visited[p->adjvex]) {
                p =p->nextarc;  // maybe the first arcvode is visited but the next arcvode is not, then progress ends.
                continue;
            }
            if(p->adjvex == j) return 1;
            queue_index[rear++] = p->adjvex;
            visited[p->adjvex] = true;
            p = p->nextarc;
        }
    }
    return 0;
}

//7.3

int BFS_find(int i, int j, VNode g[], bool visited[], int &count){
    int queue_index[100];
    int front, rear;
    front = rear = count = 0;
    visited[i] = true;
    VNode tem = g[i];
    queue_index[rear++] = tem.data;

    while(front!=(rear+1)){
        tem = g[queue_index[front++]];
        ArcNode * p = tem.firstarc;
//        while(p&& !visited[p->adjvex]) {  the wrong method, thus divided into two steps,
        while(p){
            if(visited[p->adjvex]) {
                p =p->nextarc;  // maybe the first arcvode is visited but the next arcvode is not, then progress ends.
                continue;
            }
            if(p->adjvex== j) return 1;
            queue_index[rear++] = p->adjvex;
            visited[p->adjvex] = true;
            p = p->nextarc;
        }
        count ++;
    }
    return 0;
}

//7.4
typedef struct MGraph{
    int numVertexes;
    int (*arc)[9];// NIUDE ]
};

void minispantree_prim(MGraph g){
    int adjvex[100];
    int lowcost[100];
    lowcost[0] =0;
    adjvex[0] = 0;
    for(int i=1; i<g.numVertexes; ++i){
        lowcost[i] = g.arc[0][i];
        adjvex[i] = 0;
    }
    for(int i =1; i<g.numVertexes; ++i){
        int min = INFINITY;
        int j=1, k=0;
        while(j<g.numVertexes){
            if(lowcost[j]!= 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            ++j;
        }
        printf("(%d, %d)", adjvex[k], k);
        lowcost[k] = 0;
        for(j = 1; j<g.numVertexes; ++j){
            if(lowcost[j]!=0 && g.arc[k][j] < lowcost[j])
            {
                lowcost[j] = g.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}

int main() {
//    VNode g[6];
//    for(int i= 0; i<6; ++i){
//        g[i].data=i;
//        g[i].firstarc = (ArcNode *)malloc(sizeof (ArcNode));
//    }
//    g[0].firstarc->adjvex=1;
//    g[0].firstarc->nextarc = (ArcNode *)malloc(sizeof (ArcNode));
//    ArcNode *p = g[0].firstarc->nextarc;
//    p->adjvex =2;
//    p->nextarc = NULL;
//    g[1].firstarc->adjvex =0;
//    g[1].firstarc->nextarc = NULL;
//    g[2].firstarc->adjvex = 3;
//    g[2].firstarc->nextarc = (ArcNode*) malloc(sizeof (ArcNode));
//    p = g[2].firstarc->nextarc;
//    p->adjvex =4;
//    p->nextarc = (ArcNode*) malloc(sizeof (ArcNode));
//    p = p->nextarc;
//    p->adjvex = 0;
//    p->nextarc = NULL;
//    p= g[3].firstarc;
//    p->adjvex = 2;
//    p->nextarc = (ArcNode*) malloc(sizeof (ArcNode));
//    p = p ->nextarc;
//    p->adjvex = 5;
//    p->nextarc = NULL;
//    p = g[4].firstarc;
//    p->adjvex = 2;
//    p->nextarc = NULL;
//    p = g[5].firstarc;
//    p->adjvex = 3;
//    p->nextarc = NULL;
//
//    bool visited[6] ;
//    for(int i =0 ; i<6; ++i)
//        visited[i] = false;
//    if(DFS_find(0, 5 , g, visited))
//        printf("right\n") ;
//    else printf("0");
//
//
//    for(int i= 0; i<6; ++i) visited[i] = false;
//    if(BFS_find(0, 5, g, visited))
//        printf("right by BFS\n");
//    else printf("no way");
//
//    for(int i= 0; i<6; ++i) visited[i] = false;
//    int count;
//    int k = 3;
//    if(BFS_find(0, 5 , g, visited, count)){
//        printf("there is one way and the count is %d\n", count);
//        if(count == k) printf("satisfy the num k\n");
//    }
    MGraph g;
//    g.arc = (int **) malloc(sizeof(int *) *9);
//    for(int i=0; i<9; ++i){
//        g.arc[i] = (int *) malloc(sizeof (int ) *9);
//    }
    int graph[9][9] = {
        {0,     10,    65535, 65535, 65535, 11,    65535, 65535, 65535},
        {10,    0,     18,    65535, 65535, 65535, 16,    65535, 12},
        {65535, 65535, 0,     22,    65535, 65535, 65535, 65535, 8},
        {65535, 65535, 22,    0,     20,    65535, 65535, 16,    21},
        {65535, 65535, 65535, 20,    0,     26,    65535, 7,     65535},
        {11,    65535, 65535, 65535, 26,    0,     17,    65535, 65535},
        {65535, 16,    65535, 65535, 65535, 17,    0,     19,    65535},
        {65535, 65535, 65535, 16,    7,     65535, 19,    0,     65535},
        {65535, 12,    8,     21,    65535, 65535, 65535, 65535, 0}
};
    g.numVertexes = 9;
    g.arc = graph;
    minispantree_prim(g);
}
