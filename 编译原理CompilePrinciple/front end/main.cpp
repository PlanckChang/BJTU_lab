#include<iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;
#define ORMAXFORGRAMMAR 10
// assume every reasoning the or is max 10

map<string, set<string> > first;
map<string, set<string> > follow;
map<string, string> Vn;
map<string, string> Vt;
map<string, int> flag_e;
map<string, vector<string>[ORMAXFORGRAMMAR]> grammar;
map<pair<string,vector<string>>, set<string>> first_alpha;

string start_notion;
class expression{
public:
    string left;
    vector<string> right;
    int point;

    expression(string left_, vector<string> right_, int point_) {
        left = left_;
        right = right_;
        point = point_;
    };
    bool operator < (const expression &tem) const{
        if(left != tem.left) return left < tem.left;
        else if(right != tem.right) return right < tem.right;
        else return point < tem.point;
    }

    string get_pointing() const {
//        return the next element of the right of point
        if(point+1 > right.size()) return "end";
        else return right[point];
    }

    expression reason(){
        expression tem = *this;
        if(point<right.size()){
            tem.point++;
        }
        else tem.point=-1;
        return tem;
    }

    int isend(){
        if(point >= right.size()) return 1;
        else return 0;
    }

    bool operator !=(const expression & new_express) const{
        if(left != new_express.left || point!= new_express.point || right!=new_express.right){
            return true;
        }
        else return false;
    }
};


bool judge_Vn(string &a){
    if(Vn[a] == a)
        return true;
    else return false;
}

struct state_DFA{
//    end 1 for have reasoned, so skip it
    int id;
    set<expression> compont;
    map<string, int> next;
    string from;
    int end=0;

//from for the input when reasoning
    state_DFA(int choice, string left = "NULL"){
//        choice is for different construction method
//        0 for Vn closure,
//        1 for reasoning and simple
        if(choice ==0){
            for(auto&item:grammar[left]){
                if(item.empty()) break;
                expression tem(left, item, 0);
                compont.insert(tem);
            }
            int flag=1;
            while(flag){
                int length = compont.size();
                for(auto item:compont){
                    string tem_point = item.get_pointing();
                    if(judge_Vn(tem_point)){
                        for(auto item1:grammar[tem_point]){
                            if(item1.empty()) break;
                            expression tem_express(tem_point, item1, 0);
                            compont.insert(tem_express);
                        }
                    }
                }
                if(length == compont.size()) flag=0;
            }
        }
        else if(choice==1){
            from = left;
        }
        else if(choice == 2){
//            do nothing

        }
    }



    bool operator < (const state_DFA &tem) const{
        if(compont.size() != tem.compont.size()){
            return compont.size()<tem.compont.size();
        }
        else{
            for(auto tem1 = compont.begin(), tem2 = tem.compont.begin(); tem1!=compont.end(); ++tem1, ++tem2){
                return *tem1 < *tem2;
            }
        }
    }

    int get_next(){
        for(auto &item:compont){
            string point_now = item.get_pointing();
            if(point_now=="end") continue;
            else{
                expression tem_express(item);
                tem_express.point++;
            }

        }
    }

    bool operator == (const state_DFA & new_state) const{
        if(compont.size() != new_state.compont.size()) return false;
        else {
            for(auto i=compont.begin(), j = new_state.compont.begin(); i!=compont.end(); i++, j++){
                if(*i != *j){
                    return false;
                }
            }
            return true;
        }
    }


};
vector<state_DFA> DFA_set;

int create_DFA(){
    string start_tem = start_notion;
    state_DFA start_DFA(0, start_tem);
    start_DFA.id = 0;

    DFA_set.emplace_back(start_DFA);

    while(true){
        int length = DFA_set.size();

        for(int index_now_state =0; index_now_state < DFA_set.size(); ++index_now_state){
            if(DFA_set[index_now_state].end == 1) continue;
//            end ==1 means this state reasoning end, so skip it
            vector<state_DFA> tem_state;
            for(auto express_source:DFA_set[index_now_state].compont){
//                for-loop each express in DFA_set's per state
                if(express_source.isend()) continue;
//  the express is ended, but not equals state ends. state could have lots of express
                else{
                    string input = express_source.get_pointing();
                    expression tem_express = express_source.reason();
//                    int flag_tem = 1;
                    int i;
                    for(i=0;i<tem_state.size();++i){
                        if(tem_state[i].from !=input){
                            continue;
                        }
                        else{
//                            flag_tem=0;
                            break;
                        }
                    }
                    if(i==tem_state.size()){
//                     that this condition satisfied means reasoning to a brandy new state
                        state_DFA state_next(2);
//  todo
//  may be could set as a class method, but not a outside func
                        state_next.compont.insert(tem_express);
                        state_next.from = input;
                        input = tem_express.get_pointing();
//  judge element pointed whether Vn or not, if so, then closure is necessary.
                        if(judge_Vn(input)){
                            state_DFA closure(0, input);
                            for(auto& item:closure.compont){
                                state_next.compont.insert(item);
                            }
                        }
                        tem_state.emplace_back(state_next);
                    }
                    else{
                        state_DFA & state_next = tem_state[i];
// this condition satisfied means reasoning from the same element to the same state
                        state_next.compont.insert(tem_express);
                        input = tem_express.get_pointing();
                        if(judge_Vn(input)){
                            state_DFA closure(0, input);
                            for(auto& item:closure.compont){
                                state_next.compont.insert(item);
                            }
                        }
                    }
                }
            }
//            reasoning end, add state_new to DFA_set
            DFA_set[index_now_state].end = 1;
//            add new state to DFA set
            for(auto &state_new:tem_state){
//              look up all DFA_set, ensure it is a new state
                int j;
                for(j=0;j<DFA_set.size();++j){
                    if(DFA_set[j] == state_new) break;
//                    if true, means state has existed, need not add
                }
                if(j==DFA_set.size()){
//                    it is a new state
//              size of DFA_set is the index & id of new state
                    state_new.id = DFA_set.size();
                    string tem_from = state_new.from;
                    DFA_set[index_now_state].next[tem_from] = DFA_set.size();
//                   the form for next struct add elements like
//                  next[era string input reasoning] = int next state's id
//                  like this, so complex form, so why not set as a func or class method
//                    todo
//  when DFA_set add a new state, then DFA_set change address. may be we use index to access DFA is better, but not use for(auto item:...)
                    DFA_set.emplace_back(state_new);
                }
                else{
//                    has a same state
                    string tem_from = state_new.from;
                    DFA_set[index_now_state].next[tem_from] = j;
                }
            }
        }
        if (DFA_set.size()==length) break;
    }
}

struct table{
//    0 for move inside, 1 for jump goto, 2 for acc, 3 for guiyue
    int next;
    int op;
    string left;
    vector<string> right;
};

map<int, map<string, table>> analysis_table;


int analysis_table_show(){
    cout << "\n";
    cout << "analysis_table is following\n";
    cout << " 0 for move inside, 1 for jump goto, 2 for acc, 3 for guiyue\n";
    cout << "state_id\t" << "input\t" << "op\t" << "\n";
    for(auto &item:analysis_table){
        cout << item.first << "\n";
        for(auto &item1:item.second){
            //    0 for move inside, 1 for jump goto, 2 for acc
            cout << "\t" << item1.first << "\t" << item1.second.op << "\t";
//            output additional information
            if(item1.second.op == 3){
                cout << "\t" << item1.second.left << " -> ";
                for(auto item2:item1.second.right) cout << item2 << " ";
                cout << "\n";
            }
            else if(item1.second.op == 1 || item1.second.op == 0){
                cout << "\t" << item1.second.next << '\n';
            }
            else if (item1.second.op == 2) cout << "\tacc\n";
        }
    }
    cout << "\n";
}

int create_analysis_table(){
    //    0 for move inside, 1 for jump goto, 2 for acc, 3 for guiyue
    for(auto& state: DFA_set){
         for(auto express:state.next){
             table tem_table;
             string input = express.first;
             int next_state = express.second;
             tem_table.next = next_state;
             if(judge_Vn(input)){
//                 if input is Vn, then need not move inside, just go to
                 tem_table.op = 1;
             }
             else tem_table.op = 0;

             analysis_table[state.id][input] = tem_table;
         }
         for(auto express:state.compont){
             if(express.left == "S" && express.isend()){
                 table tem_table;
                 tem_table.op = 2;
                 tem_table.left = express.left;
                 tem_table.right = express.right;
                 analysis_table[state.id]["#"] = tem_table;
             }
             else if(express.isend()) {
                 for (auto &follow: follow[express.left]) {
                     table tem_table;
                     tem_table.left = express.left;
                     tem_table.right = express.right;
                     tem_table.op = 3;
                     analysis_table[state.id][follow] = tem_table;
                 }
             }
         }
    }
}



struct Keyword{
    string notation;
    int class_num;
    int line;
    Keyword(string str, int num, int line_){
        notation = str;
        class_num = num;
        line = line_;
    }
    Keyword(char* str, int num, int line_){
        notation = string(str);
        class_num = num;
        line = line_;
    }
    Keyword(char str, int num, int line_){
        notation = string(1, str);
        class_num = num;
        line = line_;
    }
};


Keyword plus_keyword("+", 0, 0);
Keyword subtract_keyword("-", 0, 0);
Keyword multiply_keyword("*", 0, 0);
Keyword division_keyword("/", 0, 0);
Keyword pound_key_keyword("#", 0, 0);
Keyword left_bracket_keyword("(", 0, 0);
Keyword right_bracket_keyword(")", 0, 0);
Keyword equal_keyword("=", 0, 0);
//source is numeric & identifier and
Keyword numeric_var("n", 1, 0);
Keyword identifier_num("i", 0, 0);

int error_count = 0;
vector<Keyword> class_num_combine;
set<string> set_union_my(set<string> &a, set<string> &b){
    for(auto item:b){
        a.insert(item);
    }
    return a;
}

string class_num2string(int class_num){
    for(auto item:class_num_combine){
        if(item.class_num==class_num){
            return item.notation;
        }
    }
}



bool judge_Vt(string &b){
    if(Vt[b] == b){
        return true;
    }
    else return false;
}

int append_first_alpha(string header, vector<string> reason_out, set<string> first_set){
    pair<string,vector<string>> expression(header, reason_out);
    if(first_alpha[expression].empty()){
//        pair<pair<string,vector<string>>, set<string>> tem(expression, first_set);
        first_alpha[expression] = first_set;
    }
    else
        set_union_my(first_alpha[expression],  first_set);
}

int create_Vn_Vt_grammar(string &grammar_path){
    ifstream fin;

    string tem_string;
    fin.open(grammar_path);
    if(!fin){
        cerr << grammar_path << " open error\n";
        return -1;
    }

    fin >> tem_string;
//    create Vn Vt set
    if(tem_string=="Vn"){
        while(fin.get()==' '){
            fin >> tem_string;
            Vn[tem_string] = tem_string;
        }
    }

    fin >> tem_string;
    if(tem_string=="Vt"){
        while(fin.get()==' '){
            fin >> tem_string;
            Vt[tem_string] = tem_string;
//          x belong to Vt, the first(x) = x
            first[tem_string].insert(tem_string);
        }
    }

// Vt Vn set constructed finish

    while(fin >> tem_string){
        if(tem_string == "end") break;
        else if(tem_string == "start"){
            fin >> start_notion;
            continue;
        }

        string key = tem_string;

        fin >> tem_string;
        int count = 0;
//        to record the count of or

//        to skip ->
        flag_e[key] = 0;
        if(tem_string=="->")
            fin >> tem_string;
//            use Vt[string] == string to judge whether it belongs to Vt set


        if(Vt[tem_string] == tem_string){
            first[key].insert(tem_string);
        }
        grammar[key][count].emplace_back(tem_string);
        if(tem_string=="e") flag_e[key] = 1;
        while(fin.get()==' '){
            fin >> tem_string;
            if(tem_string == "|"){
                count++; // todo don't pre-set the max size of vector, but counter | , append a vector, or vector<vector>
                fin >> tem_string;
                if(Vt[tem_string] == tem_string){
                    first[key].insert(tem_string);
                }
            }
            if(tem_string =="e"){
                flag_e[key] = 1;
            }
            else {
                grammar[key][count].emplace_back(tem_string);
            }
        }
    }
    fin.close();
}

int create_first(string &grammar_path){

//    first of A

//    o for not change, 1 change
    first["S"].insert("#");
    while(true){

        int flag = 0;
        for(auto i:grammar){
            for(auto & m : i.second){
                for(const auto& j:m){
                    if(Vn[j] == j) {

                        int ifirst_size = first[i.first].size();
                        first[i.first] = set_union_my(first[i.first], first[j]);
                        if(first[i.first].size()>ifirst_size){
                            flag = 1;
                        }
                    }
                    if(flag_e[j]==1 && m.back() == j){
                        flag = 1;
                        flag_e[i.first] =1;
                    }
                    if(flag_e[j]==0){
                        break;
                    }
                }
            }
        }
//        map<string, set<string> > first;
//        map<string, vector<string>[ORMAXFORGRAMMAR] > grammar;
//        flag == 0, all the first not change, which is biggest, stop
        if(flag==0){
            break;
        }
    }

//    first of A set constructed successfully.
// first of alpha begin

    for(auto i:grammar){
        for(auto m:i.second){

            if(m.empty()) continue;
            for(auto j:m){
                append_first_alpha(i.first, m, first[j]);
                if(flag_e[j]==0) break;
            }
        }
    }
//    alpha reason out e, which equals to A -> alpha -> e, so this is oped when create
//    first of A

}

int create_follow() {
    // follow set start
    follow["S"].insert("#");
    while (true) {

        int flag = 0;
        for (auto i: grammar) {
//            int flag_firstVn = 0;
            for (auto m: i.second) {
//                std::reverse(m.begin(), m.end());
                if (m.size() == 0) continue;
//                *j1 is a string
//              rule 1
                for (auto j1 = m.begin(); j1 < m.end(); ++j1) {
                    if (judge_Vt(*j1)) continue;
                    auto j2 = j1;
                    do {
                        if (++j2 == m.end()) {
//                            flag_e[*j1] =1;
                            int j1follow_size = follow[*j1].size();
                            follow[*j1].insert("#");
                            if (follow[*j1].size() > j1follow_size) {
                                flag = 1;
                            }
                            break;
                        };
                        int j1follow_size = follow[*j1].size();

                        follow[*j1] = set_union_my(first[*j2], follow[*j1]);
//                        if()
//                        follow[*j1] = set_union_my(follow[i.first], follow[*j1]);
                        if (follow[*j1].size() > j1follow_size) {
                            flag = 1;
                        }
                    } while (flag_e[*j2] == 1);
                }
            }
        }
        if (flag == 0) break;
    }
//                rule2 for follow
    while (true) {
        int flag = 0;
        for (auto i: grammar) {
//            int flag_firstVn = 0;
            for (auto m: i.second) {
//                std::reverse(m.begin(), m.end());
                if (m.size() == 0) continue;
//                *j1 is a string
                for (auto j1 = m.rbegin(); j1 < m.rend(); ++j1) {
                    if (judge_Vt(*j1)) break;
                    int j1follow_size = follow[*j1].size();
                    follow[*j1] = set_union_my(follow[*j1], follow[i.first]);
                    if (follow[*j1].size() > j1follow_size) flag = 1;
                    if (flag_e[*j1] == 0) break;
                }
            }
        }
        if (flag == 0) break;
    }
}

int class_num_init(string &base_out){
    ifstream fin;
    string tem_string;
//    base_source class num init
    fin.open(base_out);
    if(!fin){
        cerr << "config file open error\n";
        return 1;
    }
    int tem_int;

    while(fin >> tem_string){
        if(tem_string == "+"){
            fin >> tem_int;
            plus_keyword.class_num = tem_int;
        }
        else if(tem_string == "-"){
            fin >> tem_int;
            subtract_keyword.class_num = tem_int;
        }
        else if(tem_string == "*"){
            fin >> tem_int;
            multiply_keyword.class_num = tem_int;
        }
        else if(tem_string == "/"){
            fin >> tem_int;
            division_keyword.class_num = tem_int;
        }
        else if(tem_string == "#"){
            fin >> tem_int;
            pound_key_keyword.class_num = tem_int;
        }
        else if(tem_string == "("){
            fin >> tem_int;
            left_bracket_keyword.class_num = tem_int;
        }
        else if(tem_string == ")"){
            fin >> tem_int;
            right_bracket_keyword.class_num = tem_int;
        }
        else if(tem_string == "="){
            fin >> tem_int;
            equal_keyword.class_num = tem_int;
        }
    }
    fin.close();
    return 0;
}

struct ConfigResult{
    string need_handle;
    string output_four;
    int mode;
};


ConfigResult config_init(string &config_path){
    ifstream fin;
    fin.open(config_path);
    if(!fin){
        cerr << "config file open error\n";
        return {};
    }
    string tem_string;
    string base_source;
    string base_out;
    string input_file;
    string output_file;
    ConfigResult result;

    while(fin >> tem_string){
        if(tem_string == "base_source"){
            fin >> tem_string;
            base_source = tem_string;
        }
        else if(tem_string == "base_out"){
            fin >> tem_string;
            base_out = tem_string;
        }
        else if(tem_string == "input_file"){
            fin >> tem_string;
            input_file = tem_string;
        }
        else if(tem_string == "output_file"){
            fin >> tem_string;
            result.need_handle = tem_string;
            output_file = tem_string;
        }
        else if(tem_string == "output_four"){
            fin >> tem_string;
            result.output_four = tem_string;
        }
        else if(tem_string == "four_output_mode"){
            fin >> result.mode;
        }
        else if(tem_string == "end")
            break;
    }

    string command = "Lexical_Analyzer.exe "+base_source + "  " + base_out;
    system(command.c_str());
    command = "Lexical_Analyzer.exe "+input_file + "  " + output_file;
    system(command.c_str());

    fin.close();
//  base out is the standard class num for func class_num_init()
    class_num_init(base_out);
//    return output_file from lexical analyzer is the file need to grammar analyzer.
//      output_file is for alu_anlysis
    return result;
}



int correct_op(int &line, ifstream & fin, stack<string> & stack_notation, stack<int>&stack_state, int &tem_class){
    cout << "line " << line << " syntax correct\n";
    string tem_string;
    int tem_line;
    while(tem_class!=pound_key_keyword.class_num){
        fin >> tem_string >> tem_class >> tem_line;
    }
    while(stack_notation.top()!="#"){
        stack_notation.pop();
    }
    while(stack_state.top()!=0){
        stack_state.pop();
    }
    return 0;
}
int error_prom(int &tem_line){
    cout << "line " << tem_line << " has " << " syntax error\n";
    return 0;
};

int error_op(int tem_line, ifstream & fin, stack<string> & stack_notation, stack<int>&stack_state, int &tem_class){
//    error_count++;
//    ifstream fin;
    string tem_string;
    error_prom(tem_line);
    while(tem_class!=pound_key_keyword.class_num){
        fin >> tem_string >> tem_class >> tem_line;
    }
    while(stack_notation.top()!="#"){
        stack_notation.pop();
    }
    while(stack_state.top()!=0){
        stack_state.pop();
    }
//    error_count=0;
}


int combine_keyword(){
    class_num_combine.emplace_back(plus_keyword);
    class_num_combine.emplace_back(subtract_keyword);
    class_num_combine.emplace_back(multiply_keyword);
    class_num_combine.emplace_back(division_keyword);
    class_num_combine.emplace_back(pound_key_keyword);
    class_num_combine.emplace_back(left_bracket_keyword);
    class_num_combine.emplace_back(right_bracket_keyword);
    class_num_combine.emplace_back(equal_keyword);
    class_num_combine.emplace_back(numeric_var);
    class_num_combine.emplace_back(identifier_num);
}

bool judge_exist_analysis(int &state,string& input){
    if(analysis_table.count(state)==0){
        return false;
    }
    else if(analysis_table[state].count(input)==0){
        return false;
    }
    else return true;
}

int output_four_element_formula(string &file_output, vector<string> &four_element, int &tem_line){
    ofstream fout;
    fout.open(file_output, ios::app);
    if(!fout){
        cout << file_output << " file open error\n";
        return -1;
    }

    fout << "line " << tem_line << "\n";
    for(auto &item:four_element)
        fout << item << " ";
    fout << "\n\n";

    fout << "op\t" << "left\t" << "right\t" << "result\n";

    int order = 0;
    stack<string> output_four;
//                    four element is input reverse Polish form
    for(auto &item:four_element){
        if(item=="+" || item=="-" || item=="*" || item=="/" || item=="="){
            string right = output_four.top();
            output_four.pop();
            string left = output_four.top();
            output_four.pop();
            fout << item << "\t" << left << "\t\t" << right << "\t\t" << "T" << order << "\n";
            string tem = "T" + to_string(order++);
            output_four.push(tem);
        }
        else output_four.push(item);
    }
    fout << "\n\n";
    fout.close();
}


int analyzer_stack(string file_path="../alu_result1.txt", int mode=0, string file_output=".//four_element_formula.txt"){
//  mode 0 default no generate four element formula, mode 1 to generate
    ifstream fin;
    fin.open(file_path);
    if(!fin){
        cout << file_path << " file open error\n";
        return -1;
    }
    stack<int> stack_state;
    stack<string> stack_notation;
    vector<string> four_element;

    string tem_string;
    int tem_line, tem_class;
    string tem_input;
    fin >> tem_string >> tem_string >> tem_string;
    stack_state.push(0);
    stack_notation.push("#");
    table tem_table;

    while(fin >> tem_string >> tem_class >> tem_line){
        tem_input = class_num2string(tem_class);
//        break for read next input, continues not.
        while(1){
            int state_now = stack_state.top();

            if(judge_exist_analysis(state_now, tem_input)){
                tem_table = analysis_table[state_now][tem_input];
            }
            else{
                error_op(tem_line, fin, stack_notation, stack_state, tem_class);
                four_element.clear();
                break;
            }

            if(mode){
                for(int i =0;i<tem_table.right.size(); ++i){
                    if(tem_table.right[i] == "+") four_element.emplace_back("+");
                    else if(tem_table.right[i] == "-") four_element.emplace_back("-");
                    else if(tem_table.right[i] == "*") four_element.emplace_back("*");
                    else if(tem_table.right[i] == "/") four_element.emplace_back("/");
                    else if(tem_table.right[i] == "=") four_element.emplace_back("=");
                }
                if(tem_class == identifier_num.class_num || tem_class == numeric_var.class_num)
                    four_element.push_back(tem_string);
            }


            //    0 for move inside, 1 for jump goto, 2 for acc, 3 for guiyue
            if(tem_table.op==0){
                stack_notation.push(tem_input);
                stack_state.push(tem_table.next);
                break;
            }
            else if(tem_table.op==3){
//            op ==3 means could be reasoning with A-> X1 X2...
//  but table struct has the right side, it is not necessary,
//  could be optimized to only a left side, in other word just A and
//  the size of right part
                for(int i=0;i<tem_table.right.size();++i){
                    stack_notation.pop();
                    stack_state.pop();
                }

                state_now = stack_state.top();
                stack_notation.push(tem_table.left);

                if(judge_exist_analysis(state_now, tem_table.left)){
                    tem_table = analysis_table[state_now][tem_table.left];
                }
                else{
                    error_op(tem_line, fin, stack_notation, stack_state, tem_class);
                    four_element.clear();
                    break;
                }

//            the tem_table.left is Vn, op actually 1, could add  a judge
                stack_state.push(tem_table.next);
                continue;
            }
            else if(tem_table.op ==2){
                correct_op(tem_line, fin, stack_notation, stack_state, tem_class);

                if(mode)
                    output_four_element_formula(file_output, four_element, tem_line);

                four_element.clear();
                break;
            }
            else{
                error_op(tem_line, fin, stack_notation, stack_state, tem_class);
                four_element.clear();
                break;
            }
        }
    }
}


int DFA_state_show(){
    for(auto &item:DFA_set){
        cout << "id\t" << item.id << '\n';
        for(auto &item1:item.compont){
            cout << item1.left << " -> ";
            for(auto &item2:item1.right){
                if(item1.get_pointing() == item2){
                    cout << " . " << item2;
                }
//                else if (item1.get_pointing() == "end"){
//                    cout << " . ";
//                }
//                else if(item1.get_pointing()=="end") cout << ""
                else cout<< " " << item2 << " ";
            }
            if (item1.get_pointing() == "end"){
                    cout << " . ";
            }
            cout << '\n';
        }
        cout << "\n";
        cout << "next\n";
        for(auto item3:item.next){
            cout << item3.first << "\t" << item3.second << '\n';
        }
        cout << '\n';

    }

}


int main(){


    string grammar_path = "../grammar.txt";
    create_Vn_Vt_grammar(grammar_path);
    create_first(grammar_path);
    create_follow();
    create_DFA();
    DFA_state_show();
    create_analysis_table();
    analysis_table_show();

    string config_path = "../config.txt";
    string need_to_anlysis_manully = ""; //"../alu_result1.txt";
    string class_init_path = "../alu_class_base_result.txt";
    ConfigResult config_result;

    if (!need_to_anlysis_manully.empty()) {
        class_num_init(class_init_path);
        combine_keyword();
        analyzer_stack();
    }
    else{
        config_result = config_init(config_path);
        combine_keyword();
        analyzer_stack(config_result.need_handle,  config_result.mode , config_result.output_four);
    }

    return 0;
}

