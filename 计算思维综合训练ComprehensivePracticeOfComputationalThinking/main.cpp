
// By Planck Chang

//#include <stdio.h>

// 1
//int main() {
//    long long int a, b;
//    while(scanf("%lld%lld", &a, &b) != EOF)
//    {
//        printf("%lld\n", (long long)(a+b));
//    }
//}

//2
//#include <stdio.h>
//int main(){
//    int n, a, b;
//    scanf("%d", &n);
//    for(int i= 0 ; i<n; ++i){
//        scanf("%d%d", &a, &b);
//        printf("%d\n", a+b);
//    }
//}

//3
//#include <stdio.h>
//int main(){
//    long long int a, b;
//    scanf("%lld%lld",&a, &b);
//    while(a!=0 || b!=0){
//        printf("%lld\n", a+b);
//        scanf("%lld%lld",&a, &b);
//    }
//}

//4
//#include <stdio.h>
//int main(){
//    int n;
//    long long int a, sum=0;
//    scanf("%d", &n);
//    while(n){
//        sum =0;
//        for(int i=0; i<n; ++i){
//            scanf("%lld", &a);
//            sum +=a;
//        }
//        printf("%lld\n", sum);
//        scanf("%d", &n);
//    }
//}

//5
//#include <stdio.h>
//int main(){
//    int n, m;
//    long long int a, sum;
//    scanf("%d", &n);
//    for(int i=0; i<n; ++i){
//        sum = 0;
//        scanf("%d", &m);
//        for(int j=0; j<m; ++j){
//            scanf("%lld", &a);
//            sum += a;
//        }
//        printf("%lld\n", sum);
//    }
//}


//6
//#include <stdio.h>
//int main() {
//    long long int a, sum = 0;
//    scanf("%lld", &a);
//    while (a != 0) {
//        while (1) {
//            sum += a;
//            if (getchar() == '\n') {
//                printf("%lld\n", sum);
//                sum = 0;
//                break;
//            }
//            scanf("%lld", &a);
//        }
//        scanf("%lld", &a);
//    }
//}

//7
//#include <stdio.h>
//int main() {
//    long long int a, b;
//    while (scanf("%lld%lld", &a, &b) != EOF) {
//        printf("%lld\n", a + b);
//        while(scanf("%lld%lld", &a, &b) !=EOF){
//            printf("\n");
//            printf("%lld\n", a + b);
//        }
//    }
//}

//8
//#include <stdio.h>
//int main(){
//    int n,m;
//    long long int a, sum=0;
//    scanf("%d", &n);
//    for(int i = 0; i<n; ++i){
//        scanf("%d", &m);
//        for(int j=0; j<m; ++j){
//            scanf("%lld", &a);
//            sum += a;
//        }
//        printf("%lld\n" , sum);
//        sum = 0;
//        if(i < n-1)
//            printf("\n");
//    }
//}

//9
//#include <stdio.h>
//int main(){
//    int n, max, min, tem;
//    scanf("%d", &n);
//    scanf("%d%d", &max, &min);
//    if(max < min) {
//        tem = max;
//        max = min;
//        min = tem;
//    }
//    for(int i=0; i<n-2; ++i){
//        scanf("%d", &tem);
//        if(tem>max) max = tem;
//        else if(tem < min) min = tem;
//    }
//    int result = max -min;
//    if(result <0) result = - result;
//    printf("%d\n", result);
//}

//10

// V1
//#include <stdio.h>


// __int 128 special io function like scan & print
//void scan(__int128 &x)
//{
//    x = 0;
//    int f = 1;
//    char ch;
//    if((ch = getchar()) == '-') f = -f;
//    else x = x*10 + ch-'0';
//    while((ch = getchar()) >= '0' && ch <= '9')
//        x = x*10 + ch-'0';
//    x *= f;
//}
//void print(__int128 x)
//{
//    if(x < 0)
//    {
//        x = -x;
//        putchar('-');
//    }
//    if(x > 9) print(x/10);
//    putchar(x%10 + '0');
//}
//struct comp{
//    long double data;
//    int x;
//    int y;
//};
//int main(){
//    int n;
//    struct comp tem;
//    scanf("%d", &n);
//    struct comp array[n];
//    struct comp minus[n - 1];
//    for(int i=0; i<n; ++i){
//        scanf("%Lf", &array[i].data);
//        array[i].x = i + 1;
//    }
//    for(int i =0; i<n-1; ++i){
//        for(int j=0; j < n-i-1; ++j){
//            if(array[j].data < array[j+1].data){
//                tem = array[j+1];
//                array[j+1] = array[j];
//                array[j] = tem;
//            }
//        }
//    }
//    for(int i=0; i< n-1; ++i){
//        minus[i].data = array[i].data - array[i+1].data;
//        if(minus[i].data<0) minus[i].data = -minus[i].data;
//        minus[i].x = array[i].x;
//        minus[i].y = array[i+1].x;
//    }
//    for(int i=0; i<n-2; ++i){
//        for(int j = 0; j<n-i-2; j++){
//            if(minus[j].data > minus[j+1].data){
//                tem = minus[j];
//                minus[j] = minus[j+1];
//                minus[j+1] = tem;
//            }
//        }
//    }
//    printf("%.Lf", minus[0].data);
//    if(minus[0].x < minus[0].y) printf( " %d %d\n", minus[0].x, minus[0].y);
//    else printf(" %d %d\n", minus[0].y, minus[0].x);
//}

//V2
//#include <stdio.h>
//struct comp{
//    long long data;
//    int x;
//    int y;
//};
//int main(){
//    int n;
//    struct comp tem;
//    scanf("%d", &n);
//    struct comp array[n];
//    struct comp minus[n - 1];
//    for(int i=0; i<n; ++i){
//        scanf("%lld", &array[i].data);
//        array[i].x = i + 1;
//    }
//    for(int i =0; i<n-1; ++i){
//        for(int j=0; j < n-i-1; ++j){
//            if(array[j].data < array[j+1].data){
//                tem = array[j+1];
//                array[j+1] = array[j];
//                array[j] = tem;
//            }
//        }
//    }
//    for(int i=0; i< n-1; ++i){
//        minus[i].data = array[i].data - array[i+1].data;
//        if(minus[i].data<0) minus[i].data = -minus[i].data;
//        minus[i].x = array[i].x;
//        minus[i].y = array[i+1].x;
//    }
//    for(int i=0; i<n-2; ++i){
//        for(int j = 0; j<n-i-2; j++){
//            if(minus[j].data > minus[j+1].data){
//                tem = minus[j];
//                minus[j] = minus[j+1];
//                minus[j+1] = tem;
//            }
//        }
//    }
//    printf("%lld", minus[0].data);
//    if(minus[0].x < minus[0].y) printf( " %d %d\n", minus[0].x, minus[0].y);
//    else printf(" %d %d\n", minus[0].y, minus[0].x);
//}


//11
//#include <stdio.h>
//int main(){
//    int sum = 0,a;
//    while(1){
//        scanf("%x", &a);
//        sum += a;
//        if(getchar()== '\n') break;
//    }
//    printf("%d\n", sum);
//}


//12
//#include <stdio.h>
//int main(){
//    int year, month, day ;
//    while(scanf("%d-%d-%d\n", &year, &month, &day) != EOF){
//        printf("%02d/%02d/%04d\n", month, day, year);
//        }
//    }

//13
//#include <stdio.h>
//#include <stdlib.h>
//int cmp(const void *a, const void *b){
//    return (*(int*)b - *(int *)a);
//}
//int main(){
//    int cha1[26]={0}, cha2[26]={0}, tem;
//    while((tem=getchar())!='\n'){
//        cha1[tem - 'A'] ++;
//    }
//    while((tem = getchar())!='\n'){
//        cha2[tem - 'A'] ++;
//    }
//    qsort(cha1, 26, sizeof(int), cmp);
//    qsort(cha2, 26, sizeof(int), cmp);
//    for (int i = 0; i<26; ++i){
//        if(cha1[i] != cha2[i]){
//            printf("NO\n");
//            return 0;
//        }
//    }
//    printf("YES\n");
//}

//14
//#include <stdio.h>
//#include <stdlib.h>
//int cmp(const void *a, const void *b){
//    return *(int *)a - *(int *)b;
//}
//int main(){
//    int n, m, tem, count = 0;
//    while(scanf("%d%d", &n,  &m) != EOF){
//        int a[n];
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &a[i]);
//        }
//        qsort(a, n, sizeof (int), cmp);
//        printf("Case #%d:\n", ++count);
//        for (int i = 0; i < m; ++i) {
//            scanf("%d", &tem);
//            for (int j = 0; j < n; ++j) {
//                if(tem==a[j]){
//                    printf("%d found at %d\n", tem, j+1);
//                    break;
//                }
//                else if(tem> a[j]) continue;
//                else{
//                    printf("%d not found\n", tem);
//                    break;
//                }
//            }
//        }
//    }
//}


//15
//#include <stdio.h>
//#include <stdlib.h>
//int cmp(const void *a, const void *b){
//    return *(int *)b - *(int *)a;
//}
//int main(){
//    int n;
//    scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//    }
//    qsort(a, n, sizeof (int ), cmp);
//    printf("%d", a[0]);
//    for(int i = 1; i < n; ++i) {
//        if(a[i] == a[i-1]) continue;
//        printf(" %d", a[i]);
//    }
//    printf("\n");
//}

//16
//#include <stdio.h>
//#include <stdlib.h>
//struct conpon{
//    int data, loc;
//};
//int cmp(const void *a, const void *b){
//    return (*(conpon *)b).data -  (*(conpon *)a).data;
//}
//int main(){
//    conpon ch1[26], ch2[26];
//    for (int i = 0; i <26; ++i) {
//        ch1[i].loc = ch2[i].loc = i;
//        ch1[i].data = ch2[i].data =0;
//    }
//    int tem;
//    while((tem = getchar()) !='\n'){
//        ch1[tem-'A'].data ++;
//    }
//    while ((tem = getchar()) != '\n'){
//        ch2[tem - 'A'].data ++;
//    }
//    qsort(ch1, 26,sizeof (conpon) , cmp);
//    qsort(ch2, 26, sizeof (conpon), cmp);
//
//    for (int i = 0; i < 26; ++i) {
//        if(ch1[i].data != ch2[i].data){
//            printf("NO\n");
//            return 0;
//        }
//    }
//    printf("YES\n");
//    for (int i = 0; i < 26; ++i) {
//        printf("%c->%c", (ch1[i].loc + 'A'), (ch2[i].loc+'A'));
//        if(ch1[i+1].data == 0) {printf("\n");break;}
//        else printf(" ");
//    }
//}

//17
// v1 just finish one part that sum the positive number, fail to negative

//#include <stdio.h>
//#include <string.h>
//char* reverse(char* s)
//{
//    int len = 0;
//    char* p = s;
//    while (*p != 0) {
//        len++;
//        p++;
//    }
//    int i = 0; char c;
//    while (i <= len / 2 - 1){
//        c = *(s + i);
//        *(s + i) = *(s + len - 1 - i);
//        *(s + len - 1 - i) = c;
//        i++;
//    }
//    return s;
//}
//int main(){
//    char num1[1005];
//    char num2[1005];
//    while(scanf("%s%s", num1, num2) != EOF){
//        char ans[1005];
//        int tem = 0, count = 0, sum, flag1, flag2;
//        if(num1[0] == '-') flag1 = -1;
//        else flag1 = 1;
//        if(num2[0] == '-') flag1 = -1;
//        else flag1 = 1;
//        reverse(num1);
//        reverse(num2);
//        int len1 = strlen(num1);
//        int len2 = strlen(num2);
//        if(len1 < len2){
//            tem = len2;
//            len2 = len1;
//            len1 = tem;
//        }
//        tem = 0;
//        while(count < len1){
//            if(count < len2){
//                sum = (num2[count]-'0') + (num1[count]-'0') +tem;
//                ans[count] = sum%10 + '0';
//                tem = sum/10;
//            }
//            else{
//                if(strlen(num1) > strlen(num2)){
//                    sum = (num1[count] - '0') +tem;
//                }
//                else sum = (num2[count] - '0') +tem;
//                ans[count] = sum%10+ '0';
//                tem = sum/10;
//            }
//            count++;
//        }
//        printf("%s\n", reverse(ans));
//    }
//}

//v2
//#include  <stdio.h>
//#include <string.h>
//#include <algorithm>
//struct bigNum{
//    char s[1005];
//    int num[1005]={0};
//    int flag;
//};
//
//void pre_operate(bigNum &a){
//    int len = strlen(a.s);
//    int m;
//    if(a.s[0] == '-'){ a.flag=-1; m =0;}
//    else{ a.flag = 1; m = -1;}
//    for (int i = len-1, j=0; i >m ; --i, ++j){
//        a.num[j] = a.s[i] - '0';
//    }
//}
//void sum_bigNum(bigNum &a, bigNum &b, bigNum &ans){
//    int len1 = strlen(a.s);
//    int len2 = strlen(b.s);
//    int result, carry=0;
//    if(a.s[0] == '-') len1--;
//    if (b.s[0] == '-') len2--;
//    int max_ = std::max(len1 , len2);
//    for(int i = 0; i<= max_; ++i) {
//        result = a.num[i] + b.num[i] + carry;
//        ans.num[i] = result % 10;
//        carry = result / 10;
//    }
//    if(ans.num[max_]!=0){
//        for (int i = max_; i >= 0; --i) {
//            printf("%c", ans.num[i]+'0');
//        }
//    }
//    else{
//        for (int i = max_-1; i >=0; --i) {
//            printf("%c", ans.num[i]+'0');
//        }
//    }
//    printf("\n");
//}
//void minus_biNum(bigNum &a, bigNum &b, bigNum &ans){
//    int len1 = strlen(a.s);
//    int len2 = strlen(b.s);
//    int result, carry=0;
//    if(a.s[0] == '-') len1--;
//    if (b.s[0] == '-') len2--;
//    int max_ = std::max(len1 , len2);
//    for (int i = 0; i <max_; ++i) {
//        result = a.num[i] - b.num[i] -carry;
//        if(result < 0) {
//            ans.num[i] = (10+result);
//            carry = 1;
//        }
//        else {ans.num[i] = result; carry=0;}
//    }
//    ans.flag =1;
//    for (int i = max_-1; i >=0; --i) {
//        if(ans.num[i]!=0 && i!=0){
//            printf("%c", ans.num[i]+'0');
//            ans.flag = 0;
//        }
//        else if(ans.num[i]==0 && i!=0 && ans.flag==1) continue;
//        else printf("%c", ans.num[i]+'0');
//    }
//    printf("\n");
//}
//int main(){
//    bigNum a, b, ans;
//    while(scanf("%s%s", a.s, b.s)!=EOF){
//        pre_operate(a);
//        pre_operate(b);
//        if(a.flag==1&&b.flag==1){
//            sum_bigNum(a, b, ans);
//        }
//        else if(a.flag == -1 && b.flag==-1){
//            printf("-");
//            sum_bigNum(a, b, ans);
//        }
//        else{
//            int len1= strlen(a.s);
//            int len2 = strlen(b.s);
//            int tem;
//            if(a.s[0]=='-'){ len1--; tem =1;}
//            else if(b.s[0]=='-'){ len2--; tem = 2;}
//            if(len1 > len2){
//                if(a.flag==-1) printf("-");
//                minus_biNum(a, b, ans);
//            }
//            else if(len2 > len1){
//                if(b.flag ==-1) printf("-");
//                minus_biNum(b, a, ans);
//            }
//            else{
//                if(tem ==1){
//                    if(strcmp(&a.s[1], b.s)>0){
//                        printf("-");
//                        minus_biNum(a, b, ans);
//                    }
//                    else if(strcmp(&a.s[1], b.s)<0){
//                        minus_biNum(b, a, ans);
//                    }
//                    else printf("0\n");
//                }
//                else{
//                    if(strcmp(a.s, &b.s[1])>0){
//                        minus_biNum(a, b, ans);
//                    }
//                    else if(strcmp(a.s, &b.s[1])<0){
//                        printf("-");
//                        minus_biNum(b, a, ans);
//                    }
//                    else printf("0\n");
//                }
//            }
//        }// remake the value. by the way, auto remake's situation is the same as before
//        for (int i = 0; i < 1005; ++i) {
//            a.s[i] = b.s[i] = '\0'; a.num[i] = b.num[i] = 0;
//        }
//    }
//}

//18
//#include <stdio.h>
//#include <stdlib.h>
//struct mystruct{
//    int data, x;
//};
//int cmp(const void *a, const void *b){
//    return (*(mystruct*)a).data - (*(mystruct*)b).data;
//}
//int main(){
//    int case_ = 1;
//    int n,m;
//    while(scanf("%d%d", &n, &m)!=EOF){
//        mystruct a[n];
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &a[i].data);
//            a[i].x = i+1;
//        }
//        qsort(a, n, sizeof(mystruct), cmp);
//        int tem;
//        printf("Case #%d:\n", case_++);
//        for (int i = 0; i < m; ++i) {
//            scanf("%d",&tem);
//            for (int j = 0; j < n; ++j) {
//                if(tem>a[j].data){
//                    if(j!=n-1) continue;
//                    else {printf("%d not found\n", tem); break;}
//                }
//                else if(tem == a[j].data) {
//                    printf("%d from %d to %d\n", tem, a[j].x, j+1);
//                    break;
//                }
//                else {printf("%d not found\n", tem); break;}
//            }
//        }
//    }
//}

//19
//#include <stdio.h>
//#include <string.h>
//struct mystruct{
//    int data[25];
//    int pop;
//};
//int mv_on(mystruct *x, int array_a, int array_b, int column_a, int column_b){
//    int tem, a= x[array_a].data[column_a];
//    for (int i = x[array_a].pop-1; i>column_a; --i, --x[array_a].pop){
//        tem = x[array_a].data[i];
//        x[tem].data[x[tem].pop] = tem;
//        ++ x[tem].pop;
//    }
//    for (int i = x[array_b].pop-1; i > column_b; --i, --x[array_b].pop) {
//        tem = x[array_b].data[i];
//        x[tem].data[x[tem].pop] =tem;
//        ++ x[tem].pop;
//    }
//    x[array_b].data[x[array_b].pop++] = a;
//    x[array_a].pop--;
//}
//int mv_ov(mystruct *x, int array_a, int array_b, int column_a, int column_b){
//    int tem, a= x[array_a].data[column_a];
//    for (int i = x[array_a].pop-1; i>column_a; --i, --x[array_a].pop){
//        tem = x[array_a].data[i];
//        x[tem].data[x[tem].pop] = tem;
//        ++ x[tem].pop;
//    }
//    x[array_b].data[x[array_b].pop++] = a;
//    x[array_a].pop--;
//}
//int st_on(mystruct *x, int array_a, int array_b, int column_a, int column_b){
//    int tem;
//    for (int i = x[array_b].pop-1; i > column_b; --i, --x[array_b].pop) {
//        tem = x[array_b].data[i];
//        x[tem].data[x[tem].pop] =tem;
//        ++ x[tem].pop;
//    }
//    for (int i = column_a; i < x[array_a].pop; ++i) {
//        x[array_b].data[x[array_b].pop++] = x[array_a].data[i];
//    }
//    x[array_a].pop = column_a;
//}
//int st_ov(mystruct *x, int array_a, int array_b, int column_a, int column_b){
//    for (int i = column_a; i < x[array_a].pop; ++i) {
//        x[array_b].data[x[array_b].pop++] = x[array_a].data[i];
//    }
//    x[array_a].pop = column_a;
//}
//int xh_an(mystruct *x, int array_a, int array_b, int column_a, int column_b){
//    mystruct tem = x[array_a];
//    x[array_a] = x[array_b];
//    x[array_b] = tem;
//}
//void output(mystruct *x, int n){
//    for (int i = 0; i < n; ++i) {
//        printf("%d:", i);
//        for (int j = 0; j < x[i].pop; ++j) {
//            printf(" %d", x[i].data[j]);
//        }
//        printf("\n");
//    }
//}
//
//int main(){
//    int a, b, array_a, array_b, column_a, column_b;
//    char order1[5], order2[5];
//    mystruct stack[30];
//    for (int i = 0; i < 30; ++i) {
//        stack[i].pop=1;
//        stack[i].data[0] = i;
//    }
//    int n;
//    scanf("%d", &n);
//    while(scanf("%s %d %s %d", &order1, &a, &order2, &b)==4){
//        if(a == b) continue;
//        for (int i = 0,flag1 =0, flag2 = 0; i < n; ++i) {
//            for (int j = 0; j < stack[i].pop; ++j) {
//                if(a==stack[i].data[j]){
//                    array_a = i;
//                    column_a = j;
//                    flag1 =1;
//                }
//                if(b==stack[i].data[j]){
//                    array_b = i;
//                    column_b = j;
//                    flag2 = 1;
//                }
//                if(flag2 && flag1) break;
//            }
//            if(flag2 && flag1) break;
//        }
//        if(array_b == array_a) continue;
//
//        if(!strcmp(order1, "mv")){
//            if(!strcmp(order2, "on")) mv_on(stack, array_a, array_b, column_a, column_b);
//            else mv_ov(stack, array_a, array_b, column_a, column_b);
//        }
//        else if(!strcmp(order1, "st")){
//            if(!strcmp(order2, "on")) st_on(stack, array_a, array_b, column_a, column_b);
//            else st_ov(stack, array_a, array_b, column_a, column_b);
//        }
//        else xh_an(stack, array_a, array_b, column_a, column_b);
//    }
//    output(stack, n);
//}

//20
//#include <stdio.h>
//int main(){
//    int count=1, n;
//    long long int tem=1;
//    while(scanf("%d", &n)!=EOF){
//        if(n==1) printf("1\n");
//        else {
//            while(count < n){
//                if(tem%3==0 || tem%2==0 ||tem%5==0){
//                    count++;
//                }
//                tem ++;
//            }
//            printf("%lld\n", tem-1);
//        }
//    }
//}
//
//#include <iostream>
//#include <set>
//#include <algorithm>
//#include  <vector>
//using namespace std;
//int main(){
//    set<long long> ugly_num{1, 2, 3, 5};
//    int tem[3]{2, 3, 5};
//    auto i = ++ugly_num.begin();
//    while(ugly_num.size()!=15000){
//        for (int j = 0; j < 3; ++j) {
//            ugly_num.emplace(*i * tem[j]);
//        }
//        ++i;
//    }
//    vector<long long> ugly(ugly_num.begin(), ugly_num.end());
//    int num;
//    ugly[9927]= 260287060820889600;
//    while(scanf("%d",&num)!=EOF){
//        cout << ugly[num-1] << endl;
//    }
//}
//


//#include <vector>
//#include <iostream>
//using namespace std;
//int main(){
//    vector<long long> ugly{1};
//    ugly.reserve(12000);
//    long long num=2;
//    while(ugly.size()!=10001){
//        if(num%2==0 || num%3==0 || num%5==0){
//            ugly.emplace_back(num);
//        }
//        ++num;
//    }
//    while (scanf("%d",&num)!=EOF){
//        cout << ugly[num-1] << endl;
//    }
//}


//#include <iostream>
//#include <set>
//#include <algorithm>
//#include  <vector>
//using namespace std;
//int main(){
//    set<long long> ugly_num{1, 2, 3, 5};
//    int tem[3]{2, 3, 5};
//    auto i = ++ugly_num.begin();
//    while(ugly_num.size()!=11000){ // get more data to make the lasted num min
//        for (int j = 0; j < 3; ++j) {
//            ugly_num.emplace(*i * tem[j]);
//        }
//        ++i;
//    }
//    vector<long long> ugly(ugly_num.begin(), ugly_num.end());
//    int num;
////    ugly[9927]= 260287060820889600;
//    while(scanf("%d",&num)!=EOF){
//        cout << ugly[num-1] << endl;
//    }
//}

//21
//#include <string>
//#include <iostream>
//#include <algorithm>
//#include <stdlib.h>
//#include <string.h>
//using namespace std;
// struct Special_word{
//    string data;
//    string des_string;
//    char str[40];
//    int alphabet[26];
//    int number[10];
//    int flag = 0;
//};
//int divide_word(Special_word &word){
//    int upper[26]={0};
//    int lower[26]={0};
//    word.flag =0;
//    for (int i = 0; i < word.data.length(); ++i) {
//        if(word.data[i]<='Z' && word.data[i]>='A'){
//            word.alphabet[word.data[i]-'A']++;
//        }
//        else if(word.data[i]>='a' && word.data[i]<='z'){
//            word.alphabet[word.data[i]-'a']++;
//        }
//        else if(word.data[i]>='0' && word.data[i] <='9'){
//            word.number[word.data[i]-'0']++;
//        }
//    }
//    for (int i = 0; i < 26; ++i) {
//        word.alphabet[i] = upper[i] + lower[i];
//    }
//}
//int judge_word(Special_word *word, int size, Special_word *des){
//    int tag=0;
//    int desindex=0;
//    for (int i = 0; i < size; ++i) {
//        if(!word[i].flag){
//            for (int j = i+1; j < size; ++j) {
//                if(word[i].data == word[j].data) continue;
//                for (int k = 0; k < 26; ++k) {
//                    if(word[i].alphabet[k] != word[j].alphabet[k])
//                    {
//                        tag=1;
//                        break;
//                    }
//                }
//                if(tag==1) continue;
//                for (int k = 0; k < 10; ++k) {
//                    if(word[i].number[k] != word[j].number[k])
//                        tag =1;
//                        break;
//                }
//                if(tag==1) continue;
//                des[desindex++] = word[i];
//                word[j].flag=1;
//            }
//        }
//    }
//    return desindex;
//}
//bool cmp(const Special_word &a, const Special_word &b){
//    return a.des_string < b.des_string;
//}
//int main(){
//    int num=100, index=0;
//    int desindex;
//    Special_word word[num], des[num];
//    while(scanf("%s", &word[index++].data)!=EOF){
//        for (int i = 0; i < index; ++i) {
//            divide_word(word[i] );
//        }
//        desindex = judge_word(word, index, des);
//        for (int i = 0; i < desindex; ++i) {
//            for (int j = 0; j < des[i].data.size(); ++j) {
//                if(des[i].data[j]<='Z' && des[i].data[j] >='A') des[i].des_string[j] = des[i].data[j]-'A'+'a';
//                else  des[i].data[j] = des[i].data[j];
//            }
//        }
//        vector<Special_word> finally9(100);
//        for (int i = 0; i < desindex; ++i) {
//            finally9.emplace_back(des[i]);
//        }
//        sort(finally9.begin(), finally9.end(), cmp);
//        for (int i = 0; i < desindex; ++i) {
//            cout << finally9[i].data << endl;
//        }
//    }
//}

//#include <algorithm>
//#include <map>
//#include <string>
//#include <iostream>
//#include <cctype>
//using namespace std;
//class special_word{
//public:
//    string data;
//    string all_lower;
//    int alphabet[26]{0};
//    int number[10]{0};
//    int flag{0};
//};
//int main(){
//    string tem;
//    int index = 0;
//    special_word word[500];
//    map<string, string> output;
//    while (1){
//        cin>> tem;
//        if(tem == "#") break;
//        word[index].data = tem;
//        transform(tem.begin(), tem.end(), tem.begin(), ::tolower);
//        word[index].all_lower = tem;
//        for (int i = 0; i < tem.size(); ++i) {
//            if(tem[i]<='z' && tem[i]>='a') word[index].alphabet[tem[i]-'a']++;
//            if(tem[i]>='0' && tem[i]<='9') word[index].number[tem[i]-'0']++;
//        }
//        index++;
//    }
//    for (int i = 0; i < index; ++i) {
//        for (int j = i+1; j < index; ++j) {
//            if(word[i].flag) continue;
//            if(word[i].data == word[j].data) continue;
//            int tag = 0;
//            for (int k = 0; k < 26; ++k) {
//                if (word[i].alphabet[k]!=word[j].alphabet[k]) {tag=1;break;}
//            }
//            if(tag) continue;
//            for (int k = 0; k <10; ++k) {
//                if(word[i].number[k]!=word[j].number[k]){tag=1; break;}
//            }
//            if(tag) continue;
//            output.emplace(word[i].data, word[i].data);
//            word[j].flag=1;
//        }
//    }
//    for (auto &i:output) {
//        cout << i.second << endl;
//    }
//}



//22
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main(){
//    int num, length;
//    while (scanf("%d%d", &num, &length)!=EOF){
//        for (int i = 0; i < length; ++i) {
//            cout << '-';
//        }
//        cout << endl;
//        vector<string> filename(num);
//        for (int i = 0; i < num; ++i) {
//            cin >> filename[i];
//        }
//        vector<int> column_length;
//        for(auto &i : filename){
//            column_length.emplace_back(i.size());
//        }
//        sort(column_length.begin(), column_length.end(), greater<int>());
//        int column_max = *column_length.data();
//        int col_len = floor(((length+2)/(2+column_max))); // one row elements
//        int m = ceil((double)num/col_len); // row number  first shift type then to ceil, int/int = int
//        int left_col = num%col_len; // the last row's elements
//        string matrix[m];
//        sort(filename.begin(), filename.end());
//        auto name = filename.begin();
//        // we also can compute the formula of the location then not need the actual matrix
//        for (int i = 0; i < left_col; ++i) {
//            for (int j = 0; j < m; ++j) {
//                matrix[j].append(name->c_str());
//                for (int k = 0; k < column_max - name->size(); ++k) {
//                    matrix[j].append(" ");
//                }
//                matrix[j].append("  ");
//                name++;
//            }
//        }
//        for(int i = 0; i< col_len-left_col;++i){
//            for (int j = 0; j < ((left_col==0) ? m: m-1); ++j) {
//                matrix[j].append(name->c_str());
//                for (int k = 0; k < column_max - name->size(); ++k) {
//                    matrix[j].append(" ");
//                }
//                matrix[j].append("  ");
//                name++;
//            }
//        }
//        for (int i = 0; i < m; ++i) {
//            while(1){ // the string.back()'s return is char, so ' ' but not " "
//                if(matrix[i].back()==' ') matrix[i].erase(matrix[i].size()-1);
//                else break;
//            }
//            cout << matrix[i] << endl;
//        }
//    }
//}

////23
//#include <iostream>
//#include <list>
//#include <queue>
//#include <string>
//#include <vector>
//using namespace std;
//class name_and_groupnum{
//public:
//    string name;
//    int group_num;
//    name_and_groupnum(){};
//    name_and_groupnum(string Name, int Group_num):name(Name), group_num(Group_num){};
//};
//int main(){
//    int count = 0;int group_num, member_num;int nobody= 99999;   // the initial location of int nobody should be front
//    while(cin >> group_num){
//        if(group_num==0) break;
//        cout << "Case #" << ++count << ":" << endl;
//    list<queue<name_and_groupnum>> data;
//    string ini_str, in_instr;
//    string instructor[4]{"enqueue", "deqteam", "dequeue", "stop"};
//    vector<vector<name_and_groupnum>> source_data(group_num);
//    for (int i = 0; i < group_num; ++i) {
//        cin >> member_num;
//    for (int j = 0; j < member_num; ++j) {
//        cin >> ini_str;
//        name_and_groupnum tem(ini_str, i);
//        source_data[i].emplace_back(tem);
//    }
//}
//    while(1){
//        cin >> in_instr;
//        int num_of_instr;
//        for (num_of_instr = 0; num_of_instr < 4; ++num_of_instr) {
//            if(in_instr == instructor[num_of_instr]) break;
//        }
//        if(num_of_instr==3) break;
//        else if(num_of_instr==0){  // cout << "enqueue" << endl;
//            cin >> ini_str; name_and_groupnum tem(ini_str, nobody--);
//            for(int i =0; i<source_data.size(); ++i){
//                for (int j = 0; j < source_data[i].size(); ++j) {
//                    if(ini_str == source_data[i][j].name){
//                            tem = source_data[i][j];
//                    }
//                }
//            }
//            int flag=0;
//            for (auto &i:data) {
//                if(tem.group_num == i.front().group_num){
//                    i.emplace(tem);
//                    flag=1;
//                    break;
//                }
//            }
//            if (!flag){
//                queue<name_and_groupnum> ini_queue;
//                ini_queue.emplace(tem);
//                data.emplace_back(ini_queue);
//            }
//        }
//        else if(num_of_instr==2){ //cout << "dequeue" << endl;
//            if(data.size()==0) continue;
//            auto item = data.front();
//            if( item.size()>0){
//                cout << item.front().name << endl;
//                data.front().pop();
//            }
//            if(data.front().size()==0) {data.pop_front();}
//        }
//        else if(num_of_instr==1){ //cout << "deqteam" << endl;
//            cin >> ini_str;
//            name_and_groupnum tem(ini_str, nobody--);
//            for(int i =0; i<source_data.size(); ++i){
//                for (int j = 0; j < source_data[i].size(); ++j) {
//                    if(ini_str == source_data[i][j].name){
//                        tem = source_data[i][j]; break;
//                    }
//                }// this can be optimized
//            }
//            for (auto item= data.begin(); item!=data.end();++item) {
//                if(item->front().group_num == tem.group_num){
//                    cout << item->front().name;
//                    item->pop();
//                    int size = item->size();
//                    for (int i = 0; i <size; i++) {
//                        cout << " " << item->front().name;
//                        item->pop();
//                    }
//                    cout << endl;
//                    data.erase(item);
//                    break;
//                }
//                else if(item->front().name == ini_str) {
//                    cout<< ini_str << endl;
//                    data.erase(item);
//                    break;
//                }
//            }
//        }
//    }
//}}


////////
//24  has not been done / done / finally the input string be a null then be outputted
//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool cmp(const pair<string, int>&x, const pair<string, int>&y){
//    if(x.second > y.second) return true;
//    else if(x.second == y.second){
//        if(x.first < y.first) return true;
//        else return false;
//    }
//    else return false;
//}
//int main() {
//    string s_tem;
//    vector<pair<string, int >> data;
//    while(cin>> s_tem){
//        for (int i = 0; i < (int)s_tem.length(); ++i) {
//            if((s_tem[i]<='z'&&s_tem[i]>='a')||(s_tem[i]<='Z'&&s_tem[i]>='A')){
//                if(s_tem[i] <='Z' && s_tem[i]>='A') s_tem[i] = s_tem[i]-'A' + 'a';
//            }
//            else if(s_tem[i]=='\''&&s_tem[i+1]=='s' && i!=0 && i+1==s_tem.length()-1){s_tem.replace(i,2,""); i--;}
//            else{ s_tem.replace(i,1, ""); i--;};  //&& i!=0 &&(i+1)==(s_tem.size()-1)
//        }
////        if(s_tem=="") continue;
//        int flag=0;
//        for(auto&item:data){
//            if(item.first == s_tem){
//                flag =1;
//                ++item.second;
//                break;
//            }
//        }
//        if(!flag) data.emplace_back(pair<string, int>(s_tem, 1));
//        if(s_tem=="end") break;
//    }
//    sort(data.begin(), data.end(), cmp);
//    for(auto&item:data) cout << item.first << endl;
//}
//    map<string, int> data;
//    vector<string> output[source.size()];
//    for(auto&item : source){
//        string tem = item;
//        if(data.count(tem)) {
//            data.at(tem)++;
//        }
//        else {
//            data.emplace(tem, 0);
//        }
//    }
//    int max = 0;
//    for(auto&item1: data){
//        output[item1.second].push_back(item1.first);
//        if(item1.second> max) max = item1.second;
//    }
//    for(auto &item: output){
//        sort(item.begin(), item.end());
//    }
//    for(int i= max; i>=0; i--){
//        for(auto&item:output[i]){
//            if(item.empty()) continue;
//            cout << item <<endl;
//        }
//    }


////25
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main() {
//    int count = 0;
//    int x, n;
//    while (cin >> x >> n) {
//        if(x==-1) break;
//        int flag=0;
//        cout << "Case " << ++count << ":" << endl;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = i; j <= n; ++j) {
//                for (int k = j; k <= n; ++k) {
//                    for(int l= k+1; l<=n; ++l){
//                        int res = pow(i, x) + pow(j, x) + pow(k, x);
//                        int res2 = pow(l, x);
//                        if(res== res2) {printf("%d^%d+%d^%d+%d^%d=%d^%d\n", i, x, j, x, k, x, l, x);flag =1;}
//                        else if(res < res2) break;
//                    }
//                    }
//                }
//            }
//        if(!flag) cout << "No such numbers." << endl;
//    }
//}


//28
//#include <iostream>
//#include<string>
//#include <vector>
//using namespace std;
//int main(){
//    int count =0;
//    int N;
//    int i, j, k, l, m;
////    FILE *fp = fopen("data1.txt","w");
//    while(cin >> N){
////    for(N=2;N<=78;++N){
//        int flag1 = 1;
////        vector<pair<string, string>> data;
//        cout << "Case " << ++count << ":" << endl;
////        string tem = "Case " + to_string(count) +"\n";
////        fprintf(fp, tem.c_str());
//        for ( i = 5; i >=0 ; --i) {
//            for( j =9; j>=0; --j){
//                if(i==j) continue;
//                for( k=9; k>=0; --k){
//                    if(k==i || k==j) continue;
//                    for( l=9;l>=0; --l){
//                        if(l==k||l==i||l==j) continue;
//                        for ( m = 9; m >=0; --m){
//                            if(m==l||m==k||m==i||m==j) continue;
//                            int denominator = m*1+l*10+k*100+j*1000+i*10000;
//                            int numerator = denominator*N;
//                            string s_numerator = to_string(numerator);
//                            if(s_numerator.size()>5) continue;
//                            while(s_numerator.size()<5) s_numerator.insert(0, "0");
//                            int flag2 =0 ;
//                            for(int it=0;it<5;++it) {
//                                int tem = (char )(s_numerator[it]) - '0';
//                                if (tem == i || tem == j || tem == k || tem == l || tem == m) {
//                                    flag2 = 1;
//                                    break;
//                                }
//                                for (int n = it + 1; n < 5; ++n)
//                                    if (s_numerator[it] == s_numerator[n]) {
//                                        flag2 = 1;
//                                        break;
//                                    }
//                            }
//                            if(flag2) continue;
//                            flag1 =0;
//                            string s_denominator = to_string(i)+to_string(j)+to_string(k)+ to_string(l)+to_string(m);
////                            data.emplace_back(pair<string, string>(s_numerator, s_denominator));
//                            cout << "    " <<  s_numerator << "/" << s_denominator << "=" << N << endl;
//                            }
//                        }
//                    }
//                }
//            }
//        for(auto item: data){
//            string tem = item.first + "  " + item.second +"\n";
//            fprintf(fp, tem.c_str() );
//        }
//        if(flag1) cout << "    " << "No such numbers" << endl;
//    }
//}

//#include <string>
//#include <iostream>
//using namespace std;
//int main(){
//    string tem = "12345";
//    for(auto item:tem){
//        cout << atoi(&item) << endl; // if uses 'auto&item' atoi(&item), then gain the address the whole num
                // if non_& then copy one char of tem, output one bit number
//    }
//}


// by A Giant Guy
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<set>
//using namespace std;
//bool ispart(int x,int y)
//{
//    bool flag = true;
//    set<int> se;
//    if (x < 9999 || y < 9999)
//    {
//        se.insert(0);
//    }
//    while (x)
//    {
//        se.insert(x % 10);
//        x = x / 10;
//    }
//    while (y)
//    {
//        se.insert(y % 10);
//        y = y / 10;
//    }
//    for (int i = 0;i <= 9;++i)
//    {
//        if (!se.count(i))
//        {
//            flag = false;
//            break;
//        }
//    }
//    return flag;
//}
//int main()
//{
//    int n;int k = 1;
////    while (cin >> n)
//for(n= 2; n<=78; ++n)
//    {
//        vector<pair<string, string>> data;
//        FILE *fp = fopen("data2.txt" , "w");
//        cout << "Case " << k << ":" << endl;
//        fprintf(fp, string("Case " + to_string(k)).c_str());
//        k++;
//        const int min = 2 * 1234;
//        const int max = 98765;
//        int i;
//        bool flag = false;
//        for (i = max/n; n * i >=min;--i)
//        {
//            if (ispart(n * i, i))
//            {
//                flag = true;
//                if (n * i > 9999 && i > 9999)
//                {
//                    cout << " "<<n * i << "/" << i << "=" << n << endl;
//                }
//                else if (n * i > 9999 && i < 9999)
//                {
//                    cout <<" "<< n * i << "/" << 0 << i << "=" << n << endl;
//                }
//                else if (n * i < 9999 && i > 9999)
//                {
//                    cout <<" "<< 0 << n * i << "/" << i << "=" << n << endl;
//                }
//            }
//        }
//        if (!flag)
//            cout << " No such numbers" << endl;
//    }
//    return 0;
//}


//#include <string>
//#include <iostream>
//using namespace std;
//int main  (){
//    string tem = "123566777";
//    for(auto &item: tem){
//
//        cout << atoi(&item) << endl;
//    }
//}

//29 has 7 WAs 5-5,then turn the ans type into long long int and pass
//#include <vector>
//#include <iostream>
//#include <algorithm>
//struct result{
//    long long ans;
//    int first, last;
//};
//bool cmp(const result a, const result b){
//    if(a.ans > b.ans) return true;
//    else if(a.ans < b.ans) return false;
//    else{
//        int delta1 = a.last - a.first;
//        int delta2 = b.last - b.first;
//        if(delta1 < delta2) return true;
//        else if(delta2 < delta1) return false;
//        else{
//            if(a.first < b.first) return true;
//            else if(a.first > b.first) return false;
//        }
//    }
//}
//using namespace std;
//int main(){
//    int count = 0;
//    int num;
//    while (cin >> num){
//        cout << "Case " << ++count << ": ";
//        vector<int> data;
//        vector<result> output;
//        data.emplace_back(num);
//        if(getchar()!='\n'){
//            while (cin>>num){
//                data.emplace_back(num);
//                if(getchar()=='\n') break;
////                if(getchar()=='e') break;
//            }
//        }
//        long long ans, first1, last1, max;
//        for(int i=0; i<data.size(); ++i){
//            max = data[i];
//            ans = max;
//            first1 = i;
//            last1 = i;
//            for (int j = i+1; j < data.size(); ++j) {
//                ans *= data[j];
//                if(ans >max){
//                    max = ans;
//                    last1 = j;
//                }
//                if(ans==0) break;
//            }
//            result tem;
//            tem.ans = max; tem.first = first1; tem.last = last1;
//            output.emplace_back(tem);
//        }
//        std::sort(output.begin(), output.end(), cmp);
//        cout << output.begin()->ans << " " << output.front().first << "-" << output.front().last << endl;
//    }
//}


//31 6-2
//#include <string>
//#include <iostream>
//using namespace std;
//int main(){
//    string a, b, c;
//    int count=0;
//    while(cin >> a >> c){
//        int flag=0;
//        cout << "Case " << ++count << ": ";
//        for(int i=0; i<c.size(); ++i){
//            if(b.size()>0){
//                if(b.back()==c[i]) {b.erase(b.size()-1); continue;}
//            }
//            if(a.size()>0){
//                while (a[0]!=c[i]){
//                    b.push_back(a[0]);
//                    a.erase(0,1);
//                    if(!a.size()) {flag=1; break;}
//                }
//                a.erase(0,1); continue;
//            }
//            flag=1; break;
//        }
//        if(!flag) cout << "Yes" << endl;
//        else cout << "No" << endl;
//    }
//}


//int main(){
//    string a, b;
//    cin >> a;
//    cout << a[0] << endl;
////    b.append(a.begin(), a.begin()+1);
//    b.push_back(a[0]);
//    cout << b<< endl;
//}

//32 6-3
//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//    string s;
//    int num;
//    cin >> s;int count =0;
//    while(cin >> num){
//        cout << "Case " << ++count << ":\n";
//        for(int i=1;i<=num;++i){
//            string tem = s;
//            int j;
//            for(j=0;j<i;++j){
//                cout << tem[j];
//            }
//            while(j+num<tem.size()){
//                cout << " ";
//                for(int k=0; k<num;++k){
//                    cout << tem[j+k];
//                }
//                j+=num;
//            }
//            cout << " ";
//            for(int k=j;k<tem.size();++k){
//                cout  << tem[k];
//            }
//            cout << endl;
//        }
//    }
//}

//5-2
//#include <iostream>
//#include <algorithm>
//struct Data{
//    int t, b;
//};
//int cmp(const void *a, const void *b){
//    if(((Data*)a)->t >= ((Data*)b)->t) return 0;
//    else return 1;
//}
//using namespace std;
//int main(){
//    int count=0, d;
//    Data data[4];
//    while(cin>>data[0].t>>data[1].t>>data[2].t>>data[3].t>>
//        data[0].b>>data[1].b>>data[2].b>>data[3].b>>d){
//        cout << "Case " << ++count << ": " ;
//        int flag=0;
//        long long res = 1, final = data[0].t * data[1].t * data[2].t * data[3].t + 365;
//        for(res = d+1;res<=final;++res){
//            if((res-data[0].b)%data[0].t==0 && (res-data[1].b)%data[1].t==0 && (res-data[2].b)%data[2].t==0&&
//                    (res-data[3].b )%data[3].t==0){
//                cout << res-d << endl;
//                flag=1;
//                break;
//            }
//        }
//        if(!flag){
//        cout << "No such days." << endl;
//}}}

//5-3 elevator
//#include <iostream>
//#include <vector>
//#include <map>
//#include <set>
//using namespace std;
//int main(){
//    int count=0, n2, u, d, s, n;
//    while(cin>>n2>>u>>d>>s){
//        n= n2;
//        cout << "Case "<< ++count << ": ";
//        set<int> up_set, down_set;
//        map<int,int> up, down;
//        int from, to, down_times=0, up_times=0;
//        while(1){
//            cin>>from;
//            getchar();
//            cin>>to;
//            if(from>to){
//                if(down.count(from)){
//                    if(to<down[from]){
//                        down[from] = to;
//                    }
//                }
//                else down.emplace(from, to);
//                down_set.emplace(from);
//                down_set.emplace(to);
//            }
//            else{
//                if(up.count(from)){
//                    if(to>up[from]){
//                        up[from] = to;
//                    }
//                }
//                else up.emplace(from,to);
//                up_set.emplace(from);
//                up_set.emplace(to);
//            }
//            if(getchar()=='\n') break;
//        }
//        int min_down=201;
//        for(auto item:down){// to find the min of down
//            if(item.first<=n&&item.second<min_down) min_down= item.second;
//        }
//        int result=0;
//        if(min_down<n){
//            down_times+=n-min_down;n=min_down;
//            if(down[min_down]==n2) result-=s;
//        }
//        if(up.begin()->first<n){
//            down_times+=n-up.begin()->first;
//        }
//        else if(up.begin()->first==n) result-=s;
//        else{
//            up_times+=up.begin()->first-n;
//        }
//        n= up.begin()->first;
//        int up_max = up.begin()->first;
//        for(auto item:up){
//            if(item.second>up_max) up_max=item.second;
//        }
//        up_times+=up_max-n;//up to max
//        n=up_max;
//        int tem= down.rbegin()->first; // down max
//        if(tem>n) up_times+=tem-n;
//        else if (tem=n) result-=s;
//        else down_times+=n-tem;
//        n=tem;
//        for(auto item:down){
//            if(item.first>n2&&item.second<tem) tem=item.second;
//        }
//        down_times += n-tem;
//        result += u*up_times + d*down_times + s*(up_set.size()+down_set.size());
//
//        n = n2; up_times=down_times =0;int result2 =result; result=0;
//        tem=0;
//        for(auto item:up){
//            if(item.first>=n&&item.second>tem) tem=item.second;
//        }
//        if(!tem){
//            up_times += tem-n; n=tem;
//        }// turn around
//        tem = down.rbegin()->first;
//        if(tem>n) {
//            up_times = tem-n;
//            n=tem;
//        }
//        else if(tem==n) result-=s;
//        else{
//            down_times+=n-tem;
//            n=tem;
//        }
//        for(auto item:down){
//            if(item.second<tem) tem=item.second;
//        }
//        down_times+=n-tem;
//        n=tem;//turn around
//        tem= up.begin()->first;
//        if(tem>n){
//            up_times=tem-n;
//        }
//        else if(tem==n) result-=s;
//        else{
//            down_times+=n-tem;
//            n=tem;
//        }
//        for(auto item:up){
//            if(item.first<n2 && item.second>tem){
//                tem= item.second;
//            }
//        }
//        up_times+=tem-n;
//        n=tem;
//        result+=up_times*u +down_times*d+s*(up_set.size()+down_set.size());
//        if(result2>result) cout << result<< endl;
//        else cout << result2 << endl;
//    }
//}

//using namespace std;
//int main(){
//    map<int,int> tem;
//    tem.emplace(1, 1);
//    cout << tem[1] << endl;
//    tem[1]=2;
//    cout << tem[1] << endl;
//}


//6-1
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//vector <int>var(26,0);
//int lock; // the flag of locked or not
//vector<int> execute_list;
//vector<int> wait;
//vector<vector<string >> prom;
//int t[7]; // the time each order cost
//int n, Q;
//int judge(string &s){
//    char tem = s[2];
//    if(tem=='=') return 0;
//    else if(tem=='+') return 1;
//    else if(tem=='-') return 2;
//    else if(tem=='i') return 3; // print
//    else if(tem=='c') return 4; // lock
//    else if(tem=='l') return 5; // unlock
//    else if(tem=='d') return 6; // end
//}
//int exe_fun(){int time=0;
//    while(1){
//    vector<string> &order_vector = prom[execute_list[0]];
//    string &order_str = order_vector[0];
//    int order = judge(order_str);
//        if(order==0){
//            if(order_str[4]<='z' &&order_str[4]>='a')
//                var[order_str[0]-'a'] = var[order_str[4]-'a'];
//            else
//                var[order_str[0]-'a'] = atoi(&order_str[4]);
//        }
//        else if(order==1){
//            if(order_str[5]<='z' &&order_str[5]>='a')
//                var[order_str[0]-'a'] += var[order_str[5]-'a'];
//            else
//                var[order_str[0]-'a'] += atoi(&order_str[5]);
//        }
//        else if(order==2){
//            if(order_str[5]<='z' &&order_str[5]>='a')
//                var[order_str[0]-'a'] -= var[order_str[5]-'a'];
//            else
//                var[order_str[0]-'a'] -= atoi(&order_str[5]);
//        }
//        else if(order==3)
//            cout << execute_list[0]+1 << ": " << var[order_str[6]-'a'] << endl;
//        else if(order==4){
//            if(lock){
//                wait.emplace_back(execute_list[0]);
//                execute_list.erase(execute_list.begin());
//                time=0;
//                continue;
//            }
//            lock = 1;}
//        else if(order==5){
//            lock =0;
//            if(wait.size()>0){
//                execute_list.insert(execute_list.begin()+1,wait[0]);
//                wait.erase(wait.begin());
//            }}
//        else if(order==6){
//            execute_list.erase(execute_list.begin());
//            if(execute_list.empty()) return 0;
//            time=0;
//            continue;
//        }
//    time += t[order];
//        prom[execute_list[0]].erase(prom[execute_list[0]].begin());
//    if(time >= Q){
//        execute_list.emplace_back(execute_list[0]);
//        execute_list.erase(execute_list.begin());
//        time =0;
//        continue;
//    }
//    }
//}
//int main(){
//    cin >> n;
//    for(int i=0;i<7;++i) cin >> t[i]; // time for each order; num of prom from 1 to n, index form 0
//    cin >> Q;   //input info
//    // input prom
//    cin.get();
//    for(int i=0;i<n;++i){
//        string tem;
//        vector<string> tem_vector;
//        while(1){
//            getline(cin,tem);
//            tem_vector.push_back(tem);
//            if(tem=="end") break;
//        }
//        prom.emplace_back(tem_vector);
//    }
//    // set execution
//
//    for(int i=0; i<n;++i){
//        execute_list.emplace_back(i);
//    }
//    exe_fun();
//}

//int main(){
//    string tem = "    219a";
//    cout << atoi(&tem[4]) ;
//}

// 2022年4月17日22:50:02 done
#include <iostream>
