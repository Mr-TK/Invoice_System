#include<stdio.h>
#include "customer.h"
#include "Savetransc.h"
#include <windows.h>
FILE *fp;

#include "saveinvoice.h"		
	
#define TRUE 1	
#define FALSE 0




void CreateInvoice(){
	char contact[11];
	COORD cordinate;
	int continueList = TRUE;
	item *listOfItem;
	char tmpItemName[20];
	int numOfItems = 1,counter;
	float tmpQnt,tmpPrice,tmpAmount, total = 0, grand_total = 0;
	char save;
		
	printf("\n************************************************************************************************************************");
	printf("\n\t*****************************************    New Invoice    ****************************************************");
	printf("Enter your number: ");
	scanf("%s",contact);
	fp=fopen(contact,"r");
	if(fp != NULL || fp == NULL)
		fp = fopen(contact,"a");
	customer cust = GetCustomer(contact);
	printf ("\n[Enter x to finish the item list]");
	printf ("\n=====================================================================================================");
	cordinate.X = 0;
	cordinate.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	
	printf ("ITEM");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	printf ("QNT");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	printf ("PRICE");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	printf ("AMOUNT");
	cordinate.X = 0;
	cordinate.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);

	printf ("=====================================================================================================");
	cordinate.Y += 1;
	
	listOfItem = (item *) malloc(numOfItems * sizeof(item));
	
	do{
		cordinate.X = 0;
			cordinate.Y += 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			fflush(stdin);
			scanf("%s",tmpItemName);
			if(strcmp(tmpItemName,"x") == 0 ){
				continueList = FALSE;
				break;
			}
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			scanf("%f",&tmpQnt);
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			scanf("%f",&tmpPrice);
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			tmpAmount = tmpQnt * tmpPrice;
			printf ("%0.2f",tmpAmount);
			
			strcpy(listOfItem[numOfItems-1].item,tmpItemName);
			listOfItem[numOfItems-1].qnt = tmpQnt;
			listOfItem[numOfItems-1].price = tmpPrice;
			listOfItem[numOfItems-1].amount = tmpAmount;
			numOfItems++;
			listOfItem = (item *) realloc(listOfItem, numOfItems * sizeof(item));
			total += tmpAmount;
		
		}while(continueList);
			printf ("=====================================================================================================");
			cordinate.X = 72;
			cordinate.Y += 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			grand_total = total;
			printf ("%0.2f",total);

		
		cordinate.X = 1;
		cordinate.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);

		
		
	
		printf("Do you want to save your invoice\n(c)confirm\t\t\t(x)to cancel");
		save = getch();
		if(save == 'c' || save == 'C'){
			
			saveInvoice(listOfItem, grand_total, numOfItems);
			char date[10];
			scanf("%s",date);
			printf("SAVING INVOICE");
			saveTransactoin(contact,date, grand_total);
		}
		else
			printf("OKAY");
		
		
	}

