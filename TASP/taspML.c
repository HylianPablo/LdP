#include <stdio.h>
#include <stdlib.h>

int sgteCompLex(){
    char c= getChar();
    while (c==' ' || c =='\t'|| c=='\n') c = getChar();
    switch(c) {
        case 'a' : case 'b' : case ';' : case EOF : return c;
        default: {
            printf("Error léxico\n");
            exit(1);
        }
    }
}