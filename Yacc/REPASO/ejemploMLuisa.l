%{
#include "y.tab.h"
%}

%%
[ \t]+	;
"/*"	return ABRIR;
"*/"	return CERRAR;
\n	return yytext[0];
.	;
