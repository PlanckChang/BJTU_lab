#include <stdio.h>
#include <random>
#include <stdlib.h> 
struct Maze{
    int data[8][8];
};

struct Node{
    int a;
    int b;
    Node* next;
};

struct Map_stack{
    Node* head;
};

Maze*create_maze(){

    // 外带一圈死路，便于循环
    Maze*maze=(Maze*) malloc(sizeof(Maze));
    int array[8][8] ={
        { 0,0, 0, 0, 0, 0, 0 ,0 },
        { 0,1, 1, 1, 1, 1, 0, 0 },
        { 0,1, 0, 1, 0, 1, 0, 0 },
        { 0,1, 1, 1, 1, 1, 0, 0 },
        { 0,1, 0, 0, 0, 1, 1, 0 },
        { 0,1, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 1, 1 ,0},
        { 0,0, 0, 0, 0, 0, 0 ,0 },
    };
    for(int i= 0; i<8; i++) {
        for (int j = 0; j < 8; j++) {
            maze->data[i][j] = array[i][j];
        }
    }

    return maze;
}

void push(Map_stack*mapStack, Node*node){
    Node* tem = (Node*) malloc(sizeof (Node));
    *tem = *node;
    tem->next = mapStack->head->next;
    mapStack->head->next = tem;

}

void pop(Map_stack*mapStack){
    Node*tem = mapStack->head->next;
    mapStack->head->next = mapStack->head->next->next;
    free(tem);
}

Maze* find_map(Map_stack*mapStack, Maze*maze) {
    int x = 1;
    int y = 1;
    int choice = 1;

    Node *tem = (Node*) malloc(sizeof(Node));
    tem->a = x;
    tem->b = y;
    //
    tem->next = NULL;
    push(mapStack, tem);


    while (x != 6 || y != 6) {

        if(mapStack->head->next == NULL){
            printf("no way\n");
            break;
        }

        switch (choice){
            case 1:
                // east
                 if (maze->data[x][y+1] == 1 && (x != (mapStack->head->next->next->a) || (y+1) != mapStack->head->next->next->b)){
                    tem->a = x;
                    tem->b = ++y;
                    push(mapStack, tem);
                    choice = 1;
                    continue;
                }

            case 2:
                // south
                if(maze->data[x+1][y] == 1 && ((x+1) != mapStack->head->next->next->a || y != mapStack->head->next->next->b)){
                    tem->a = ++x;
                    tem->b = y;
                    push(mapStack, tem);
                    choice = 1;
                    continue;
                }
            case 3:
                // west
                if (maze->data[x][y-1] == 1 && (x != mapStack->head->next->next->a || (y-1) != mapStack->head->next->next->b)){
                    tem->a = x;
                    tem->b = --y;
                    push(mapStack, tem);
                    choice = 1;

                    continue;
                }
            case 4:
                // north
                if (maze->data[x-1][y] == 1 && ((x-1) != mapStack->head->next->next->a || y != mapStack->head->next->next->b)) {
                    tem->a = --x;
                    tem->b = y;
                    push(mapStack, tem);
                    continue;
                }
            default:
                // return
                if (mapStack->head->next->a - mapStack->head->next->next->a == 1 &&
                    mapStack->head->next->b - mapStack->head->next->next->b == 0)
                    choice = 3;
                if (mapStack->head->next->a - mapStack->head->next->next->a == 0 &&
                    mapStack->head->next->b - mapStack->head->next->next->b == -1)
                    choice = 4;
                if (mapStack->head->next->a - mapStack->head->next->next->a == 0 &&
                    mapStack->head->next->b - mapStack->head->next->next->b == 1)
                    choice = 2;
                pop(mapStack);
                x = mapStack->head->next->a;
                y = mapStack->head->next->b;
                continue;
        }
    }
}

void mapDisplay(Map_stack*mapStack){
    Node* p = mapStack->head->next;
    if(mapStack->head->next == NULL)
        printf("no way\n");

    while(p->next != NULL){

        int n =0;
        printf("(%d,%d)<-",p->a, p->b);
        n++;
        if(n%10 == 0)
            printf("\n");
        p = p->next;
    }
//    printf("(%d,%d)",p->a, p->b);
}




void mazeDisplay(Maze*maze){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%3d", maze->data[i][j]);
        }
        printf("\n");
    }

}


int main() {
    Maze*maze = create_maze();
    mazeDisplay(maze);

    Map_stack*mapStack = (Map_stack*)malloc(sizeof(Map_stack));
    mapStack->head = (Node*)malloc(sizeof (Node));
    mapStack->head->next = (Node*)malloc(sizeof (Node));
    mapStack->head->next->next =NULL;

    find_map(mapStack, maze);
    mapDisplay(mapStack);

}
