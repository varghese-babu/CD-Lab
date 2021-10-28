#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20];
int top=-1;
void push(char val) {
	top++;
	stack[top]=val;
	}
void pop() {
	if(top!=-1) {
		top--;
		}
	}
int prec(char c) {
	switch(c) {
		
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '%':
			return 3;
			break;
		default:
			return 0;
			break;
		}
	}
void main() {
	
	int i,k=0,temp=0,temp1=48;
	char op1,op2,res;
	char postfix[20];
	for(i=0;i<20;i++)
		postfix[i]='\0';
	for(;i<20;i++)
		stack[i]='\0';
	char str[20];
	while(1)
{
temp=90;
temp1=65;
	printf("enter the infix expression :\n");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++) {
		
		if(str[i]=='(') {
			
			push(str[i]);
			}
		else if(str[i]==')') {
			
			while(stack[top]!='(') {
				
				postfix[k++]=stack[top];
				pop();
				}
			pop();
			}
		else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
			
			postfix[k++]=str[i];
			}
		else if(str[i]=='%' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') {
			
			if(top==-1 || stack[top]=='(') {
				
				push(str[i]);
				}
			else if(prec(str[i])>=prec(stack[top])) {
				
				push(str[i]);
				}
			else if(prec(str[i])<prec(stack[top])) {
				
				while(prec(str[i])<prec(stack[top])) {
					
					postfix[k++]=stack[top];
					pop();
					}
				push(str[i]);
				}
			}
		}
	while(top!=-1) {
		
		postfix[k++]=stack[top];
		pop();
		}
	printf("\nposftix is: %s\n",postfix);
	printf("\nQuadruple: \n\n");
	printf("\toperator\toperand 1\toperand 2\t result\n");
	for(i=0;postfix[i]!='\0';i++) {
		
		if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z')) {
			
			push(postfix[i]);
			}
		else if(postfix[i]=='%' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/') {
			
			op2=stack[top];
			pop();
			op1=stack[top];
			pop();
			res=temp--;
			push(res);
			printf("\n\t%c\t\t%c\t\t%c\t\t%c\n",postfix[i],op1,op2,res);
			}
		}
	printf("\n\ntriple: \n\n");
	printf("operator\toperand 1\toperand 2\t\n");
	for(i=0;postfix[i]!='\0';i++) {
		
		if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z'))
			push(postfix[i]);
		else if(postfix[i]=='%' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/') {
			
			op2=stack[top];
			pop();
			op1=stack[top];
			pop();
			res=temp1++;
			push(res);
			printf("\t%c\t\t%c\t\t%c\n",postfix[i],op1,op2);
			}
		}
	}
}
