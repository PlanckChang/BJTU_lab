#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
#define THREAD 5
#define RESOURCE 3

int Finish[THREAD] = {0};
int Work[RESOURCE] = {0};
int Max[THREAD][RESOURCE] = {0};
int Allocation[THREAD][RESOURCE] = {0};
int Need[THREAD][RESOURCE] = {0};
int Available[RESOURCE] = {0};
int n; // num for thread
int m; // num for classification of resource
ifstream fin;

int Security[THREAD] = {-1};
int count = 0; // the order of security line
int tem_allocation[RESOURCE] = {0};


int init(string &test_file_path= (string &) "../test1"){

    fin.open(test_file_path);
    if(!fin){
        cerr << "file " << test_file_path << " open error!\n";
        return -1;
    }

    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        fin >> Available[i];
    }



    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            fin >> Max[i][j];
        }
        for(int j=0;j<m;++j){
            fin >> Allocation[i][j];
            tem_allocation[j] += Allocation[i][j];
        }
        for (int j=0; j<m; ++j) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    int flag_allocation = 0;
    for(int i=0;i<m;++i){
        if(tem_allocation[i] > Available[i]){
            flag_allocation = 1;
            break;
        }
        Available[i] -= tem_allocation[i];
    }
    if(flag_allocation){
        cout<< "test sample error initial allocation resource is bigger than total \n";
        return -1;
    }
//    fin.close();
    return 0;
}

int finish_all_true(){
    int result = 0;
    for(int i=0;i<n;++i){
        result +=Finish[i];
    }
    if(result==n){
        return 0;
    }
    else{
        return -1;
    }
}
int satisfied(int &id_thread){
    int flag = 0;
    for(int i=0;i<m; ++i){
        if(Work[i]>=Need[id_thread][i]) continue;
        else {
            flag = 1;
            break;
        }
    }
    if(flag) return -1;
    else return 0;
}
int work_assign_available(){
    for(int i=0;i<m;++i){
        Work[i] = Available[i];
    }
    return 0;
}
int distribute(){
    string tem_string;

    fin >> tem_string;
    if(tem_string == "end"){

    }
    else if(tem_string=="request"){
        int tem_id_thread;
        int tem_resource_array[m];
        int num_special_request;
        fin >> num_special_request;

        for(int j=0; j<num_special_request;++j){
            fin >> tem_id_thread;
            int flag = 0;
            for (int i = 0; i < m; ++i) {
                fin >> tem_resource_array[i];
                if(tem_resource_array[i]<=Need[tem_id_thread][i]){}
                else{
                    flag = 1;
                    return -1;
                }
            }

            if(flag==1){}
            else{
                int k = 0;
                for(;k<m;++k){
                    if(tem_resource_array[k]<=Need[tem_id_thread][k] && tem_resource_array[k]<=Available[tem_id_thread]){}
                    else break;
                }
                if(k==m){
                    work_assign_available();
                    if(Finish[tem_id_thread]==0 && satisfied(tem_id_thread)==0) {
                        Finish[tem_id_thread] = 1;
                        Security[count++] = tem_id_thread;
                        for (int j = 0; j < m; ++j) {
                            Available[j] = Work[j] + Allocation[tem_id_thread][j];
                        }
                    }
                }
            }
        }
    }




    while(1){
        int flag = 0;
        if(finish_all_true()==0){
            cout << "this test sample has a security line\n";
            return 0;
            break;
        }
        work_assign_available();

        for(int i=0;i<n;++i){
            if(Finish[i]==0 && satisfied(i)==0){
                Finish[i] = 1;
                Security[count++] = i;
                for(int j=0;j<m;++j){
                    Available[j] = Work[j] + Allocation[i][j];
                }
                work_assign_available();
                flag = 1;
            }
        }
        if(!flag){
            cout << "this test sample has no security line\n";
            return -1;
            break;
        }
    }
}

int show_security_line(string &path){
    cout << path << " security line is followed\n";
    for(int i=0;i<n;++i){
        cout << Security[i] << "\t";
    }
    cout << endl;
}
int main() {
    string test_file_path = "../test2";
    if (init(test_file_path) == -1) return -1;
    if(distribute()==0){
        show_security_line(test_file_path);
    }
    return 0;
}
