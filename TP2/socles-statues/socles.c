#include <stdio.h>

int main(void){
    int base,haut;
    scanf("%i\n%i",&base,&haut);
    int res=0;
    for(haut=haut;haut<=base;haut++){
        res+=haut*haut;
    }
    printf("%i\n",res);
}