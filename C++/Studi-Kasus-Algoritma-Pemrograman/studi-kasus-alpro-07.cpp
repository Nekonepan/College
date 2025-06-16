#include <iostream>
#include <fstream>
using namespace std;

const int MAKS = 100;

void write_data(const string id[], const string nama[], const string jabatan[], const string telp[], int jumlah) {
    ofstream file("data_karyawan.txt");
    if (file.is_open()) {
        file << jumlah << endl;
        for (int i = 0; i < jumlah; i++) {
            file << id[i] << endl;
            file << nama[i] << endl;
            file << jabatan[i] << endl;
            file << telp[i] << endl;
            file << "--------------------------" << endl;
        }
        file.close();
    } else {
        cout << "Gagal menyimpan data" << endl;
    }
}

void read_data(string id[], string nama[], string jabatan[], string telp[], int &jumlah) {
    ifstream file("data_karyawan.txt");
    if (file.is_open()) {
        file >> jumlah;
        file.ignore();
        for (int i = 0; i < jumlah; i++) {
            getline(file, id[i]);
            getline(file, nama[i]);
            getline(file, jabatan[i]);
            getline(file, telp[i]);
            string batas;
            getline(file, batas);
        }
        file.close();
    } else {
        jumlah = 0;
    }
}

void input_data(string id[], string nama[], string jabatan[], string telp[], int &jumlah) {
    cout << "Jumlah karyawan yang ingin diinput: ";
    cin >> jumlah;
    cin.ignore();
    
    for (int i = 0; i < jumlah; i++) {
        cout << endl;
        cout << "Data ke-" << i + 1 << endl;
        cout << "ID Karyawan : ";
        getline(cin, id[i]);
        cout << "Nama Karyawan : ";
        getline(cin, nama[i]);
        cout << "Jabatan : ";
        getline(cin, jabatan[i]);
        cout << "No. Telp : ";
        getline(cin, telp[i]);
        cout << endl;
    }

    write_data(id, nama, jabatan, telp, jumlah);
}

void tampil_data(const string id[], const string nama[], const string jabatan[], const string telp[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "DATA ke-" << i + 1 << endl;
        cout << "ID : " << id[i] << endl;
        cout << "Nama : " << nama[i] << endl;
        cout << "Jabatan : " << jabatan[i] << endl;
        cout << "No. Telp : " << telp[i] << endl;
        cout << endl;
    }

    write_data(id, nama, jabatan, telp, jumlah);
}

void sort_ascending(string id[], string nama[], string jabatan[], string telp[], int jumlah) {
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

void sort_descending(string id[], string nama[], string jabatan[], string telp[], int jumlah) {
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

void cari_karyawan(const string id[], const string nama[], const string jabatan[], const string telp[], int jumlah) {
    string cari_id;

    cout << "Masukkan ID karyawan yang ingin dicari: ";
    getline(cin >> ws, cari_id);

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
    string id[MAKS];
    string nama[MAKS];
    string jabatan[MAKS];
    string telp[MAKS];
    int jumlah = 0;
    int pilihan;

    read_data(id, nama, jabatan, telp, jumlah);

    do {
        system("cls");
        cout << "===============================================" << endl;
        cout << "           DATA KARYAWAN PT AMBATAGOR          " << endl;
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
            case 1: {
                system("cls");
                input_data(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                cout << endl;
                cout << "=== DATA DESCENDING (ID terbesar ke terkecil) ===" << endl;
                sort_descending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);
                
                cout << "=== DATA ASCENDING (ID terkecil ke terbesar) ===" << endl;
                sort_ascending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                cari_karyawan(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 0: {
                system("cls");
                cout << "Program selesai." << endl;
                system("pause");
                break;
            }
            default: {
                cout << "Pilihan tidak valid." << endl;
            }
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}