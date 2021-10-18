#include <stdio.h>
#include <stdlib.h>


int main(void){
    char * str;
    fgetc(str,100,stdin);
    for(int i=0;str[i]!='\0';i++){
        switch (str[i])
        {
        case 'f':
            printf("c");
            break;
        case 'c':
            printf("e");
            break;
        case 'r':
            printf("t");
            break;
        case 'y':
            printf("a");
            break;
        case 'm':
            printf("l");
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        case /* constant-expression */:
            /* code */
            break;
        
        
        default:
            break;
        }
    }

return 0; }