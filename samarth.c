#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct ItemVariant{
    int parentId, id;
    char variant_name[100];
    double price;
};
struct Item{
    int id;
    double price;
    char name[100];
    char description[256];
    struct ItemVariant variants[4];
};
/*
Functions :
    void show_bank_balance()
*/
void openAdminMenu(){
    printf("Welcome Admin!\nEnter Your Choice\n1.Create a new item\n2.Edit existing item\nEnter -1 to Exit\n");
    int ch=-1;
    do{
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            createItem();            
            break;
        
            default:
            break;
        }
    }while(ch!=-1);
}
void createItem(){
    struct Item item;      
    int id=100; // id that acts as a foreign key in our database file
    printf("Enter Item Details\nName : ");
    gets(item.name);
    printf("\n");
    printf("Description : ");
    gets(item.description);
    printf("\n");
    printf("Price : ₹");
    scanf("%lf",&item.price);
    printf("\n");
    int vc=0;// counts number of variants
    printf("Enter Variants count (if any else 0)");
    scanf("%d",&vc);
    struct ItemVariant variants[vc];
    while(--vc>-1){
        printf("Enter Variant Details\nName : ");
        gets(variants[vc].variant_name);
        printf("Price : ₹");
        scanf("%lf",&variants[vc].price);
        variants[vc].parentId=id;
        variants[vc].id=vc+1; //Variant Id of any given parent is the incremented value of it's index.
        printf("\n");
    }

}
char * convertToString(struct Item item){
    char *ptr=malloc(sizeof(char) * 500); /* size of char is although 1 so,
    malloc will allocate 500 bytes of memory to pointer*/
    itoa(item.id,ptr,10);
}
int saveItem(char data[]){
    int saved=0;
    FILE *ptr ;
	
	// Get the data to be written in file
	
    

	// Open the existing file GfgTest.c using fopen()
	// in write mode using "w" attribute
	ptr = fopen("groceryDatabase.c", "w") ;
	
	// Check if this filePointer is null
	// which maybe if the file does not exist
	if ( ptr == NULL )
	{
		printf( "Database file not found\n" ) ;
	}
	else
	{
		
		printf("The file is now opened.\n") ;
		
		// Write the dataToBeWritten into the file
		if ( strlen ( data ) > 0 )
		{
			
			// writing in the file using fputs()
			fputs(data, ptr) ;
			fputs("\n", ptr) ;
		}
		
		// Closing the file using fclose()
		fclose(ptr) ;
		
		printf("Data successfully written in file GfgTest.c\n");
		printf("The file is now closed.") ;
	}
	return 0;	
    
}
