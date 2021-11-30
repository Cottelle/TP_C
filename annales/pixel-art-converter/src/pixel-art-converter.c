#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/errno.h>
#include <ctype.h>
#include <unistd.h>

#include "bmp-io.h"
#include "filter.h"
#include "gui.h"
#include "utils.h"

typedef struct
{
   int debug;
    int with_filter;
    int with_ui; 
    char * path;
    char * output_path;
} info;



void print_usage(void)
{
    printf("usage: ./fichier OPTIONS\n"
    "options:\n"
    "\t-i FICHIER    indiquer le fichier à ouvrir\n"
    "\t-o FICHIER    indiquer le fichier ou est sauvegarder le résultat\n"
    "\t-u            afficher l'image dans une fenêtre\n"
    "\t-f            application de la fonction de filtre\n"
    "\t-d            afficher le debug\n\n\n"
    "Exemples:\n"
    "./fichier -i image.bmp -d -f -u -o image_out.bmp\n");
}

int GetOption(int argc, char ** argv,info *info)
{
    char c;
    while ((c = getopt (argc, argv, "hi:fduo:")) != -1)
    {
        switch (c)
        {
            case 'h':
                print_usage();
                return 0;
            case 'd':
                info->debug = 1;
                break;
            case 'u':
                info->with_ui = 1;
                break;
            case 'f':
                info->with_filter = 1;
                break;
            case 'i':
                info->path = optarg;
                break;
            case 'o':
                info->output_path = optarg;
                break;
            
            case '?':
                if (optopt == 'i')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);

                print_usage();

                return 1;
        }
    }
    return 0;
}



int main(int argc, char ** argv)
{
    info *info=malloc(sizeof(info));
    info->debug = 0;
    info->with_filter = 0;
    info->with_ui = 0; 
    info->path = NULL;
    info->output_path = NULL;

    if(info->path == NULL)
    {
        fprintf(stderr, "Il manque l'option -i suivie du nom du fichier à ouvrir\n");
        print_usage();
        return 1;
    }
    GetOption(argc,argv,info);
    image_t *image = open_bmp(info->path);
    if(image->error != NULL) goto error;

    if(info->debug)
    {
        print_headers(image);
    }

    if(info->with_filter) 
    {
        apply_filter(image);
    }

    if(info->with_ui)
    {
        render_gui(image);
    }

    if(info->output_path)
    {
        save_bmp(image, info->output_path);
    }



    close_image(image);
    return 0;



    error:
    if(image && image->error)
    {
        fprintf(stderr, "%s\n", image->error);
    }
    close_image(image);
    return 1;

}