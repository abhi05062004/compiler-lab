#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char icode[10][10],str[10],opr[20];
	int n,i,j;
	printf("Enter the no.of ic\n");
	scanf("%d",&n);
	printf("Enter the set of intermediate codes: \n");
	for(i=0;i<n;i++)
	{
		scanf(" %s",icode[i]);
	}
	
	for(i=0;i<n;i++){
		strcpy(str,icode[i]);
		switch(str[3])
		{
		case '+':
			strcpy(opr,"ADD");
			break;
		
		case '-':
			strcpy(opr,"SUB");
			break;
		case '*':
			strcpy(opr,"MUL");
			break;
		case '/':
			strcpy(opr,"DIV");
			break;
		default:
			printf("Unsupported operator: %c",str[3]);
			break;
		}
	
	printf("\n\tMOV %c R%d", str[2],i);
	printf("\n\t%s %c R%d",opr, str[4], i);
	printf("\n\tMOV R%d %c",i,str[0]);
	
}
}
	
	
