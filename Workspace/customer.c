#include<stdio.h>
#include<string.h>
typedef struct Customer
{
	char contact[11];
	char name[20];
	char city[10];
	char street[10];
}customer;
int flag = 0;
void GetCustomer(char *contact){
	customer cust = {"234","Titas","kolkata","vdr"};
	
	if(strcmp(contact,cust.contact) == 0)
		printf("%s\n%s\n%s\n%s",cust.name,cust.city,cust.street);	
	else{
		printf("not reg.");
		flag = 1;
	}
}
	
