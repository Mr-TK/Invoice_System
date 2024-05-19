#include<stdio.h>
#include<string.h>
#include "datadefinition.h"
customer cust1;
customer Savecustomer();
void writefile(customer cust);
FILE *fpt;
customer GetCustomer(char *contact){
	char temp[11],info[10];
	int line_num = 0, find_result = 0,i,line= 0,len = 0;
	char save;
	fpt = fopen("customer.txt","r");	
	while(fgets(temp,11,fpt) != NULL) {

		if((strstr(temp, contact)) != NULL) 
			find_result++;
		if(find_result>0)
			break;
		
		len = line_num;
		line_num++;
	}
	if(find_result != 0){
	printf("got it");	
	
		while(fgets(temp,20,fpt) != NULL){
			printf("%s", temp);
	
			if(line==len+3){
				fseek(fpt, 0, SEEK_SET);
				break;
			}
			line++;
	}
		}
		
	else{
		printf("Not reg.");
		fflush(stdin);
		
		customer cust2 = Savecustomer();
		fpt = fopen("customer.txt","a");
		printf("Do you want to save (c) to confirm (x) to cancel");
		save = getch();
			if(save == 'C' || save == 'c'){
				fprintf(fpt,"%s\n",contact);
				writefile(cust2);
				fclose(fpt);
				printf("CUSTUMER IS SAVED");
			}
			else{
				printf("OKAY");
				fclose(fpt);
			}
	}
}
customer Savecustomer(){
	fflush(stdin);
	printf("Enter Name: ");
	scanf("%[^\n]",cust1.name);
	fflush(stdin);
	printf("Enter City: ");
	scanf("%[^\n]",cust1.city);
	fflush(stdin);
	printf("Enter Street: ");
	scanf("%[^\n]",cust1.street);
	fflush(stdin);
	return cust1;
	
}
void writefile(customer cust){
	fprintf(fpt,"%s\n",cust1.name);
	fprintf(fpt,"%s\n",cust1.street);
	fprintf(fpt,"%s\n",cust1.city);
	fprintf(fpt,"------\n");
}

