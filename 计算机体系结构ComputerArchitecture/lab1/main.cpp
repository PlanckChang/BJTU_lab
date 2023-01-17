#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int slow_gcd(int a, int b){
    for(int i=b; i>=2; --i){
        if(a%i==0 && b%i==0){
            break;
        }
        else{
            continue;
        }
    }
}

int fast_gcd(int a, int b){
    if(a%b==0){
        return 0;
    }
    else{
        fast_gcd(b, a%b);
    }
}

double run(double k){
    clock_t  start, end;
    int a, b;
    int count = k*10000;

    start = clock();
    for(int i=0; i<count; ++i){
        a = (rand()<<5) + rand();
        b = (rand()<<5) + rand();
        if(a<b){
            int tem = a;
            a = b;
            b = tem;
        }
        slow_gcd(a, b);
    }
    end = clock();

    double slow_gcd_time = (double)(end-start)/CLOCKS_PER_SEC;

    count = (1-k)*10000;
    start = clock();
    for(int i=0;i<count;++i ){
        a = (rand()<<5) + rand();
        b = (rand()<<5) + rand();
        if(a<b){
            int tem = a;
            a = b;
            b = tem;
        }
        fast_gcd(a, b);
    }
    end = clock();
    double fast_gcd_time = (double )(end - start)/CLOCKS_PER_SEC;

    double total_time = fast_gcd_time + slow_gcd_time;
    return total_time;
}
int main() {
    cout << "0.5  "<< run(0.5) << "\n";
    cout << "0.1  "<< run(0.1) << "\n";
    cout << "0.9  "<< run(0.9) << "\n";


    

}
