#include <stdio.h>


char *readline(FILE *file,char* buffer);
/* lit simplement une ligne de de file (de longueur maximal 1000) et la sock dans le buffer de taille 1001 */

int countpath(char *str,char* path);
/* renvoie le nombre de fois où path apparait dans str */

char *decal(char *str,int n);
/* decale le str de n espace (on suposera que c'est possible) */

int testdebut(char *str,char *path);
/* test si path se trouve au debut de str (en fait sans tenir compte du tout premier caratere)*/

char *surpblanc(char *str);
/* Supprime les espace au debut de la ligne */