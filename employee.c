#include<stdio.h>
#include<string.h>
#include<limits.h>
struct employee{
    char name[15];
    int EmpID, Exp, Salary;
};

void bubblesort(struct employee arr[],int n){
    int min = INT_MAX;
    for(int i=0; i<n-1; i++){
        struct employee temp;
        for(int j=0; j<n-1; j++){
            if(arr[j].Exp > arr[j+1].Exp){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionsort(struct employee arr[], int n){
    int min = INT_MAX,minidx = -1;
    struct employee temp;
    for(int i=0; i<n-1; i++){
        min = INT_MAX;
        for(int j=i+1; j<n; j++)
        {
            if(min > arr[j].Salary)
            {
                min = arr[j].Salary;
                minidx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
}

void insertionsort(struct employee arr[], int n){
    struct employee temp;
    int i,j;
    for(int i=1; i<n; i++){
        j=i;
        while(arr[j].EmpID < arr[j-1].EmpID){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int linearsearch(struct employee arr[], int n){
    int max = -1,maxidx = -1;
    for(int i=0; i<n; i++){
        if(arr[i].Salary > max){
            max = arr[i].Salary;
            maxidx = i;
        }
    }
    return maxidx;
}

int main(){    
    int n;
    struct employee Employee[50];
    printf("Enter number of Employees\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nEnter details of Employee %d : \n",i+1);
        printf("Name : ");
        scanf("%s", Employee[i].name);
        printf("EmpID : ");
        scanf("%d", &Employee[i].EmpID);
        printf("Exp : ");
        scanf("%d", &Employee[i].Exp);
        printf("Salary : ");
        scanf("%d", &Employee[i].Salary);
    }
    printf("Employee Ledger sorted by Exp :\n");
    bubblesort(Employee,n);
    for(int i=0; i<n; i++){
        printf("Name : %s\t\tEmpId : %d\t\tExp : %d\t\tSalary : %d\n\n", Employee[i].name, Employee[i].EmpID, Employee[i].Exp, Employee[i].Salary);    
    }
    printf("\n\nEmployee Ledger Sorted by Salary\n");
    selectionsort(Employee,n);
    for(int i=0; i<n; i++)
        printf("Name : %s\t\tEmpId : %d\t\tExp : %d\t\tSalary : %d\n\n", Employee[i].name, Employee[i].EmpID, Employee[i].Exp, Employee[i].Salary);
    printf("\n\nEmployee Ledger Sorted by EmpID\n");
    insertionsort(Employee,n);
    for(int i=0; i<n; i++)
        printf("Name : %s\t\tEmpId : %d\t\tExp : %d\t\tSalary : %d\n\n", Employee[i].name, Employee[i].EmpID, Employee[i].Exp, Employee[i].Salary);
    int maxidx = linearsearch(Employee , n);
    for(int i=0; i<n; i++)
        printf("\nEmployee with Max Salaery\n");
        printf("Name : %s\t\tEmpId : %d\t\tExp : %d\t\tSalary : %d\n\n", Employee[maxidx].name, Employee[maxidx].EmpID, Employee[maxidx].Exp, Employee[maxidx].Salary);
    return 0;
    }
