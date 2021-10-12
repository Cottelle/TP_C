#include <stdio.h>
int prixkilo[10]={9, 5, 12, 15, 7, 42, 13, 10, 1 ,20};
int res=0;
int entrer = 0;

int main(void){
    for (int i=0;i<10;i++){
        scanf("%i",&entrer);
        res+= entrer*prixkilo[i];
    }
    printf("%i\n",res);

    return 0;
}