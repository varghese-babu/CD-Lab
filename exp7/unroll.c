#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char word[100],res[50][50];
int len=0,i,r,k=0,j;

void main() {
	
	FILE *f1=fopen("text.txt","r");
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
						
						strcpy(res[k],word);
						k++;
						}
					}
				}
			}
		}
	for(;j<r;j++) {
		
		printf("\nloop iteration: %d\n\n",j);
		for(i=0;i<k;i++) {
			
				printf("%s\n",res[i]);
				}
			}
		}
