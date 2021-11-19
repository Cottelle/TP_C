#include "io-utils.h"

#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>


void copy_file(FILE*in, FILE*out) {
    char buffer[1000];
    long nb = 0;
    while((nb = fread(buffer, 1, 1000, in)) != 0) {
        fwrite(buffer, 1, nb, out);
    }
}

int openFiles(options_t * options) {
    options->inputFile = fopen(options->inputFilename, "r");

    if(options->inputFile == NULL) {
        const char *format = "Error while opening the input file '%s': %s";

        options->errorMessage = malloc(
            strlen(options->inputFilename)
            + strlen(format)
            + strlen(strerror(errno)
            + 1));

        sprintf(options->errorMessage, format, options->inputFilename, strerror(errno));
        return 0;
    }



    if(options->outputFilename != NULL) {
        options->outputFile = fopen(options->outputFilename, "w+");

        
        if(options->outputFile == NULL) {
            const char *format = "Error while opening the output file '%s': %s";
            
            options->errorMessage = malloc(
                strlen(options->outputFilename)
                + strlen(format)
                + strlen(strerror(errno)
                + 1));

            sprintf(options->errorMessage, format, options->outputFilename, strerror(errno));
            return 0;
        }

        copy_file(options->inputFile, options->outputFile);
        fseek(options->outputFile, 0, SEEK_SET);
    }


    return 1;
}