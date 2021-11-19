#include "encoder.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>


int isFileBMP(FILE * file) {
    char key[2];
    fread(key, 1, 2, file);

    return key[0] == 'B' && key[1] == 'M';
}

void encode_byte(FILE * in, char c){
    uint8_t pixel;

    for(int bi = 0; bi < 8; bi++)
    {    
        fread(&pixel, 1, 1, in);
        pixel = (pixel & 0b11111110) | ((c & (1 << bi)) >> bi);
        fseek(in, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, in);
    }
}

void seekPixelArray(FILE *in) {
    uint32_t pixel_offset;
    fseek(in, 10, SEEK_SET);
    fread(&pixel_offset, 4, 1, in);
    fseek(in, pixel_offset, SEEK_SET);
}

encoder_error_type_t encode(FILE*in, const char *message) {

    if(!isFileBMP(in)) return ENCODER_WRONG_INPUT_FORMAT;

    seekPixelArray(in);

    uint32_t len = strlen(message);

    for(uint32_t i = 0; i < 4; i++) {
        encode_byte(in, (len >> (8*i)) & 0xFF);
    }

    for(uint32_t i = 0; i < len; i++) {
        encode_byte(in, message[i]);
    }
    return ENCODER_OK;

}

encoder_error_type_t decode(FILE*in, char **message){

    if(!isFileBMP(in)) return ENCODER_WRONG_INPUT_FORMAT;

    uint32_t len = 0;
    // retrieve the lenght of the message
    //...

    // alloc the memory to store the message
    *message = malloc(len + 1);
    (*message)[len] = '\0';

    // retrieve the message
    //...

    return ENCODER_OK;
}

