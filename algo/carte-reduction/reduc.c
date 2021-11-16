#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N;
    scanf("%i", &N);
    int present[1000000] = {0};
    int a;
    for (int i = 0; i < N; i++)
    {
        scanf("%i", &a);
        if (present[a] == 1)
        {
            printf("%i\n", a);
            return 0;
        }
        present[a] = 1;
    }
    printf("-1\n");
}