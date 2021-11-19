#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
    if (argc!=3)
    {
        fprintf(stderr,"Probleme dans les arguments\n");
        return 1;
    }
    FILE *fileread=fopen(argv[1],"r");
    FILE *filewrite=fopen(argv[2],"w");
    if (filewrite == NULL || fileread==NULL)
    {
        fprintf(stderr,"Probleme dans les chemins\n");
        return 1;
    }
    double value;
    double neinq= 9/5;
    while(!feof(fileread))
    {
        fscanf(fileread,"%lf\n",&value);
        value=value*(9./5.)+ 32;
        fprintf(filewrite,"%.2lf\n",value);
    }
    
    fclose(filewrite);
    return 0;
}