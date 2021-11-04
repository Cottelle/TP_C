#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse(const char * line, double *a, double *b, char *op){
    if(strlen(line)<5){
        return PARSE_ERREUR_FORMAT;
    }
    int a1=1;
    int a2=2;
    for (int i=0;line[i]!='\0';i++){
        if(a1 && (line[i]>47 && line[i]<58) || (a2 && line[i]=='.'))
    }
}

