#include <stdio.h>
#include "matrix-In.h"
#include <stdlib.h>

int main(void){
    int n;
    scanf("%i",&n);
    int **mat=matrixI1(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            printf("%i",mat[i][j]);
        }
        printf("\n");
    }
}