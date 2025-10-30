%{
#include<stdio.h>
int flag=0;
%}
%token NUMBER
%left '+''-'
%left '%''/';'*'
%left '('')'
%%
arithmatic :E
{
printf("\nResult=%d\n",$$);
return 0;
};
E:E '+' E  {$$=$1+$3;}
 |E '-' E  {$$=$1-$3;}
 |E '*' E  {$$=$1*$3;}
 |E '%' E  {$$=$1%$3;}
 |E '/' E  {$$=$1/$3;}
 |'(' E ')'  {$$=$2;}
 |NUMBER  {$$=$1;}
;
%%
void main()
{
printf("enter the expression");
yyparse();
}
void yyerror()
{
flag=1;
printf("\nInvalid\n");
}

