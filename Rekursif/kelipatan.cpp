#include <iostream>

using namespace std;
int kelipatanAngka(int m, int n);

int main()
{
    cout << kelipatanAngka(5, 5);
    return 0;
}

int kelipatanAngka(int m, int n)
{
    int angka = 0;
    while (n > 0)
    {
        angka = angka + m;
        n--;
    }
    return angka;
}