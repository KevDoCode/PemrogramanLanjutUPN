#include <iostream>

using namespace std;

void pangkat(int *x, int y)
{
    int i, hasil = 1;
    if (y != 0)
    {
        for (i = 0; i < y; i++)
        {
            hasil *= (*x);
        }
    }

    *x = hasil;
}

int main()
{
    int x = 2, y = 0;
    pangkat(&x, y);
    cout << x;
}