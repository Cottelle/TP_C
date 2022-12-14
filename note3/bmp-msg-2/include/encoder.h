#ifndef ENCODER_H
#define ENCODER_H

#include "types.h"
#include "args-parser.h"
#include <stdint.h>


/** 
 * @brief encode inside the input file the given message encoded
 * @returns an error type.
 */
error_type_t encode(FILE*in, const char *message, uint64_t length, uint8_t compr);

/** 
 * @brief decode the input file and put the result in a heap allocated message string
 * @returns an error type.
 */
error_type_t decode(FILE*in, char **message, uint64_t *length);


/** 
 * @brief encode one byte in the file (in the next 8 bytes in the file)
 */
void encode_byte(FILE * in, uint8_t c,uint8_t compr);

/** 
 * @brief decode one byte from the file (from the next 8 bytes of the file)
 */
uint8_t decode_byte(FILE * in,uint8_t compr);

#endif