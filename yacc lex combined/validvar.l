%{
#include "y.tab.h"
%}
%%
[A-Za-z]   {return ALPHA;}
[0-9]      {return DIGIT;}
[\n]	    {return ENTER;}
.	{return ER;}
%%
int yywrap()
{
return 1;
}

