#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
struct array2{
	int a;
	int b;
	int c;
};

void Fileopreate2(int number, char txtaddress[]){
	FILE*pf = fopen(txtaddress, "w");
	struct array2* array[]  = (array2*)malloc(sizeof(array2)*number);

	for(int i=0; i<number; i++ ){
		array[i]->a =rand()%100;
		array[i]->b =rand()%100;
		array[i]->c =rand()%100;
	}
	if(pf==NULL){
		printf("open error\n");
		exit(0);
	}
	fprintf(pf, "%d\n", number);
	for(int i=0; i<number; i++){
		fprintf(pf,"%d, %d, %d\n", array[i]->a,array[i]->b,array[i]->c);
		}
		fprintf(pf, "\n");
	
	if(fclose(pf)!=0){
		printf("close error\n");
	}
	
	printf("opreate success!\n");
	free(array);
}	
// 一维数组 模拟二维 表格 （实则 二维都是一维 通过变量变换 模拟出来的）
void Fileopreate3(int number, char txtaddress[]){
	FILE*pf = fopen(txtaddress, "w");
	int *array=(int*)malloc(sizeof(int)*number*3);
	for(int i=0; i<number; i++ ){
		for(int j=0;j<3; j++){
			array[i*3+j]= rand%100;
		}
		
	if(pf==NULL){
		printf("open error\n");
		exit(0);
	}
	fprintf(pf, "%d\n", number);
	for(int i=0; i<number; i++){
		for(int j=0; j<3; j++){
			fprintf(pf,"%d, ", array[i*3+j);
		}
		fprintf(pf, "\n");
	}
	if(fclose(pf)!=0){
		printf("close error\n");
	}
	
	printf("opreate success!\n");
	free(array);
}

}
	

void Fileopreate(int number, char txtaddress[]){
	FILE*pf = fopen(txtaddress, "w");
	int(*array)[3] = (int(*)[3])malloc(sizeof(int)*number*3);
	
	
	for(int i=0; i<number; i++ ){
				for(int j=0; j<3; j++){
					array[i][j] =rand()%100;
				}
	}
	if(pf==NULL){
		printf("open error\n");
		exit(0);
	}
	fprintf(pf, "%d\n", number);
	for(int i=0; i<number; i++){
		for(int j=0; j<3; j++){
			fprint f(pf,"%d, ", array[i][j]);
		}
		fprintf(pf, "\n");
	}
	if(fclose(pf)!=0){
		printf("close error\n");
	}
	
	printf("opreate success!\n");
	free(array);
}

int main(int argc, char *argv[]){
	int number, i, j, k,length,choice;
	char txtaddress[20];

	choice = argc ;
	srand((int)time(0));
	

	
	switch(choice){
		case 1 :
			number = rand();
			strcpy(txtaddress,"test2.txt");
			
			
			Fileopreate(number, txtaddress);
			 break;
		case 2 :
			length = strlen(argv[1]);
			for(k=1;k<=length;k++){
									
				if(argv[1][k]>='0'&&argv[1][k]<='9') continue;
				else break;
			} 
			if(k==length){
				number = atoi(argv[1]);
				strcpy(txtaddress, "test2.txt");
			}
			else{
				strcpy(txtaddress, argv[1]);
				number = rand();
			}
			Fileopreate(number, txtaddress);
			break;
		case 3 :	
			number = atoi(argv[1]);
			strcpy(txtaddress ,argv[2]);
			Fileopreate(number, txtaddress);
			break;
	}
	
	return 0;
}
