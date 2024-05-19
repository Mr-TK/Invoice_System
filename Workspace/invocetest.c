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
	//char contact[10];
	char tmpItemName[20];
	int numOfItems = 1,counter;
	float tmpQnt,tmpPrice,tmpAmount, total = 0, grand_total = 0;
	char save;
		
	printf("\n************************************************************************************************************************");
	printf("\n\t*****************************************    New Invoice    ****************************************************");
	printf("Enter your number: ");
	scanf("%s",contact);
	fp = fopen(contact,"w");
	customer cust = GetCustomer(contact);
	printf ("\n[Enter x to finish the item list]");
	printf ("\n=====================================================================================================");
	cordinate.X = 0;
	cordinate.Y = 13;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	
	printf ("ITEM");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	//fprintf(fp,"ITEM");
	printf ("QNT");
	//fprintf(fp,"\t\tQNT");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	printf ("PRICE");
	printf("%d",ftell(fp));
	//fprintf(fp,"\t\t\tPRICE");
	cordinate.X += 24;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
	printf("%d",ftell(fp));
	printf ("AMOUNT");
	//fprintf(fp,"\t\tAMOUNT\n");
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
	//		fprintf(fp,"%s\t\t\t",tmpItemName);
			if(strcmp(tmpItemName,"x") == 0 ){
				continueList = FALSE;
				break;
			}
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			scanf("%f",&tmpQnt);
	//		fprintf(fp,"%0.2f\t\t\t",tmpQnt);
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			scanf("%f",&tmpPrice);
	//		fprintf(fp,"%0.2f\t\t",tmpPrice);
			
			cordinate.X += 24;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordinate);
			tmpAmount = tmpQnt * tmpPrice;
			printf ("%0.2f",tmpAmount);
	//		fprintf(fp,"%0.2f\n",tmpAmount);
			
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
	//	printf ("CONFIRM (C)               CANCEL(X) ",total);
		
		
	
		//saveCustomer();
		save = getch();
		if(save == 'c' || save == 'C'){
			saveInvoice(listOfItem, grand_total, numOfItems);
			//Temp code TODO
			char date[10] = "date";
			scanf("%s",date);
			saveTransactoin(contact, date, grand_total);
		}
		
		
	}
	int main(){
		CreateInvoice();
	
	}
