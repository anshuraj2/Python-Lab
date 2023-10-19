#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*a[100];

void set(int value, int size){
    struct node *newnode,*ptr;
    int idx = value%size;
    if(a[idx]==NULL){
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        a[idx] = newnode;
    }
    else{
        ptr = a[idx];
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        ptr->next = newnode;
    }
}

void delete(int data){
    struct node *ptr, *preptr;
    int idx = data%10;
    ptr = a[idx];
    preptr = ptr;
    while(ptr->data!=data){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
}

void display(int n1){
    struct node *ptr;
    for(int i=0; i<n1; i++){
        ptr = a[i];
        while(ptr!=NULL){
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\\0\n");
    }
}
int main(){
    struct node *ptr;
    int n1;
    printf("Enter number of buckets : ");
    scanf("%d", &n1);
    int choice = -1;
    do{
        int data;
        printf("\nEnter choice \n1.Insertion\n2.Deletion\n3.Display Hash Table\n0.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 0 :
                printf("Exiting!!!");
                break;
            case 1 :
                printf("Enter element to insert : ");
                scanf("%d", &data);
                set(data,n1);
                break;
            case 2 :
                printf("Enter element to delete : ");
                scanf("%d",&data);
                delete(data);
                break;
            case 3 :
                printf("\t\tHASH TABLE\n");
                display(n1);
                break;
            default :
                printf("\t\tINVALID INPUT!!!!\n");
        }
    }while(choice!=0);
    return 0;
}
