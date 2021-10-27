#include<stdio.h>
#include<string.h>

void main() {
	
	char op[15][15],arg1[15][15],arg2[15][15],result[15][15],dummy[15][15],replacement[15][15];
	int num,i,j,k=0,test=0;
	int exclude[15];
	printf("enter number of intermediate codes:\n");
	scanf("%d",&num);
	for(i=0;i<num;i++) {
		
		printf("enter operator,arg1,arg2,result %d\n",i);
		scanf("%s",op[i]);
		scanf("%s",arg1[i]);
		scanf("%s",arg2[i]);
		scanf("%s",result[i]);
		}
	printf("\n\ninput\n------------\n");
	printf("operator\targ1\targ2\tresult\n");
	for(i=0;i<num;i++) {
		
		printf("%s\t\t%s\t%s\t%s\n",op[i],arg1[i],arg2[i],result[i]);
		}
	for(i=0;i<num;i++) {
		
		for(j=i+1;j<num;j++) {
			
			if((strcmp(op[i],op[j]) || strcmp(arg1[i],arg1[j])) || strcmp(arg2[i],arg2[j]))
				continue;
			else {
				
				strcpy(dummy[k],result[j]);
				strcpy(replacement[k],result[i]);
				exclude[k]=j;
				k++;
				strcpy(result[j],result[i]);
				}
			}
		}
	for(i=0;i<num;i++) {
		
		for(j=0;j<k+1;j++) {
			
			if((strcmp(arg1[i],dummy[j])==0)) {
				
				strcpy(arg1[i],replacement[j]);
				}
			if((strcmp(arg2[i],dummy[j])==0)) {
				
				strcpy(arg2[i],replacement[j]);
				}
			}
		}
	printf("\n\noutput\n---------------\n");
	printf("operator\targ1\targ2\tresult\n");
	for(i=0;i<num;i++) {
		
		for(j=0;j<k;j++) {
			
			if(exclude[j]==i)
				test=1;
			}
		if(test!=1) {
			
			printf("%s\t\t%s\t%s\t%s\n",op[i],arg1[i],arg2[i],result[i]);
			}
		test=0;
		}
	}
