#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <map>
#include <climits>
using namespace std;



struct Page{
    int num;
    int times;
    int mode;
    int location_when_in;
//    mode 0 for read, mode 1 for write
// location when in, the location when visit it in the visit list
// and in func LRU for location in the visit list when visited last time
// in func CLOCK use it for access
};

struct MemPageControl{
    int allocated_size; // the page size to be allocated to the process
    int missing_num; // num for missing page, the call interruption
    vector<Page> page;
} inside_page;

struct OutSidePage{
    vector<Page> visit_list;
    int current;
} outside_page;

struct ResultIndex{
    double miss_rate;
    double cost_time;
};

int min_my(int a , int b){
    if(a>=b) return b;
    else return a;
}


int get_random_visit_list(int &total_size, int &v_job, int &w, int & RANTIME){
//    outside_page.visit_list.resize(total_size);

//    srand((unsigned ) time(NULL));
    srand(32);
    if(RANTIME) srand(time(NULL));
    int s = rand() % total_size;
    double t = rand() % 10 / 10.0; // gain a number [0,1]
    int v = v_job;
    while(outside_page.visit_list.size() < total_size){
        for(int i=0; i<v && outside_page.visit_list.size()<total_size;i++){
            Page tem_page;
            int tem_int = w + s;
            tem_page.num = rand() % (min_my(tem_int, total_size-1) - s + 1) + s;
//            tem_page.num = (s + (rand() % ((int)outside_page.visit_list.size()))) % total_size;
            double r = (rand() % 10) / 10.0;
            if(r > 0.7 && rand() % 2 == 1){
                tem_page.mode = 1;
            }
            else tem_page.mode = 0;

            outside_page.visit_list.emplace_back(tem_page);
//            if(outside_page.visit_list.size()>=total_size) break;
        }
        double r = (rand()% 10 )/ 10.0;

        if(r<t){
            s = rand()  % total_size;
        }
        else s = (s+1) % total_size;

    }
}

int preallocate(){
    outside_page.current = 0;
    int &current = outside_page.current;
    inside_page.page.resize(inside_page.allocated_size);
    for(int i=0; i < inside_page.allocated_size; ++i){
//        inside_page.page.emplace_back(outside_page.visit_list[current++]);
//        inside_page.page.back().times = 1;
        inside_page.page[i] = outside_page.visit_list[current++];
        inside_page.page[i].times = 1;
        inside_page.page[i].location_when_in = current;
    }
}

int show_visit_list(){
    cout << "\n" << "following is visit page list\n";

    for(int i=0, j=1;i<outside_page.visit_list.size();++i, ++j){
        cout << outside_page.visit_list[i].num << "\t";
        if(j%10 ==0) cout << '\n';
    }
    cout << endl;
}

int init(string &path){
    ifstream fin;

    fin.open(path);
    if(!fin){
        cerr << "file open error " << path << "\n";
        return -1;
    }
    int total_size_visit_list, v_job_set, w, randomtime;
    fin >> randomtime;
    fin >> inside_page.allocated_size;
    fin >> total_size_visit_list;
    fin >> v_job_set;
    fin >> w;
    inside_page.missing_num = 0;
    get_random_visit_list(total_size_visit_list, v_job_set, w, randomtime);
    outside_page.current = 0;
    preallocate();
    show_visit_list();
}

int is_inside(){
    int &current = outside_page.current;
    int page_num = outside_page.visit_list[current].num;
    for(int i=0;i<inside_page.page.size();++i){
        if(inside_page.page[i].num == page_num){
            return i;
        }
    }
    return -1;
}

int cmp(pair<int, int> a, pair<int, int> b){
    if(a.second >= b.second) return 1;
    else return 0;
}
int find_far(){
    int size = inside_page.allocated_size;
    int tem = 0;
    vector<pair<int, int>> find;
    int &current = outside_page.current;
//    memset(find, -1, sizeof(find));
    for(int i=0;i<size;++i){
        find.emplace_back(pair<int, int> (i, INT_MAX));
        for(int j=current+1;j<outside_page.visit_list.size();++j){
            int target = inside_page.page[i].num;
            int location = outside_page.visit_list[j].num;
            if(target==location){
                find[i].second = j;
                break;
            }
        }
    }
//    sort(find[0], find[size-1], cmp);
    std::sort(find.begin(), find.end(), cmp);
    return find[0].first;
}
int show_gotit(){
    int current = outside_page.current;
    cout << "visit " << outside_page.visit_list[current].num;
    cout << " inside mem is [ ";
    for(auto item:inside_page.page){
        cout << item.num << ' ';
    }
    cout << "] \t";
    cout << "got it\n";
}

int show_miss(){
    int current = outside_page.current;
    cout << "visit " << outside_page.visit_list[current].num;
    cout << " inside mem is [ ";
    for(auto item:inside_page.page){
        cout << item.num << ' ';
    }
    cout << "] \t";
    cout << "miss it\n";
}

ResultIndex OPT(){
    preallocate();
    time_t start, end;
    double cost=0;
    inside_page.missing_num = 0;
    int &current = outside_page.current;
    for(;current<outside_page.visit_list.size();current++){
        int is_inside_result = is_inside();
        int flag = 0;
        if(is_inside_result==-1){
            start = clock();

            int find_result = find_far();
            inside_page.page[find_result] = outside_page.visit_list[current];
            inside_page.page[find_result].times = 1;
            inside_page.missing_num++;

            end = clock();
            cost += (double)end-start;
        }
        else{
            inside_page.page[is_inside_result].times ++;
            flag = 1;
        }
        if(flag) show_gotit();
        else show_miss();
    }
    double missing_rate = (double)inside_page.missing_num/outside_page.visit_list.size();
    cost = cost / CLOCKS_PER_SEC;
    cout << "OPT missing rate is " << missing_rate;
    cout << "\tsearch time cost is  " << cost;
    cout << "\n" << endl;
    ResultIndex resultIndex;
    resultIndex.cost_time = cost;
    resultIndex.miss_rate = missing_rate;
    return resultIndex;
}

int find_most_early(){
    int size = inside_page.allocated_size;
    int tem = 0;
    map<int,int> find;

    for(int i=0;i<size;++i){
        find[inside_page.page[i].location_when_in] = i;
    }
    return find.begin()->second;
}
ResultIndex FIFO(){
    preallocate();
    time_t start, end;
    double cost=0;
    inside_page.missing_num = 0;
    int &current = outside_page.current;
    for(;current<outside_page.visit_list.size();current++){
        int is_inside_result = is_inside();
        int flag = 0;
        if(is_inside_result==-1){
            start = clock();

            int find_result = find_most_early();
            inside_page.page[find_result] = outside_page.visit_list[current];
            inside_page.page[find_result].times = 1;
            inside_page.page[find_result].location_when_in = current;
            inside_page.missing_num++;
            end = clock();
            cost += (double)end-start;
        }
        else{
            inside_page.page[is_inside_result].times ++;
            flag = 1;
        }
        if(flag) show_gotit();
        else show_miss();
    }
    double missing_rate = (double)inside_page.missing_num/outside_page.visit_list.size();
    cost = cost / CLOCKS_PER_SEC;
    cout << "FIFO missing rate is " << missing_rate;
    cout << "\tsearch time cost is  " << cost;
    cout << "\n" << endl;
    ResultIndex resultIndex;
    resultIndex.cost_time = cost;
    resultIndex.miss_rate = missing_rate;
    return resultIndex;
}

int find_last_resent_unused(){
    int size = inside_page.allocated_size;
    int tem = 0;
    map<int,int> find;

    for(int i=0;i<size;++i){
        find[inside_page.page[i].location_when_in] = i;
    }
    return find.begin()->second;
}

ResultIndex LRU(){
    preallocate();
    time_t start, end;
    double cost=0;
    inside_page.missing_num = 0;
    int &current = outside_page.current;
    for(;current<outside_page.visit_list.size();current++){
        int is_inside_result = is_inside();
        int flag = 0;
        if(is_inside_result==-1){
            start = clock();

            int find_result = find_last_resent_unused();
            inside_page.page[find_result] = outside_page.visit_list[current];
            inside_page.page[find_result].times = 1;
            inside_page.page[find_result].location_when_in = current;
            inside_page.missing_num++;
            end = clock();
            cost += (double)end-start;
        }
        else{
            inside_page.page[is_inside_result].times ++;
            inside_page.page[is_inside_result].location_when_in = current;
//            visit it, change the location last use
            flag = 1;
        }
        if(flag) show_gotit();
        else show_miss();
    }
    double missing_rate = (double)inside_page.missing_num/outside_page.visit_list.size();
    cost = cost / CLOCKS_PER_SEC;
    cout << "LRU missing rate is " << missing_rate;
    cout << "\tsearch time cost is  " << cost;
    cout << "\n" << endl;
    ResultIndex resultIndex;
    resultIndex.cost_time = cost;
    resultIndex.miss_rate = missing_rate;
    return resultIndex;
}
int find_not_access(){
    int size = inside_page.allocated_size;

    for(int i=0;i<size;++i){
        if(inside_page.page[i].location_when_in==1) inside_page.page[i].location_when_in = 0;
        else return i;
    }
    for(int i=0;i<size;++i){
        if(inside_page.page[i].location_when_in==0) return i;
    }
}

ResultIndex CLOCK(){
    preallocate();
    for(auto& item:inside_page.page){
        item.location_when_in = 1;
    }
// to patch func preallocate
    time_t start, end;
    double cost=0;
    inside_page.missing_num = 0;
    int &current = outside_page.current;
    for(;current<outside_page.visit_list.size();current++){
        int is_inside_result = is_inside();
        int flag = 0;
        if(is_inside_result==-1){
            start = clock();

            int find_result = find_not_access();
            inside_page.page[find_result] = outside_page.visit_list[current];
            inside_page.page[find_result].times = 1;
            inside_page.page[find_result].location_when_in = 1;
            inside_page.missing_num++;
            end = clock();
            cost += (double)end-start;
        }
        else{
            inside_page.page[is_inside_result].times ++;
            inside_page.page[is_inside_result].location_when_in = 1;
//            visit it, change the access/ location when in = 1
            flag = 1;
        }
        if(flag) show_gotit();
        else show_miss();
    }
    double missing_rate = (double)inside_page.missing_num/outside_page.visit_list.size();
    cost = cost / CLOCKS_PER_SEC;
    cout << "CLOCK missing rate is " << missing_rate;
    cout << "\tsearch time cost is  " << cost;
    cout << "\n" << endl;
    ResultIndex resultIndex;
    resultIndex.cost_time = cost;
    resultIndex.miss_rate = missing_rate;
    return resultIndex;
}

int find_clock_pro(){
    int size = inside_page.allocated_size;

    for(int i=0;i<size;++i){
        Page & tem_page = inside_page.page[i];
        if(tem_page.location_when_in==0 && tem_page.mode==0) return i;
    }
    for(int i=0;i<size;++i){
        Page & tem_page = inside_page.page[i];
        if(tem_page.location_when_in==0 && tem_page.mode==1) return i;
        else tem_page.location_when_in=0;
    }
    for(int i=0;i<size;++i){
        Page &tem_page = inside_page.page[i];
        if(tem_page.location_when_in==0 && tem_page.mode==0) return i;
    }
    for(int i=0;i<size;++i){
        Page &tem_page = inside_page.page[i];
        if(tem_page.location_when_in==0 && tem_page.mode==1) return i;
    }
}

ResultIndex CLOCK_PRO(){
    preallocate();
    for(auto& item:inside_page.page){
        item.location_when_in = 1;
    }
// to patch func preallocate
    time_t start, end;
    double cost=0;
    inside_page.missing_num = 0;
    int &current = outside_page.current;
    for(;current<outside_page.visit_list.size();current++){
        int is_inside_result = is_inside();
        int flag = 0;
        if(is_inside_result==-1){
            start = clock();

            int find_result = find_clock_pro();
            inside_page.page[find_result] = outside_page.visit_list[current];
            inside_page.page[find_result].times = 1;
            inside_page.page[find_result].location_when_in = 1;
            inside_page.missing_num++;
            end = clock();
            cost += (double)end-start;
        }
        else{
            inside_page.page[is_inside_result].times ++;
            inside_page.page[is_inside_result].location_when_in = 1;
            inside_page.page[is_inside_result].mode = outside_page.visit_list[current].mode;
//            visit mode may change
//            visit it, change the access/ location when in = 1
            flag = 1;
        }
        if(flag) show_gotit();
        else show_miss();
    }
    double missing_rate = (double)inside_page.missing_num/outside_page.visit_list.size();
    cost = cost / CLOCKS_PER_SEC;
    cout << "CLOCK_PRO missing rate is " << missing_rate;
    cout << "\tsearch time cost is  " << cost;
    cout << "\n" << endl;
    ResultIndex resultIndex;
    resultIndex.cost_time = cost;
    resultIndex.miss_rate = missing_rate;
    return resultIndex;
}
int main() {
    string path_config = "../test.txt";
    map<string,ResultIndex> resultIndex;
    init(path_config);

    resultIndex["OPT"] = OPT();
    resultIndex["FIFO"] = FIFO();
    resultIndex["LRU"] = LRU();
    resultIndex["CLOCK"] = CLOCK();
    resultIndex["CLOCK_PRO"] = CLOCK_PRO();
    cout << "algorithm\t" << "missing_rate\t" << "time_cost\t" << "\n";
    for(auto &item:resultIndex){
        cout << item.first << '\t';
        if(item.first != "CLOCK_PRO") cout << '\t';
        cout << item.second.miss_rate << "\t\t" << item.second.cost_time << "\n";
    }
}
