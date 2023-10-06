#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXSIZE 100

char stack[MAXSIZE];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main(){
    char exp[20], soln[20];
    int p=0;
    char *e,x, ch;
    printf("Enter infix expression : ");
    scanf("%s", exp);
    strrev(exp);
    e = exp;
    while(*e != '\0'){
        if(isalnum(*e)){
            soln[p]= *e;
            p++;
            printf("%c ", *e);
        }
        else if (*e == '(')
            push(*e);
        else if (*e == ')'){
            while((x = pop()) != '('){
                printf("%c ",x);
                soln[p]= x;
                p++;
            }
        }
        else{
            while(priority(*e) <= priority(stack[top])){
                ch=pop();
                printf("%c ",ch);
                soln[p]= ch;
                p++;
            }
            push(*e);
        }
        e++;
    }
    while(top != -1){
        ch=pop();
        printf("%c ",ch);
        soln[p]= ch;
        p++;
    }
    printf("\n");
    for(int i=0; i<p; i++) printf("%c ",soln[i]);
    strrev(soln);
    printf("Prefix : %s", soln);
    return 0;
}
