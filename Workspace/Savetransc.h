#include<stdio.h>
#include "dt_tm.h"

void saveTransactoin(char *contact,char date[10], float total){
	char *Date;
	Date = DateTime();
	printf("%s",Date);
	FILE *fpr; 
	fpr = fopen(date,"w");
	fprintf (fpr,"%s\n%s---------%f",contact, Date, total);
	fprintf(fpr,"\n=====================================================================================================");
	fclose(fpr);
} 
