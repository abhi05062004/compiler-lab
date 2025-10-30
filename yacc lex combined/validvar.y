%{
#include<stdio.h>
#include<ctype.h>
%}
%token ALPHA DIGIT ENTER ER
%%
var:v ENTER	 {printf("valid\n");exit(0);}
v:ALPHA EXP1
EXP1: ALPHA EXP1|DIGIT EXP1|;
%%
int main()
{
printf("enter an expression:\n");
yyparse();
return 1;
}
void yyerror()
{
printf("Invalid\n");
}


