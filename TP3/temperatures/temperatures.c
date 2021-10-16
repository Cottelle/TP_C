#include <stdio.h>

int main(void){
    int nb,m,M;
    scanf("%i\n%i\n%i\n",&nb,&m,&M);
    int val;
    for (int i=0;i<nb;i++){
        scanf("%i",&val);
        if(val >M || val<m){
            printf("Alerte !!\n");
            return 0;
        }
            printf("Rien à signaler\n");
        
    }

    return 0;
}