#include <iostream>
using namespace std;

const int MAKS = 100;

void input_data(int id[], string nama[], string jabatan[], string telp[], int &jumlah) {
    cout << "Jumlah karyawan yang ingin diinput: ";
    cin >> jumlah;
    cin.ignore();
    
    for (int i = 0; i < jumlah; i++) {
        cout << endl;
        cout << "Data ke-" << i + 1 << endl;
        cout << "ID Karyawan : ";
        cin >> id[i];
        cin.ignore();
        cout << "Nama Karyawan : ";
        getline(cin, nama[i]);
        cout << "Jabatan : ";
        getline(cin, jabatan[i]);
        cout << "No. Telp : ";
        getline(cin, telp[i]);
        cout << endl;
    }
}

void tampil_data(int id[], string nama[], string jabatan[], string telp[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "DATA ke-" << i + 1 << endl;
        cout << "ID : " << id[i] << endl;
        cout << "Nama : " << nama[i] << endl;
        cout << "Jabatan : " << jabatan[i] << endl;
        cout << "No. Telp : " << telp[i] << endl;
        cout << endl;
    }
}

void sort_ascending(int id[], string nama[], string jabatan[], string telp[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (id[i] > id[j]) {
                swap(id[i], id[j]);
                swap(nama[i], nama[j]);
                swap(jabatan[i], jabatan[j]);
                swap(telp[i], telp[j]);
            }
        }
    }
}

void sort_descending(int id[], string nama[], string jabatan[], string telp[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (id[i] < id[j]) {
                swap(id[i], id[j]);
                swap(nama[i], nama[j]);
                swap(jabatan[i], jabatan[j]);
                swap(telp[i], telp[j]);
            }
        }
    }
}

void cari_karyawan(int id[], string nama[], string jabatan[], string telp[], int jumlah) {
    int cari_id;
    cout << "Masukkan ID karyawan yang ingin dicari: ";
    cin >> cari_id;
    bool find = false;
    for (int i = 0; i < jumlah; i++) {
        if (id[i] == cari_id) {
            cout << endl;
            cout << "Karyawan ditemukan:" << endl;
            cout << "ID      : " << id[i] << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Jabatan : " << jabatan[i] << endl;
            cout << "No. Telp: " << telp[i] << endl;
            find = true;
            break;
        }
    }
    if (!find) {
        cout << "Karyawan dengan ID " << cari_id << " tidak ditemukan." << endl;
    }
}

int main() {
    int id[MAKS];
    string nama[MAKS];
    string jabatan[MAKS];
    string telp[MAKS];
    int jumlah = 0;
    int pilihan;

    do {
        cout << "===============================================" << endl;
        cout << "           DATA KARYAWAN PT AMBALABU           " << endl;
        cout << "===============================================" << endl;
        cout << "1. Input data karyawan" << endl;
        cout << "2. Tampilkan data karyawan (ASC/DESC)" << endl;
        cout << "3. Cari karyawan berdasarkan ID" << endl;
        cout << "0. Keluar" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                input_data(id, nama, jabatan, telp, jumlah);
                break;
            case 2:
                cout << endl;
                cout << "=== DATA DESCENDING (ID terbesar ke terkecil) ===" << endl;
                sort_descending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);

                cout << "=== DATA ASCENDING (ID terkecil ke terbesar) ===" << endl;
                sort_ascending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);
                break;
            case 3:
                cari_karyawan(id, nama, jabatan, telp, jumlah);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}