//
// Created by Planck Chang on 2022/10/4.
//

#include <iostream>
#include <windows.h>


using namespace std;
int nAccount1 = 0, nAccount2 = 0;
// lp is the prefix of a pointer var
DWORD WINAPI ThreadExecuteZZW(LPVOID lpParameter){
    int *pID = (int*)lpParameter;

    int nLoop = 0;
    int nTemp1, nTemp2, nRandom;
    do
    {
        cout << "thread " << *pID << " is called"<< " nLoop is " << nLoop << endl;
        nRandom = rand();
        nTemp1 = nAccount1;
        nTemp2 = nAccount2;
        nAccount1 = nTemp1 + nRandom;
        nAccount2 = nTemp2 - nRandom;
        ++nLoop;
    } while ((nAccount1 + nAccount2) == 0);

    return 0;
}
int main(){
    HANDLE hThread[2];
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
    Sleep(100);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    cout << "sub threads end\n";
    cout << "main thread end\n";
}
