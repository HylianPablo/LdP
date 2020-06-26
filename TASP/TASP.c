#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador = 0;

void takeS(char c);

char sgteCompLex() {
	char c = getchar();
	while (c==' ' || c=='\t' || c=='\n') c = getchar(); // saltar blancos ...
	switch (c) {
		case 'a': case 'b': case ';': case EOF: return c;
		default: {
			printf ("Error léxico\n");
			exit(1);
		}
	}
}

void takeB(char c){
	switch (c) {
		case 'a' : 
			takeB(sgteCompLex());
			takeB(sgteCompLex());
			break;
		case 'b' :
			break;
		default : {
			printf("error\n");
			exit(-1);
		}
	}
}

void takeA(char c){
	switch (c) {
		case 'a' : 
			break;
		case 'b' : 
			takeA(sgteCompLex());
			takeA(sgteCompLex());
			break;
		default  : {
			printf("error\n");
			exit(-1);
		}
	}
}

void takeR(char c){
	char r;
	switch (c) {
		case 'a' : 
			r = sgteCompLex();
			takeB(r);
			if(r!=';'){
				r=sgteCompLex();
			}
			takeS(r);
			break;
		case 'b' :
			r=sgteCompLex(); 
			takeA(r);
			if(r!=';'){
				r=sgteCompLex();
			}
			takeS(r);
			break;
		default  : {
			printf("error\n");
			exit(-1);
		}
	}
}

void takeS(char c){
	switch (c) {
		case 'a' : 
		case 'b' : 
			takeR(c);
			break;
		case ';' : break;
		default  : {
			printf("error\n");
			exit(-1);
		}
	}
}

void takeP(char c){
	switch (c) {
		case 'a' : 
		case 'b' : 
		case ';' : 
			takeS(c);
			takeP(sgteCompLex());
			break;
		default : {
			printf("Error. No es una cadena de igual número de 'a' y 'b'\n");
			exit(-1);
		}
	}
}

int main(){
	printf("Introduzca cadenas de igual número de 'a' y 'b'\n");
	takeP(sgteCompLex());
}

