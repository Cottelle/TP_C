#include <stdio.h>
#include <stdlib.h>

int ** matrixI1(int n){
    int **matrix=malloc(sizeof(int *)*n);
    if (matrix==NULL){
        free(matrix);
        return NULL;
    }
    for (int i=0;i<n;i++){
        matrix[i]=malloc(n*sizeof(int));
        if (matrix[i]==NULL)
        {
            for(int j=0;j<=i;j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void matrixI2(int n, int *** mat){
         for (int i=0;i<n;i++){
        mat[i]=malloc(n*sizeof(int));
        if (mat[i]==NULL)
        {
            for(int j=0;j<=i;j++)
            {
                free(mat[j]);
            }
            free(mat);
        }
    }
}

void freeMatrix(int n, int ** mat){
    for(int i=0;i<n;i++){
        free(mat[i]);
    }
    free(mat);
}