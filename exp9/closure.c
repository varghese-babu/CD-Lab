#include<stdio.h>

char state[10][100],states[10]="0123456789";

//char gone_state[10];
//char gone_ctrl=0;

void closure(char st) {
	
	int k=0;
	int i=st-'0';
	while(state[i][k]!='#') {
		
		k++;
		}
		
	if(state[i][k-2]=='N')
		return;
	
		
	printf("%c,",state[i][k-2]);
	closure(state[i][k-2]);
	}


void main() {
	
	int number_of_states,number_of_input_symbols;
	
	printf("enter number of states::");
	scanf("%d",&number_of_states);
	printf("\n");
	printf("enter number of input symbols::");
	scanf("%d",&number_of_input_symbols);
	printf("\n");
	printf("enter the transitions::\n");
	for(int i=0;i<number_of_states;i++) {
		
		scanf("%s",state[i]);
		}
		
	printf("epsilon closure::\n");
	for(int i=0;i<number_of_states;i++) {
		
		printf("closure of %c = { %c,",states[i],states[i]);
		
		int k=0;
		while(state[i][k]!='#') {
			
			k++;
			}
		if(state[i][k-2]!='N') {
		
			printf("%c,",state[i][k-2]);
			closure(state[i][k-2]);
			}
		
		
		printf(" }\n");
		}
	}	
