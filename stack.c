#include<stdio.h>
#include<stdlib.h>

#define N 1000

int top = -1;
int stack[N];

void push(){
    int data;
    if( top == N-1){
        printf("Overflow!!!");
        return;
    }
    printf("Enter elements to push onto Stack\n");
    scanf("%d", &data);
    stack[top] = data;
    top++;
}

void pop(){
    if(top == NULL){
        printf("Underflow\n");
        return;
    }
    else{
        printf("Popped element : %d", stack[top]);
        top--;
    }
}

int main(){
    int choice=5;
    printf("\t!!!PRESS!!!\n");
    while(choice!=0){
    printf("1.Push\n2.Pop\n3.Display\n0.Exit\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1 :{
            push();
            break;
        }
        case 2 :{
            pop();
            break;
        }
        case 3 :{
            while(top!=-1){
                printf("%d\n", stack[top]);
                top--;
            }
        }
        default :
            break;
    }
    }
    while(top!=-1){
                printf("%d\n", stack[top]);
                top--;
    }
    return 0;
}