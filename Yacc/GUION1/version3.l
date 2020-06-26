%{
#include <stdio.h>
#include "y.tab.h"
%}
double	[0-9]*[.]?[0-9]*(e|E)?(\-|\+)?[0-9]*|0
print	(p|P)(r|R)(i|I)(n|N)(t|T)
white	(\x20|\t)
%%
[ \t]+	;
{print}{white}	{return PRINT;}
{double}	{
			yylval.dd = atof(yytext);
			return NUMD;
		}
.|\n	{ 
		return yytext[0];
	}
