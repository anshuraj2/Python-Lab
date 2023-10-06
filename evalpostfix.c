#include<stdio.h>

int stack[100];
int top = -1; 

/*void pushch(char x){
    stack[++top] = x;
}*/

void pushint(int x){
    stack[++top] = x;
}

int pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int main(){
    char exp[20];
    printf("Enter postfix expression : ");
    scanf("%[^\n]s", exp);
    char *e;
    e = exp;
    while (*e != '\0') {
        if (*e >= '0' && *e <= '9') { // Fix: Comparison with character '0' and '9'
            pushint(*e - '0'); // Convert character to integer
        } else {
            int a = pop();
            int b = pop();
            int res;
            if (*e == '+')   res = b + a;
            if (*e == '-')   res = b - a; // Fix: Correct order of subtraction
            if (*e == '*')   res = a * b;
            if (*e == '/')   res = b / a; // Fix: Correct order of division
            pushint(res);
        }
        e++;
    }
    printf("%d\n", pop());
    return 0;
}
