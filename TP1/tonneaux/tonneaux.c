#include <stdio.h>
#include "tonneaux.h"

int main(void)
{
    vider(3);
    vider(5);
   remplir(5);
   transferer(5,3);
   vider(3);
   transferer(5,3);
   remplir(5);
   transferer(5,3);
   return 0;
}