%{
#include<ctype.h>
int a,b,c;
%}
a[012][0][12]
b[012][1][02]
c[012][2][01]


%%
{a}|{b}|{c} {printf("valid%s\n",yytext);}
.* {printf("Invalid");}


%%
int main()
{
printf("enter the string :\n");
yylex();
return 0;
}
int yywrap()
{
return 1;
}

