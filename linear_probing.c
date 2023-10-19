#include<stdio.h>

int tble[100]={0};

void insert(int value, int size){
    for(int i=0; i<size; i++){
        int idx = (value%size + i)%size;
        if(tble[idx]==0){
            tble[idx] = value;
            break;
        }
    }
}

void delete(int value,int size){
    for(int i=0; i<size; i++){
    int idx = (value%size + i)%size;
        if(tble[idx]==value){
            tble[idx] = 0;
        }
    }
}

void display(int size){
    printf("Key\t\tValue\n");
    for(int i=0; i<size; i++){
        printf("%d\t\t%d\n", i,tble[i]);
    }
}

int main(){
    int n;
    printf("Enter number of keys : ");
    scanf("%d", &n);
    int choice;
    do{
        int data;
        printf("Enter choice :\n1.Insert\n2.Delete\n3.Display\n0.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 0 : 
                printf("Exitting!!");
                break;
            case 1 :
                printf("Enter element to insert : ");
                scanf("%d",&data);
                insert(data,n); 
                break;
            case 2 :
                printf("Enter element to delete : ");
                scanf("%d",&data);
                delete(data, n);
                break;
            case 3 :
                printf("\t\tHash Table\n");
                display(n);
                break;
            default :
                printf("INVALID INPUT!!!!");
        }
    }while(choice!=0);
    return 0;
}