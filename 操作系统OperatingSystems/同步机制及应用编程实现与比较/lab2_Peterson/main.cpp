#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
#define MAXLOOP 10000

int nAccount1 = 0;
int nAccount2 = 0;

bool flag[2];
int turn =0;
int nLoop = 0;
DWORD WINAPI ThreadExecuteZZW0(LPVOID lpParameter){
    int *pID = (int *)lpParameter;
    int nTemp1, nTemp2, nRandom;
    do{

        flag[0] = true;
        turn = 1;
        while(flag[1] && turn == 1){};

        if(nLoop%1000 == 0){
            cout << "thread "<< *pID << " is called " << "nLoop is "<< nLoop << endl;
        }
        nRandom = rand();
        nTemp1 = nAccount1;
        nTemp2 = nAccount2;
        nAccount1 = nTemp1 + nRandom;
        nAccount2 = nTemp2 - nRandom;
        ++nLoop;

        flag[0] = false;
    }while((nAccount1+nAccount2)==0 && nLoop < MAXLOOP);

    return 0;
}

DWORD WINAPI ThreadExecuteZZW1(LPVOID lpParameter){
    int *pID = (int *)lpParameter;
    int nTemp1, nTemp2, nRandom;
    do{
        flag[1] = true;
        turn = 0;
        while(flag[0] && turn == 0){};

        if(nLoop%1000 == 0){
            cout << "thread "<< *pID << " is called " << "nLoop is "<< nLoop << "\n";
        }
        nRandom = rand();
        nTemp1 = nAccount1;
        nTemp2 = nAccount2;
        nAccount1 = nTemp1 + nRandom;
        nAccount2 = nTemp2 - nRandom;
        ++nLoop;

        flag[1] = false;
    }while((nAccount1+nAccount2)==0 && nLoop < MAXLOOP);

    return 0;
}

int main() {
    HANDLE hThread[2];
    time_t start, end;

    start = clock();
    int nPID0 = 0;
    int nPID1 = 1;
    if((hThread[0] = CreateThread(NULL, 0, ThreadExecuteZZW0, &nPID0, 0, NULL))==NULL){
        cout << "create thread 0 failed\n";
        exit(0);
    };
    if((hThread[1] = CreateThread(NULL, 0, ThreadExecuteZZW1, &nPID1, 0, NULL)) == NULL){
        cout << "create thread 1 failed\n";
        exit(0);
    }
//    Sleep(1000);
    WaitForMultipleObjects(2,hThread,true,INFINITE);
    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    cout << "sub threads end\n";
    cout << "main thread end\n";

    end = clock();
    cout << "the time era peterson is " << ((double)end - start)/ CLK_TCK << "\n";
}
