#include <stdio.h>
#include <string.h>

void show_bank_balance();
/*int main(){
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
}*/

void append(char **source,char **addition){
    char **ptr1=source;
    while(**addition != '\0'){
        char *address=*source;
        address=address+1;
        (*addition)++;
    }
}
void main()
{
    char *ptr="Hello";
    char *ptr2=" World";
    append(&ptr,&ptr2);
    printf("%s",ptr);
}
/*char * convertToString(){
    int n;
    scanf("%d",&n);
    char *ptr=malloc(sizeof(char) * 500); /* size of char is although 1 so,
    malloc will allocate 500 bytes of memory to pointer*//*
    itoa(n,ptr,10);
}*/
