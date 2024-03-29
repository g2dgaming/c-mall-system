#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Item{
    int id;
    float price;
    char *name;
    char *description;
}items[100];
const char fileFormat[]="id:%d name:%s description:%s price:%f";
int current_index=-1;
const int MAX_NAME_SIZE=100;
const int MAX_DESCRIPTION_SIZE=100;
void getInput(struct Item *item,int isNew);
char * convertToString();
int saveItem(char *dataToBeWritten);
void load();
void print(struct Item item);
void print_all();
void clear();
void desanatize(char **str);
void sanatize(char **str);
void listGroceryItems();
void openAdminMenu(){
    printf("Welcome Admin!\n");
    int ch=-1;
	load();
    do{
		printf("Enter Your Choice\n1.Create a new item\n2.List Items\nEnter -1 to Exit\n");
        scanf("%d",&ch);
		struct Item item;
        switch (ch)
        {
            case 1:
            getInput(&item,1); //sending 0 because we are creating new item so new id will be required
			char *result=convertToString(item);
			printf("Item is %ssaved\n",saveItem(result)?"":"not ");
			desanatize(&(item.name));
			desanatize(&(item.description));
			items[++current_index]=item;
			break;
			case 2:
			listGroceryItems();			
			break;				
            default:
            break;
        }
    }while(ch!=-1);
}
void listGroceryItems(){
	clear();
	load();
	print_all();
}
void print_all(){
	for(int x=0;x<=current_index;x++){
		printf("Item Number %d\n",x+1);
		print(items[x]);
	}
}
void clear(){
	memset(items, 0, sizeof(struct Item));
}
void print(struct Item item){
	printf("ID: %d\n",item.id);
	printf("Name: %s\n",item.name);
	printf("Description: %s\n",item.description);
	printf("Price: %f\n",item.price);
}
void sanatize(char **str){
	int size=strlen(*str);
	char *ptr=malloc(1000);
	for(int x=0;x<size;x++)
	{
		ptr[x]=(*str)[x]==' '?'_':(*str)[x];
	}
	*str=ptr;
}
void desanatize(char **str){
	int size=strlen(*str);
	char *ptr=malloc(1000);
	for(int x=0;x<size;x++)
	{
		ptr[x]=(*str)[x]=='_'?' ':(*str)[x];
	}
	*str=ptr;
}
void load(){
		int index=0;
		FILE *pointer; //Reading from file 
		pointer=fopen("groceryDatabase","r");
		int ch=0;
		while(ch != EOF){
			items[index].name=malloc(sizeof(char) * MAX_NAME_SIZE);
			items[index].description=malloc(sizeof(char) * MAX_DESCRIPTION_SIZE);
			fscanf(pointer,fileFormat,&items[index].id,items[index].name,items[index].description,&items[index].price);
			desanatize(&items[index].name);
			desanatize(&(items[index].description));	
			ch=getc(pointer);
			index++;
		}
		if(index>0){
			current_index=index-2;
		}
		
}
void getInput(struct Item *item,int isNew){
	if(isNew){
		item->id=current_index+2; // id that acts as a foreign key in our database file
	}
    printf("Enter Item Details\nName : ");
	item->name=malloc(sizeof(char) * MAX_NAME_SIZE);
	item->description=malloc(sizeof(char) * MAX_DESCRIPTION_SIZE);	
	char *empty="";
    gets(item->name);
	strcpy(item->name,"");
	gets(item->name);
	sanatize(&item->name);
    printf("\n");
	printf("Description : ");
    gets(item->description);
	sanatize(&item->description);
    printf("\n");
	printf("Price : Rs.");	
	scanf("%f",&item->price);
    printf("\n");
	

}
char * convertToString(struct Item item){
	char *ptr=malloc(sizeof(char) * 500); /* size of char is although 1 so,
	malloc will allocate 500 bytes of memory to pointer*/
	//Adding id to string
	strcpy(ptr,""); /*Removing all existing characters from 
	string to avoid any unnecessary characters*/
	char *idptr=malloc(sizeof(int) * 4);//allocating 16 bytes of memory to pointer
	sprintf(idptr,"%d",item.id);
	strcat(ptr,"id:");
	strcat(ptr,idptr);
	strcat(ptr," name:");
	strcat(ptr,item.name);
	strcat(ptr," description:");
	strcat(ptr,item.description);
	char *priceptr=malloc(sizeof(double) * 10);//allocating  memory to price pointer
	strcat(ptr," price:");
	sprintf(priceptr,"%f",item.price);
	strcat(ptr,priceptr);
	return ptr; 
}
int saveItem(char *data){
    int saved=0;
    FILE *ptr ;
	ptr = fopen("groceryDatabase", "ab+") ;
	if ( ptr == NULL )
	{
		printf( "Database file not found\n" ) ;
	}
	else
	{		
		if ( strlen ( data ) > 0 )
		{			
			// writing in the file using fputs()
			fputs(data, ptr) ;
			fputs("\n", ptr) ;
			saved=1;
		}		
		// Closing the file using fclose()
		fclose(ptr) ;
	}
	return saved;	    
}