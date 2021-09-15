#include <iostream>

using namespace std;

int main()
{
    int x;
    int *px;

    x = 10;
    px = &x;
    cout << "x berada di alamat memori " << px;
    return 0;
}