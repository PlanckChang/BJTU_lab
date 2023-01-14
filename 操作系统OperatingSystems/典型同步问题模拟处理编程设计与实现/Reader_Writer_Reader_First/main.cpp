#include <iostream>
#include <windows.h>
#include <string>

using namespace std;
#define N 1
#define MAXNLOOP 30
int readercount =0;
HANDLE WINAPI rmutex = CreateMutex(NULL, FALSE, "MutexToProtectCriticalResource");
HANDLE WINAPI wmutex = CreateMutex(NULL, FALSE, "MutexToProtectCriticalResource");

string buffer[N];
int nloop = 0;
int in = 0;
int out = 0;
DWORD WINAPI ThreadExecuteZZWWriter(LPVOID lpParameter){
    int *pID = (int*)lpParameter;
    string nextp = to_string(*pID) + " wrote";

    while(1){
        WaitForSingleObject(wmutex, INFINITE);
        if(nloop >= MAXNLOOP) break;
        buffer[in] = nextp;
        in = (in + 1) % N;
        cout << "nloop " << nloop << " writer " <<  *pID << " has wrote on the buffer " << in << "\n";
        ++nloop;
        ReleaseMutex(wmutex);
    }
    return 0;
}

DWORD WINAPI ThreadExecuteZZWReader(LPVOID lpParameter){
    int *pID = (int*)lpParameter;
    string nextp;
    while(1){
        WaitForSingleObject(rmutex, INFINITE);
        if(readercount == 0) WaitForSingleObject(wmutex, INFINITE);
        ++readercount;
        if(nloop>=MAXNLOOP) break;
        ++nloop;
        ReleaseMutex(rmutex);

        nextp = buffer[out];
        out = (out +1) % N;
        cout << "nloop " << nloop << " reader "<< *pID << " has read on the buffer " << out << " the content is writer "<< nextp << "\n";

        WaitForSingleObject(rmutex, INFINITE);
        --readercount;
        if(readercount==0) ReleaseMutex(wmutex);
        ReleaseMutex(rmutex);
    };
    return 0;
}
int main() {
    HANDLE hThread[4];
    int nPID0 =0;
    int nPID1 =1;
    if((hThread[0] = CreateThread(NULL, 0, ThreadExecuteZZWReader, &nPID0, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[1] = CreateThread(NULL, 0, ThreadExecuteZZWReader, &nPID1, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    }
    if((hThread[2] = CreateThread(NULL, 0, ThreadExecuteZZWWriter, &nPID0, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[3] = CreateThread(NULL, 0, ThreadExecuteZZWWriter, &nPID1, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    }

    WaitForMultipleObjects(4,hThread,true,INFINITE);
//    WaitForSingleObject(2, writerThread, true, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);
    CloseHandle(hThread[2]);
    CloseHandle(hThread[3]);
    cout << "sub threads end\n";
    cout << "main thread end\n";
}


