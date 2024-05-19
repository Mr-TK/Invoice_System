#include<stdio.h>
#include "customer.h"

void saveInvoice(item *listOfItem, float total, int numOfItems);
void CreateInvoice(){
	char contact[11];
	printf("Enter your number: ");
	scanf("%s",contact);
	customer cust = GetCustomer(contact);
	
}
int main(){
	CreateInvoice();
	
	return 0;
}
