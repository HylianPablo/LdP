%{
#include<stdio.h>
	yyerror(char* s) {
		fprintf(stderr, "%s\n", s);
	}
%}
%%
S	: 'h' 'o' 'l' 'a' '\n'	{printf ("S -> h0la\n");} 
 	;
O	: O 'o'		{printf("O -> Oo\n");}
  	|		{printf ("O -> epsilon\n");}
	;
%%
int yylex() { return getchar() ; }
main() {
	yyparse();
}
