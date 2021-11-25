#include<stdio.h>
#include<stdio.h>
#include<string.h>

void main(){
char icode[10][30],str[20],opr[10];
int i=0;
char reg='A';
printf("\nEnter the set of intermediate code (terminated by exit):\n");
do
{
scanf("%s",icode[i]);
} while(strcmp(icode[i++],"exit")!=0);
printf("\n target code generation");
printf("\n************************");
i=0;
do
{
strcpy(str,icode[i]);
switch(str[0])
{
case '+':strcpy(opr,"ADD");
	break;
case '-':strcpy(opr,"SUB");
	break;
case '*':strcpy(opr,"MUL");
	break;
case '/':strcpy(opr,"DIV");
	break;
}
if(str[0]=='+' || str[0]=='-')
{
printf("\n\tMOV %cX,[%c]",reg,str[1]);
printf("\n\t%s %cX,[%c]",opr,reg,str[2]);
printf("\n\tMOV [%c],%cX",str[3],reg);
}
else{
printf("\n\tMOV AX,[%c]",str[1]);
printf("\n\tMOV %cX,[%c]",reg,str[2]);
printf("\n\t%s %cX",opr,reg);
printf("\n\tMOV [%c],AX",str[3]);
}
reg+=1;
}while(strcmp(icode[++i],"exit")!=0);
printf("\n");
}
