#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ok= true;

void takeP(char c);
void takeS(char c);

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
			printf("Error en Q con símbolo %c, vuelta a empezar. \n",c);
			ok=false;
			takeS(sgteCompLex());
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
			printf("Error en P con símbolo %c, vuelta a empezar. \n",c);
			ok=false;
			takeS(sgteCompLex());
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
			printf("Error en E con símbolo %c, vuelta a empezar.\n",c);
			ok=false;
			takeS(sgteCompLex());
		}
	}
}

void takeS(char c){
	switch (c) {
		case '(' : 
		case '[' : 
		case ';' : 
			takeE(c);
			if(ok)
				printf("OK\n");
			ok=true;
			takeS(sgteCompLex());
			break;
		default : {
			printf("Error en S con símbolo %c, vuelta a empezar.\n",c);
			takeS(sgteCompLex());
		}
	}
}

int main(){
	printf("Introduzca cadena\n");
	takeS(sgteCompLex());
}

