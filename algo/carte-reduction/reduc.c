#include <stdio.h>
#include <stdlib.h>
// int iserdico(int *tab, int value, int *size)
// {
//     int deb = 0;
//     int fin = *size;
//     while (deb != fin)
//     {
//         int ite=(fin-deb)/2;
//         if (tab[ite] < value)
//         {
//             fin=ite;
//         }
//         else if (tab[ite] == value)
//         {
//             return 0;
//         }
//         else
//         {
//             deb=ite;
//         }
//     }
// }

int main(void)
{
    int N;
    scanf("%i", &N);
    int cartes[N];
    int a;
    for (int i = 0; i < N; i++)
    {
        scanf("%i", &a);
        for (int j = 0; j < i; j++)
        {
            if (a == cartes[j])
            {
                printf("%i\n", a);
                return 0;
            }
        }
        cartes[i] = a;
    }
    printf("-1\n");
}
