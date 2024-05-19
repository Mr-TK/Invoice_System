#include<stdio.h>
#include<stdio.h>


void saveInvoice(item *listOfItem, float *total, int numOfItems){
	int i;
	for(i = 0;i<numOfItems;i++){
		fprintf (fp,"%s\t\t",listOfItem[i].item);
		fprintf(fp,"%0.2f\t\t",listOfItem[i].qnt);
		fprintf(fp,"%0.2f\t\t",listOfItem[i].price);
		fprintf(fp,"%0.2f\n",listOfItem[i].amount);
		
}
fprintf(fp,"\n=====================================================================================================");
}
