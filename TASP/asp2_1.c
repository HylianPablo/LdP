#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void takeP(char c);

char sgteCompLex() {
	char c = getchar();
	while (c==' ' || c=='\t' || c=='\n') c = getchar(); // saltar blancos y tabuladores
	switch (c) {
		case '(': case ')': 
		case '[': case ']': 
		case ';': case EOF :return c;
		default: {
			printf ("Error léxico\n");
			exit(1);
		}
	}
}

void takeQ(char c){
	char tmp;
	switch (c) {
		case '[' :
			tmp = sgteCompLex();
			takeP(tmp);
			if(tmp!=';'){
				tmp = sgteCompLex();
			}
			takeQ(tmp);
			break;
		case ')':
			break;
		case ';':
			break;
		default  : {
			printf("Error en Q. \n");
			exit(-1);
		}
	}
}

void takeP(char c){
	char tmp;
	switch (c) {
		case '(' :
		tmp = sgteCompLex(); 
			takeQ(tmp);
			if(tmp!=';'){
				tmp=sgteCompLex();
			}
			takeP(tmp);
			break;
		case ']':
			break;
		case ';':
			break;
		default  : {
			printf("Error en P. \n");
			exit(-1);
		}
	}
}

void takeE(char c){
	char tmp; 
	switch (c) {
		case '(' :
			tmp = sgteCompLex();
			takeQ(tmp);
			if(tmp!=';'){
				tmp=sgteCompLex();
			}
			takeP(tmp);
			break; 
		case '[' : 
			tmp = sgteCompLex();
			takeP(tmp);
			if(tmp!=';'){
				tmp = sgteCompLex();
			}
			takeQ(tmp);
			break;
		case ';':
			break;
		default  : {
			printf("Error en E.\n");
			exit(-1);
		}
	}
}

void takeS(char c){
	switch (c) {
		case '(' : 
		case '[' : 
		case ';' : 
			takeE(c);
			takeS(sgteCompLex());
			break;
		default : {
			printf("Error en S.\n");
			exit(-1);
		}
	}
}

int main(){
	printf("Introduzca cadena\n");
	takeS(sgteCompLex());
}