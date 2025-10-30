%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *s);
int yylval;
%}

%token DIGIT
%left '-' '+'
%left '/' '*'

%%
line: expr '\n' { printf("Result: %d\n", $1); }
    ;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    | '-' expr      { $$ = -$2; }
    | DIGIT         { $$ = $1; }
    ;
%%

int main(void)
{
    printf("Enter an expression:\n");
    yyparse();
    return 0;
}

void yyerror(char *s)
{
    printf("Error: %s\n", s);
}

int yylex(void)
{
    int c;
    while ((c = getchar()) == ' ' || c == '\t');

    if (isdigit(c))
    {
        yylval = c - '0';
        return DIGIT;
    }

    return c;
}

