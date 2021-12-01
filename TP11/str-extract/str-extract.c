#include <stdio.h>
#include <string.h>

void strExtract(FILE *in, char *delim, char *buffer, size_t size)
{
    int acc = 0;
    int n = strlen(delim);
    for (size_t i = 0; i < size - 1; i++)
    {
        char c = fgetc(in);
        for (size_t j = 0; j < n; j++)
        {
            if (c==EOF)
            {
                buffer[i]='\0';
                return;
            }
            if (c == delim[j])
            {
                buffer[i] = '\0';
                fseek(in, -1, SEEK_CUR);
                return;
            }
        }
        buffer[i]=c;
    }
    buffer[size]='\0';
}
