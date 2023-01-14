//
// Created by Planck Chang on 2022/10/20.
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
// assume every reasoning the or is max 10

map<string, map<string, vector<string>>> analyzer_table;
map<string, set<string> > first;
map<string, set<string> > follow;
map<string, string> Vn;
map<string, string> Vt;
map<string, int> flag_e;
map<string, vector<string>[ORMAXFORGRAMMAR] > grammar;
map<pair<string,vector<string>>, set<string>> first_alpha;


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

bool judge_Vn(string &a){
    if(Vn[a] == a)
        return true;
    else return false;
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

int create_follow(){
    // follow set start
    follow["S"].insert("#");
    while(true) {

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
        if(flag==0) break;
    }
//                rule2 for follow
    while(true) {
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
        if(flag==0) break;
    }
//                failed tried, sad.

//                for(auto j:m){
//                    if(judge_Vn(j)){
//                        while(flag_e[m[loc]])
//                        if(m.size()>loc+1){
//                            follow[j] = set_union_my(follow[j], first[m[loc+1]]);
//                        }
//                    }
//
//                    if( 2 <= m.size()){
//
//                        if(judge_Vn(m[loc+1]) ){
//                            int ifollow_size = follow[i.first].size();
//                            follow[m[1]] = set_union_my(first[m[0]], follow[m[1]]);
//                            if(follow[m[1]].size()>ifollow_size){
//                                flag = 1;
//                            }
//                        }
//                    }
//                    if(judge_Vn(m[0]) ){
//                        int ifollow_size = follow[m[0]].size();
//                        follow[m[0]] = set_union_my(follow[i.first], follow[m[0]]);
//                        if(follow[m[0]].size()>ifollow_size){
//                            flag = 1;
//                        }
//                    }
//                    if(flag_e[m[0]] && judge_Vn(m[1])){
//                        int ifollow_size = follow[m[1]].size();
//                        follow[m[1]] = set_union_my(follow[i.first], follow[m[1]]);
//                        if(follow[m[1]].size()>ifollow_size){
//                            flag = 1;
//                        }
//                    }
//                }
//        if(flag==0){
//            break;
//        }
//    }
}

int create_analyzer_table(){
// i.first is expression A - > alpha , i.second is the first of alpha
    for(auto &i: first_alpha){
        for(auto &m:i.second){
//            m is derivation for reasoning.
            if(m.empty()) continue;

            if(flag_e[i.first.first]==1){
                for(auto &k:follow[i.first.first])
//                    todo have something wrong
                    analyzer_table[i.first.first][k].emplace_back("e");
            }

            for(auto k:i.second){
//                todo
                analyzer_table[i.first.first][k] = i.first.second;
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
int analyzer_stack(string &file_path){
    ifstream fin;
    fin.open(file_path);
    if(!fin){
        cerr << file_path << " file open error\n";
        return -1;
    }
    stack<string> analysis_stack;
    analysis_stack.push("#");
    analysis_stack.push("S");

    string tem_string;
    int tem_line, tem_class;
    string tem_input;
    fin>> tem_string >> tem_string >> tem_string;
    while(fin >> tem_string >> tem_class >> tem_line){
        tem_input = class_num2string(tem_class);

        while(true){
            if(judge_Vn(analysis_stack.top())){
//            todo
//            cout << analyzer_table[analysis_stack.top()][tem_input][0];

                vector<string> reasoning(analyzer_table[analysis_stack.top()][tem_input]);
                if(reasoning.empty()){
                    error_op(tem_line, fin, analysis_stack, tem_class);
                    analysis_stack.push("S");
                    break;
                }
                else{
                    analysis_stack.pop();
                    for(auto i = reasoning.rbegin(); i<reasoning.rend();++i){
                        if(*i != "e")
                            analysis_stack.push(*i);
                    }
                }
            }
            else if(judge_Vt(analysis_stack.top()) && tem_input==analysis_stack.top() && analysis_stack.top()!="#"){
                if(tem_input == analysis_stack.top()){
                    analysis_stack.pop();
                    break;
                }
                else{
                    error_op(tem_line, fin, analysis_stack, tem_class);
                    analysis_stack.push("S");
                    break;
                }
            }
            else if(analysis_stack.top()=="#" || tem_input=="#"){
                if(tem_input==analysis_stack.top()){
                    if(error_count==0){
                        correct_prom(tem_line);
                        analysis_stack.push("S");
                        break;
                    }
                    else{
                        error_op(tem_line, fin, analysis_stack, tem_class);
                        analysis_stack.push("S");
                        break;
                    }
                }
                else {
                    error_op(tem_line, fin, analysis_stack, tem_class);
                    analysis_stack.push("S");
                    break;
                }
            }
            else{
                error_op(tem_line, fin,analysis_stack, tem_class);
                analysis_stack.push("S");
                break;
            }
        }
    }
    fin.close();
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
int main(){
    string grammar_path = "../grammar.txt";
    create_Vn_Vt_grammar(grammar_path);
    create_first(grammar_path);
    create_follow();
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

//    cout << analyzer_table["E"]["i"][0] << endl;
//    cout << analyzer_table["S"]["i"][0] << endl;
    return 0;
}

// ends on 2022 10 22 13:44 more than 13 hours