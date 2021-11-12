#include "pair.h"
#include <stdlib.h>


pair_t *pair_create(void *first, void *second){
    pair_t *pair=malloc(sizeof(pair_t));
    if (pair==NULL){
        free(pair);
        return NULL;
    }
    pair->first=first;
    pair->second=second;
    return pair;
}

void *pair_get_first(pair_t *pair){
    return (pair->first);
}

void *pair_get_second(pair_t *pair){
    return (pair->second);
}

void pair_free(pair_t *pair){
    free(pair);
}

void pair_swap(pair_t *pair){
    void * first=pair->first;
    pair->first=pair->second;
    pair->second=first;
}

