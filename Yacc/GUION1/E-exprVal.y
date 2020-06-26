%{
 #include <stdio.h>
 int yyerror(char *err) { fprintf(stderr, "%s\n",err); }
 int yylex();
%}
%token NUM 
%left '+' '-'
%left '*' 'x' '/'
%%
s	: s p
	|
	;
p	: expr  '\n' {printf ("Resultado: %d\nIntroduzca una operación, por favor.\n", $1); }
	;
expr 	: expr '+' expr {$$ = $1 + $3; }
	| expr '-' expr {$$ = $1 - $3; }
	| expr '*' expr {$$ = $1 * $3; }
	| expr 'x' expr {$$ = $1 * $3; }
	| expr '/' expr {$$ = $1 / $3; }
	| '(' expr ')' {$$ = $2;}
	| NUM 
	;
%%
int main() { 
	printf("Introduzca una operación, por favor.\n");
	yyparse(); 
}
