#include<stdio.h>
void GetInvoice(){
	FILE *fpC;
	char c;
	char contact[10];
	printf("Enter contact no. : ");
	scanf("%s",contact);
	fpC= fopen(contact,"r");
	c = fgetc(fpC);
	while(c != EOF){
		printf("%c",c);
		c = fgetc(fpC);
	}
	fclose(fpC);
	return 0;
}

