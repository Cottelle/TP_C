

void *ca_malloc(int n);
/* revoie un pointeur de n+16 espaces alloué dynamiquement mais renvoie unique le pointeur de plus 8 octect */

void ca_free(void *pointeur);
/* free le pointeur et verifie que il n'y a pas de betises de faites */