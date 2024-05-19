#include<stdio.h>

void saveInvoice(item *listOfItem, float total, int numOfItems){
	int i;
	fprintf(fp,"ITEM\t\tQNT\t\tPRICE\t\tAMOUNT\n");
	for(i = 0;i<numOfItems;i++){
		fprintf (fp,"%s\t\t",listOfItem[i].item);
		fprintf(fp,"%0.2f\t\t",listOfItem[i].qnt);
		fprintf(fp,"%0.2f\t\t",listOfItem[i].price);
		fprintf(fp,"%0.2f\n",listOfItem[i].amount);
		
	}
	fprintf(fp,"%0.2f",total);
	fprintf(fp,"\n=====================================================================================================");
} 
