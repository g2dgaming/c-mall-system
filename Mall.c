#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void main()
{
   	char  *str=malloc(10);
	strcat(str,"id: ");
	sprintf(str,"%d",100);
	printf("%s",str);
}
