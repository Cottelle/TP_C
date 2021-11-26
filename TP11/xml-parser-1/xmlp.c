#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xmlp.h"

char *GetText(char chara, FILE *file, int tagopen)
{
    char *text = malloc(1);
    char *test;
    int acc = 0;
    text[0] = chara;
    chara = fgetc(file);
    while (chara != '<' && chara != '>')
    {
        if (chara == ' ' && tagopen == 1)
        {
            while (chara != '>')
            {
                if (chara == EOF)
                {
                    free(text);
                    fprintf(stderr, "Unexpected end of tag (missing '>')\n");
                    exit(ERROR_UNEXPECTED_END_OF_TAG);
                }
                chara = fgetc(file);
            }
            break;
        }
        if (chara == EOF && tagopen == 1)
        {
            free(text);
            fprintf(stderr, "Unexpected end of tag (missing '>')\n");
            exit(ERROR_UNEXPECTED_END_OF_TAG);
        }
        acc++;
        test = realloc(text, acc + 1);
        if (test == NULL)
        {
            fprintf(stderr, "Erreur GetTetxt: Erreur Malloc");
            exit(1);
        }
        text = test;
        text[acc] = chara;
        chara = fgetc(file);
    }
    if (chara == '<')
    {
        fseek(file, -1, SEEK_CUR);
    }
    test = realloc(text, acc + 2);
    if (test == NULL)
    {
        fprintf(stderr, "Erreur GetTetxt: Erreur Malloc");
        exit(1);
    }
    text = test;
    text[acc + 1] = '\0';
    return text;
}

parser_error_type_t parse(const char *filename, parser_info_t *info)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Erreur parse: Impossible d'ouvir le fichier\n");
        exit(1);
    }
    char chara = 'r';
    while (!feof(file))
    {
        chara = fgetc(file);
        if (chara == EOF)
        {
            return PARSER_OK;
        }
        if (chara != '<')
        {
            char *text = GetText(chara, file, 0);
            if (text != NULL)
            {
                (info->handleText)(text, info->data);
            }
            free(text);
        }
        else
        {
            chara = fgetc(file);
            if (chara != '/')
            {
                char *text = GetText(chara, file, 1);
                (info->handleOpenTag)(text, info->data);
                free(text);
            }
            else
            {
                chara = fgetc(file);
                char *text = GetText(chara, file, 1);
                (info->handleCloseTag)(text, info->data);
                free(text);
            }
        }
    }
    return PARSER_OK;
}
