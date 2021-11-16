#ifndef G
#define G

#include <stdint.h>


uint64_t ci_encode(uint32_t value);
int ci_check(uint64_t value);
uint32_t ci_decode(uint64_t value, int *ok);

#endif