//
// Created by Planck Chang on 2022/11/20.
//

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

// use 0 for <, 1 for =, 2 for > in analyzer_table. and the relationship with # is not in analyzer_table, but use the judge_func

map<string, map<string, int>> analyzer_table;

map<string, set<string> > firstVt;
map<string, set<string> > lastVt;
map<string, string> Vn;
map<string, string> Vt;
map<string, int> flag_e;
map<string, vector<string>[ORMAXFORGRAMMAR] > grammar;
map<pair<string,vector<string>>, set<string>> first_alpha;

vector<string> leftest_increase;
stack <string> analysis_stack;
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

vector<Keyword> class_num_combine;



int error_grammar_prom(){
    cout << "grammar is not legal. This not Arithmetic Prior Grammar\n";
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
//            first[tem_string].insert(tem_string);
        }
    }

// Vt Vn set constructed finish

    while(fin >> tem_string){
        if(tem_string == "end") break;

        string key = tem_string;

        fin >> tem_string;
        int count = 0;
//        to record the count of or

//        to skip ->
        flag_e[key] = 0;
        if(tem_string=="->")
            fin >> tem_string;
//            use Vt[string] == string to judge whether it belongs to Vt set


//        if(Vt[tem_string] == tem_string){
//            first[key].insert(tem_string);
//        }
        grammar[key][count].emplace_back(tem_string);
        if(tem_string=="e") flag_e[key] = 1;
        while(fin.get()==' '){
            fin >> tem_string;
            if(tem_string == "|"){
                count++; // todo don't pre-set the max size of vector, but counter | , append a vector, or vector<vector>
                fin >> tem_string;
//                if(Vt[tem_string] == tem_string){
//                    first[key].insert(tem_string);
//                }
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

bool judge_Vn(string &a){
    if(Vn[a] == a)
        return true;
    else return false;
}


set<string> set_union_my(set<string> &a, set<string> &b){
    for(auto item:b){
        a.insert(item);
    }
    return a;
}

bool judge_Vt(string &b){
    if(Vt[b] == b){
        return true;
    }
    else return false;
}

int create_firstVt(){
    while(true){
        int flag = 0;
        for (auto i:grammar){
            for(auto &m: i.second){
                if(m.empty()) break;
                int ifirst_size = firstVt[i.first].size();
                if(judge_Vt(m[0])){
                    firstVt[i.first].insert(m[0]);
                }
                else if (m.size()>=2 && judge_Vt(m[1]) && judge_Vn(m[0])){

                    firstVt[i.first].insert(m[1]);
                }
                else if(m.size()==1 && judge_Vn(m[0])){
                    firstVt[i.first] = set_union_my(firstVt[i.first], firstVt[m[0]]);
                }
                if(firstVt[i.first].size()> ifirst_size){
                    flag = 1;
                }
            }
        }
        if(!flag) break;
    }
}

int create_lastVt(){
    while(true){
        int flag = 0;
        for (auto i:grammar){
            for(auto m: i.second){
                if(m.empty()) break;
                int ilast_size = lastVt[i.first].size();
                std::reverse(m.begin(), m.end());
                if(judge_Vt(m[0])){
                    lastVt[i.first].insert(m[0]);
                }
                else if (m.size()>=2 && judge_Vt(m[1]) && judge_Vn(m[0])){
                    lastVt[i.first].insert(m[1]);
                }
                else if(m.size()==1 && judge_Vn(m[0])){
                    lastVt[i.first] = set_union_my(lastVt[i.first], lastVt[m[0]]);
                }
                if(lastVt[i.first].size()>ilast_size){
                    flag = 1;
                }
            }
        }
        if(!flag) break;
    }
}

int create_analyzer_table(){

//    have something error, blank is error
    // use 0 for <, 1 for =, 2 for > in analyzer_table
    for(auto i: grammar){
        for(auto m:i.second){
            for(int j=0, k=1; k<m.size(); ++j, ++k){
                string &tem1 = m[j];
                string &tem2 = m[k];
                if(judge_Vt(tem1) && judge_Vt(tem2)){
                    analyzer_table[tem1][tem2] = 1;
                }
                else if(judge_Vt(tem1) && judge_Vn(tem2)){
                    for(auto tem3:firstVt[tem2]){
                        analyzer_table[tem1][tem3] = 0;
                    }
                    if(k+1 < m.size() && judge_Vt(m[k+1])){
                        analyzer_table[tem1][m[k+1]] = 1;
                    }
                }
                else if(judge_Vn(tem1) && judge_Vt(tem2)){
                    for(auto tem3:lastVt[tem1]){
                        analyzer_table[tem3][tem2] = 2;
                    }
                }
                else{
                   error_grammar_prom();
                }
            }
        }
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

string config_init(string &config_path){
    ifstream fin;
    fin.open(config_path);
    if(!fin){
        cerr << "config file open error\n";
        return "1";
    }
    string tem_string;
    string base_source;
    string base_out;
    string input_file;
    string output_file;

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
            output_file = tem_string;
        }
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
    return output_file;
}

string class_num2string(int class_num){
    for(auto item:class_num_combine){
        if(item.class_num==class_num){
            return item.notation;
        }
    }
}

int correct_prom(int &line){
    cout << "line " << line << " syntax correct\n";
    return 0;
}
int error_prom(int &tem_line){
    cout << "line " << tem_line << " has " << " syntax error\n";
    return 0;
};

int error_op(int tem_line, ifstream & fin, stack<string> & stack_, int &tem_class){
//    error_count++;
//    ifstream fin;
    string tem_string;
    error_prom(tem_line);
    while(tem_class!=pound_key_keyword.class_num){
        fin >> tem_string >> tem_class >> tem_line;
    }
    while(stack_.top()!="#"){
        stack_.pop();
    }
//    error_count=0;
}

int judge_relation(string &left, string &right){
//    if(left == "#"){
//        return 0;
//    }
//    else if(right =="#")
//        return 2;
//    not exist relationship between left and right, error

    if(analyzer_table.count(left)==0 || analyzer_table[left].count(right)==0){
        return -1;
    }
    return analyzer_table[left][right];
}
string judge_leftest_increase(){
    std::reverse(leftest_increase.begin(), leftest_increase.end());
    string tem;
    int j;
    for(auto i:grammar){
        for(auto m: i.second){
            if(m.empty()) break;
            if(m.size() != leftest_increase.size()) continue;
            for(j = 0;j<m.size();++j){
                if(leftest_increase[j] == "N" && judge_Vn(m[j])) continue;
                if(leftest_increase[j] == m[j]) continue;
                break;
            }
            if(j == m.size()){
                tem = i.first;
                break;
            }
        }
        if(!tem.empty()) break;
    }
    if(tem.empty())
        tem = "error";
    leftest_increase = vector<string>(0);
    return tem;
}

int stack_out(){
    string tem = analysis_stack.top();
    analysis_stack.pop();
    leftest_increase.emplace_back(tem);
}
int analyzer_stack(string &file_needed_analysis){
    ifstream fin;
    fin.open(file_needed_analysis);
    if(!fin){
        cerr << file_needed_analysis << " file open error" << endl;
        return -1;
    }
    analysis_stack.push("#");

    string tem_string;
    int tem_line, tem_class;
    string tem_input;
    string Q;
    string tem_right;
    fin >> tem_string >> tem_string >> tem_string;
//    first line is the title. drop them
    int flag_jump_from = 0;
    string tem_top;
    int relationship;
    while(1){
        do {
            if(flag_jump_from == 0){
                if(!(fin >> tem_string >> tem_class >> tem_line)) return 0;
                tem_input = class_num2string(tem_class);
                if(!judge_Vt(analysis_stack.top())) {
                    stack_out();
                    if(!judge_Vt(analysis_stack.top())){
                        error_op(tem_line, fin, analysis_stack, tem_class);
                        continue;
                    }
                }
                tem_top = analysis_stack.top();
            }

            relationship = judge_relation(tem_top, tem_input);
            if(relationship == 2) break;
            else if(relationship == -1){
                error_op(tem_line, fin, analysis_stack, tem_class);
                flag_jump_from = 0;
                continue;
            }
            else{
                analysis_stack.push(tem_input);
                flag_jump_from = 0;
            }
        }while(1);

        do{
//            todo tem_top change, after error op should input
            if(tem_top != analysis_stack.top() && analysis_stack.top() == "N"){
                stack_out();
            }
//            todo
            tem_right = analysis_stack.top();
            stack_out();
            if(!judge_Vt(analysis_stack.top())) {
                stack_out();
                if(!judge_Vt(analysis_stack.top())){
                    error_op(tem_line, fin, analysis_stack, tem_class);
                    break;
                }
            }
            int relation = judge_relation(analysis_stack.top(), tem_right);
            if(relation == 0)   break;
            else if(relation ==-1) {
                error_op(tem_line, fin, analysis_stack, tem_class);
                continue;
            }
            else continue;
        }while(1);

        string tem_result = judge_leftest_increase();
        if(tem_result == "error"){
            error_op(tem_line, fin, analysis_stack, tem_class);
            continue;
        }
        tem_top = analysis_stack.top();

        analysis_stack.push("N");

         if(analysis_stack.size()==2 && tem_input == "#"){
            correct_prom(tem_line);
            analysis_stack.pop();
            flag_jump_from = 0;
        }
        else flag_jump_from = 1;
    }

//    while(fin >> tem_string >> tem_class >> tem_line){
//
//        tem_input = class_num2string(tem_class);
//        if(!judge_Vt(analysis_stack.top()))
//            analysis_stack.pop();
//        if(!judge_Vt(analysis_stack.top())) {
//            error_op(tem_line, fin, analysis_stack, tem_class);
//            continue;
//        }
        //        # belong to Vt
//        while(true){
//
//            int relation = judge_relation(analysis_stack.top(), tem_input);
//            if(relation==2){
//                tem_right = analysis_stack.top();
//                analysis_stack.pop();
//                while(!(judge_Vt(analysis_stack.top()) && judge_relation(analysis_stack.top(), tem_right)==0)){
//                    if(!judge_Vt(analysis_stack.top())) analysis_stack.pop();
//                    if(!judge_Vt(analysis_stack.top())) {
//                        error_op(tem_line, fin, analysis_stack, tem_class);\
//                        break;
//                    }
//                    if(analysis_stack.size()==1 || judge_relation(analysis_stack.top(), tem_right)==-1){
//                        error_op(tem_line, fin, analysis_stack, tem_class);\
//                        break;
////                    different from ll1 algorithm, needn't push an S.
//                    }
//                    tem_right = analysis_stack.top();
//                    analysis_stack.pop();
//                }
//                analysis_stack.push("N");
//                if(tem_input == "#" && analysis_stack.size()==1 ){
//                    correct_prom(tem_line);
//                    break;
//                }
////            analysis_stack.push("N");
//            }
//            else if(relation==0 || relation==1){
//                analysis_stack.push(tem_input);
//                break;
////                jump out inside loop, read next input string
//            }
//            else if(relation==-1){
//                error_op(tem_line, fin, analysis_stack, tem_class);
//                break;
//            }
//
//            if(tem_input == "#" && analysis_stack.size()==1 ){
//                correct_prom(tem_line);
//                break;
//            }
//        }

}
int main(){
    string grammar_path = "../grammar.txt";
    create_Vn_Vt_grammar(grammar_path);
    create_firstVt();
    create_lastVt();
    create_analyzer_table();
    string config_path = "../config.txt";
    string need_to_anlysis_manully = ""; //"../alu_result1.txt";
    string class_init_path = "../alu_class_base_result.txt";

    if (!need_to_anlysis_manully.empty()) {
        class_num_init(class_init_path);
        combine_keyword();
        analyzer_stack(need_to_anlysis_manully);

    }
    else{
        string need_to_analysis = config_init(config_path);
        combine_keyword();
        analyzer_stack(need_to_analysis);
    }
    return 0;
}