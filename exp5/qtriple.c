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
	
	int i,k=0,temp=90,temp1=48;
	char op1,op2,res;
	char postfix[20];
	for(i=0;i<20;i++)
		postfix[i]='\0';
	for(;i<20;i++)
		stack[i]='\0';
	char str[20];
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
		else if(str[i]=='%' || str 
