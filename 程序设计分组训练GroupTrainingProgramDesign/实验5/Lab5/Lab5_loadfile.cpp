//
// Created by Planck Chang on 2021/12/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lab5_data.h"
#include "Lab5_view.h"
#include "Lab5_loadfile.h"



char *choose(char *str) {
    static char file1[100];
    char filesavepath[100];
    char filename[100];
    if(strcmp(str, "\0") == 0)
    {
        FILE*fp=fopen("conf.ini","r");
        if (fp==NULL)
        {
            printf("file open error\n");
            exit(1);
        }
        fscanf(fp,"%s\n",filesavepath);
        fscanf(fp,"%s",filename);
        strcpy(file1,filesavepath);
        strcat(file1,"\\");
        strcat(file1,filename);
    }
    else
        strcpy(file1, str);
    return file1;
}

void loadtoarray(char *path, int filetype) {
    FILE * pf;
    int record_num;
    int **item;
    if(filetype==1)
    {
        pf = fopen(path, "r");
        if(!pf)
        {
            printf("file open error1\n");
            exit(1);
        }
        fscanf(pf, "%d", &record_num);

        item = (int **) malloc(sizeof (item)*record_num);

        for(int i=0;i<record_num; ++i)
        {
            item[i] = (int *)malloc(3*sizeof (int ));

            //read in format control (cheak in outputfile)
            fscanf(pf, "%d %d %d\n", &item[i][0], &item[i][1], &item[i][2]);
        }
        fclose(pf);
    }
    else{
        pf = fopen(path, "rb");
        if(!pf)
        {
            printf("file open error1\n");
            exit(1);
        }

        fread(&record_num, 4, 1, pf);
        item =(int **) malloc(sizeof(item)*record_num);
        for (int i = 0; i < record_num; ++i) {
            item[i] = (int *) malloc(sizeof(int)*3);
            fread(&item[i], sizeof (int )*3, 1, pf  );
        }
        fclose(pf);
    }
    showarray(item, record_num);
    for (int i = 0; i < record_num; ++i) {
        free(item[i]);
    }
    free(item);
}

void loadtostructarray(char *path, int filetype) {
    FILE * pf;
    int record_num;
    DATAITEM * item;
    if(filetype==1) {
        pf = fopen(path, "r");
        if (!pf) {
            printf("file open error2\n");
            exit(1);
        }
        fscanf(pf, "%d", &record_num);

        item = (DATAITEM *) malloc(sizeof(DATAITEM) * record_num);
        for (int i = 0; i < record_num; ++i) {
            fscanf(pf, "%d %d %d\n", &item[i].item1, &item[i].item2, &item[i].item3);
        }
        fclose(pf);
    }
    else{
        pf = fopen(path, "rb");
        if(!pf)
        {
            printf("file open error2\n");
            exit(1);
        }
        fread(&record_num, 4, 1, pf);
        item = (DATAITEM*) malloc(sizeof(DATAITEM)*record_num);
        for (int i = 0; i <record_num; ++i) {
            fread(&item[i].item1, 4, 1, pf);
            fread(&item[i].item2, 4, 1, pf);
            fread(&item[i].item3, 4, 1, pf);
        }
        fclose(pf);
    }
    showstructarray(item, record_num);
    free(item);
}

void loadtopointerarray(char *path, int filetype) {
    FILE * pf;
    int record_num;
    DATAITEM **item;
    if(filetype==1) {
        pf = fopen(path, "r");
        if (!pf) {
            printf("file open error3\n");
            exit(1);
        }
        fscanf(pf, "%d", &record_num);
        item = (DATAITEM **) malloc(sizeof(DATAITEM *) * record_num);
        for (int i = 0; i < record_num; ++i) {
            item[i] = (DATAITEM *) malloc(sizeof(DATAITEM));
            fscanf(pf, "%d %d %d", &item[i]->item1, &item[i]->item2, &item[i]->item3);
        }
        fclose(pf);
    }
    else{
        pf = fopen(path, "rb");
        if(!pf)
        {
            printf("file open error3\n");
            exit(1);
        }
        fread(&record_num, 4, 1, pf);
        item = (DATAITEM**)malloc(sizeof (DATAITEM*)*record_num);
        for (int i = 0; i < record_num; ++i) {
            item[i] = (DATAITEM *) malloc(sizeof(DATAITEM));
            fread(&item[i]->item1, 4, 1, pf);
            fread(&item[i]->item2, 4, 1, pf);
            fread(&item[i]->item3, 4, 1, pf);
        }
        fclose(pf);
    }
    showpointerarray(item, record_num);
    for (int i = 0; i < record_num; ++i) {
        free(item[i]);
    }
    free(item);
}

void loadtolink(char *path, int filetype) {
    FILE *pf;
    int record_num;
    Link *head = (Link *) malloc(sizeof(Link));


    if (filetype == 1) {
        pf = fopen(path, "r");
        if (!pf) {
            printf("file open error4\n");
            exit(1);
        }
        fscanf(pf, "%d", &record_num);
        head->totaldatanum = record_num;
        Node *pre = (Node *) malloc(sizeof(Node));
        fscanf(pf, "%d %d %d", &pre->data[0], &pre->data[1], &pre->data[2]);
        head->next = pre;

        for (int i = 0; i < record_num; ++i) {
            Node *p = (Node *) malloc(sizeof(Node));
            fscanf(pf, "%d %d %d", &p->data[0], &p->data[1], &p->data[2]);
            pre->next = p;
            pre = p;
        }
        pre->next = NULL;
        fclose(pf);
    }
    else{
        pf = fopen(path, "rb");
        if(!pf)
        {
            printf("file open error4\n");
            exit(1);
        }
        fread(&record_num, 4, 1, pf);

        Link * head = (Link*) malloc(sizeof(Link));
        head->totaldatanum = record_num;
        Node * pre = (Node*) malloc(sizeof (Node));
        fread(&pre->data[0], 4, 1, pf);
        fread(&pre->data[1], 4, 1, pf);
        fread(&pre->data[2], 4, 1, pf);
        head->next = pre;

        for (int i = 0; i < record_num; ++i) {
            Node * p = (Node*) malloc(sizeof(Node));
            fread(&p->data[0], 4, 1, pf);
            fread(&p->data[1], 4, 1, pf);
            fread(&p->data[2], 4, 1, pf);
            pre->next = p;
            pre = p;
        }
        pre->next = NULL;
        fclose(pf);
        showlink(head->next);
    }
}