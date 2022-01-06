#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct symtab
{
	char name[20];
	int addr;
};
struct symtab s[30];

void main()
{
	int ch,i=0,j;
	int cho,ad,flg,ad1;
	char na[20],na1[20];
   while(1)
  {
	printf("Enter choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 0 : printf("\nEnter name and address: \n");
			 scanf("%s",s[i].name);
			 scanf("%d",&s[i].addr); i++;
			 break;
		
		case 1: printf("Name\tAddress\n");  
			for(j=0;j<i;j++)
			{			
				printf("%s\t", s[j].name);
				printf("%d\n",s[j].addr);
			}	  
			 break;

		case 2: 
			printf("Name 0 Address 1: ");
			scanf("%d",&cho);
			flg=0;
			if(cho == 0)
			{
				printf("Enter name : ");
				scanf("%s",na);
				for(j=0;j<i;j++)
				{
					if(strcmp(s[j].name,na) == 0){
						printf("%s\t%d\n",s[j].name,s[j].addr);flg=1; break;}
				}
				if(flg == 0)
				{
					printf("Not found\n");
                                }
                         }
			 else
			 {
				flg=0;
				printf("Enter address : ");
				scanf("%d",&ad);
				for(j=0;j<i;j++)
				{
					if(s[j].addr == ad){
						printf("%s\t%d\n",s[j].name,s[j].addr);flg=1; break;}
				}
				if(flg == 0)
				{
					printf("Not found\n");
                                }
                         }
                         break;

		case 3: 
			printf("\nName 0 Address 1: ");
			scanf("%d",&cho);
			
			if(cho == 0)
			{
				printf("\nEnter old name : ");
				scanf("%s",na);
				printf("\nEnter the new name");
				scanf("%s",na1);
				for(j=0;j<i;j++)
				{
					if(strcmp(s[j].name,na) == 0){
						strcpy(s[j].name,na1); break;}
				}
				
                         }
			 else
			 {
				
				printf("Enter old address : ");
				scanf("%d",&ad);
				printf("Enter new address : ");
				scanf("%d",&ad1);
				for(j=0;j<i;j++)
				{
					if(s[j].addr == ad){
						s[j].addr = ad1; break;}
				}
				
                         }
                         break;	
	

         }
  }
}
