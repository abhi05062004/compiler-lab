#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>  
#define MAX 10
int n;
struct expr
{
  char op[10],op1[10],op2[10],res[10];
  int flag;
}arr[MAX];

void input();
void constant();
void change(int p,char *res);
void output();

int main()
{
input();
constant();
output();
return 0;
}
void input()
{
int i;
printf("\n Enter the number of production:\t");
scanf("%d",&n);
printf("enter the production in order (operator operator1 operator 2 result)\n");
for(i=0;i<n;i++)
{
scanf("%s",arr[i].op);
scanf("%s",arr[i].op1);
scanf("%s",arr[i].op2);
scanf("%s",arr[i].res);
arr[i].flag=0;
}
}
void constant()
{
int op1,op2,res,i;
char resstr[10],op;
for(i=0;i<n;i++)
{
if((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]))||strcmp(arr[i].op,"=")==0)
{
op1=atoi(arr[i].op1);
op2=atoi(arr[i].op2);
op=arr[i].op[0];
switch(op)
{
case '+':
res=op1+op2;
break;
case '-':
res=op1-op2;
break;
case '*':
res=op1*op2;
break;
case '/':
if(op2!=0)
res=op1/op2;
else 
printf("zero divison error\n");
return ;
break;
case '=':
res=op1;
}
sprintf(resstr,"%d",res);
arr[i].flag=1;
change(i,resstr);
}
}
}
void change(int p,char *res)
{
int i;
for(i=p+1;i<n;i++)
{
if(strcmp(arr[p].res,arr[i].op1)==0)
{
strcpy(arr[i].op1,res);
}
if(strcmp(arr[p].res,arr[i].op2)==0)
{
strcpy(arr[i].op2,res);
}
}
}
void output()
{
int i;
printf("\nOPTIMIZED CODE \n");
for(i=0;i<n;i++)
{
printf("\n%s %s %s %s\n",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
}
}

