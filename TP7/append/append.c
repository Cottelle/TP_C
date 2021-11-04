#include <stdio.h>
#include <stdlib.h>
#include "tps_unit_test.h"

int append(int ** tab, size_t *size, int value){
    if (tab == NULL || size==NULL){
        return 0;
    }
    int *tabcopy=realloc(*tab,(*size+1)*sizeof(int));
    if (tabcopy==NULL){
        free(tabcopy);
        return 0;
    }
    tabcopy[*size]=value;
    *size=*size+1;
    *tab=tabcopy;
    return 1;




}