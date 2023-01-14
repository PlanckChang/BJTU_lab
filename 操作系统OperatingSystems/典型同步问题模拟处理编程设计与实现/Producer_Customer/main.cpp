#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
#define N 5
#define MAXNLOOP 30

int in = 0;
int out = 0;
HANDLE WINAPI empty = CreateSemaphore(NULL, 10, 10, "empty");
HANDLE WINAPI full = CreateSemaphore(NULL, 0, 10, "full");
HANDLE WINAPI mutex = CreateMutex(NULL, FALSE, "MutexToProtectCriticalResource");

string buffer[N];
int nloop = 0;
DWORD WINAPI ThreadExecuteZZWProducer(LPVOID lpParameter){
    int *pID = (int *)lpParameter;
    string nextp = to_string(*pID) + " produced";
    while(1){
        WaitForSingleObject(empty, INFINITE);
        WaitForSingleObject(mutex, INFINITE);
        if(nloop>MAXNLOOP) break;
        buffer[in] = nextp;
        in = (in + 1) % N;
        cout << "nloop " << nloop << " producer " <<  *pID << " has produced on the buffer " << in << "\n";
        ++nloop;
        ReleaseMutex(mutex);
        ReleaseSemaphore(full, 1, NULL);

    }
    return 0;
}

DWORD WINAPI ThreadExecuteZZWConsumer(LPVOID lpParameter){
    int *pID = (int*)lpParameter;
    string nextp;
    while(1){
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(mutex, INFINITE);
        if(nloop>MAXNLOOP) break;
        nextp = buffer[out];
        out = (out +1) % N;
        cout << "nloop " << nloop << " consumer "<< *pID << " has consumed on the buffer " << out << " the content is producer "<< nextp << "\n";
        ++nloop;
        ReleaseMutex(mutex);
        ReleaseSemaphore(empty, 1, NULL);
    };
    return 0;
}

int main() {
    HANDLE hThread[4];
    int nPID0 =0;
    int nPID1 =1;
    if((hThread[0] = CreateThread(NULL, 0, ThreadExecuteZZWConsumer, &nPID0, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[1] = CreateThread(NULL, 0, ThreadExecuteZZWConsumer, &nPID1, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    }
    if((hThread[2] = CreateThread(NULL, 0, ThreadExecuteZZWProducer, &nPID0, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[3] = CreateThread(NULL, 0, ThreadExecuteZZWProducer, &nPID1, 0, NULL)) == NULL){
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
