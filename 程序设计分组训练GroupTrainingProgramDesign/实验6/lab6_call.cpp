//
// Created by Planck Chang on 2021/12/20.
//

#include "lab6_call.h"
#include <stdio.h>
#include <stdlib.h>
/// callLab4txt
/// \param storepath path of stored file
/// \param data count of dataitems
/// \return 1
int callLab4txt(char *storepath, char *data) {
    char pave[100];
    sprintf(pave, "Lab4.exe %s %s.txt t", data, storepath );
    system(pave);
    return 1;
}
/// callLab4dat
/// \param storepath path of stored file
/// \param data  count of dataitems
/// \return 2
int callLab4dat(char *storepath, char *data)
{
    char pave[100];
    sprintf(pave, "Lab4.exe %s %s d", data, storepath);
    system(pave);
    return 2;
}
