#include "args-parser.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

void printUsage(void)
{
    printf("Les option a mettrent en paramatre sont\n \n -e          pour passer en mode encodage\n -d          pour passer en mode decodage\n -i FICHIER  la source sera le chemin donner par FICHIER\n -o FICHIER  la destination sera donne par le le chemin FICHIER\n -m MESSAGE  donne le message a encoder\n -f CHIFFRE  permet de definir le factuer de compression par CHIFFRE sans specification il est a 1\n -h          affiche l'aide\n\n");
    return;
}

void cleanOptions(options_t *options)
{

    free(options->messageToEncode);

    if (options->inputFile)
        fclose(options->inputFile);
    if (options->outputFile)
        fclose(options->outputFile);
}

void readMessageFromStdin(char **message, uint64_t *lenght)
{
    uint64_t allocated = 10;
    *lenght = 0;
    uint64_t nb_read = 0;
    *message = malloc(allocated);
    while (0 !=
           (nb_read = fread(*message + *lenght, 1, allocated - *lenght, stdin)))
    {
        *lenght += nb_read;
        if (*lenght >= allocated)
        {
            allocated *= 2;
            void *tmp = realloc(*message, allocated);
            if (tmp == NULL)
            {
                fprintf(stderr, "Memory allocation error\n");
                exit(6);
            }
            *message = tmp;
        }
    }
    printf("Message of length %" PRIu64 " read from stdin\n", *lenght);
}

void initOptions(options_t *options)
{
    options->action = ACTION_UNKNOWN;
    options->inputFilename = NULL;
    options->outputFilename = NULL;
    options->messageToEncode = NULL;
    options->inputFile = NULL;
    options->outputFile = NULL;
    options->compressing = 1;
    options->messageLength = 0;
}

void checkOptionsValidity(options_t *options)
{

    if (options->compressing != 1 && options->compressing != 2 && options->compressing != 4 &&options->action==ACTION_ENCODE)
    {
        fprintf(stderr, " -f option needs 1,2 or 4 \n");
        exit(1);
    }
    if (options->action == ACTION_ENCODE)
    {
        if (options->inputFilename == NULL || options->outputFilename == NULL)
        {
            fprintf(stderr, "encode action requires an input and output file\n");
            exit(1);
        }
        if (options->messageToEncode == NULL)
        {
            readMessageFromStdin(&options->messageToEncode, &options->messageLength);
        }
    }
    else
    {

        if (options->inputFilename == NULL)
        {
            fprintf(stderr, "encode action requires an input file.\n");
            exit(2);
        }
    }
}

void parseArgs(int argc, char **argv, options_t *options)
{

    initOptions(options);

    int c;
    while ((c = getopt(argc, argv, "hedi:o:m:f:")) != -1)
    {
        switch (c)
        {
        case 'e':
            options->action = ACTION_ENCODE;
            break;
        case 'd':
            options->action = ACTION_DECODE;
            break;
        case 'i':
            options->inputFilename = optarg;
            break;
        case 'o':
            options->outputFilename = optarg;
            break;
        case 'm':
            options->messageToEncode = strdup(optarg);
            options->messageLength = strlen(options->messageToEncode);
            break;
        case 'h':
            printUsage();
            break;
        case 'f':
            options->compressing = atoi(optarg);
            break;
        case '?':
            if (optopt == 'i' || optopt == 'o' || optopt == 'm' || optopt == 'f')
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
            abort();
        default:
            abort();
        }
    }

    checkOptionsValidity(options);
}