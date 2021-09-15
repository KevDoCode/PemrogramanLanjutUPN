#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0
void getModus(int arr[], int size);
int main()
{
    int dataAngka[] = {92, 63, 60, 81, 91, 83, 60, 58, 71, 84, 56, 89, 89, 97, 79, 68, 73, 55, 49, 80, 79, 55, 67};
    int size = sizeof(dataAngka) / sizeof(dataAngka[0]);
    getModus(dataAngka, size);
}

void getModus(int arr[], int size)
{

    sort(arr, arr + size);
    int i, tempModus = 0, modus = 0, frekModus = 0;
    for (i = 0; i < size; i++)
    {

        if (i < 1)
        {
            tempModus++;
        }
        else if (arr[i] == arr[i - 1])
        {
            tempModus++;
        }
        else
        {
            if (frekModus < tempModus)
            {
                frekModus = tempModus;
            }
            tempModus = 0;
        }
    }
    tempModus = 0;
    cout << "Modus : \n";
    for (i = 0; i < size; i++)
    {
        if (frekModus == 0)
        {
            cout << arr[i - 1] << ",";
        }
        else if (i < 1)
        {
            tempModus++;
        }
        else if (arr[i] == arr[i - 1])
        {
            tempModus++;
        }
        else
        {

            if (frekModus == tempModus && arr[i - 1] == arr[i - 2])
            {
                cout << arr[i - 1] << ",";
            }
            tempModus = 0;
        }
    }
}