#include<stdio.h>
#include<stdio.h>

FILE *fp;
void saveInvoice(item *listOfItem, total, numOfItems);{
	for(i = 0;i<numOfItems;i++){
		fprintf (fp,"%s",listOfItem[numOfItems-1].item);
		fprintf(fp,"%s",listOfItem[numOfItems-1].qnt);
		fprintf(fp,"%s",listOfItem[numOfItems-1].price);
		fprintf(fp,"%s",listOfItem[numOfItems-1].amount);
		fprintf(fp,"\n=====================================================================================================");
	
}
