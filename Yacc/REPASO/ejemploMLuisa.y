%{
#include <stdio.h>
	int yyerror(char *s){
		fprintf(stderr, "%s\n",s);
	}
	int yylex();
%}
%token ABRIR CERRAR
%%

R	: S '\n'
  	;
S	: ABRIR S CERRAR S
  	|
	;
%%

int main(){
	yyparse();
}
