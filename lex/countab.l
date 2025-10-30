// COUNT AB IN STRING
%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int count=0;
%}
%%
AB|aB|ab|Ab  {count++;}
[ ]	{}
[\t]      {}
.	{}	
%%
int main()
{
printf("enter the string\n");
yylex();
printf("%d\n",count);

return 0;
}
int yywrap()
{
return 1;
}

