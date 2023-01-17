/* 
A program for showing the functionality of a set-associative cache 
Author: Wei-Min Wu
Date: March, 2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Here we assume 1-word block */
int associativity=4;
int numOfAddressBits=8;
int numOfSetBits=3;
int numOfByteOffsetBits=2;
int numOfBlockOffsetBits=0;
int numOfTagBits
         =numOfAddressBits-numOfByteOffsetBits-numOfBlockOffsetBits-numOfSetBits;
int numOfAddressableBlocks=1<<(numOfAddressBits-numOfByteOffsetBits);
int numOfCacheBlocks=(1<<(numOfSetBits+numOfBlockOffsetBits))*associativity;
int numOfSets=1<<numOfSetBits;
int numOfBlocksInSet=associativity;

int numOfAccesses=40;
int *accessList;
int *numOfOccupied;

int hitNum=0,missNum=0,replaceNum=0;

typedef struct item
{
 int tag;
 struct item *last, *next;
} ITEM;

ITEM **itemListHead,**itemListTail;


void main()
{
  int i, j;
  ITEM *item,*item1,*item2,*item3,*newItem;
  int blockNum;
  int tag,setNum;
  ITEM *head, *tail;
  int mark;
  int occupyNum;
  time_t t;

  accessList=(int*)calloc(numOfAccesses,sizeof(int));
  srand((unsigned)time(NULL)); 
  for (i=0; i<numOfAccesses; i++)
  {
   accessList[i]=rand()%numOfAddressableBlocks;
  }
  
  numOfOccupied=(int*)calloc(numOfSets,sizeof(int));
  
  itemListHead=(ITEM**)calloc(numOfSets,sizeof(ITEM*));
  for (i=0; i<numOfSets; i++) itemListHead[i]=(ITEM*)calloc(1,sizeof(ITEM));
  itemListTail=(ITEM**)calloc(numOfSets,sizeof(ITEM*));
  for (i=0; i<numOfSets; i++) itemListTail[i]=(ITEM*)calloc(1,sizeof(ITEM));
  for (i=0; i<numOfSets; i++)
  {
   itemListHead[i]->next=itemListTail[i];
   itemListTail[i]->last=itemListHead[i];
  };


  for (i=0; i<numOfAccesses; i++)
   {
    blockNum=accessList[i];
    tag=blockNum/numOfSets;        
    setNum=blockNum%numOfSets;

    occupyNum=numOfOccupied[setNum]; 
    head=itemListHead[setNum];    
    tail=itemListTail[setNum];

    item=head->next;
    mark=0;
    while (item!=tail)   
     {
      if (item->tag==tag)
       { hitNum++; 
         item1=item->last;
         item2=item->next;                  
         item1->next=item2;
         item2->last=item1;
         item3=head->next;         
         head->next=item;
         item->last=head;
         item->next=item3;
         item3->last=item;
         mark=1; 
         break;
       };
      item=item->next;      
     };

    if (mark==0)
     {
      missNum++;
      if (occupyNum<numOfBlocksInSet)
       {
        numOfOccupied[setNum]++;    
        item=head->next;
        newItem=(ITEM*)calloc(1,sizeof(ITEM)); 
		newItem->tag=tag;
        newItem->next=item;
        item->last=newItem;
        head->next=newItem;
        newItem->last=head;      
       } else
       {
        item=tail->last;
        item->tag=tag;

        item1=item->last;
        item1->next=tail;
        tail->last=item1;
        item2=head->next;
        head->next=item;
        item->last=head;
        item->next=item2;
        item2->last=item;

        replaceNum++;
       };      

     };

   };  

  printf("\n");

  printf("THe number of address bits is %d.\n", numOfAddressBits);
  printf("We assume 1-word block, so the number of block bits %d-2=%d.\n", 
	  numOfAddressBits, numOfAddressBits-2);
  printf("So there are %d blocks in memory.\n", numOfAddressableBlocks);
  printf("\n");

  printf("We assume there are %d blocks in cache, half of that in memory.\n", numOfCacheBlocks);
  printf("We adopt 4-way associative cache, so the number of sets is %d.\n", numOfSets);

  printf("We create %d blocks numbers to access memory, and calculate the number of hits, misses and replacements.\n", numOfAccesses);
  printf("Theses accesses are: \n");
  for (i=0; i<numOfAccesses; i++)
  {
   if (i%10==0) printf("\n\n");
   printf("%5d ", accessList[i]);
  };

  printf("\n\n");

  printf("The result is as following ...\n");
  printf("The number of accesses is %d, in which \n", numOfAccesses);
  printf(" the number of Hits is %d,\n", hitNum);
  printf(" the number of Mises is %d,\n", missNum);
  printf(" the number of replacements is %d.\n", replaceNum);
  printf("\n");
  printf("\n");
 
  printf("Now it is your task to demonstrate how these results are obtained.\n");
  printf("Good luck!\n\n");
};