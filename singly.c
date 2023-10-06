#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void createlist(int n){
    struct node *newnode, *ptr;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL){
        printf("Unable to allocate memory\n");
        return;
    }

    printf("Enter data in node 1 : ");
    scanf("%d", &head->data);

    head->next = NULL;
    ptr = head;
    for(int i=2; i<=n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode==NULL){
            printf("Unable to allocate memory\n");
            return;
        }

        printf("Enter data in node %d : ",i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        ptr->next = newnode;
        ptr = ptr->next;
    }
}

void traverse(){
    struct node *ptr;
    ptr = head;
    int i=1;
    if(head == NULL){
        printf("List is empty \n");
        return;
    }
    printf("\t\tLinked List \n");
    while(ptr != NULL){
        printf("data in node %d is : %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}

void deletebeg(){
    if(head == NULL)
    {
        printf("List is already empty\n");
        return;
    }
    head = head->next;
    traverse();
}

void delete(int loc){
    struct node *ptr;
    if(head == NULL)
    {
        printf("List is already empty\n");
        return;
    }
    ptr = head;
    while((loc-2)!=NULL){
        ptr = ptr->next;
        loc--;
    }

    ptr->next = ptr->next->next;
    traverse();
}

void deleteend(){
    struct node *ptr, *preptr;
    if(head == NULL)
    {
        printf("List is already empty\n");
        return;
    }
    ptr = head;
    preptr = ptr;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    traverse();
}
int main(){
    int n;
    printf("Enter number of nodes : \n");
    scanf("%d", &n);
    createlist(n);
    traverse();
    int choice;
    printf("Press 1 for deletion at beginning\nPress 2 for deletion at any position\nPress 3 for deletion at end\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            {
                deletebeg();
                break;
             }
        case 2:
            {
                int loc;
                printf("Enter location\n");
                scanf("%d", &loc);
                delete(loc);
                break;
             }
        case 3:
            {
                deleteend();
                break;
            }
        default :
            {
                printf("Invalid input");
                break;
            }
    }
}