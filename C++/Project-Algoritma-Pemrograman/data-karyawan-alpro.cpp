#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAKS = 100;

void write_data(const string id[], const string nama[], const string jabatan[], const string telp[], int jumlah) {
    ofstream file("data_karyawan.txt");
    if (file.is_open()) {
        file << "Jumlah Karyawan : " << jumlah << endl << endl;
        file << "| " << setw(12) << left << "ID Karyawan" 
             << "| " << setw(17) << left << "Nama Karyawan" 
             << "| " << setw(12) << left << "Jabatan" 
             << "| " << setw(12) << left << "No. HP" 
             << "|" << endl;
        file << setfill('-') << setw(61) << "-" << setfill(' ') << endl;

        for (int i = 0; i < jumlah; i++) {
            file << "| " << setw(12) << left << id[i] 
                 << "| " << setw(17) << left << nama[i] 
                 << "| " << setw(12) << left << jabatan[i] 
                 << "| " << setw(12) << left << telp[i] 
                 << "|" << endl;
        }

        file.close();
        cout << "Data berhasil disimpan dalam bentuk tabel." << endl;
    } else {
        cout << "Gagal membuka file." << endl;
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
    cout << "| " << setw(12) << left << "ID Karyawan"
         << "| " << setw(17) << left << "Nama Karyawan" 
         << "| " << setw(12) << left << "Jabatan"
         << "| " << setw(12) << left << "No. HP"
         << "|" << endl;

    cout << setfill('-') << setw(61) << "-" << setfill(' ') << "\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(12) << left << id[i] 
             << "| " << setw(17) << left << nama[i] 
             << "| " << setw(12) << left << jabatan[i] 
             << "| " << setw(12) << left << telp[i] 
             << "|" << endl;
    }
}

void sort_ascending(string id[], string nama[], string jabatan[], string telp[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (id[i] > id[j]) {
                string temp;
                
                //SWAP ID
                temp = id[i];
                id[i] = id[j];
                id[j] = temp;
                
                //SWAP NAMA
                temp = nama[i];
                nama[i] = nama[j];
                nama[j] = temp;
                
                //SWAP JABATAN
                temp = jabatan[i];
                jabatan[i] = jabatan[j];
                jabatan[j] = temp;
                
                //SWAP TELEPON
                temp = telp[i];
                telp[i] = telp[j];
                telp[j] = temp;
            }
        }
    }
}

void sort_descending(string id[], string nama[], string jabatan[], string telp[], int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (id[i] < id[j]) {
                string temp;
                
                //SWAP ID
                temp = id[i];
                id[i] = id[j];
                id[j] = temp;
                
                //SWAP NAMA
                temp = nama[i];
                nama[i] = nama[j];
                nama[j] = temp;
                
                //SWAP JABATAN
                temp = jabatan[i];
                jabatan[i] = jabatan[j];
                jabatan[j] = temp;
                
                //SWAP TELEPON
                temp = telp[i];
                telp[i] = telp[j];
                telp[j] = temp;
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
            case 1: { //INPUT DATA KARYAWAN ------------------------------------------------
                system("cls");
                input_data(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 2: { //TAMPILKAN DATA KARYAWAN --------------------------------------------
                system("cls");
                cout << endl;
                cout << "=== DATA DESCENDING (ID terbesar ke terkecil) ===" << endl;
                sort_descending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);
                
                cout << endl;
                cout << "=== DATA ASCENDING (ID terkecil ke terbesar) ===" << endl;
                sort_ascending(id, nama, jabatan, telp, jumlah);
                tampil_data(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 3: { //CARI KARYAWAN ------------------------------------------------------
                system("cls");
                cari_karyawan(id, nama, jabatan, telp, jumlah);
                system("pause");
                break;
            }
            case 0: { // KELUAR ------------------------------------------------------------
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