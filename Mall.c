#include <stdio.h>
void show_bank_balance();
int main(){
    int choice=0;
    printf("Welcome to The Mall\nEnter Your Choice\n1.View Bank Balance\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        show_bank_balance();
        break;
    
    default:
        printf("Wrong choice");
        break;
    }
}