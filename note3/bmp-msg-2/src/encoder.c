#include "encoder.h"

#include <string.h>
#include <stdlib.h>

int isFileBMP(FILE *file)
{
    char key[2];
    fread(key, 1, 2, file);

    return key[0] == 'B' && key[1] == 'M';
}

void encode_byte(FILE *in, uint8_t c, uint8_t compr)
{
    uint8_t pixel;
    uint8_t tab[10];
    tab[1] = 0b11111110;
    tab[2] = 0b11111100;
    tab[4] = 0b11110000;
    tab[5] = 0b1;
    tab[6] =0b11;
    tab[8]= 0b1111;
    for (int bi = 0; bi < 8 / compr; bi++)
    {
        fread(&pixel, 1, 1, in);
        pixel = (pixel & tab[compr]) | ((c & (tab[compr+4] << (bi * compr))) >> (bi * compr));
        fseek(in, -1, SEEK_CUR);
        fwrite(&pixel, 1, 1, in);
    }
}

uint8_t decode_byte(FILE *in, uint8_t compr)
{
    uint8_t pixel;
    uint8_t byte = 0;
    uint8_t tab[5];
    tab[1] = 0b00000001;
    tab[2] = 0b00000011;
    tab[4] = 0b00001111;

    for (int bi = 0; bi < 8 / compr; bi++)
    {
        fread(&pixel, 1, 1, in);
        byte = byte | ((pixel & tab[compr]) << (bi * compr));
    }
    return byte;
}

void seekPixelArray(FILE *in)
{
    uint32_t pixel_offset;
    fseek(in, 10, SEEK_SET);
    fread(&pixel_offset, 4, 1, in);
    fseek(in, pixel_offset, SEEK_SET);
}

uint32_t getDataSize(FILE *in)
{
    uint32_t dataSize;
    fseek(in, 34, SEEK_SET);
    fread(&dataSize, 4, 1, in);
    if (dataSize == 0)
    {
        uint16_t bitsPerPixel;
        uint32_t width;
        uint32_t height;
        fseek(in, 28, SEEK_SET);
        fread(&bitsPerPixel, 2, 1, in);
        fseek(in, 18, SEEK_SET);
        fread(&width, 4, 1, in);
        fseek(in, 22, SEEK_SET);
        fread(&height, 4, 1, in);
        dataSize = (uint32_t)((((bitsPerPixel * width + 31) * 4 * height) / 32));
    }
    return dataSize;
}

error_type_t encode(FILE *in, const char *message, uint64_t length, uint8_t compr)
{
    uint32_t magic = 0b10101010;
    if (!isFileBMP(in))
        return ERROR_WRONG_INPUT_FORMAT;

    if ((length + 8) * 8 > getDataSize(in))
    {
        return ERROR_MESSAGE_TOO_LONG;
    }

    seekPixelArray(in);
    printf("[");                        // bare de progression du type [===========================]
    encode_byte(in, compr, 1);          //il est coder en premier pour pouvoir le recuperer en premier et pouvoir decoder la suite avec sa valeur. Pas de bouble for car qu'un seul octet a passer uint8_t
    for (uint32_t i = 0; i < 4; i++)
    {
        encode_byte(in, (magic >> (8 * i)) & 0xFF, compr);               
    }
    printf("=");                        // affiche des = quand il a reussi a encode magic et lenght
    for (uint32_t i = 0; i < 8; i++)
    {
        if(i==4){
            printf("=");
        }
        encode_byte(in, (length >> (8 * i)) & 0xFF, compr);
    }

    for (uint32_t i = 0; i < length; i++)
    {
        if(i%40==0)                     //puit un = tout les 40 octects, ce qui reste tres rapide, mais une barre de progression rapide c'est agréable. 
        {
            printf("=");
        }
        encode_byte(in, message[i], compr);
    }
    printf("]\n");
    return ENCODER_OK;
}

error_type_t decode(FILE *in, char **message, uint64_t *length)
{
    uint32_t magic = 0;
    uint32_t mustbe = 0b10101010;
    uint8_t compr=0;
    if (!isFileBMP(in))
        return ERROR_WRONG_INPUT_FORMAT;

    seekPixelArray(in);
    //get compr qui est utilie pour la suite
    compr=(decode_byte(in,1));                                //est coder sur 1 octets 
    //  get magic number
    for (uint64_t i = 0; i < 4; i++)
    {
        magic = magic | (decode_byte(in,compr) << (8 * i));
    }
    if (magic != mustbe)
    {

        return (ERROR_NO_DECODING_MESSAGE);
    }
    // retrieve the lenght of the message
    for (uint64_t i = 0; i < 8; i++)
    {
        *length = *length | (decode_byte(in,compr) << (8 * i));
    }

    // alloc the memory to store the message
    *message = malloc(*length + 1);
    (*message)[*length] = '\0';

    // retrieve the message
    for (uint64_t i = 0; i < *length; i++)
    {
        (*message)[i] = decode_byte(in,compr);
    }

    return ENCODER_OK;
}
