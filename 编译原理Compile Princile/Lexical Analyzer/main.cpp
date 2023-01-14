#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// var first should not use like "first + num", because if one case is dropped, the case list is confused, thus use
// like "first ++", dynamically computing the line num.


// code annotation  is needed todo
// class num output
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
vector<Keyword> symbol_table;
vector<Keyword> output;
// following notation is just a for the class_num , line is random.
Keyword identifier_num("identifier", 0, 0);
Keyword numeric("numeric", 1, 0);
Keyword annotation("annotation", 2, 0);

int init(){
    ifstream fin;
    fin.open("../reserved_word.txt", ios::in);
    if(!fin) cerr << "open file error\n";
    string tem;
    int i = 10;
    while(fin >> tem){
        symbol_table.emplace_back(Keyword(tem, i++, 0));
    }
    fin.close();
    return 0;
}


int lexical_analysis(string file_path){
    ifstream fin;
    int first = symbol_table[symbol_table.size()-1].class_num;
    fin.open(file_path, ios::in);
    if(!fin) cerr << "open the file needs to be lex analysed error\n";
    char sentence_char[1000];
// in clion, the code is beginning with line 1
    int line = 1;
    while(fin.getline(sentence_char, 1000)){
        string sentence(sentence_char);
        if(sentence.size()>=80){
            cerr << "line " << line << " length is longer than 80\n";
        }
//        todo
// the length of one code line is bigger than 80 is error
//        if(sentence.size()){
//            cerr << "line " << line << " length is longer than 80\n";
//        }

        int i = 0;
        for(; i< sentence.size(); ++i){
            if(sentence[i] == '\n' || sentence[i] == ' ' || sentence[i] == '\t'){
                continue;
            }
            else if(sentence[i]<= 'z' && sentence[i] >= 'a' || sentence[i]<='Z'&&sentence[i]>='A'){
                string word;
                int j = 0;
                word.push_back(sentence[i]);
                ++i;
                ++j;
                while((sentence[i]<= 'z' && sentence[i] >= 'a' || sentence[i]<='Z'&&sentence[i]>='A') ||
                      (sentence[i]<='9'&&sentence[i]>='0')){
                    word.push_back( sentence[i++]);
                }
                if(word.size() >32) {
                    cerr << "line " << line << " " << word << " longer than 32\n";
                    continue;
                }

                int flag = 1;
                for(auto item:symbol_table){
                    if (item.notation == word){
                        output.emplace_back(Keyword(word, item.class_num, line));
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    output.emplace_back(Keyword(word, identifier_num.class_num, line));
                }
                i--;

            }
//            numeric
            else if(sentence[i] >='0' && sentence[i]<='9'){
                string word;

                word.push_back(sentence[i++]);
                while(sentence[i] >='0' && sentence[i] <='9'){
                    word.push_back(sentence[i++]);
                }
                if(sentence[i]<= 'z' && sentence[i] >= 'a' || sentence[i]<='Z'&&sentence[i]>='A'){
                    while((sentence[i]<= 'z' && sentence[i] >= 'a' || sentence[i]<='Z'&&sentence[i]>='A') ||
                          (sentence[i]<='9'&&sentence[i]>='0')){
                        word.push_back( sentence[i++]);
                    }
                    cerr << "line " << line << " var is invalid, begin with number\n";
                }
                else{
                    output.emplace_back(Keyword(word, numeric.class_num,line));
                }
                i--;
//                todo
// this only classifier the num + letter-type invalid var, but the weired fixed symbols one does not be differentiated.
            }
//            other notation
            else

                switch(sentence[i]){
                    case '#':{
                        output.emplace_back(Keyword(sentence[i], first+0, line));
                        break;
                    }

                    case '=':{
                        ++i;
                        if(sentence[i] == '='){
                            output.emplace_back(Keyword("==", first+1, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword("=", first+2 ,line));
                        }
                        break;
                    }

                    case '>':{
                        ++i;

                        if(sentence[i] == '='){
                            output.emplace_back(Keyword(">=", first+3, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword('>', first+4, line));
                        }
                        break;
                    }

                    case '<':{
                        ++i;
                        if(sentence[i] == '='){
                            output.emplace_back(Keyword("<=", first+5, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword('<',first+6, line));
                        }
                        break;
                    }

                    case '+':{
                        ++i;
                        if(sentence[i] == '+'){
                            output.emplace_back(Keyword("++", first+7, line));
                        }
                        else if(sentence[i]=='='){
                            output.emplace_back(Keyword("+=", first+8, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword('+', first+9, line));
                        }
                        break;
                    }
                    case '-':{
                        ++i;
                        if(sentence[i] == '-'){
                            output.emplace_back(Keyword("--", first+10, line));
                        }
                        else if(sentence[i]=='='){
                            output.emplace_back(Keyword("-=", first+11, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword('-', first+12, line));
                        }
                        break;
                    }

                    case '*':{
                        ++i;
                        if(sentence[i] == '*'){
                            output.emplace_back(Keyword("**", first+13, line));
                        }
                        else if(sentence[i]=='='){
                            output.emplace_back(Keyword("*=", first+14, line));
                        }
                        else{
                            --i;
                            output.emplace_back(Keyword('*', first+15, line));
                        }
                        break;
                    }
                    case '/':{
                        ++i;
                        if(sentence[i] == '/'){
                            output.emplace_back(Keyword("//", first+16, line));
                            if(!(sentence[i+1]=='"' && sentence[i-2] == '"')){
                                output.emplace_back(Keyword(sentence.substr(i+1, sentence.size()-1), annotation.class_num, line));
                                i = sentence.size();
                            }

                        }
                        else if(sentence[i]=='='){
                            output.emplace_back(Keyword("/=", first+17, line));
                        }
                        else{
//                            escape character
                            --i;
                            output.emplace_back(Keyword('/', first+18, line));
                        }
                        break;
                    }
                    case ':':{
                        output.emplace_back(Keyword(':', first+19, line));
                        break;
                    }
                    case ';':{
                        output.emplace_back(Keyword(';', first+20, line));
                        break;
                    }
                    case '(':{
                        output.emplace_back(Keyword('(', first+21, line));
                        break;
                    }
                    case ')':{
                        output.emplace_back(sentence[i], first+22, line);
                        break;
                    }
                    case '{':{
                        output.emplace_back(sentence[i], first+23, line);
                        break;
                    }
                    case '}':{
                        output.emplace_back(sentence[i], first+24, line);
                        break;
                    }
                    case '[':{
                        output.emplace_back(sentence[i], first+25, line);
                        break;
                    }
                    case ']':{
                        output.emplace_back(sentence[i], first+26, line);
                        break;
                    }
                    case ',':{
                        output.emplace_back(sentence[i], first+27, line);
                        break;
                    }
                    case '"':{
                        output.emplace_back(sentence[i], first+28, line);
                        break;
                    }
                    case '\'':{
                        output.emplace_back(sentence[i, i+1], first+22, line);
                        ++i;
                        break;
                    }
                    case '&':{
                        ++i;
                        if(sentence[i] == '&'){
                            output.emplace_back("&&", first+23, line);
                        }
                        else{
                            --i;
                            output.emplace_back('&', first+24, line);
                        }
                        break;
                    }
                    case '|':{
                        ++i;
                        if(sentence[i] == '|'){
                            output.emplace_back("||", first+25, line);
                        }
                        else{
                            --i;
                            output.emplace_back('|', first+26, line);
                        }
                        break;
                    }
                    case '!':{
                        ++i;
                        if(sentence[i] == '='){
                            output.emplace_back("!=", first+27, line);
                        }
                        else{
                            --i;
                            output.emplace_back('!', first+28, line);
                        }
                        break;
                    }
                    case '%':{
                        ++i;
                        if(sentence[i] == '='){
                            output.emplace_back("%=", first+29, line);
                        }
                        else{
                            --i;
                            output.emplace_back('%', first+30, line);
                        }
                        break;
                    }
//                    todo
//                    case '<':{
//                      printf in which format control
//                      ' can not be insert
//                    }
                }
        }
        ++line;
    }
    fin.close();
}

int main(int argc, char *argv[]) {
    init();

    ifstream  fin;
    ofstream fout;
    string file_path = argv[1];
    string out_file_path = argv[2];

    lexical_analysis(file_path);
    fout.open(out_file_path, ios::out);
    if(!fout) cerr << "file open error\n";
    fout << "notation\t" << "class_num\t" << "line" << "\n";
    for(auto item:output){
            fout << item.notation;
            int width = 18 - item.notation.size();
            fout.width( (width> 0) ? width: 0);
            if(item.class_num == 2) fout << "\n\t\t\t\t";
//            consider annotation is usually long so the class_num and line info is under one line
            fout  << item.class_num;
            fout << "\t\t" << item.line;
            fout << "\n";
    }

    fout.close();
}
