#include <stdio.h>

int pangkat(int *a, int *b, int *c)
{
    int i;

    if (*b == 0)
    {
    }

    else
    {
        for (i = 0; i < *b; i++)
        {
            *c *= (*a);
        }
    }
}

int main()
{
    int hasil = 1;
    int a = 2, b = 2;
    pangkat(&a, &b, &hasil);
    printf("Hasil %d pangkat %d = %d", a, b, hasil);

    return 0;
}
