#ifndef ENCODER_H
#define ENCODER_H

#include "args-parser.h"

typedef enum encoder_error_type_t {
    ENCODER_OK,
    ENCODER_WRONG_INPUT_FORMAT
} encoder_error_type_t;

/** 
 * @brief encode inside the input file the given message encoded
 * @returns an error type.
 */
encoder_error_type_t encode(FILE*in, const char *message);

/** 
 * @brief decode the input file and put the result in a heap allocated message string
 * @returns an error type.
 */
encoder_error_type_t decode(FILE*in, char **message);


#endif