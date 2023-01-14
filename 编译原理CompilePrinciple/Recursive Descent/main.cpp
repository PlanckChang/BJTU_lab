#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
        notation = str;
        class_num = num;
        line = line_;
    }
};

// we match different class with the class_num of Struct Keyword
// func init() would set the real class_num, but the num and
// identifier is pre-set manually
Keyword plus_keyword('+', 0, 0);
Keyword subtract_keyword('-', 0, 0);
Keyword multiply_keyword('*', 0, 0);
Keyword division_keyword('/', 0, 0);
Keyword pound_key_keyword('#', 0, 0);
Keyword left_bracket_keyword('(', 0, 0);
Keyword right_bracket_keyword(')', 0, 0);
Keyword equal_keyword('=', 0, 0);
Keyword numeric_var("numeric", 1, 0);
Keyword identifier_num("identifier", 0, 0);
// identifier_num and numeric_var class num is the same as exe. Lexical config.


int tem_class;
int tem_line;
string tem_string;
ifstream fin;
int error_count = 0;

int expression();

int goon(){
    fin >> tem_string >> tem_class >> tem_line;
}

int error_prom(){
    cout << "line " << tem_line << " syntax error\n";
    return 0;
};
int correct_prom(int &line){
    cout << "line " << line << " syntax correct\n";
    return 0;
}

int arithmetic(){
    if(tem_class==plus_keyword.class_num){
        goon();
        return 0;
    }
    else if(tem_class==subtract_keyword.class_num){
        goon();
        return 0;
    }
    else{
//        error_prom();
        return 1;
    }
}
int factor(){
    if(tem_class==left_bracket_keyword.class_num){
        goon();
        if(expression()==0){
            if(tem_class==right_bracket_keyword.class_num){
                goon();
//                correct_prom();
                return 0;
            }
            else{
//                error_prom();
                return 1;
            }
        }
        else{
//            error_prom();
            return 1;
        }
    }
    else if(tem_class==numeric_var.class_num ||tem_class==identifier_num.class_num){
        goon();
        return 0;
    }
    else{
//        error_prom();
        return 1;
    }
};
int M(){
    if(tem_class==multiply_keyword.class_num){
        goon();
        return 0;
    }
    else if(tem_class == division_keyword.class_num){
        goon();
        return 0;
    }
    else{
//        error_prom();
        return 1;
    }
}
int term_1(){
    while(1){
        if(tem_class==multiply_keyword.class_num || tem_class==division_keyword.class_num){
            if(M()==0){
                if(factor()==0){
                    continue;
                }

                else{
//                error_prom();
                    return 1;
                }
            }
            else{
//            error_prom();
                return 1;
            }
        }
        else if(tem_class==right_bracket_keyword.class_num || tem_class==pound_key_keyword.class_num ||
                tem_class==plus_keyword.class_num || tem_class==subtract_keyword.class_num){
//        correct_prom();

            return 0;
        }
        else{
//        error_prom();
            return 1;
        }
    }

};
int term(){
    if(tem_class == identifier_num.class_num || tem_class==numeric_var.class_num
       || tem_class== left_bracket_keyword.class_num){
        if(factor()==0){
            if(term_1()==0){
//                correct_prom();
                return 0;
            }
            else{
//                error_prom();
                return 1;
            }
        }
        else{
//            error_prom();
            return 1;
        }
    }
    else{
//        error_prom();
        return 1;
    }
};
int expression_1(){
    while(1){
        if(tem_class==plus_keyword.class_num||tem_class==subtract_keyword.class_num){
            if(arithmetic()==0){
                if(term()==0){
                    continue;
//                todo try two method,1.
                }
                else {
//                error_prom();
                    return 1;
                }
            }
            else {
//            error_prom();
                return 1;
            }
        }
        else if(tem_class==right_bracket_keyword.class_num || tem_class==pound_key_keyword.class_num){
//        correct_prom();

            return 0;
        }
        else{
//        error_prom();
            return 1;
        }
    }

}
int expression(){
    if(tem_class == identifier_num.class_num || tem_class==numeric_var.class_num
        || tem_class== left_bracket_keyword.class_num){
//    if(tem_class == identifier_num.class_num || tem_class==left_bracket_keyword.class_num){
        if(term()==0){
            if(expression_1()==0){
//                correct_prom();
                return 0;
            }
            else {
//                error_prom();
                return 1;
            }
        }
        else {
//            error_prom();
            return 1;
        }
    }
    else{
//        error_prom();
        return 1;
    }
};

int class_num_init(string &base_out){
    ifstream fin;
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
int statement(){
//    if(tem_class==identifier_num.class_num || tem_class == numeric_var.class_num){
    if(tem_class == identifier_num.class_num){
        goon();
        if(tem_class == equal_keyword.class_num){
            goon();
            return expression();
        }
        else return 1;
    }
    else return 1;
}
int alu_analysis(string file_path){
    fin.open(file_path);
    if(!fin){
        cerr << "file needed to analysis open error\n";
        return 1;
    }


    fin >> tem_string >> tem_string >> tem_string;

    fin >>tem_string >>  tem_class >> tem_line;
    do{
//        if(line_!=tem_line && error_count==0){
//            correct_prom(line_);
//            line_ = tem_line;
//            error_count = 0;
//        }
        if(statement()==0){
            if(tem_class == pound_key_keyword.class_num) correct_prom(tem_line);
        }
        else {
            error_prom();
            ++error_count;
            while(tem_class != pound_key_keyword.class_num){
                fin >>tem_string >> tem_class >> tem_line;
            }
            continue;
        }
    }while(fin >>tem_string >>  tem_class >> tem_line);
//    if(error_count == 0){
//        correct_prom(line_);
//    }
    fin.close();
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
int main() {
//    in config.txt, we can change the base class file and needed to analyzer test sample
    string config_path = "../config.txt";
    string need_to_anlysis_manully = ""; //"../alu_result1.txt";
    string class_init_path = "../alu_class_base_result.txt";

    if (!need_to_anlysis_manully.empty()) {
        class_num_init(class_init_path);
        alu_analysis(need_to_anlysis_manully);
    }
    else{
        string need_to_analysis = config_init(config_path);
        alu_analysis(need_to_analysis);
    }


}
