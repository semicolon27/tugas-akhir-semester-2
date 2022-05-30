/**
 * KELOMPOK 3
 * - M. Hanan Bian Prakoso		(065121105)
 * - Novia Permata Sari		(065121057)
 * - Randy Apriliansyah		(065121023)
 * - Heni Herlina 			(065121044)
 *
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// panjang maksimal data
const int length = 100;
int panjang_list_pesanan = 0;
int panjang_list_menu = 4;

struct Menu
{
    string nama;
    int harga;
};

struct Pesanan
{
    int index_menu;
    int jumlah = 0;
};

Menu list_menu[4] = {
    {"Nasi Goreng Informatika", 5000},
    {"Nasi Soto Ayam Internet", 7000},
    {"Gado-gado Disket", 4500},
    {"Bubur Ayam LAN", 4000},
};

Pesanan list_pesanan[100];

void tampil_menu()
{
    cout << "==============================" << endl;
    cout << "| Daftar Menu Makanan        |" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < panjang_list_menu; i++)
    {
        cout << " | " << i + 1 << " | " << list_menu[i].nama << " | " << list_menu[i].harga << " |" << endl;
    }
    cout << "==============================" << endl;
}

void pesanan_baru()
{
    int nomor_menu;
    int jumlah;
    cout << "0 => Kembali ke Menu Utama" << endl;
    cout << "Masukkan Nomor Menu : ";
    cin >> nomor_menu;

    // balik ke menu apabila input 0
    if (nomor_menu == 0)
        return;

    cout << "Masukkan Jumlah : ";
    cin >> jumlah;
    // index_menu = nomor_menu - 1 karena saat daftar menu ditampilkan, urutannya dimulai dari 1, bukan 0.
    list_pesanan[panjang_list_pesanan].index_menu = nomor_menu - 1;
    list_pesanan[panjang_list_pesanan].jumlah = jumlah;
    panjang_list_pesanan++;
}

// tampil tabel pesanan
void show_list_pesanan()
{
    cout << "========================" << endl;
    cout << "| List Pesanan         |" << endl;
    cout << "========================" << endl;

    int total_harga = 0;

    cout << " | "
         << "No."
         << " | "
         << "Nama Pesanan"
         << " | "
         << "Jumlah"
         << " | " << endl;
    for (int i = 0; i < panjang_list_pesanan; i++)
    {
        int index_menu = list_pesanan[i].index_menu;
        total_harga = total_harga + (list_menu[index_menu].harga * list_pesanan[i].jumlah);
        cout << " |  " << i + 1 << "  | "
             << " | " << list_menu[index_menu].nama << " | "
             << list_pesanan[i].jumlah << " | " << endl;
    }

    cout << " | "
         << "Total Harga"
         << " | " << total_harga << " | " << endl;

    if (panjang_list_pesanan <= 0)
    {
        cout << endl;
        cout << "!! Pesanan Kosong !!" << endl;
        cout << endl;
    }
}

void tambah_jumlah()
{
    try
    {
        cout << "==========================" << endl;
        cout << "| Tambah Jumlah Pesanan |" << endl;
        cout << "==========================" << endl;

        cout << "0 => Kembali ke Menu Utama" << endl;

        int nomor_pesanan;
        cout << "Masukan nomor pesanan yang akan ditambah: ";
        cin >> nomor_pesanan;

        // balik ke menu apabila input 0
        if (nomor_pesanan == 0)
            return;

        int tambah_jumlah;
        cout << "Masukan jumlah yang akan ditambahkan: ";
        cin >> tambah_jumlah;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int index_pesanan = nomor_pesanan - 1;
        list_pesanan[index_pesanan].jumlah = list_pesanan[index_pesanan].jumlah + tambah_jumlah;

        cout << "Berhasil tambah jumlah menu " << list_menu[index_pesanan].nama << "Sebanyak" << tambah_jumlah << ", total = " << list_pesanan[index_pesanan].jumlah << endl;
        return;
    }
    catch (...) // apabila input tidak valid
    {
        cout << "Gagal tambah jumlah, input tidak valid" << endl;
    }
}

void kurangi_jumlah()
{
    try
    {
        cout << "==========================" << endl;
        cout << "| Kurangi Jumlah Pesanan |" << endl;
        cout << "==========================" << endl;
        int nomor_pesanan;

        cout << "0 => Kembali ke Menu Utama" << endl;
        cout << "Masukan nomor pesanan yang akan dikurangi: ";
        cin >> nomor_pesanan;

        // balik ke menu apabila input 0
        if (nomor_pesanan == 0)
            return;

        int kurangi_jumlah;
        cout << "Masukan jumlah yang akan dikurangi: ";
        cin >> kurangi_jumlah;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int index_pesanan = nomor_pesanan - 1;
        list_pesanan[index_pesanan].jumlah = list_pesanan[index_pesanan].jumlah - kurangi_jumlah;

        cout << "Berhasil kurangi jumlah pesanan " << list_menu[index_pesanan].nama << "Sebanyak" << kurangi_jumlah << ", total = " << list_pesanan[index_pesanan].jumlah << endl;
        return;
    }
    catch (...) // apabila input tidak valid
    {
        cout << "Gagal kurangi jumlah, input tidak valid" << endl;
    }
}

void hapus_pesanan()
{
    cout << "=================" << endl;
    cout << "| Hapus Pesanan |" << endl;
    cout << "=================" << endl;

    int nomor_pesanan;
    cout << "0 => Kembali ke Menu Utama" << endl;
    cout << "Masukan nomor pesanan yang akan DIHAPUS : ";
    cin >> nomor_pesanan;

    // balik ke menu apabila input 0
    if (nomor_pesanan == 0)
        return;

    int index_pesanan = nomor_pesanan - 1;
    if (index_pesanan == -1)
    {
        cout << "!!!Gagal hapus pesanan, nomor pesanan tidak ditemukan!!!" << endl;
        return;
    }
    int index_menu = list_pesanan[index_pesanan].index_menu;
    cout << "Pesanan dihapus : " << endl;
    cout << "- Nama menu : " << list_menu[index_menu].nama << endl;

    for (int j = index_pesanan; j < panjang_list_pesanan; j++)
    {
        list_pesanan[j] = list_pesanan[j + 1];
    }
    cout << "Berhasil hapus pesanan" << endl;
    panjang_list_pesanan -= 1;
    return;
}

void clear()
{
    string input;
    cout << "Yakin akan hapus semua pesanan ? (Y/N): ";
    getline(cin, input);
    if (input == "Y" || input == "y")
    {
        panjang_list_pesanan = 0;
        cout << "Berhasil hapus semua pesanan" << endl;
    }
    else
    {
        cout << "Batal hapus semua pesanan" << endl;
    }
}

int main()
{
    auto pilihan_user = 0;
    auto isLoop = true;

    while (isLoop)
    {
        show_list_pesanan();
        cout
            << "Aplikasi Pesanan"
            << "\n1. pesanan baru"
            << "\n2. tambah jumlah pesanan"
            << "\n3. kurangi jumlah pesanan "
            << "\n4. hapus pesanan"
            << "\n5. clear"
            << "\n0. Quit" << endl;
        cout << "Masukan pilihan: ";
        cin >> pilihan_user;
        cin.ignore();

        switch (pilihan_user)
        {
        case 1:
            tampil_menu();
            pesanan_baru();
            cout << endl;
            break;

        case 2:
            show_list_pesanan();
            tambah_jumlah();
            cout << endl;
            break;

        case 3:
            show_list_pesanan();
            kurangi_jumlah();
            cout << endl;
            break;

        case 4:
            show_list_pesanan();
            hapus_pesanan();
            cout << endl;
            break;

        case 5:
            clear();
            cout << endl;
            break;

        case 0:
            isLoop = false;
            cout << "Program exit." << endl;
            break;

        default:
            cout << "Salah input!" << endl;
            cout << endl;
            break;
        }
    }

    return 0;
}
