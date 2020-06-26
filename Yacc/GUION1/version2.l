%{
#include <stdio.h>
#include "y.tab.h"
%}
entero	[1-9][0-9]*|0
print	(p|P)(r|R)(i|I)(n|N)(t|T)
white	(\x20|\t)
%%
[ \t]+	;
{print}{white}	{return PRINT;}
{entero}	{
			yylval = atoi(yytext);
			return NUM;
}
.|\n	{ 
		return yytext[0];
	}
