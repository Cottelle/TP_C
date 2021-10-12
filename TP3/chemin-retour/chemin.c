#include <stdio.h>
int n,dep;

int main(void){
    scanf("%i",&n);
    int tab[n];
    for (int i=0;i<n;i++){
        scanf("%i",&dep);
        switch (dep)
        {
        case 1:
            tab[i]=2;
            break;
        case 2:
            tab[i]=1;
            break;
        case 3:
            tab[i]=3;
            break;
        case 4:
            tab[i]=5;
            break;
        case 5:
            tab[i]=4;
            break;
        

        
        default:
            break;
        }
        
        }
    for(int i=0;i<n;i++){
                printf("%i\n",tab[n-1-i]);
    }



    return 0;
}