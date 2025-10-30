%{
#include<stdio.h>
int consonant=0,vowel=0;
%}
%%
[AEIOUaeiou] {vowel++;}
[b-zB-Z] {consonant++;} //no need of all letter this is rule -df-hj-np-tv-  -DF-HJ-NP-
./n {/*ignore*/}
%%
int main()
{
printf("enter the input\n");
yylex();
printf("vowels:%d\n",vowel);
printf("constant:%d\n",consonant);
}
int yywrap()
{
return 1;
}

