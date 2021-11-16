#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int count(int64_t n)
{
    int count = 0;
    for (int i = 0; i < 64; i++)
    {
        if ((n >> i) & 1)
        {
            count++;
        }
    }
    return count;
}

int match(int64_t n, int64_t m)
{
    while (n)
    {
        if (n & 0xFF == m)
        {
            return 1;
        }
        n = n >> 1;
    }
    return 0;
}

int main(void)
{
    int64_t n;
    scanf("%li", &n);
    printf("nb de 1 =%i\n", count(n));
    int64_t m;
    scanf("%li", &m);
    printf("match = %i\n", match(n, m));
}
