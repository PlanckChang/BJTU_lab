#include <iostream>
#include <time.h>
#include <string.h>
#define time_speed 3600
#define parking_count 2

// 时间测试中，车辆入场出场时间太短，这里由宏定义修改时间倍率进行调整
// 这里以一秒为一小时计算， 现实中倍率为1
// parking_count 为了方便测试用 当其比较小时方便测试

struct vehicle{
    char id[10];
    time_t start_time;
    time_t end_time;
    int duration;
    int fee;
    int count;
    vehicle* next;

};

struct parking_lot{
    vehicle* vehicle_ongoing;
    vehicle* vehicle_over;
    vehicle* waiting_vehicle;
};
void waiting_vehicle_add(parking_lot*lot, vehicle*p){
    vehicle*q= (vehicle*)malloc(sizeof(vehicle));
    vehicle*r = lot->waiting_vehicle;

    while(r->next != NULL){
        r = r->next;
    }

    *q = *p;
    r->next = q;
}

void add_vehicle(parking_lot*l, vehicle*p){
    if(l->vehicle_ongoing->count >=parking_count){
        printf("the parking lot is full, please wait\n");
    }
    else{
        vehicle*q= (vehicle*)malloc(sizeof(vehicle));
        *q = *p;
        q->next= l->vehicle_ongoing->next;
        l->vehicle_ongoing->next = q;

        l->vehicle_ongoing->count++;
    }
}

int leave_vehicle(parking_lot*l, char*s){
    vehicle *p = l->vehicle_ongoing->next;
    vehicle *q = (vehicle*) malloc(sizeof(vehicle));
    vehicle *r = l->vehicle_ongoing;

    if(l->vehicle_ongoing->count==0) return -1;
    while(p!=NULL){
        if(strcmp(s, p->id) == 0){
            p->end_time = time(0);
            p->duration = difftime(p->end_time, p->start_time);
            p->fee = p->duration * time_speed / 3600.0 * 10;
            printf("leave success\n");

            *q= *p;
            q->next=l->vehicle_over->next;
            l->vehicle_over->next = q;

            r->next = p->next;
            free(p);


            l->vehicle_ongoing->count--;
            l->vehicle_over->count++;
            break;
        }
        else{
            p=p->next;
            r=r->next;
        }
    }
    return 0;
}

int on_going_display(parking_lot*l){
    vehicle*p = l->vehicle_ongoing->next;

    printf("car id\t     start time\n");
    if(p==NULL) return -1;
    while(p->next!=NULL){
        printf("%s\t%s", p->id, ctime(&(p->start_time)));
        p= p->next;
    }
    printf("%s\t%s\n", p->id, ctime(&(p->start_time)));
    p= p->next;
    return 0;
}

int waiting_display(parking_lot*l){
    vehicle*p = l->waiting_vehicle->next;

    printf("car id\t     start time\n");
    if(p==NULL) return -1;
    while(p->next!=NULL){
        printf("%s\t%s", p->id, ctime(&(p->start_time)));
        p= p->next;
    }
    printf("%s\t%s\n", p->id, ctime(&(p->start_time)));
    p= p->next;
    return 0;
}
char* delete_final_character(char*t2){
    char*t = (char*) malloc(sizeof(char)*25);
    strcpy(t, t2);
    t[strlen(t)-1]='\0';
    return t;
}

int over_display(parking_lot*l){
    vehicle*p = l->vehicle_over->next;
    if(p ==NULL) return -1;
    printf("car id\t         star time\t        end time\t\t duration\t fee\n");
    while(p->next!=NULL){
        printf("%s \t%s  %s  \t     %d   \t %d\n", p->id,delete_final_character(ctime(&(p->start_time))),
               delete_final_character(ctime(&(p->end_time))), p->duration, p->fee);
        p = p->next;
    }
    printf("%s \t%s  %s  \t     %d   \t %d\n", p->id, delete_final_character(ctime(&(p->start_time))),
           delete_final_character(ctime(&(p->end_time))), p->duration, p->fee);
    p= p->next;
    return 0;
}



//time not jingque  ctime zidonghuanhang
int main(){
    parking_lot *pl = (parking_lot*) malloc(sizeof(parking_lot));
    pl->vehicle_over =(vehicle*) malloc(sizeof(vehicle));
    pl->vehicle_ongoing = (vehicle*) malloc(sizeof(vehicle));
    pl->vehicle_ongoing->count = pl->vehicle_over->count =0;
    pl->waiting_vehicle = (vehicle*) malloc(sizeof(vehicle));

    pl->vehicle_over->next = NULL;
    pl->vehicle_ongoing->next = NULL;
    pl->waiting_vehicle->next = NULL;


    vehicle*tem = (vehicle*) malloc(sizeof(vehicle));
    vehicle* tem1;
    tem->next=NULL;

    int choice;
    char* s;
    printf("please enter the choice\n");

    printf("1 add a car\n");
    printf("2 leave a car\n");
    printf("3 display all the cars on-going\n");
    printf("4 display all the fee information\n");
    printf("5 display all the cars waiting\n");

    scanf("%d", &choice);
    while(choice!=0){

        switch(choice){
            case 1:
                printf("please enter the id\n");
                scanf("%s",&(tem->id));
                tem->start_time = time(0);
                if(pl->vehicle_ongoing->count>=parking_count){
                    printf("the parking lot is full, please wait\n");
                    waiting_vehicle_add(pl, tem);
                }
                else{
                    add_vehicle(pl, tem);
                }
                break;
            case 2:
                printf("please enter the id\n");
                scanf("%s", &(tem->id));
                leave_vehicle(pl, tem->id);
                if(pl->vehicle_ongoing->count < parking_count){
                    if(pl->waiting_vehicle->next!=NULL){
                        tem1 = pl->waiting_vehicle->next;
                        add_vehicle(pl, tem1);
                        pl->waiting_vehicle->next = pl->waiting_vehicle->next->next;
                        free(tem1);
                    }
                }
                break;
            case 3:
                on_going_display(pl);
                break;

            case 4:
                over_display(pl);
                break;
            case 5:
                waiting_display(pl);
                break;
        }
        printf("1 add a car\n");
        printf("2 leave a car\n");
        printf("3 display all the cars on-going\n");
        printf("4 display all the fee information\n");
        printf("5 display all the cars waiting\n");

        printf("please enter the choice\n");
        scanf("%d", &choice);

    }

};