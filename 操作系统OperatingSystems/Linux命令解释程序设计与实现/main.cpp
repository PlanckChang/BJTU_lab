#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <wait.h>
#include <algorithm>
#include <cstring>
#include <sys/stat.h>


using namespace std;
#define INSTRUCTION_MAX_SIZE 255;
#define BUFFER_MAX (1024*1024)  // 1MB
int builtin_command_num = 5;

vector<string> instruction;
vector<string> history_command_list;

struct builtin_command{
    string name;
    int (*address)(char **);
};

int my_cd(char **argv){
    if(strcmp(argv[0], "cd")){
        cout << "error: the instruction is not cd\n";
        return 0;
    }
    if(argv[1]==NULL){
        cout << "parameter error\n";
        return 0;
    }
    chdir(argv[1]);
}

int my_history(char **argv){
    if(strcmp(argv[0], "history")){
        cout << "error: the instruction is not history\n";
        return 0;
    }
    if(history_command_list.empty()){
        cout << "the command history list is empty. you have never used command\n";
        return 0;
    }
    for(auto & i : history_command_list){
        cout << i << "\t";
    }
    cout << "\n";
}

int my_mkdir(char **argv){
    if(strcmp(argv[0], "mkdir")){
        cout << "the instruction is not mkdir\n";
        return 0;
    }
    if(argv[1]==nullptr){
        cout << "parameter error\n";
        return -1;
    }
//    directory has existed
    if(access(argv[1], F_OK) >=0){
        return 0;
    }
    return mkdir(argv[1], 0777);
}

int my_cp(char **argv){
    if(strcmp(argv[0], "cp")){
        cout << "the instruction is not cp\n";
        return -1;
    }
    if(argv[1]==nullptr || argv[2]==nullptr){
        cout << "param error\n";
        return -1;
    }
    if(access(argv[1], F_OK) < 0){
        return 0;
    }

//    set up a dynamic buffer to copy file
    FILE *p_src = fopen(argv[1], "rb");
    FILE *p_des = fopen(argv[2], "wb");

    struct stat stat1;
    stat(argv[1], &stat1);

    int size_dynamic = stat1.st_size;

    if(size_dynamic>BUFFER_MAX){
        size_dynamic = BUFFER_MAX;
    }

    char *buffer = new char[size_dynamic];
    int res_fread=0;
    while(!feof(p_src)){
        res_fread = fread(buffer, sizeof(char), size_dynamic, p_src);
        fwrite(buffer, sizeof(char), res_fread, p_des);
    }
    delete buffer;
    fclose(p_src);
    fclose(p_des);

    cout << "copy " << argv[1] << " to " << argv[2] << " successfully \n";
}

int my_date(char **argv){
    if(strcmp(argv[0],"date")){
        cout << "the instruction is not date\n";
        return -1;
    }

    time_t time_raw = time(nullptr);
    char *time_c_local = ctime(&time_raw);
    cout << "the local time is " << time_c_local;
}
builtin_command builtin_command_list[]={
        "cd", my_cd,
        "history", my_history,
        "mkdir", my_mkdir,
        "cp", my_cp,
        "date", my_date,
};



int promt_show() {
    cout << "[zhangzhiwei@20271259]:\t";
    char string[255];
    cout << getcwd(string, 255);
    cout << "/$ ";
}

int get_instruction() {
    int max_size = INSTRUCTION_MAX_SIZE;
    string instruct_input;
    char instruction_input_char[255];
    int count =0;
    while(count < max_size && cin >> instruct_input){
        if(instruct_input.size() >= max_size){
            cout << "the instruction is too long\n";
            return -1;
        }
        instruction.emplace_back(instruct_input);
//      if inputted command followed by a blank bar, then continue. it enhances robust.
        int flag_cin_get;
        flag_cin_get = cin.get();
        if(flag_cin_get == '\n') break;
    }
    return 0;
}

char** transfer2char(vector<string> &src){
    char **des = new char*[src.size()+1];
    for(int i=0; i<src.size(); ++i){
        des[i] = new char[255];
        strcpy(des[i], src[i].c_str());
    }
    return des;
}


int execute(){
//    match the builtin command first
    if(instruction[0]=="builtin"){
        cout << "the builtin command archived right now has " << builtin_command_num << "\n";
        for(int i=0; i<builtin_command_num; ++i){
            cout << builtin_command_list[i].name << "\n";
        }
        return 0;
    }

    char ** argv = transfer2char(instruction);
    int status;

    for(int i=0; i< builtin_command_num;++i){
        if(instruction[0]==builtin_command_list[i].name){
            history_command_list.emplace_back(instruction[0]);
            return builtin_command_list[i].address(argv);
        }
    }

// match the outside command in PATH
//    todo to use fork to call execvp func to avoid process done
    pid_t pid = fork();
    if(pid == 0){
//        todo some parameters of child ps change but not the father ps by calling execvp func
// such as cd command, in this case, the workdir of child's has change but not the father's
// from web, cd must be a builtin command because one ps can't change the workdir of its father

        execvp(instruction[0].c_str(), argv);
    }
    else if(pid < 0){
        perror("error:\t");
    }
    else{
        waitpid(pid, &status, WUNTRACED);
    }


    history_command_list.emplace_back(instruction[0]);
    for(int i=0; i<instruction.size(); ++i){
        delete argv[i];
    }
    delete argv;
    return 0;
}
int free_vector(){
    instruction.erase(instruction.begin(), instruction.end());
    return 0;
}
int runs(){
    cout << "welcome to Zhang Zhiwei's shell" << "\n\n";
    while(1){
        promt_show();
        get_instruction();
        execute();
        free_vector();
    }



}
int main() {

    runs();
//    execvp("ls", NULL);
}
