%{
#include <stdio.h>
int n = 0;
%}

DIGIT      [0-9]
LETTER     [a-zA-Z]
ID{LETTER}({LETTER}|{DIGIT})*

%%
\n                         { n++; }
{DIGIT}+                  { printf("AN INTEGER - %s\n", yytext); }
{DIGIT}+"."{DIGIT}+       { printf("A FLOATING - %s\n", yytext); }
"IF"|"THEN"|"SWITCH"|"ELSE"|"END"|"BEGIN"  { printf("A KEYWORD - %s\n", yytext); }
{ID}                      { printf("IDENTIFIER - %s\n", yytext); }
"+"|"-"|"*"               { printf("AN OPERATOR - %s\n", yytext); }

%%
int main()
{
    printf("Enter the expression:\n");
    yylex();
    printf("Number of lines = %d\n", n);
    return 0;
}

int yywrap()
{
    return 1;
}

