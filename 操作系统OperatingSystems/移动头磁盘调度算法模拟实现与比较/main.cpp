#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trace_accessed;
int total_num_trace_access;
int random_seed;
int min_random;
int max_random;
int initial_now;

int pre_set(string& file_path){
    fstream fin;
    fin.open(file_path);
    if(!fin){
        cout << file_path << " file open error\n";
        return -1;
    }

    fin >> total_num_trace_access;
    fin >> random_seed;
    fin >> min_random;
    fin >> max_random;
    fin.close();
    srand(random_seed);
    int num;
//    (rand() % (b-a+1))+ a
    for(int i=0; i<total_num_trace_access; ++i){
        num = (rand() % (max_random-min_random+1)) + min_random;
        trace_accessed.emplace_back(num);
    }
    initial_now = (rand() % (max_random - min_random +1)) + min_random;
//output
    cout << "initial trace head location\t" << initial_now << "\n";
    cout << "source trace access queue\n";
    for(auto item:trace_accessed){
        cout << item << "\t";
    }
    cout  << "\n\n";
}

int FIFO(){
    vector<int>access_result = trace_accessed;
    int total_move=0;
    int now = initial_now;
    double mean;
    for(auto item:access_result){
        total_move += abs(item - now);
        now = item;
    }
    mean = (double)total_move / total_num_trace_access;
    cout << "FIFO\n";
    cout << "accessed queue\n";
    for(auto item: access_result){
        cout << item << "\t";
    }
    cout << "\nmean trace cost\t" << mean << "\n\n";
}

int SSTF(){
    vector<int> access_result = trace_accessed;
    std::sort(access_result.begin(), access_result.end());
    vector<int> result;
    int total_move =0 ;
    int now = initial_now;
    double mean;
    int b_index;
    int a_index;
    while(!access_result.empty()){
        b_index = lower_bound(access_result.begin(), access_result.end(), now) - access_result.begin();
        a_index = b_index-1;
        if(b_index == 0){
            total_move += abs(access_result[b_index] - now);
            now = access_result[b_index];
            access_result.erase(access_result.begin());
        }
        else if(b_index == access_result.size()){
            total_move += abs(access_result[b_index-1] - now);
            now = access_result[b_index-1];
            access_result.erase(access_result.end()-1);
        }
        else{
            int tem1 = abs(access_result[b_index] - now);
            int tem2 = abs(access_result[a_index]- now);
            if(tem1 >= tem2){
                total_move += tem2;
                now = access_result[a_index];
                access_result.erase(access_result.begin() + a_index);
            }
            else{
                total_move +=tem1;
                now = access_result[b_index];
                access_result.erase(access_result.begin() + b_index);
            }
        }
        result.push_back(now);
    }
    mean = (double) total_move / total_num_trace_access;
    cout << "SSTF\n";
    cout  << "accessed queue\n";
    for(auto item:result){
        cout << item << "\t";
    }
    cout << "\nmean trace cost\t" << mean  << "\n\n";
}

int SCAN(){
    vector <int>access_result = trace_accessed;
    std::sort(access_result.begin(), access_result.end());
    vector<int>result;
    int total_move =0 ;
    int now = initial_now;
    double mean;

    auto b_index = std::lower_bound(access_result.begin(), access_result.end(), now);
    result.insert(result.end(), b_index, access_result.end());
    reverse_iterator<vector<int>::iterator> tem_reverse(b_index);
//    pointer the left of b_index
    result.insert(result.end(), tem_reverse, access_result.rend());

    for(auto item:result){
        total_move += abs(item - now);
        now = item;
    }
    mean = (double)total_move / total_num_trace_access;
    cout << "SCAN\n";
    cout << "accessed queue\n";
    for(auto item:result){
        cout << item << "\t";
    }
    cout << "\nmean trace cost\t" << mean << "\n\n";
//    return now;
}

int CSCAN(){
    vector<int> access_result = trace_accessed;
    std::sort(access_result.begin(), access_result.end());
    vector<int>result;
    int total_move =0 ;
    int now = initial_now;
    double mean;

    auto b_index = std::lower_bound(access_result.begin(), access_result.end(), now);
    result.insert(result.end(), b_index, access_result.end());

//    pointer the left of b_index
    result.insert(result.end(), access_result.begin(), b_index);

    for(auto item:result){
        total_move += abs(item - now);
        now = item;
    }
    mean = (double)total_move / total_num_trace_access;
    cout << "CSCAN\n";
    cout << "accessed queue\n";
    for(auto item:result){
        cout << item << "\t";
    }
    cout << "\nmean trace cost\t" << mean << "\n\n";
}

int DFSCAN(){
    vector<int> access_result = trace_accessed;
    vector<int> access_result1(trace_accessed.begin(), trace_accessed.begin()+int(total_num_trace_access/2));
    vector<int> access_result2(trace_accessed.begin()+int(total_num_trace_access/2), trace_accessed.end());

    vector<int>result;
    int total_move =0 ;
    int now = initial_now;
    double mean;

    for(int i=0;i<2;++i){
        vector<int> tem;
        if(i==0) tem = access_result1;
        else if(i==1) tem = access_result2;
        std::sort(tem.begin(), tem.end());

        auto b_index = std::lower_bound(tem.begin(), tem.end(), now);
        result.insert(result.end(), b_index, tem.end());
        reverse_iterator<vector<int>::iterator> tem_reverse(b_index);
//    pointer the left of b_index
        result.insert(result.end(), tem_reverse, tem.rend());

//        second scan begin
        now = result.back();
    }

    now = initial_now;
//    to compute cost
    for(auto item:result){
        total_move += abs(item - now);
        now = item;
    }
    mean = (double)total_move / total_num_trace_access;
    cout << "DFSCAN\n";
    cout << "first scan queue\n";
    for(auto item: access_result1){
        cout<< item << "\t";
    }
    cout << "\n";
    cout << "second scan queue\n";
    for(auto item:access_result2){
        cout << item << "\t";
    }
    cout << '\n';
    cout << "accessed queue\n";
    for(auto item:result){
        cout << item << "\t";
    }
    cout << "\nmean trace cost\t" << mean << "\n\n";

}

int main() {
    string config_path = "../config.txt";
    pre_set(config_path);

    FIFO();
    SSTF();
    SCAN();
    CSCAN();
    DFSCAN();

}

