#include <errno.h>
#include <stdlib.h>


struct List;
typedef struct List List;


List * list_create();


void*  list_last(const List *l);
void*  list_first(const List *l);
size_t list_size(const List *l);

void * list_pop_first(List *l);
int    list_push_last(List *l, void* element);

void   list_free(List *l);