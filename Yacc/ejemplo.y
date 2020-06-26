%{
#include <stdio.h>
	int yyerror (char *s){
		fprintf(stderr,"%s\n",s);
	}
%}
%token ABRIR CERRAR
%%

R	: S '\n'
  	;
S	: ABRIR CERRAR S
  	|
	;
%%
int main(){
	yyparse();
}
