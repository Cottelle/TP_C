#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonction.h"

char *readline(FILE *file, char *buffer)
{
    char *ret = fgets(buffer, 1000, file);
    return ret;
}
int countpath(char *str, char *path)
{
    int longstr = strlen(str);
    int longpath = strlen(path);
    int count = 0;
    char *newstr = malloc(longpath + 1);
    for (int i = 0; i < longstr - longpath + 1; i++)
    {
        for (int j = 0; j < longpath; j++)
        {
            newstr[j] = str[j + i];
        }
        newstr[longpath] = '\0';
        if (strcmp(newstr, path) == 0)
        {
            count++;
        }
    }
    free(newstr);
    return count;
}

char *decal(char *str, int n)
{
    char *new = malloc(1001);
    for (int i = 0; i < n; i++)
    {
        new[i] = ' ';
    }
    for (int i = 0; i < 1001 - n; i++)
    {
        new[i + n] = str[i];
    }
    return new;
}
int testdebut(char *str, char *path)
{
    int longstr = strlen(str);
    int longpath = strlen(path);
    if (longstr +1 < longpath)
    {
        return -1;
    }
    char *new = malloc(longpath + 1);
    for (int i =0 ; i < longpath; i++)
    {
        new[i] = str[i+1];
    }
    new[longpath] = '\0';
    int sort=strcmp(new, path)==0;
    free(new);
    return sort;
}

char *surpblanc(char *str)
{
    char *new=malloc(1001);
    int i=0;
    for (i=0;i<1001;i++)
    {
        if (str[i]!=' ')
        {
            break;
        }
    }
    for(int j=0;j<1001-i;j++)
    {
        new[j]=str[i+j];
    }
    return new;
}

