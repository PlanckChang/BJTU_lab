#include <iostream>
#include <string.h>
#include <stdlib.h>

struct staff{
    char name[10];
    int id;
    char position[10];
    staff *next;
};

staff *init_link(){
    staff *head= (staff*) malloc(sizeof(staff));
    head->next=NULL;
    return head;
}

void add_node(staff*l, staff add){
    staff*p=l;
    staff*q=(staff*) malloc(sizeof(staff));
    while(p->next!=NULL)
        p= p->next;
    *q=add;
    p->next=q;
}

void select_node(staff*l, int id){
    staff*p= l;
    p=p->next;
    while (p->id!=id){
        p= p->next;
    }
    printf("%5s %5d %5s\n", p->name, p->id, p->position );
}

void insert_node(staff*l, int location, staff new_node){
    staff*p=l->next;
    staff*q =(staff*) malloc(sizeof(staff));
    *q = new_node;

    for(int i=0; i<location-1; i++)
        p=p->next;
    q->next=p->next;
    p->next=q;
}

void display_node(staff*l){
    staff*p=l;
    p=p->next;
    while(p->next!=NULL){
        printf("%5s %5d %5s\n", p->name, p->id, p->position );
        p=p->next;
    }
    printf("%5s %5d %5s\n", p->name, p->id, p->position );

}

void delete_node(staff*l, int id){
    staff*p= l->next;
    staff*q=l;
    while(p->next!=NULL){
        if(p->id==id){
            q->next=p->next;
            free(p);
            break;
        }
        else{
            q=q->next;
            p=p->next;
        }
    }
}





int main(){
    int choice, location;
    staff tem;
    tem.next=NULL;
    staff*l= init_link();

    printf("1 add a staff information\n");
    printf("2 insert a staff information\n");
    printf("3 delete a staff information\n");
    printf("4 display all the information\n");
    printf("5 select a staff\n");
    printf("please enter the choice\n");
    scanf("%d", &choice);
    while(choice!=0){
        switch (choice) {
            case 1:
                scanf("%s %d %s",&tem.name ,&tem.id, &tem.position);
                add_node(l, tem);
                break;
            case 2:
                scanf("%s %d %s",&tem.name ,&tem.id, &tem.position);
                scanf("%d", &location);
                insert_node(l, location, tem);
                break;
            case 3:
                scanf("%d", &tem.id);
                delete_node(l, tem.id);
                break;
            case 4:
                display_node(l);
                break;
            case 5:
                scanf("%d",&location);
                select_node(l, location);
                break;
        }
        printf("please enter the choice\n");

        scanf("%d", &choice);
    }
}
