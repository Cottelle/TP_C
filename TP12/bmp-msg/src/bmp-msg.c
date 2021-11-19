#include <stdio.h>
#include <stdlib.h>
#include "args-parser.h"
#include "io-utils.h"
#include "encoder.h"


int main(int argc, char **argv) {
    
    int exitCode = 0;

    options_t options;
    
    parseArgs(argc, argv, &options);

    if(!openFiles(&options)) {
        fprintf(stderr, "%s\n", options.errorMessage);
        exitCode = 1;
        goto quit;
    }

    char * message = "TEST";
    int res;
    switch(options.action) {
        case ACTION_DECODE: 
            if(ENCODER_OK != 
                (res = decode(
                    options.inputFile, 
                    &message))) 
                {
                    fprintf(stderr, "error while decoding %i\n", res);
                    exitCode = 2;
                    goto quit;
                }
            puts(message);
            free(message);
            break;
        case ACTION_ENCODE:
            if(ENCODER_OK != 
                (res = encode(
                    options.outputFile, 
                    options.messageToEncode))) 
                {
                    fprintf(stderr, "error while encoding %i\n", res);
                    exitCode = 3;
                    goto quit;
                }
            break;
        case ACTION_UNKNOWN:
            fprintf(stderr, "action is missing\n");
            exitCode = 4;
            goto quit;
    }


    quit:
    cleanOptions(&options);
    return exitCode;
}