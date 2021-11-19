#include "args-parser.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void cleanOptions(options_t *options) {

    free(options->errorMessage);
    free(options->messageToEncode);

    if(options->inputFile)
        fclose(options->inputFile);
    if(options->outputFile)
        fclose(options->outputFile);
}

void parseArgs(int argc, char **argv, options_t *options) {

    options->action = ACTION_UNKNOWN;
    options->inputFilename = NULL;
    options->outputFilename = NULL;
    options->messageToEncode = NULL;
    options->inputFile = NULL;
    options->outputFile = NULL;

    int c;
    while ((c = getopt (argc, argv, "edi:o:m:")) != -1) 
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
                break;

            case '?':
                if (optopt == 'i' 
                    || optopt == 'o' 
                    || optopt == 'm' )
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                abort();
            default:
                abort ();
        }
    }


    if(options->action == ACTION_ENCODE) {
        if(options->inputFilename == NULL 
        || options->outputFilename== NULL) {
            fprintf(stderr, "encode action requires an input and output file\n");
            exit(1);
        }
    } else {

        if(options->inputFilename == NULL) {
            fprintf(stderr, "encode action requires an input file.\n");
            exit(2);
        }
    }


}