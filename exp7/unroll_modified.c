#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char word[100],res[50][50],temp1[100],temp2[100];
int len=0,i,r,k=0,j;


void main() {
	
	FILE *f1=fopen("text.txt","r");
	FILE *f2=fopen("body.txt","w");
	FILE *f3=fopen("unrolled.txt","w");
	
	
	
	int number_of_unroll;
	printf("enter number of unrolls required :\n");
	scanf("%d",&number_of_unroll);
	
	//int i_start,i_end,i_control;
	fscanf(f1,"%s",temp1);
	//printf("%s\n",temp1);
	fprintf(f3,"%s\n",temp1);
	
	
	rewind(f1);
	
	
	while(fscanf(f1,"%s",word)!=EOF) {
		
		
		len=strlen(word);
		for(i=0;i<len;i++) {
			
			if(word[i]=='i' && word[i+1]=='=')
				j=word[i+2]-'0';
			if(word[i]=='<') {
				
				if(word[i+1]=='=')
					r=word[i+2]-'0'+1;
				else
					r=word[i+1]-'0';
				}
			if(word[i]=='{') {
				
				while(fscanf(f1,"%s",word)!=EOF && word[i]!='}') {
					
					if(word[0]!='}') {
						
						fprintf(f2,"%s\n",word);
						k++;
						}
					}
				}
			}
		}
	
	fclose(f2);
	FILE *f4=fopen("body.txt","r");
	
	fprintf(f3,"%s\n","{");
	for(int i=0;i<number_of_unroll;i++) {
	
		
		while(fscanf(f4,"%s",temp2)!=EOF) {
		
			fprintf(f3,"%s\n",temp2);
			}
		//fclose(f4);
		if(i==number_of_unroll-1)
			continue;
		fprintf(f3,"%s\n","i++");
		rewind(f4);
		}
	fprintf(f3,"%s\n","}");
		
	fclose(f1);
	fclose(f4);
	fclose(f3);
	}
