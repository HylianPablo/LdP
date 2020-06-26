%{
 #include <stdio.h>
 int yyerror(char *err) { fprintf(stderr, "%s\n",err); }
 int yylex();

	// expr 'E+' term {$$ = $1 * (Math.pow(10,$3))}

%}
%union {
	double dd;
}
%token <dd> NUMD
%token PRINT
%type <dd> expr
%type <dd> term
%type <dd> fact
%type <dd> indv
%%
s	: s p
	|
	;
p	:  print expr  '\n' {printf ("Resultado: %f\nIntroduzca una operación, por favor.\n", $2); }
	| '\n'
	;
print	: PRINT
		;
expr	: expr '+' term {$$ = $1 + $3; }
		| expr '-' term {$$ = $1 - $3; }
		| term {$$ = $1;}
		;
term	: term '*' fact {$$ = $1 * $3; }
		| term '/' fact {$$ = $1 / $3; }
		| fact
		;
fact	: '-' fact {$$ = -$2;}
		| '+' fact {$$ = $2;}
		| indv
		;
indv	: '(' expr ')' {$$ = $2;}
    	| NUMD
		;
%%
int main() { 
	printf("Introduzca una operación, por favor.\n");
	yyparse(); 
}
