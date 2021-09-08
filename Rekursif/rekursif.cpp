#include <iostream>
using namespace std;
//n = 1 = m
int panggil(int m, int n);
int panggilFor(int m, int n);
int main()
{
    cout << panggil(2, 4);
    cout << panggilFor(2, 4);
    return 0;
}

int panggilFor(int m, int n)
{
    int i, angka = 0;
    while (n > 0)
    {
        angka = m + angka;
        n--;
    }
    return angka;
}

int panggil(int m, int n)
{
    if (n == 1)
    {
        return m;
    }
    else
    {
        return m + panggil(m, n - 1);
    }
}
