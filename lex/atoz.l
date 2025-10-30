// program to change ABC SUBSTRING TO XYZ

%{
#include<ctype.h>
#include<string.h>
int count=0;
%}
%%
"ABC"  {count++;printf("XYZ");}
.\|n   {printf("%s",yytext);}
%%
int main()
{
printf("enter the string");
yylex();
printf("%d",count);
return 0;
}
int yywrap()
{
return 1;
}
