#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void create(int n){
    struct node *newnode, *ptr;
    int data;
    
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Error!!!");
        return;
    }

    printf("Enter data in node 1 : ");
    scanf("%d",&head->data);

    ptr = head;
    for(int i=2; i<=n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL){
            printf("Error!!");
            return ;
        }

        printf("Enter data in node %d : ",i);
        scanf("%d", &newnode->data);

        newnode->next = head;
        ptr->next = newnode;
        ptr = ptr->next;
        ptr = newnode;
    }
    ptr->next = head;
}

void traverse(){
    struct node *ptr;
    ptr = head;
    int flag=0;
    int i=1;
    if(head == NULL){
        printf("List is empty \n");
        return;
    }
    printf("\t\tLinked List \n");
    while(ptr != head || flag==0){
        flag=1;
        printf("data in node %d is : %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}

int main(){
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    create(n);
    traverse();
    return 0;
}