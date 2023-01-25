//
// Created by Planck Chang on 2021/12/20.
//

#ifndef LAB6_LAB6_CMP_H
#define LAB6_LAB6_CMP_H

#include <cstdio>
#include "lab6_conf.h"
#include "lab6_data.h"
#include "lab6_conf.h"
#include "lab6_view.h"
int cmppionterarray(const void*a, const void *b);
int cmpstructarray(const void *a, const void *b);
int cmparray(const void *a, const void *b);
void bubblesortlink(Link * head);


//output function
void show_array(int **a, int num);

void show_structarray(DATAITEM data[], int num);

void show_pointerarry(DATAITEM *data[], int num);

void show_link(Link *head);
#endif //LAB6_LAB6_CMP_H
