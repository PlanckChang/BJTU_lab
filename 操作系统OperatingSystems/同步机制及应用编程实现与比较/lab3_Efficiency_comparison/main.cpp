#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
#define MAXLOOP 10000
int nAccount1 = 0;
int nAccount2 = 0;

HANDLE hMutex = CreateMutex(NULL, FALSE, "MutexToProtectCriticalResource");
int nLoop = 0;
DWORD WINAPI ThreadExecuteZZW(LPVOID lpParameter){
    int *pID = (int *)lpParameter;
    int nTemp1, nTemp2, nRandom;

    do{
        WaitForSingleObject(hMutex, INFINITE);
        if(nLoop%1000 == 0){
            cout << "thread "<< *pID << " is called " << "nLoop is "<< nLoop << "\n";
        }
        nRandom = rand();
        nTemp1 = nAccount1;
        nTemp2 = nAccount2;
        nAccount1 = nTemp1 + nRandom;
        nAccount2 = nTemp2 - nRandom;
        ++nLoop;
        ReleaseMutex(hMutex);

    }while((nAccount1+nAccount2)==0 && nLoop < MAXLOOP);

    return 0;
}
int main() {
    HANDLE hThread[2];
    clock_t start, end;
    start = clock();
    int nPID0 = 0;
    int nPID1 = 1;
    if((hThread[0] = CreateThread(NULL, 0, ThreadExecuteZZW, &nPID0, 0, NULL))==NULL){
        cout << "create thread 0 failed\n";
        exit(0);
    };
    if((hThread[1] = CreateThread(NULL, 0, ThreadExecuteZZW, &nPID1, 0, NULL)) == NULL){
        cout << "create thread 1 failed\n";
        exit(0);
    }

//    Sleep(1000);
//    system("pause");
    WaitForMultipleObjects(2,hThread,true,INFINITE);
//    WaitForMultipleObjects(1,hThread[1],true,INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    cout << "sub threads end\n";
    cout << "main thread end\n";

    end= clock();
    cout << "the time era mutex is " << ((double)end-start)/CLK_TCK << "\n";
}
