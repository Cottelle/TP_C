#include <stdio.h>
#include <stdlib.h>


int main(void){
    char str[1000];
    fgets(str,1000,stdin);
    for(int i=0;str[i]!='\0';i++){
        switch (str[i])
        {
        case 'f':
            printf("c");
            break;
        case 'c':
            printf("e");
            break;
        case 'y':
            printf("a");
            break;
        case 'm':
            printf("l");
            break;
        case 'l':
            printf("g");
            break;
        case 'e':
            printf("o");
            break;
        case 'd':
            printf("s");
            break;
        case 'r':
            printf("t");
            break;
        case 'k':
            printf("i");
            break;
        case 'x':
            printf("m");
            break;
        case 'v':
            printf("p");
            break;
        case 'n':
            printf("b");
            break;
        case 'i':
            printf("d");
            break;
        case 'b':
            printf("h");
            break;
        case 'w':
            printf("f");
            break;
        case 'p':
            printf("r");
            break;
        case 'q':
            printf("z");
            break;
        case 'h':
            printf("x");
            break;
        case 't':
            printf("w");
            break;
        case 'j':
            printf("u");
            break;
        case 'u':
            printf("j");
            break;
        case 'z':
            printf("q");
            break;
        case 'g':
            printf("v");
            break;
        case 'o':
            printf("k");
            break;
        case 'a':
            printf("y");
            break;
        case 's':
            printf("n");
            break;
        
        
        
        default:
        printf("%c",str[i]);
            break;
        }
    }

return 0; }