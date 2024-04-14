#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int find_result = 0;
	int line_num = 0,len,line = 0;
	char ph[11];
	FILE *fpt;
	char temp[20];
	int cur;
	//fpt = fopen("TEST.txt","a");
	if((fpt = fopen("customer.txt", "r")) == NULL) 
	return(-1);
	scanf("%s",ph);
	//fprintf(fpt, "\n%s",ph);

	while(fgets(temp,20,fpt) != NULL) {

		if((strstr(temp, ph)) != NULL) {
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
			if(find_result>0)
				break;
		}
		line_num++;
		len = line_num;
	}
	
	printf("%d",len);
	//cur = ftell(fpt) + 1;
	//fseek(fpt,cur,SEEK_CUR);
	
	while(fgets(temp,20,fpt) != NULL){
	
	printf("%s", temp);
	
	if(line==len+3){
		fseek(fpt, 0, SEEK_SET);
		break;
	}
	line++;
}
	fclose(fpt);
		
}
