#include <stdio.h>
#include <stdlib.h>
#include "tps_unit_test.h"
#include "matrix-In.h"

int **matrixI1(int n)
{
    int **matrix = malloc(sizeof(int *) * n);
    if (matrix == NULL)
    {
        free(matrix);
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(n * sizeof(int));
        if (matrix[i] == NULL)
        {
            for (int j = 0; j <= i; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
        matrix[i][i] = 1;
    }
    return matrix;
}

void matrixI2(int n, int ***mat)
{
    *mat=malloc(n*sizeof(int*));
    if (*mat==NULL)
    {
        free(*mat);
        *mat=NULL;
        return;
    }
    for (int i=0 ;i<n;i++)
    {
        (*mat)[i]=malloc(n*sizeof(int));
        if ((*mat)[i]==NULL)
        {
            // free((*mat)[i]);
            for (int j=0 ;j<=i;j++)
            {
                free((*mat)[j]);
            }
            free(*mat);
            *mat=NULL;
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            (*mat)[i][j]=0;
        }
        (*mat)[i][i]=1;
    }
}

void freeMatrix(int n, int **mat)
{
    for (int i = 0; i < n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}