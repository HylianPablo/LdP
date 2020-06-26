%{
#include <stdio.h>
	int yyerror (char * s){
		fprintf(stderr, "%s\n",s);
	}
%}
%%
S	:	'h' 'o' 'l' 'a' '\n'
  	;
%%
int yylex() { return getchar() ; }

int main() {
	yyparse();
}
