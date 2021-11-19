#ifndef IO_UTILS_H
#define IO_UTILS_H

#include "args-parser.h"

/**
 * @brief opens the necessary files
 * if there is an error returns 0 and put the error message in
 * the errorMessage fied of options
 * otherwise returns 1 
 * 
 * @param options 
 */
int openFiles(options_t * options);


#endif