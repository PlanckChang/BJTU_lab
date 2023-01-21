#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define M_PI  "6.283185307179586"

using namespace std;

struct divide_result{
    divide_result(string &q, string &r, string &q_p);
    string quotient, reminder, quotient_pot;
};
divide_result::divide_result(string &q, string &r, string &q_p):quotient(q),reminder(r),quotient_pot(q_p) {
}

struct two_shift{
    string four, eight, ten, sixteen;
    two_shift(string &four_, string &eight_, string&ten_, string &sixteen_);
};

two_shift::two_shift(string &four_, string &eight_, string&ten_, string &sixteen_):
    four(four_),eight(eight_),ten(ten_),sixteen(sixteen_){
}

struct four_shift{
    string two, eight, ten, sixteen;
    four_shift(string &two_, string &eight_, string&ten_, string &sixteen_);
};

four_shift::four_shift(string &two_, string &eight_, string&ten_, string &sixteen_):
    two(two_),eight(eight_),ten(ten_),sixteen(sixteen_){
}

struct eight_shift{
    string two, four, ten, sixteen;
    eight_shift(string &two_, string &four_, string&ten_, string &sixteen_);
};

eight_shift::eight_shift(string &two_, string &four_, string&ten_, string &sixteen_):
    two(two_),four(four_),ten(ten_),sixteen(sixteen_){
}

struct ten_shift{
    string two, four, eight, sixteen;
    ten_shift(string &two_, string &four_, string&eight_, string &sixteen_);
};

ten_shift::ten_shift(string &two_, string &four_, string &eight_, string &sixteen_) :
    two(two_),four(four_),eight(eight_),sixteen(sixteen_){}


struct sixteen_shift{
    string two, four, eight, ten;
    sixteen_shift(string &two_, string &four_, string&eight_, string &ten_);
};

sixteen_shift::sixteen_shift(string &two_, string &four_, string &eight_, string &ten_):
    two(ten_),four(four_),eight(eight_),ten(ten_){
}

// 加法
string add(string a, string b){
    string result;
    int cf=0;
    int he=0;

    //  分整数 和 小数运算
    if(a.find('.')==string::npos && a.find('.')==string::npos){
        int l = min(a.length(),b.length());

// the length of string a is bigger
        if(a.length()<b.length()){
            a.swap(b);
        }

//      reverse a and b, then add them from index 0 to top which equals add like
// 倒序相加
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
//        分两段
        for (int i = 0; i < l; ++i) {
            he = cf + a[i]+b[i]-2*'0';
            if(he>=10){
                cf = 1;
                he-=10;
            }
            else cf=0;
            result.append(to_string(he));
        }
//        第二段只加cf
        for(int i=l;i<a.length();++i){
            he = cf+a[i]-'0';
            if(he>=10){
                cf=1;
                he-=10;
            }
            else cf=0;
            result.append(to_string(he));
        }
//        最后一位的进位

        if(cf) result.append(to_string(cf));
    }
// 有小数时
    else{
        if(a.find('.')==string::npos) a.append(".");
        if(b.find('.')==string::npos) b.append(".");
//  反
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int a_pot = a.find('.');
        int b_pot = b.find('.');
//        a是长度最长的数

//         正 方便补零
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
// 小数点对齐
        if(a_pot>b_pot){
            b.append(a_pot-b_pot, '0');
        }
        else a.append(b_pot-a_pot, '0');

        int pos_of_pot = max(a_pot, b_pot);

        int l = min(a.length(), b.length());
        if(a.length()<b.length()){
            a.swap(b);
        }
//        反
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
// 分三段
        for(int i=0; i<pos_of_pot; ++i){
            he = cf + a[i]+b[i]-2*'0';
            if(he>=10){
                cf =1;
                he-=10;
            }
            else cf=0;
            result.append(to_string(he));
        }
        result.append(1,'.');
        for(int i=pos_of_pot+1; i<l;++i){
            he = cf + a[i] + b[i] -2*'0';
            if(he>=10){
                cf=1;
                he-=10;
            }
            else cf=0;
            result.append(to_string(he));
        }
        for(int i= l; i<a.length();++i){
            he = a[i]+cf -'0';
            if(he>=10){
                cf =1 ;
                he-=10;
            }
            else cf=0;
            result.append(to_string(he));
        }
//        最后一位进位
        if(cf) result.append(to_string(cf));
    }

    reverse(result.begin(), result.end());
//    cout<< result << "\n" ;
    return result;
}
///
/// \param a
/// \param b
/// \return
//通过预处理 保证 a b 同时是正数
string subtraction(string a, string b){
    int cha=0;
    int cf=0;
    string result;
// 整数 小数 一起运算 不区分
    if(a.find('.')==string::npos){
        a.append(".");
    }
    if(b.find('.')==string::npos){
        b.append(".");
    }
//    逆序
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int a_pot = a.find('.');
    int b_pot = b.find('.');
//  正序
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
// 正序 添0 小数点对齐
    if(a_pot>b_pot){
        b.append(a_pot-b_pot, '0');
    }
    else a.append(b_pot-a_pot, '0');

    if(a.length()<b.length()){
        a.swap(b);
    }
    else if(a.length()==b.length()){
        if(a<b){
            a.swap(b);
        }
    }

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int pos_of_pot = max(a_pot, b_pot);
    int l = min(a.length(), b.length());
//小数部分 分三段计算
    for(int i=0;i<pos_of_pot;++i){
//        原本无 为 a[i]< b[i]  测试也成果
       if(a[i]<b[i]+cf){
           cha = 10+ a[i]-cf-b[i];
            cf=1;
       }
       else{
           cha = a[i]-cf-b[i];
           cf =0;
       }
       result.append(to_string(cha));
    }
    result.append(".");
    for(int i=pos_of_pot+1; i<l;++i){
        if(a[i]<b[i]+cf){
            cha = 10+ a[i]-cf-b[i];
            cf=1;
        }
        else{
            cha = a[i]-cf-b[i];
            cf=0;
        }
        result.append(to_string(cha));
    }
    for(int i=l;i<a.length();++i){
        if(a[i]<(cf+'0')){
            cha = 10 + a[i] -cf-'0';
            cf = 1;
        }
        else{
            cha = a[i]-cf-'0';
            cf=0;
        }
        result.append(to_string(cha));
    }
//    最后一位一定够减 不用 测试 cf

    while(result.back()=='0'){
        result.erase(result.end()-1);
    }

    std::reverse(result.begin(), result.end());
    while(result.back()=='0'){
        result.erase(result.end()-1);
    }

    if(result.back()=='.'){
        result.erase(result.end()-1);
    }
    if(result.empty()) result+="0";
//    cout << result << "\n";

    return result;
}

///
/// \param a
/// \param b
/// \return
// 符号还没有处理 20220708 完成
string multiply(string a, string b){
//总体思路为 先去掉小数点 一起运算 后边再添上

//先增加小数点计算 先确定小数点位数
    if(a.find('.')==string::npos) a.append(".");
    if(b.find('.')==string::npos) b.append(".");

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int a_pot = a.find('.');
    int b_pot = b.find('.');
//    要补回的小数点位数
    int len_of_pot = a_pot+b_pot;

    a.erase(a.find('.'),1);
    b.erase(b.find('.'), 1);
//此长度不包含 小数点
    int len = min(a.length(), b.length());
    vector<string> bufenji(len,"0");

    if(a.length()<b.length()){
        a.swap(b);
    }
//    a 变为正序 配合add函数 b仍然为逆序 运算使用
    std::reverse(a.begin(), a.end());
//    以较小的数 b为乘数
    string result_tem1("0");

    for(int i=0;i<b.length();++i){
        for (int j = 0; j < b[i] - '0'; ++j) {
            result_tem1 = add(result_tem1,a);
        }
//        部分积向量组中的是正序的数 后补0 模拟笔试运算
        bufenji[i] = result_tem1.append(i,'0');
//        result tem1 清零 下次循环
        result_tem1 = "0";
    }
    string result("0");
//  部分积求和
    for (int i = 0; i < b.length(); ++i) {
        result = add(result, bufenji[i]);
    }

    result.insert(result.length()-len_of_pot, ".");
//    去掉后导的小数点和多余的0
    while(result.back()=='0') result.erase(result.end()-1);
    if(result.back()=='.') result.erase(result.end()-1);

//    cout << result << "\n";
    return result;
}


///
/// \param a
/// \param b
/// \return

bool cmp(string a, string b){
    if(a.length()<b.length()){
        return 0;
    }
    else if (a.length()==b.length() && a<b){
        return 0;
    }
    else return 1;
}
///
/// \param a
/// \param b
/// \return
/// b 不能是0 已有预处理
/// reminder 为0时 返回值是空 无前导0
divide_result  divide(string a, string b, int control_num){
    //        result_tem为不修正的余数，留作小数运算
//    算出商 余数 带小数的
    string quotient, reminder, quotient_pot, result, result_tem;

    // 按 小数位数多的 进行补零 把两数统一扩大 得到两数都是整数
    if(a.find('.')==string::npos) a.append(".");
    if(b.find('.')==string::npos) b.append(".");

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int a_pot = a.find('.');
    int b_pot = b.find('.');

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    // 小数点对齐
    if(a_pot>b_pot){
        b.append(a_pot-b_pot, '0');
    }
    else{
        a.append(b_pot-a_pot,'0');
    }
    a.erase(a.find('.'),1);
    b.erase(b.find('.'),1);

    if(a.length()<b.length()){
        quotient="0";
        reminder=a;
        result_tem = a;
    }
    else if(a.length()==b.length() && a<b){
        quotient="0";
        reminder=a;
        result_tem = a;
    }
    else{
//        截取被除数
        result = string(a.begin(), a.begin()+b.length());
        for(int i=b.length();i<=a.length();++i){
            if(!cmp(result, b)){
                if(!quotient.empty())
                    quotient.append("0");
            }
            else{
                int j=1;
                for (;j <= 9; ++j) {
                    if(!cmp(result=subtraction(result,b),b)){
                        quotient.append(to_string(j));
                        break;
                    }
                }
            }
            if(result=="0") result.erase(result.begin());
            if(i!=a.length()){
                result+=a[i];
            }
        }
//        result_tem为不修正的余数，留作小数运算
        result_tem = result;
        reminder=result;
    }
//    考虑到极小的被除数 去掉前导0方可开始运算 不然一旦小数部分运算 会出现前导0加入运算 退位为9 计算错误
// 二进制除法没有这样修正
    while(result_tem[0]=='0') result_tem.erase(0,1);

//    运算结束 开始修正小数点
    if(result_tem.empty()) result_tem+='0';
//        余数的小数点需要修正 按除数的位数修正
        if(reminder.empty()){
            reminder+="0";
        }
        else{
//            位数不够的先前补零
            if (reminder.length()<max(b_pot, a_pot)){
                reminder.insert(0,max(a_pot, b_pot) -reminder.length()+1, '0');
            }
            reminder.insert(reminder.end()-max(b_pot,a_pot), '.');
            while(reminder.back()=='0') reminder.erase(reminder.length()-1, 1);
            if(reminder.back()=='.') reminder.erase(reminder.end()-1);
            if(reminder.empty()) reminder+="0";
        }

//        小数点修正完毕 开始进行小数部分运算
//    cout << quotient << "\n";
//    cout << reminder << "\n";

//    小数点部分运算 采用去尾法处理 换而言之 最后一位不准
// len_pot 设定计算小数个数，防止die loop
    int len_pot=control_num;
    string value_quotient_pot;
    if(result_tem=="0"){
        quotient_pot = quotient;
    }
    else{
        for(int i=0;i<len_pot;++i){
            result_tem+='0';
            if(!cmp(result_tem, b)){
                value_quotient_pot+='0';
            }
            else{
                for(int j=1; j<=9;++j){
                    if(!cmp(result_tem =subtraction(result_tem,b),b)){
                        value_quotient_pot+= to_string(j);
                        break;
                    }
                }
            }
//            版本改动前 减法结果为0 则为空
            if(result_tem=="0") break;
        }
        quotient_pot=quotient + '.' + value_quotient_pot;
    }
//    cout << quotient_pot << " : " << quotient_pot <<'\n';
    return divide_result(quotient, reminder, quotient_pot);
}
// 注意 这里不能使用 内置的pi宏 乘二后转 string 这样会自动截断 有效性太低 这里的M pi 是 2倍之后的 已经是字符串 精度不会损失
// 对结果的限制只在于 pi的位数
double sin_my(string a, int control_num){
    string equ= divide(a, M_PI, control_num).reminder;
    return sin(stod(equ));
}

double cos_my(string a, int control_num){
    string equ = divide(a, M_PI, control_num).reminder;
    return cos(stod(equ));
}

string square_my(string a){
    return multiply(a, a);
}

string third_square_my(string a){
    return multiply(multiply(a, a), a);
}


/// 二进制减法
/// \param a
/// \param b
/// \return
string subtraction_max_2(string a, string b){
    int cha=0;
    int cf=0;
    string result;

    if(a.find('.')==string::npos){
        a.append(".");
    }
    if(b.find('.')==string::npos){
        b.append(".");
    }
//    逆序
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int a_pot = a.find('.');
    int b_pot = b.find('.');
//  正序
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    if(a_pot>b_pot){
        b.append(a_pot-b_pot, '0');
    }
    else a.append(b_pot-a_pot, '0');

    if(a.length()<b.length()){
        a.swap(b);
    }
    else if(a.length()==b.length()){
        if(a<b){
            a.swap(b);
        }
    }

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int pos_of_pot = max(a_pot, b_pot);
    int l = min(a.length(), b.length());

    for(int i=0;i<pos_of_pot;++i){
//        十进制减法中 没有cf

        if(a[i]<b[i]+cf){
            cha = 2+ a[i]-cf-b[i];
            cf=1;
        }
        else{
            cha = a[i]-cf-b[i];
            cf =0;
        }
        result.append(to_string(cha));
    }
    result.append(".");
    for(int i=pos_of_pot+1; i<l;++i){
        if(a[i]<b[i]+cf){
            cha = 2+ a[i]-cf-b[i];
            cf=1;
        }
        else{
            cha = a[i]-cf-b[i];
            cf=0;
        }
        result.append(to_string(cha));
    }
    for(int i=l;i<a.length();++i){
        if(a[i]<(cf+'0')){
            cha = 2 + a[i] -cf-'0';
            cf = 1;
        }
        else{
            cha = a[i]-cf-'0';
            cf=0;
        }
        result.append(to_string(cha));
    }
//    最后一位一定够减 不用 测试 cf

    while(result.back()=='0'){
        result.erase(result.end()-1);
    }

    std::reverse(result.begin(), result.end());
    while(result.back()=='0'){
        result.erase(result.end()-1);
    }

    if(result.back()=='.'){
        result.erase(result.end()-1);
    }
//
    if(result.empty()) result+="0";
//    cout << result << "\n";
    return result;
}
/// 二进制除法
/// \param a
/// \param b
/// \param control_num
/// \return
divide_result  divide_max_2(string a, string b, int control_num){
    //        result_tem为不修正的余数，留作小数运算
    string quotient, reminder, quotient_pot, result, result_tem;

    // 按 小数位数多的 进行补零 把两数统一扩大 得到两数都是整数
    if(a.find('.')==string::npos) a.append(".");
    if(b.find('.')==string::npos) b.append(".");

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int a_pot = a.find('.');
    int b_pot = b.find('.');

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    if(a_pot>b_pot){
        b.append(a_pot-b_pot, '0');
    }
    else{
        a.append(b_pot-a_pot,'0');
    }
    a.erase(a.find('.'),1);
    b.erase(b.find('.'),1);

    if(a.length()<b.length()){
        quotient="0";
        reminder=a;
        result_tem = a;
    }
    else if(a.length()==b.length() && a<b){
        quotient="0";
        reminder=a;
        result_tem = a;
    }
    else{
        result = string(a.begin(), a.begin()+b.length());
        for(int i=b.length();i<=a.length();++i){
            if(!cmp(result, b)){
                if(!quotient.empty())
                    quotient.append("0");
            }
            else{
                int j=1;
                for (;j <= 1; ++j) {
                    if(!cmp(result=subtraction_max_2(result,b),b)){
                        quotient.append(to_string(j));
                        break;
                    }
                }
            }
            if(result=="0") result.erase(result.begin());
            if(i!=a.length()){
                result+=a[i];
            }
        }
//        result_tem为不修正的余数，留作小数运算
        result_tem = result;
        reminder=result;
    }

//    运算结束 开始修正小数点
    if(result_tem.empty()) result_tem+='0';
//        余数的小数点需要修正 按除数的位数修正
    if(reminder.empty()){
        reminder+="0";
    }
    else{
//            位数不够的先前补零
        if (reminder.length()<max(b_pot, a_pot)){
            reminder.insert(0,max(a_pot, b_pot) -reminder.length()+1, '0');
        }
        reminder.insert(reminder.end()-max(b_pot,a_pot), '.');
        while(reminder.back()=='0') reminder.erase(result.end()-1);
        if(reminder.back()=='.') reminder.erase(reminder.end()-1);
        if(reminder.empty()) reminder+="0";
    }

//        小数点修正完毕 开始进行小数部分运算
//    cout << quotient << "\n";
//    cout << reminder << "\n";

//    小数点部分运算 采用去尾法处理 换而言之 最后一位不准
// len_pot 设定计算小数个数，防止die loop
    int len_pot=control_num;
    string value_quotient_pot;
    if(result_tem=="0"){
        quotient_pot = quotient;
    }
    else{
        for(int i=0;i<len_pot;++i){
            result_tem+='0';
            if(!cmp(result_tem, b)){
                value_quotient_pot+='0';
            }
            else{
                for(int j=1; j<=1;++j){
                    if(!cmp(result_tem =subtraction_max_2(result_tem,b),b)){
                        value_quotient_pot+= to_string(j);
                        break;
                    }
                }
            }
//            改动前 result_tem 即运算结果 如果为0 则为空
            if(result_tem=="0") break;
        }
        quotient_pot=quotient + '.' + value_quotient_pot;
    }
//    cout << quotient_pot << " : " << quotient_pot <<'\n';
    return divide_result(quotient, reminder, quotient_pot);
}

// 以下几个函数做映射用，不再说明
string b_2_d(string &reminder){
    string result;
// 版本变动之前 整除 余数为0 不显示 故 reminder==“”
// 只有 b to 10 使用了除法 所以 前导0 不写 但是其他进制是使用 映射表转换的 前导0 要写
    if(reminder=="0") result+="0";
    else if(reminder=="1") result+="1";
    else if(reminder=="10") result+="2";
    else if(reminder=="11") result+="3";
    else if(reminder=="100") result+="4";
    else if(reminder=="101") result+="5";
    else if(reminder=="110") result+="6";
    else if(reminder=="111") result+="7";
    else if(reminder=="1000") result+="8";
    else if(reminder=="1001") result+="9";

    return result;
}
string d_to_four(string a){
    string result;
    if(a == "00") result="0";
    else if(a=="01") result="1";
    else if(a=="10") result="2";
    else if(a=="11") result="3";
    return result;
}

string d_to_eight(string a){
    string result;
    if(a == "000") result ="0";
    else if(a == "001") result = "1";
    else if(a == "010") result = "2";
    else if(a == "011") result = "3";
    else if(a == "100") result = "4";
    else if(a == "101") result = "5";
    else if(a == "110") result = "6";
    else if(a == "111") result = "7";
    return result;
}

string d_to_sixteen(string a){
    string result;
    if(a=="0000") result = "0";
    else if(a=="0001") result="1";
    else if(a=="0010") result="2";
    else if(a=="0011") result="3";
    else if(a=="0100") result="4";
    else if(a=="0101") result="5";
    else if(a=="0110") result="6";
    else if(a=="0111") result="7";
    else if(a=="1000") result="8";
    else if(a=="1001") result="9";
    else if(a=="1010") result="A";
    else if(a=="1011") result="B";
    else if(a=="1100") result="C";
    else if(a=="1101") result="D";
    else if(a=="1110") result="E";
    else if(a=="1111") result="F";

    return result;
}
//  二进制转其他
two_shift binary(string a){
    string integer, decimal, quotient, reminder, result;
    two_shift s(integer,integer,integer,integer);
// 小数 部分转换 尚未完成

// 2 to 10
    if(a.find('.')==string::npos) a+='.';
    integer.append(a.begin(), a.begin()+a.find('.'));
    decimal.append(a.begin()+a.find('.')+1,a.end());
    quotient = integer;
//正序
    while(1){
        divide_result cal_result =divide_max_2(quotient, "1010", 0);
        quotient = cal_result.quotient;
        reminder = cal_result.reminder;
        result.append(b_2_d(reminder));
        if(quotient=="0") break;
    }
    std::reverse(result.begin(), result.end());
//    cout << "2 to 10 integer: " <<  result << "\n";
//    整数部分转换结束 下边是小数部分转换 采用乘法
    s.ten =result;
    result+=".";

//   2 to 4
//    逆序求
//    std::reverse(integer.begin(), integer.end());
    quotient = integer;

    result = "";
    reminder = "";
    if(quotient.length()%2) quotient.insert(0, 1, '0');
    for(int i=quotient.length()-1;i>=0;i-=2){
        reminder +=  string(quotient, i-1,2);
        result.append(d_to_four(reminder));
//        result.append(d_to_four(string(quotient.begin()+i-1, quotient.begin()+i)));
        reminder="";
    }
    std::reverse(result.begin(), result.end());
    if(result[0]=='0') result.erase(0, 1);

//    cout << "2 to 4: integer " << result << "\n";
    s.four = result;
//   2 to 8
    result = "";
    reminder = "";
    quotient.insert(0, 3-quotient.length()%3, '0');
    for(int i=quotient.length()-1;i>1; i-=3){
        reminder += string(quotient, i-2, 3);
        result.append(d_to_eight(reminder));
        reminder="";
    }

    std::reverse(result.begin(), result.end());
    if(result[0]=='0') result.erase(0, 1);
    cout << "2 to 8: integer " << result << "\n";
    s.eight = result;

// 2 to 16
    result = "";
    reminder= "";
    quotient.insert(0, 4-quotient.length()%4, '0');
    for(int i=quotient.length()-1; i>2;i-=4 ){
        reminder += string(quotient, i-3, 4);
        result.append(d_to_sixteen(reminder));
        reminder="";
    }
    std::reverse(result.begin(), result.end());
    if(result[0]=='0') result.erase(0, 1);
    cout << "2 to 16: integer " << result << "\n";
    s.sixteen = result;


    return  s;
}


string four_to_binary(string a){
    string result;
    if(a=="0") result="00";
    else if(a=="1") result="01";
    else if(a=="2") result="10";
    else if(a=="3") result="11";

    return result;
}


four_shift four(string a){
    string integer, decimal, quotient, reminder, result;
    four_shift s(integer,integer, integer,integer);

//  4 to 2
    if(a.find('.')==string::npos) a+='.';
    integer.append(a.begin(), a.begin()+a.find('.'));
    decimal.append(a.begin()+a.find('.')+1,a.end());

    string tem = integer;
    for(int i=0; i<tem.length();++i){
        reminder = string(tem, i, 1);
        result += four_to_binary(reminder);
        reminder ="";
    }
    if(result[0]=='0') result.erase(0, 1);
    cout << "4 to 2: integer " << result <<"\n";
    s.two = result;


//    4 to 8
    two_shift s2 = binary(s.two);
    s.eight = s2.eight;

//    4 to 10
    s.ten = s2.ten;
//    4 to 16
    s.sixteen = s2.sixteen;

    return s;
}


string eight_to_binary(string a){
    string result;
    if(a=="0") result="000";
    else if(a=="1") result="001";
    else if(a=="2") result="010";
    else if(a=="3") result="011";
    else if(a=="4") result="100";
    else if(a=="5") result="101";
    else if(a=="6") result="110";
    else if(a=="7") result="111";

    return result;
}

eight_shift eight(string a){
    string integer, decimal, quotient, reminder, result;
    eight_shift s(integer,integer, integer,integer);

//    8 to 2
    if(a.find('.')==string::npos) a+='.';
    integer.append(a.begin(), a.begin()+a.find('.'));
    decimal.append(a.begin()+a.find('.')+1,a.end());

    string tem = integer;
    for(int i=0; i<tem.length();++i){
        reminder = string(tem, i, 1);
        result += eight_to_binary(reminder);
        reminder ="";
    }

    while(result[0]=='0') result.erase(0, 1);
    cout << "8 to 2: integer " << result <<"\n";
    s.two = result;

    //    8 to 4
    two_shift s2 = binary(s.two);
    s.four = s2.four;

//    8 to 10
    s.ten = s2.ten;
//    8 to 16
    s.sixteen = s2.sixteen;

    return s;
}

string sixteen_to_binary(string a){
    string result;
    if(a=="0") result="0000";
    else if(a=="1") result="0001";
    else if(a=="2") result="0010";
    else if(a=="3") result="0011";
    else if(a=="4") result="0100";
    else if(a=="5") result="0101";
    else if(a=="6") result="0110";
    else if(a=="7") result="0111";
    else if(a=="8") result="1000";
    else if(a=="9") result="1001";
    else if(a=="A") result="1010";
    else if(a=="B") result="1011";
    else if(a=="C") result="1100";
    else if(a=="D") result="1101";
    else if(a=="E") result="1110";
    else if(a=="F") result="1111";

    return result;
}

sixteen_shift sixteen(string a){
    string integer, decimal, quotient, reminder, result;
    sixteen_shift s(integer,integer, integer,integer);

//    16 to 2
    if(a.find('.')==string::npos) a+='.';
    integer.append(a.begin(), a.begin()+a.find('.'));
    decimal.append(a.begin()+a.find('.')+1,a.end());

    string tem = integer;
    for(int i=0; i<tem.length();++i){
        reminder = string(tem, i, 1);
        result += sixteen_to_binary(reminder);
        reminder ="";
    }

    while(result[0]=='0') result.erase(0, 1);
    cout << "16 to 2: integer " << result <<"\n";
    s.two = result;

    //    16 to 4
    two_shift s2 = binary(s.two);
    s.four = s2.four;

//    16 to 8
    s.eight = s2.eight;
//    16 to 10
    s.ten = s2.ten;

    return s;
}

ten_shift ten(string a){
    string integer, decimal, quotient, reminder, result;
    ten_shift s(integer,integer, integer,integer);

//    10 to 2
    if(a.find('.')==string::npos) a+='.';
    integer.append(a.begin(), a.begin()+a.find('.'));
    decimal.append(a.begin()+a.find('.')+1,a.end());
    quotient = integer;
    //正序
    while(1){
        divide_result cal_result = divide(quotient, "2", 0);
        quotient = cal_result.quotient;
        reminder = cal_result.reminder;
        result.append(reminder);
        if(quotient=="0") break;
    }
    std::reverse(result.begin(), result.end());
    while(result[0]=='0') result.erase(0, 1);
    s.two = result;
//    cout << "10 to 2: " << result <<"\n";


    //    10 to 4
    two_shift s2 = binary(s.two);
    s.four = s2.four;

//    10 to 8
    s.eight = s2.eight;
//    10 to 16
    s.sixteen = s2.sixteen;

    return s;
}
// 拓展的 x^y 和 log10 x 可以计算带小数点的 总的算法思想是大数变小数
// 考虑到 超过的int 范围的大数 计算幂太大 所以我们可以近似
string x_power_y(string x, string y){
    string integer, decimal, result_integer=x, result_decimal;
    string result;
    if(y=="0") return "1";
    if(y.find('.')!=string::npos){
//        cout << "only can solve when y is integer, then we only take the part of integer\n";
         integer = string(y, 0, y.find('.'));
         decimal = string(y, y.find('.'), (y.length()-y.find('.')));
    }
    else{
        integer = y;
        decimal = "0";
    }
//
    while((integer=subtraction(integer,"1"))!="0"){
        result_integer = multiply(result_integer, x);
    }
//    近似运算 其实在算法有效的数范围内 误差很小 误差一大 本算法也算不出来
    result_decimal = to_string(pow(stod(x),stod(decimal)));
    result = result_integer;
    result = multiply(result_integer, result_decimal);

    return result;
}


string logarithm10(string x){
    string integer, decimal;
    double result_integer, result_decimal;
    double result;
    if(!cmp(x, "0")){
        cout << "x must be bigger than 0 \n";
        return "error\n" ;
    }
    if(x =="1") return "0";

    // 数很小 直接调用函数
    if(x.length()<=4) result = log10(stod(x));
    else{
        if(x.find('.')==string::npos) x+='.';
//    x转为科学计数法 分解x 之所以 没有直接转化为 0.xxxx 形式的数 或 1.xxxx 是因为log函数在10.xxx 斜率更小 这样近似误差更小
// 当然 如果是100.xxxx 效果更好  但是对本算法来说没有必要了
        int num1 = x.find('.');
        x.erase(x.find('.'),1);
        int num2 =0,i =0;
        while(x[i]=='0') ++i;
        if(i > x.length()){
//            小数点越位 后补0
            x+="0.0";
            num1 = num1 -i;
        }
        else{
            ++i;
            if(i>=x.length()) x+=".0";
            else x.insert(i, 1, '.');
            num2 = num1 - i;
        }
        while(x[0]=='0') x.erase(0, 1);
//       计算 10的次数 也就是移位的次数

        result_decimal = log10(stod(x));
        result_integer = num2;
//        考虑到 大数运算后为 10的次数 次数即是位数 可以 在double 范围内运算
        result = result_integer + result_decimal;
    }
    return to_string(result);
}

int menu(){
    string a;
    string b;

    while(1){

        cout << "please enter your want\n";
        cout << "1. plus\n"
             << "2. subtract\n"
             << "3. multiply\n"
             << "4. divide\n"
             << "5. pow(x, 2)\n"
             << "6. pow(x, 3)\n"
             << "7. sin(x)\n"
             << "8. cos(x)\n"
             << "9. log10(x)\n"
             << "10. x^y\n"
             << "11. binary conversion\n"
             << "12. four -in -production conversion\n"
             << "13. Octagonal conversion\n"
             << "14. decimal conversion\n"
             << "15. Hexadecimal conversion\n"
             << "16. exit\n";

        cin>>a;
        if(a=="1"){
            cout << "please enter two number\n";
            cin >> a >> b;
            if(a[0]=='-' && b[0]=='-'){
                string tem1(a.begin()+1, a.end());
                string tem2(b.begin()+1, b.end());
                cout << "-" << add(tem1, tem2) << "\n";
            }
//            一正一负 用减法
            else if(a[0]=='-' && b[0]!='-'){
                int flag;
                string tem1(a.begin()+1, a.end());
                string tem2(b.begin(), b.end());

                if(tem1.find('.')==string::npos){
                    tem1.append(".");
                }
                if(tem2.find('.')==string::npos){
                    tem2.append(".");
                }
//    逆序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());
                int tem1_pot = tem1.find('.');
                int tem2_pot = tem2.find('.');
//  正序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());

                if(tem1_pot > tem2_pot){
                    tem2.append(tem1_pot-tem2_pot, '0');
                }
                else tem1.append(tem2_pot-tem1_pot, '0');

                if(tem1.length() < tem2.length()){
                    tem1.swap(tem2);
                    flag = 1;
                }
                else flag=0;

                if(flag) {
                    cout << subtraction(tem1, tem2) <<"\n";
                }
                else{
                    cout << "-" << subtraction(tem1, tem2) <<"\n";
                }
            }
//            一正 一负用减法
            else if(a[0]!='-' && b[0]=='-'){
                int flag;
                string tem1(a.begin(), a.end());
                string tem2(b.begin()+1, b.end());

                if(tem1.find('.')==string::npos){
                    tem1.append(".");
                }
                if(tem2.find('.')==string::npos){
                    tem2.append(".");
                }
//    逆序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());
                int tem1_pot = tem1.find('.');
                int tem2_pot = tem2.find('.');
//  正序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());

                if(tem1_pot > tem2_pot){
                    tem2.append(tem1_pot-tem2_pot, '0');
                }
                else tem1.append(tem2_pot-tem1_pot, '0');

                if(tem1.length() < tem2.length()){
                    tem1.swap(tem2);
                    flag = 1;
                }
                else flag=0;

                if(flag) {
                    cout << subtraction(tem1, tem2) <<"\n";
                }
                else{
                    cout << "-" << subtraction(tem1, tem2) <<"\n";
                }
            }
//            双正 用加法
            else{
                cout << add(a, b) <<"\n";
            }
        }
//        减法
        else if(a=="2"){
            cout << "please enter two number\n";
            cin >> a >> b;
//            相当于a- b+
            if(a[0]=='-' && b[0]=='-'){
                string tem1(a.begin()+1, a.end());
                string tem2(b.begin()+1, b.end());
                int flag;

                if(tem1.find('.')==string::npos){
                    tem1.append(".");
                }
                if(tem2.find('.')==string::npos){
                    tem2.append(".");
                }
//    逆序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());
                int tem1_pot = tem1.find('.');
                int tem2_pot = tem2.find('.');
//  正序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());

                if(tem1_pot > tem2_pot){
                    tem2.append(tem1_pot-tem2_pot, '0');
                }
                else tem1.append(tem2_pot-tem1_pot, '0');

                if(tem1.length() < tem2.length()){
                    tem1.swap(tem2);
                    flag = 1;
                }
                else flag=0;

                if(flag) {
                    cout << subtraction(tem1, tem2) <<"\n";
                }
                else{
                    cout << "-" << subtraction(tem1, tem2) <<"\n";
                }


            }
//            相当于两负 用加法
            else if(a[0]=='-' && b[0]!='-'){
                string tem1(a.begin()+1, a.end());
                string tem2(b.begin(), b.end());
                cout << "-" << add(tem1, tem2) << "\n";
            }
//相当于两个正
            else if(a[0]!='-' && b[0]=='-'){
                string tem1(a.begin(), a.end());
                string tem2(b.begin()+1, b.end());
                cout << add(tem1, tem2) << "\n";
            }
//        a+ b-
            else {
                int flag;

                string tem1(a.begin(), a.end());
                string tem2(b.begin(), b.end());

                if(tem1.find('.')==string::npos){
                    tem1.append(".");
                }
                if(tem2.find('.')==string::npos){
                    tem2.append(".");
                }
//    逆序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());
                int tem1_pot = tem1.find('.');
                int tem2_pot = tem2.find('.');
//  正序
                std::reverse(tem1.begin(), tem1.end());
                std::reverse(tem2.begin(), tem2.end());

                if(tem1_pot > tem2_pot){
                    tem2.append(tem1_pot-tem2_pot, '0');
                }
                else tem1.append(tem2_pot-tem1_pot, '0');

                if(tem1.length() < tem2.length()){
                    tem1.swap(tem2);
                    flag = 0;
                }
                else flag=1;

                if(flag) {
                    cout << subtraction(tem1, tem2) <<"\n";
                }
                else{
                    cout << "-" << subtraction(tem2, tem1) <<"\n";
                }
            }
        }
//        乘法
        else if(a=="3"){
            cout << "please enter two number\n";
            cin >> a >> b;
            if(a[0]=='-' && b[0]=='-' || a[0]!='-' && b[0]!='-'){
                if(a[0]=='-') a= string(a.begin()+1, a.end());
                if(b[0]=='-') b= string(b.begin()+1, b.end());

                cout << multiply(a, b) << "\n";
            }
            else{
                if(a[0]=='-') a= string(a.begin()+1, a.end());
                if(b[0]=='-') b= string(b.begin()+1, b.end());

                cout << "-" << multiply(a, b) << '\n';
            }
        }
//        除法
        else if(a=="4"){
            cout << "please enter two number\n";
            cin >> a >> b;
            if(b=="0") cout << "b = 0 error\n";
            else{
                cout << "please enter the number of decimal your want\n";
                int num;
                cin >> num;
                if(a[0]=='-' && b[0]=='-' || a[0]!='-' && b[0]!='-'){
                    if(a[0]=='-') a= string(a.begin()+1, a.end());
                    if(b[0]=='-') b= string(b.begin()+1, b.end());

                    cout << divide(a, b, num).quotient_pot  << "\n";
                }
                else{
                    if(a[0]=='-') a= string(a.begin()+1, a.end());
                    if(b[0]=='-') b= string(b.begin()+1, b.end());

                    cout << "-" << divide(a, b, num).quotient_pot << '\n';
                }
            }

        }
        else if(a=="5"){
            cout << "please enter the num\n";
            cin >> a;
            if(a[0]=='-') a= string(a.begin()+1, a.end());
            cout << square_my(a) << "\n";
        }
        else if(a=="6"){
            cout << "please enter the num\n";
            cin >>a;
            if(a[0]=='-'){
                a = string(a.begin()+1, a.end() );
                cout << "-" << third_square_my(a) << '\n';
            }
            else cout << third_square_my(a) << '\n';
        }
        else if(a=="7"){
            cout << "please enter the num\n";
            cin >>a;
//            if(a[0]=='-'){
//                a = string(a.begin()+1, a.end() );
//                cout << "-" << sin_my(a,10) << '\n';
//            }
            cout << sin_my(a, 50) << '\n';
        }
        else if(a=="8"){
            cout << "please enter the num\n";
            cin >>a;
//            if(a[0]=='-'){
//                a = string(a.begin()+1, a.end() );
//                cout << cos_my(a,10) << '\n';
//            }
            cout << cos_my(a, 50) << '\n';
        }
        else if(a=="9"){
            cout << "please enter the num\n";
            cin >>a;
            if(a[0]=='-'){
                cout << "the num must be bigger than 0 error\n";
            }
            else cout << logarithm10(a) << '\n';
        }
        else if(a=="10"){
            cout << "please enter the num x y\n";
            cin >>a >> b;

            cout << x_power_y(a, b) << '\n';
        }
        else if(a=="11"){
            cout << "please enter the num\n";
            cin >>a;
            two_shift s = binary(a);
            cout << " to 4 " << s.four << "\n";
            cout << " to 8 " << s.eight << "\n";
            cout << " to 10 " << s.ten  << "\n";
            cout << " to 16 " << s.sixteen << "\n";
        }
        else if(a=="12"){
            cout << "please enter the num\n";
            cin >>a;
            four_shift s = four(a);
            cout << " to 2 " << s.two << "\n";

            cout << " to 8 " << s.eight << "\n";
            cout << " to 10 " << s.ten  << "\n";
            cout << " to 16 " << s.sixteen << "\n";
        }
        else if(a=="13"){
            cout << "please enter the num\n";
            cin >>a;
            eight_shift s = eight(a);
            cout << " to 2 " << s.two << "\n";
            cout << " to 4 " << s.four << "\n";
//            cout << " to 8 " << s.eight << "\n";
            cout << " to 10 " << s.ten  << "\n";
            cout << " to 16 " << s.sixteen << "\n";
        }
        else if(a=="14"){
            cout << "please enter the num\n";
            cin >>a;
            ten_shift s = ten(a);
            cout << " to 2 " << s.two << "\n";
            cout << " to 4 " << s.four << "\n";
            cout << " to 8 " << s.eight << "\n";
//            cout << " to 10 " << s.ten  << "\n";
            cout << " to 16 " << s.sixteen << "\n";
        }
        else if(a=="15"){
            cout << "please enter the num\n";
            cin >>a;
            sixteen_shift s = sixteen(a);
            cout << " to 2 " << s.two << "\n";
            cout << " to 4 " << s.four << "\n";
            cout << " to 8 " << s.eight << "\n";
            cout << " to 10 " << s.ten  << "\n";
//            cout << " to 16 " << s.sixteen << "\n";
        }
        else if(a=="16"){
            break;
        }
        else{
            cout << "the function number you inputted is error\n";
        }
    }
    return 0;
}
int main() {
// 加减法的符号处理 2022 0708 上午完成
//乘法符号处理 2022 0708 上午完成
//除法的零 完成

    menu();
    return 0;
//    cin >> a  >> b;

//    divide_result  s= divide(a, b , 30);
//    cout << s.quotient << "  " << s.reminder << "  " << s.quotient_pot << "\n";
//    cout << sin_my(a, 30);
//    cout << "\n" << cos_my(a, 30    );

//    system("pause");

//    string tem("0");
//    cin >> a >> b;
//    divide_result result = divide(a, b, 30);
//    cout << result.quotient << " " << result.reminder << " "<< result.quotient_pot << " " << "\n";
////    a.insert(0, 5,'0');
////    cout << a <<"\n";
//    cout << " sin(a)=  " << sin_my(a, 30) << "\n";
//    cout << " cos(a)=  " << cos_my(a, 30) << "\n";
//    cout << " x^2 = " << square_my(a) << "\n";
//    cout << " x^3 = " << third_square_my(a) << "\n" ;

//    cin>> a ;
//    cout << x_power_y(a, b)<< endl;
//    cout << logarithm10(a) <<"\n";

//    cout << divide(a, b, 20).quotient;

//    ten_shift s = ten(a);
//
//    cout << s.two << "  " << s.four << "  " << s.eight << "  " << s.sixteen <<"\n";

    system("pause");
    system("pause");
//    b = string(a.begin(), a.begin()+1);
//    cout << b << "\n";
//    for(int i =0; i<9;++i){
//        tem = add(tem, a);
//    }
//    cout << tem <<"\n"  ;
//    multiply(a, b);

//    cout << (a>b) << "\n";

//    b.append(5, '0');
//    cout << b;

//
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
}
