//
// Created by Planck Chang on 2021/10/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct staff{
    char name[20];
    int id;
    char position[20];
};

struct company{
    staff *member;
    int count;
};


void init_company(company* company){
    company->member = (staff*) malloc(35* sizeof(staff));
    company->count=-1;
}


void insert_staff(company *l, int location, staff *e){
    if( location<0||location>l->count){
        printf("the position inserted error\n");
    }
    else{
        for(int i=l->count; i>=location; i--){
           l->member[i+1] = l->member[i];
        }
        l->member[location] = *e;
        l->count++;
    }
}

void  locate_elem(company *l, int num){
    for(int i=0; i<=l->count; i++){
        if(l->member[i].id == num){
            printf("%s %d %s\n", l->member[i].name , l->member[i].id, l->member[i].position);
        }
    }
}

void delete_elem(company*l, int num){
    for(int i= 0; i<=l->count; i++){
        if(l->member[i].id == num){
            for(int j=i; j<l->count; j++){
                l->member[j] = l->member[j+1];
            }
            l->count--;
            break;
        }
    }
    printf("no this gay\n");
}

void display(company *l){
    printf("name\tnumber\tposition\n");
    for (int i = 0; i <= l->count; i++)
        printf("%5s %5d %5s\n", l->member[i].name, l->member[i].id, l->member[i].position);
}

void add_elem(company *l, staff *e) {
    l->member[l->count+1] = *e;
    l->count++;
}

int main(){
    int choice, location;
    staff *tem = (staff*)malloc(sizeof(staff));
    company *l = (company*) malloc(sizeof(company));

    init_company(l);

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
            scanf("%s %d %s",&tem->name ,&tem->id, &tem->position);
            add_elem(l, tem);
            break;
        case 2:
            scanf("%s %d %s",&tem->name ,&tem->id, &tem->position);
            scanf("%d", &location);
            insert_staff(l, location, tem);
            break;
        case 3:
            scanf("%d", &tem->id);
            delete_elem(l, tem->id);
            break;
        case 4:
            display(l);
            break;
        case 5:
            scanf("%d",&location);
            locate_elem(l, location);
            break;
    }
        printf("please enter the choice\n");

        scanf("%d", &choice);
}
}
