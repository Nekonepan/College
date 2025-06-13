#include <iostream>
using namespace std;

int main() {
    const int MAKS = 100;
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
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1: {
                cout << "Jumlah karyawan yang ingin diinput: ";
                cin >> jumlah;
                for (int i = 0; i < jumlah; i++) {
                    cout << "Data ke-" << i + 1 << endl;
                    cout << "ID Karyawan   : ";
                    cin >> id[i];
                    cout << "Nama Karyawan : ";
                    cin >> nama[i];
                    cout << "Jabatan       : ";
                    cin >> jabatan[i];
                    cout << "No. Telp      : ";
                    cin >> telp[i];
                }
                break;
            }
            case 2: {
                // DESCENDING
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

                cout << endl;
                cout << "=== DATA DESCENDING (ID terbesar ke terkecil) ===" << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << "DATA ke-" << i + 1 << endl;
                    cout << "ID      : " << id[i] << endl;
                    cout << "Nama    : " << nama[i] << endl;
                    cout << "Jabatan : " << jabatan[i] << endl;
                    cout << "No. Telp: " << telp[i] << endl;
                    cout << endl;
                }

                // ASCENDING
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

                cout << "=== DATA ASCENDING (ID terkecil ke terbesar) ===" << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << "DATA ke-" << i + 1 << endl;
                    cout << "ID      : " << id[i] << endl;
                    cout << "Nama    : " << nama[i] << endl;
                    cout << "Jabatan : " << jabatan[i] << endl;
                    cout << "No. Telp: " << telp[i] << endl;
                    cout << endl;
                }
                break;
            }
            case 3: {
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
                    cout << "Karyawan dengan ID " << cari_id << " tidak find." << endl;
                }
                break;
            }
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
