//
// Created by Planck Chang on 2021/10/29.
//

#ifndef LAB4_FUN_H
#define LAB4_FUN_H

#include "data.h"

int num_judge(char* num);
int random_int(int min, int max);
int file_judge(char* name);
void file_write(CONF conf);
void file_write2(CONF conf);
char* get_filepave(char* pave);
char* get_filename(char* name);
CONF&read_configinfo();

#endif //LAB4_FUN_H
