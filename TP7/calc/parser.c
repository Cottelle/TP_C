#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse(const char * line, double *a, double *b, char *op){
    if(strlen(line)<5){
        return PARSE_ERREUR_FORMAT;
    }
    int a1=1;
    int a2=1;
    int b1=1;
    int b2=1;
    char *X="";
    char *Y="";
    int i=0;
    for (i=0;a1 && line[i]!='\0';i++){
        if((line[i]>47 && line[i]<58) || (a2 && line[i]=='.')){
            if (line[i]=='.'){
                a2=0;
            }
            strcat(X,&line[i]);
        }
        else if (line[i]==' '){
            a1=0;
        }
        else{
            return PARSE_ERREUR_FORMAT;
        }

    }
    if (line[i]=='\0' && line[i+1]!=' '){
        return PARSE_ERREUR_FORMAT;
    }
    i=i+2;
    if (line[i]!='+' || line[i]!='-' || line[i]!='/' || line[i]!='*' || line[i]!='^'){
        return PARSE_ERREUR_OPERATION;
    }
    else{
        *op=line[i];
    }
    if (line[i]=='\0' && line[i+1]!=' '){
            return PARSE_ERREUR_FORMAT;
    }
    i=i+2;
    for (;b1 && line[i]!='\0';i++){
        if((line[i]>47 && line[i]<58) || (b2 && line[i]=='.')){
            if (line[i]=='.'){
                b2=0;
            }
            strcat(Y,&line[i]);
        }
        else if (line[i]=='/0'){
            b1=0;

        }
        else{
            return PARSE_ERREUR_FORMAT;
        }

    }
    *a=atof(X);
    *b=atof(Y);
    return PARSE_OK;
}

