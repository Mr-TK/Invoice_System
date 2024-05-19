/*
Objective: This is a Invoice maintanace system.
Created By: Code
Crreated On: 2022/04/11
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "invocet.c"
#include "GetInvce.c"
#define TRUE 1
#define FALSE 0

int main(){
	
	char ch,password[10],pass[10]="Tk2022";
	int choice1,choice2;
	int i,flag=TRUE;
	//system("color 4B");
	do{
		system("cls");
		//colour(4,8);
		printf("\n************************************************************************************************************************");
		printf("\n*****************************************    WELCOME TO SHOPLINE    ****************************************************");
		printf("\n\t                               YOU ARE LUCKY TO BE SHOPPING HERE");
		printf("\n\n\n\t\t\t\t\t\n\t****************************");
	    printf("\n\tPlease Select an Option: ");
	    printf("\n\t****************************");
		printf("\n\t01. New Invoice");
		printf("\n\t02. Get Customer Detail");
		printf("\n\t03. Get Invoice");
		printf("\n\t04. Get Transactions");
		printf("\n\t05. EXIT");
		printf("\n\n\t");
	
	
		printf("Please Enter an Option: ");
		scanf("%d",&choice1);
	
		system("cls");
		switch(choice1){
			case 1:
			//	system("color 2A"); 
				CreateInvoice();
				getch();
		      	break;
			case 2:
				printf("02. Get Customer Detail");
				getch();
		      	break;
			case 3:
				printf("03. Get Invoice");
				GetInvoice();
				getch();
		      	break;
		    case 4:
				printf("04. Get Transactions");
				getch();
		      	break;
		    case 5:
				printf("\n\tThank you");
				flag = FALSE;
				getch();
		      	break;
			default:
				printf("\tInvalid input");
				getch();
				break;
				
	    }
    }while(flag);
}

