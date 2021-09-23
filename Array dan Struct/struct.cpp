#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    char nama[30];
    double npm;
    char jurusan[30];
    int angkatan;
    float ipk;

} mhs[40];

int main()
{

    int i;
    int n;

    cout << "Selamat Datang di Program Manajemen Data Mahasiswa" << endl;
    cout << "===================================================" << endl;
    cout << "1. Write Data" << endl;
    cout << "2. Read Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Delete Data" << endl;
    cout << "===================================================" << endl;
    cout << "Choose number (1 - 4) = ";
    cin >> i;

    if (i == 1)
    {
        for (n = 0; n <= 40; n++)
        {
            cout << "Masukkan Nama Lengkap = ";
            cin >> mhs[n].nama;
            cout << "Masukkan NPM = ";
            cin >> mhs[n].npm;
            cout << "Masukkan Jurusan = ";
            cin >> mhs[n].jurusan;
            cout << "Masukkan Tahun Angkatan = ";
            cin >> mhs[n].angkatan;
            cout << "Masukkan Nilai IPK = ";
            cin >> mhs[n].ipk;
            break;
        }
    }
}