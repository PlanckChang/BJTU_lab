//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//#define MAXNLOOP 30
//HANDLE WINAPI chopstick[5];
//HANDLE WINAPI semCount = CreateSemaphore(NULL, 4, 4, "semCount");
//HANDLE WINAPI mutex = CreateMutex(NULL, FALSE, "MutexToProtectCriticalResource");
//int nloop = 0;
//HANDLE WINAPI chopstick0 = CreateMutex(NULL, FALSE, "0");
//HANDLE WINAPI chopstick1 = CreateMutex(NULL, FALSE, "1");
//HANDLE WINAPI chopstick2 = CreateMutex(NULL, FALSE, "2");
//HANDLE WINAPI chopstick3 = CreateMutex(NULL, FALSE, "3");
//HANDLE WINAPI chopstick4 = CreateMutex(NULL, FALSE, "4");
//
//DWORD WINAPI ThreadExecuteZZWPhilosopher(LPVOID lpParameter){
//    int *pID = (int *)lpParameter;
//
//    while(1){
//        WaitForSingleObject(mutex, INFINITE);
//        cout << "Philosopher " << *pID << " is thinking" << endl;
//        ReleaseMutex(mutex);
//
//        WaitForSingleObject(semCount, INFINITE);
//        WaitForSingleObject(chopstick[*pID], INFINITE);
//        WaitForSingleObject(chopstick[((*pID)+1)%5], INFINITE);
//
//        WaitForSingleObject(mutex, INFINITE);
//        if(nloop > MAXNLOOP) break;
//        cout << "nloop " << nloop << " Philosopher " << *pID << " is eating" << endl;
//        ++nloop;
//        ReleaseMutex(mutex);
//        ReleaseMutex(chopstick[((*pID)+1)%5]);
//        ReleaseMutex(chopstick[*pID]);
//        ReleaseSemaphore(semCount, 1, NULL);
//    }
//}
//int main() {
//    chopstick[0] = chopstick0;
//    chopstick[1] = chopstick1;
//    chopstick[2] = chopstick2;
//    chopstick[3] = chopstick3;
//    chopstick[4] = chopstick4;
//
//    HANDLE hThread[5];
//    for(int i=0;i<5;++i){
//        if((hThread[i] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &i, 0, NULL)) == NULL){
//            cout << "create thread failed\n";
//            exit(0);
//        };
//    }
//    WaitForMultipleObjects(5,hThread,true,INFINITE);
//    for(int i=0;i<5;++i){
//        CloseHandle(hThread[i]);
//    }
//    cout << "sub threads end\n";
//    cout << "main threads end\n";
//}


#include <iostream>
#include <windows.h>

using namespace std;
#define MAXNLOOP 30
int nloop = 0;
HANDLE WINAPI chopstick0 = CreateMutex(NULL, FALSE, "0");
HANDLE WINAPI chopstick1 = CreateMutex(NULL, FALSE, "1");
HANDLE WINAPI chopstick2 = CreateMutex(NULL, FALSE, "2");
HANDLE WINAPI chopstick3 = CreateMutex(NULL, FALSE, "3");
HANDLE WINAPI chopstick4 = CreateMutex(NULL, FALSE, "4");
HANDLE WINAPI chopstick[5];
HANDLE WINAPI mutex = CreateMutex(NULL, FALSE, "mutex");
DWORD WINAPI ThreadExecuteZZWPhilosopher(LPVOID lpParameter){
    int *pID = (int *)lpParameter;

    while(1){
//        WaitForSingleObject(mutex, INFINITE);
        cout << "Philosopher " << *pID << " is thinking" << endl;
//        ReleaseMutex(mutex);

        WaitForSingleObject(mutex, INFINITE);
//        WaitForSingleObject(semCount, INFINITE);
        WaitForSingleObject(chopstick[*pID], INFINITE);
        WaitForSingleObject(chopstick[((*pID)+1)%5], INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        if(nloop > MAXNLOOP) break;
        cout << "nloop " << nloop << " Philosopher " << *pID << " is eating" << endl;
        ++nloop;
        Sleep(5);
//        ReleaseMutex(mutex);
        ReleaseMutex(chopstick[((*pID)+1)%5]);
        ReleaseMutex(chopstick[*pID]);
//        ReleaseSemaphore(semCount, 1, NULL);
    }
}
int main() {
    chopstick[0] = chopstick0;
    chopstick[1] = chopstick1;
    chopstick[2] = chopstick2;
    chopstick[3] = chopstick3;
    chopstick[4] = chopstick4;

    HANDLE hThread[5];
    int nPID0 = 0;
    int nPID1 = 1;
    int nPID2 = 2;
    int nPID3 = 3;
    int nPID4 = 4;

    int tem[5];
    for (int i = 0; i < 5; ++i) {
        tem[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        if ((hThread[i] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &tem[i], 0, NULL)) == NULL) {
            cout << "create thread failed\n";
            exit(0);
        };
    }
    if((hThread[0] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &nPID0, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[1] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &nPID1, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[2] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &nPID2, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[3] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &nPID3, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };
    if((hThread[4] = CreateThread(NULL, 0, ThreadExecuteZZWPhilosopher, &nPID4, 0, NULL)) == NULL){
        cout << "create thread failed\n";
        exit(0);
    };

        WaitForMultipleObjects(5, hThread, true, INFINITE);
        for (int i = 0; i < 5; ++i) {
            CloseHandle(hThread[i]);
        }
        cout << "sub threads end\n";
        cout << "main threads end\n";
    }
