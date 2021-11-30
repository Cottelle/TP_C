
#include "bmp-io.h"
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


void load_pixels(image_t* image, FILE* in);
void load_headers(image_t * image, FILE* in);


image_t *open_bmp(const char * path)
{
    image_t *image = init_image();
    if(image == NULL)
    {
        return NULL;
    }

    FILE *in = fopen(path, "r+b");
    if(in == NULL)
    {
        image->error = strerror(errno);
        goto error;
    }

    load_headers(image, in);
    if(image->error != NULL) goto error;
    
    load_pixels(image, in);
    if(image->error != NULL) goto error;


    error:
    if(in) fclose(in);
    return image;
}



void load_pixels(image_t* image, FILE* in)
{
    fseek(in, image->offset, SEEK_SET);
    image->pixels = malloc(image->width * image->height * sizeof(image->pixels[0]));
    if(image->pixels == NULL)
    {
        image->error = "Problème d'allocation mémoire";
        return;
    }

    unsigned row_padding = 0;
    if((image->width*3) % 4) row_padding = 4 - ((image->width*3) % 4);

    for(uint32_t row = 0; row < image->height; row++)
    {
        for(uint32_t col = 0; col < image->width; col++)
        {
            if(0 == fread(&image->pixels[row*image->width + col], 3, 1, in))
            {
                image->error = "Problème de format lors de la lecture des pixels";
                return;
            }
        }
        fseek(in, row_padding, SEEK_CUR);
    }

}


void load_headers(image_t * image, FILE* in)
{
    fseek(in, 2, SEEK_CUR);
    fread(&image->size, 4, 1, in);

    fseek(in, 4, SEEK_CUR);
    fread(&image->offset, 4, 1, in);

    fseek(in, 14, SEEK_SET);
    fread(&image->DIB_header_size, 2, 1, in);
    if(image->DIB_header_size != BITMAPINFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV2INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV3INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV4INFOHEADER_SIZE
    && image->DIB_header_size != BITMAPV5INFOHEADER_SIZE)
    {
        fprintf(stderr, "DIB header size: %u\n", image->DIB_header_size);
        image->error = "The header is not of type BITMAPV*INFOHEADER";
        return;
    }


    fseek(in, 18, SEEK_SET);
    fread(&image->width, 4, 1, in);
    fread(&image->height, 4, 1, in);

    fseek(in, 28, SEEK_SET);
    fread(&image->color_depth, 2, 1, in);
    if(image->color_depth != 24)
    {
        image->error = "We currently only support a color depth of 24";
        return;
    }

    fseek(in, 30, SEEK_SET);
    fread(&image->compression_method, 4, 1, in);

    switch(image->compression_method) {
        case COMPRESSION_BI_RGB:
            image->red_mask   = 0xFF0000;
            image->green_mask = 0xFF00;
            image->blue_mask  = 0xFF;
            image->red_shift = 16;
            image->green_shift = 8;
            image->blue_shift = 0;
        break;
        case COMPRESSION_BI_BITFIELDS:
            fseek(in, 30, SEEK_SET);
            fread(&image->red_mask, 4, 1, in);
            fread(&image->green_mask, 4, 1, in);
            fread(&image->blue_mask, 4, 1, in);

            // TODO: compute that dynamically
            image->red_shift = 16;
            image->green_shift = 8;
            image->blue_shift = 0;
            image->alpha_shift = 0;

            if(image->color_depth == 32)
            {
                fread(&image->alpha_mask, 4, 1, in);
            }
        break;
        default:
        image->error = "Compression method no supported";
    }
}



void close_image(image_t*image)
{
    if(image) {
        free(image->pixels);
    }
    free(image);
}



int save_bmp(image_t* image, char *path)
{
    FILE *out = fopen(path, "wb");
    if(out == NULL) return 0;
    
    fwrite("BM", 2, 1, out);

    uint32_t tmp_word = 0;
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // Size (put 0 and come back lated to enter the size)
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // application specific
    tmp_word = 54;
    fwrite(&tmp_word, 4, 1, out); // offset
    tmp_word = 40;
    fwrite(&tmp_word, 4, 1, out); // DIB header size

    tmp_word = image->width;
    fwrite(&tmp_word, 4, 1, out); 
    tmp_word = image->height;
    fwrite(&tmp_word, 4, 1, out); 

    tmp_word = 1;
    fwrite(&tmp_word, 2, 1, out);  // plane	Number of color planes being used
    tmp_word = 24;
    fwrite(&tmp_word, 2, 1, out); // Number of bits per pixel
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // BI_RGB, no pixel array compression used
    tmp_word = 16;
    fwrite(&tmp_word, 4, 1, out); // Size of the raw bitmap data (including padding)
    tmp_word = 2835;
    fwrite(&tmp_word, 4, 1, out); // pixels/metre horizontal	Print resolution of the image,
    tmp_word = 2835;
    fwrite(&tmp_word, 4, 1, out); // pixels/metre vertical	Print resolution of the image,
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // Number of colors in the palette
    tmp_word = 0;
    fwrite(&tmp_word, 4, 1, out); // important colors	0 means all colors are important


    unsigned row_padding = 0;
    if(image->width % 4) row_padding = 4 - (image->width % 4);

    for(uint32_t row = 0; row < image->height; row++)
    {
        for(uint32_t col = 0; col < image->width; col++)
        {
            if(0 == fwrite(&image->pixels[row*image->width + col], 3, 1, out))
            {
                fclose(out);
                return 0;
            }
        }
        fwrite(&tmp_word, row_padding, 1, out);
    }

    tmp_word = ftell(out); // get size;
    fseek(out, 2, SEEK_SET); // go back at the beginning to write the size
    fwrite(&tmp_word, 4, 1, out);

    fclose(out);
    return 1;
}


