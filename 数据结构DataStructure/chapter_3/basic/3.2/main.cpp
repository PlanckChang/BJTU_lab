#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
struct Stack{
    char  *string;
    int count;
};



void push(Stack&s, char c){
    s.string[s.count]=c;
    s.string[s.count+1]='\0';
    s.count ++;
}
void pop(Stack&s){
    s.string[s.count-1]='\0';
    s.count --;
}
int main() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->count = 0;
    s->string = (char *) malloc(sizeof(char) * MAXSIZE);

    char tem[MAXSIZE];
    int i;
    printf("please enter characters consisting of {} () []\n");
    scanf("%s", &tem);
    while (strlen(tem)>0) {

        if (strlen(tem) % 2 == 1) {
            printf("invalid parentheses\n");
        }
        else{
            for (i = strlen(tem); i > 0; i--) {
                char j = tem[i - 1];
                if (j == '}' || j == ')' || j == ']') {
                    push(*s, j);
                } else {
                    if (s->count == 0) {
                        printf("invalid parentheses\n");
                        break;
                    }
                    else if (j == '{' && s->string[s->count - 1] == '}')
                        pop(*s);
                    else if (j == '(' && s->string[s->count - 1] == ')')
                        pop(*s);
                    else if (j == '[' && s->string[s->count - 1] == ']')
                        pop(*s);
                    else break;
                }

            }
            if (i == 0&&s->count==0) printf("valid parentheses\n");
            else printf("invalid parentheses\n");
        }


        printf("please enter characters consisting of {} () []\n");
        scanf("%s", &tem);
    }

}
