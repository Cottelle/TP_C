#include <stdint.h>
#include "checked-int.h"
#include "tps_unit_test.h"


uint64_t ci_encode(uint32_t value){
    int64_t n1 = value;
    int64_t n2 = n1<<32;
    return (n1 | n2);
}



int ci_check(uint64_t value)
{
    int64_t acc = value <<32;
    int32_t n1 = acc >> 32;
    int32_t n2 = value >> 32;
    if (n2 != n1)
    {
        return 0;
    } 
    return 1;
}
uint32_t ci_decode(uint64_t value, int *ok)
{
    int equ = ci_check(value);
    if (equ>0)
    {
        int32_t n = value >> 32;
        if (ok != NULL)
        {
            *ok=1;
        }
        return n;
    }
    else
    {
        if (ok != NULL)
        {
            *ok=0;
        }
        int32_t n1 = value >> 32;
        int64_t acc = value <<32;
        int32_t n2 = acc >> 32;
        if (n2 < n1)
        {
            return n2;
        }
        else
        {
            return n1;
        }

    }

}

