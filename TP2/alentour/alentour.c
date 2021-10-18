#include <stdio.h>

int main(void) {
    int km,nb;
    scanf("%i",&km);
    scanf("%i",&nb);
    int b=0;
    for(int i=0;i<nb;i++){
        int v;
        scanf("%i",&v);
        if (v-km >= -50 && v-km <= 50){
            b++;
        }
    }
    printf("%i\n",b);
    return 0;
}