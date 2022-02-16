#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structs by Samarth

/*
    Floors:
        6 floors of mall 
        -2 floor,-1 floor ,0 floor, 1st floor , 2nd floor , 3rd floor -> {"Parking Lot For 4 wheeler","Parking Lot For 2 wheeler","Ground Floor","First Floor","Second Floor","Third Floor"}
        if you have a vehicle,then starting floor would be -1 and then use elevator to navigate to other floors
        else then starting floor would be 0, and then use elevator to navigate to other floors 
       -1-> Parking Ticket module  (Made by Yash) -> 4 wheeler charge = Rs.50 , 2 wheeler charge = Rs. 20
        0-> Grocery Module (Samarth)
        1-> Under Maintenance clothing shops
        2-> Arcade(Yash) ,Food Court(Jessica)
        3-> Cinema (Aaradhya)
        Entire Navigation by Samarth & Yash
*/
//Function 
int getFloorFromParking();
void startParking();
void startArcadeGame();

// Functions By Jessica
int startFoodCourt();

//Functions By Aaradhys
int startCinema();

//function by Samarth
void listGroceryItems();
void showElevator();
void showFloorShops();
void openAdminMenu();
//Global Variables
int cf=0;
char name[]="Inf1n1ty";
char *floors[]={"Parking 2","Parking 1","Ground Floor","First Floor","Second Floor","Third Floor"};

void main()
{
    char vc='N';//Default vehicle choice is N (No)
    printf("Welcome to %s Mall\nAre you on a vehicle(Y/N) : ",name);
    scanf(" %c",&vc);  
    printf("\n");
    if(vc != 'N' && vc != 'n') {
        startParking();
        cf=getFloorFromParking();    
    }
    showElevator();
}
void showFloorShops(){
    switch(cf){
        case -2:
        startParking();
        break;
        case -1:
        startParking();
        break;
        case 0:{
            char ch='N';
            printf("Welcome To Grocery Store\nAre you an admin?(Y/N)");
            scanf("%c",&ch);
            if(ch == 'N' || ch == 'n'){
                listGroceryItems();
            }
            else{
                openAdminMenu();
            }
            break;
        }           
        case 1:
            printf("Shops in this area are under maintenance\n");
            break;
        case 2: {
            int choice=0;
            printf("Where do you want to go \n1.Arcade \n2.Food Court\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                    startArcadeGame();
                break;
                case 2:
                    startFoodCourt();
                break;
                default:
                printf("Wrong Choice\n");
                break;
            }
            break;
        }
        case 3:
            startCinema();
            break;          
    }
}

void showElevator(){
    int input=0;
    printf("What floor do you want to go?\n");
    printf("Available options: \n");
    for(int x=0;x<6;x++){
        printf("%s -> %d\n",floors[x],(x-2));            
    }
    printf("Enter Your Choice: ");
    scanf("\n%d",&input);
    printf("\n");
    cf=input;
    showFloorShops();
}

