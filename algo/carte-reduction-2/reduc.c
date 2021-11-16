#include <stdio.h>

int main(void)
{
    int N;
    scanf("%i", &N);
    unsigned long long cartes[N];
    unsigned long long carte;
    for (int i = 0; i < N; i++)
    {
        scanf("%llu", &carte);
        for (int j = 0; j < i; j++)
        {
            if (cartes[j] == carte)
            {
                printf("%llu\n", carte);
                return 0;
            }
        }
        cartes[i] = carte;
    }
    printf("-1\n");
    return 0;
}