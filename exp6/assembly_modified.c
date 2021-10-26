#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char stack[80];
int top=-1;

void push(char x) {
	
	stack[++top]=x;
	}
	
char pop() {
	
	if(top==-1)
		return -1;
	else
		return stack[top--];
	}

int priority(char x) {
	
	if(x=='(')
		return 0;
	if(x=='+' || x=='-')
		return 1;
	if(x=='%' || x=='/')
		return 2;
	}

void main() {

	char emp[20],str[20],*e,x,s,a,b,opr[10];
	int i=-1,j=0,p=0,tmpch=90,c=0;
	printf("enter the expression :\n");
	scanf("%s",emp);
	e=emp;
	while(*e!='\0') {
		
		if(isalnum(*e))
			str[++i]=*e;
		else if(*e=='(')
			push(*e);
		else if(*e==')') {
			
			while((x=pop())!='(')
				str[++i]=x;
			}
		else {
			
			while(priority(stack[top])>=priority(*e)) {
				
				s=pop();
				str[++i]=s;
				}
			push(*e);
			}
		e++;
		}
	while(top!=-1) {
		
		s=pop();
		str[++i]=s;
		}
	str[++i]='\0';
	printf("\n%s\n",str);
	top=-1;
	int offs=0;
	for(i=0;i<strlen(str);i++) {
		
		if(str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*')
			c++;
		}
	for(i=0;i<strlen(str);i++) {
		
		if(isalnum(str[i]))
			push(str[i]);
		else {
			
			a=pop();
			b=pop();
			if(b<65 || b>90) {
				
				printf("\n\tMOV AX,[%c]",b);
				}
			else {
				
				printf("\n\tMOV AX,%cX",b);
				}
			if(a<65 || a>90) {
				
				printf("\n\tMOV BX,[%c]",a);
				}
			else {
				
				printf("\n\tMOV BX,%cX",a);
				}
			switch(str[i]) {
				
				case '+':
					printf("\n\tADD AX,BX");
					break;
				case '*':
					printf("\n\tMUL AX,BX");
					break;
				case '-':
					printf("\n\tSUB AX,BX");
					break;
				case '/':
					printf("\n\tDIV AX,BX");
					break;
				}
			printf("\n\tMOV %cX,AX",offs+'C');
			push(offs+'C');
			offs=(offs+1)%2;
			}
		}
		printf("\n");
	}
