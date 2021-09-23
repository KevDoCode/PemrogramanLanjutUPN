#include <iostream>
#include <cstring>

using namespace std;

typedef struct Alamat
{
    char jalan[30];
    char desa[30];
    char kota[30];
} Alamat;

struct Mahasiswa
{
    char npm[15];
    char nama[30];
    char fakultas[20];
    char prodi[20];
    Alamat alamat;

} mahasiswa[100];

int lastIndex = 0;

//deklarasi Ulang
void tampilData();
void tambahData();
void ubahData();
void hapusData();
void tampilDataBerdasarkanPencarian();
int cariIndex(char npm[15]);

//Fungsi Setiap Menu dan aksi
//Untuk menu utama
void menuUtama()
{
    system("CLS");
    cout << "Aplikasi Manajemen Mahasiswa" << endl;
    tampilData();
    cout << "Pilih Menu :" << endl;
    cout << "1. Cari Data" << endl;
    cout << "2. Tambahkan Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Hapus Data" << endl;

    int menu;
    cin >> menu;

    switch (menu)
    {
    case 1:
        tampilDataBerdasarkanPencarian();
        break;
    case 2:
        tambahData();
        break;
    case 3:
        ubahData();
        break;
    case 4:
        hapusData();
        break;
    default:
        cout << "Menu tidak ditemukan";
        system("pause");
        menuUtama();
        break;
    }
}

bool checkExistsNPM(char npm[15], int index)
{
    int i = 0;
    while (i < lastIndex)
    {
        if (index != i && strcmp(npm, mahasiswa[i].npm) == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

//Form Inputan
void formData(int index)
{
    cin.ignore();
    system("CLS");
    cout << "Form Data Mahasiswa  " << endl;
    bool valid = false;
    cout << "Masukkan NPM Mahasiswa : " << endl;
    cin.getline(mahasiswa[index].npm, 15);
    if (!checkExistsNPM(mahasiswa[index].npm, index))
    {
        cout << "NPM " << mahasiswa[index].npm << " telah ada harap masukkan npm lain harap tekan enter untuk mencoba kembali";
        formData(index);
    }
    else
    {
        cout << "Masukkan Nama Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].nama, 30);
        cout << "Masukkan Fakultas Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].fakultas, 20);
        cout << "Masukkan Prodi Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].prodi, 20);
        cout << "Masukkan Alamat Jalan Rumah Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].alamat.jalan, 30);
        cout << "Masukkan Alamat Desa Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].alamat.desa, 30);
        cout << "Masukkan Alamat Kota Mahasiswa : " << endl;
        cin.getline(mahasiswa[index].alamat.kota, 30);
    }
}

//Untuk Tambah Data
void tambahData()
{
    formData(lastIndex);
    lastIndex++;
    menuUtama();
}

//Untuk Ubah
void ubahData()
{
    system("cls");
    char npm[15];
    cout << "Masukkan NPM mahasiswa yang ingin dirubah : ";
    cin >> npm;
    int index = cariIndex(npm);
    if (index < 0)
    {
        cout << "Data tidak ditemukan" << endl;
        cout << "Tekan enter untuk kembali ke beranda" << endl;
        system("pause");
    }
    else
    {
        formData(index);
    }
    menuUtama();
}

//Untuk Hapus data
void deleteData(int index)
{
    int i = 0, posisi = 0;

    while (i < lastIndex)
    {
        if (i != index)
        {
            mahasiswa[posisi] = mahasiswa[i];
            posisi++;
        }
        i++;
    }
    lastIndex--;
    menuUtama();
}

void hapusData()
{
    system("cls");
    char npm[15];
    cout << "Masukkan NPM mahasiswa yang ingin dirubah : ";
    cin >> npm;
    int index = cariIndex(npm);
    if (index < 0)
    {
        cout << "Data tidak ditemukan" << endl;
        cout << "Tekan enter untuk kembali ke beranda" << endl;
        system("pause");
        menuUtama();
    }
    else
    {
        deleteData(index);
    }
}

// Mendapatkan index array berdasarkan NPM
int cariIndex(char npm[15])
{
    int i = 0;
    int index = -1;

    while (i < lastIndex && index < 0)
    {
        if (strcmp(mahasiswa[i].npm, npm) == 0)
        {
            index = i;
        }
        i++;
    }
    return index;
}

//Menampilkan Data
void tampilData()
{
    int i = 0;
    while (i < lastIndex)
    {
        cout << i + 1 << ".Nama:\t\t" << mahasiswa[i].nama << endl;
        cout << "  NPM:\t\t" << mahasiswa[i].npm << endl;
        cout << "  Fakultas:\t" << mahasiswa[i].fakultas << endl;
        cout << "  Prodi:\t" << mahasiswa[i].prodi << endl;
        cout << "  Kota:\t\t" << mahasiswa[i].alamat.kota << endl;
        cout << "  Desa:\t\t" << mahasiswa[i].alamat.desa << endl;
        cout << "  Jalan:\t" << mahasiswa[i].alamat.jalan << endl;
        i++;
    }
}

void tampilDataBerdasarkanPencarian()
{
    system("CLS");
    char katakunci[30];
    cout << "Masukkan nama atau npm mahasiswa yang ingin dicari : ";
    cin.ignore();
    cin.getline(katakunci, 30);
    int i = 0;
    int urutan = 1;

    while (i < lastIndex)
    {

        if (strcmp(mahasiswa[i].npm, katakunci) == 0 || strcmp(mahasiswa[i].nama, katakunci) == 0)
        {
            cout << urutan << ".Nama:\t\t" << mahasiswa[i].nama << endl;
            cout << "  NPM:\t\t" << mahasiswa[i].npm << endl;
            cout << "  Fakultas:\t" << mahasiswa[i].fakultas << endl;
            cout << "  Prodi:\t" << mahasiswa[i].prodi << endl;
            cout << "  Kota:\t\t" << mahasiswa[i].alamat.kota << endl;
            cout << "  Desa:\t\t" << mahasiswa[i].alamat.desa << endl;
            cout << "  Jalan:\t" << mahasiswa[i].alamat.jalan << endl;
            urutan++;
        }
        i++;
    }

    if (urutan == 1)
    {
        cout << "Data tidak ditemukan" << endl;
    }
    cout << "Tekan enter untuk kembali ke beranda" << endl;
    system("pause");
    menuUtama();
}

int main()
{
    menuUtama();
}
