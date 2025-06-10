#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string tanggal;
    int jumlahLayanan;

    cout << "===============================" << endl;
    cout << "STRUK REKAP LAYANAN HARI INI" << endl;
    cout << "       BARBERSHOP ANDRE" << endl;
    cout << "===============================" << endl;

    cout << "Masukkan tanggal rekap (DD/MM/YYYY): ";
    getline(cin, tanggal);
    cout << "Masukkan jumlah jenis layanan hari ini : ";
    cin >> jumlahLayanan;

    cin.ignore();

    vector<string> namaLayanan(jumlahLayanan);
    vector<int> jumlahPelanggan(jumlahLayanan);

    cout << endl;
    cout << "=== INPUT JENIS LAYANAN ===" << endl;
    for (int i = 0; i < jumlahLayanan; ++i) {
        cout << "Nama Layanan ke-" << i + 1 << ": ";
        getline(cin, namaLayanan[i]);
    }

    cout << endl;
    cout << "=== INPUT JUMLAH PELANGGAN ===" << endl;
    for (int i = 0; i < jumlahLayanan; ++i) {
        cout << "Jumlah pelanggan untuk " << namaLayanan[i] << ": ";
        cin >> jumlahPelanggan[i];
    }

    int totalPelanggan = 0;
    for (int i = 0; i < jumlahLayanan; ++i) {
        totalPelanggan += jumlahPelanggan[i];
    }

    cout << endl;
    cout << "===============================" << endl;
    cout << "     STRUK REKAP LAYANAN HARI INI" << endl;
    cout << "       Barbershop Andre" << endl;
    cout << "       Tanggal: " << tanggal << endl;
    cout << "===============================" << endl;
    cout << "Jenis Layanan        Pelanggan" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < jumlahLayanan; ++i) {
        cout << namaLayanan[i] << "\t\t" << jumlahPelanggan[i] << endl;
    }

    cout << "------------------------------" << endl;
    cout << "Total Pelanggan Hari Ini: " << totalPelanggan << endl;

    ofstream file("rekap_layanan_barbershop.txt");
    file << "===============================" << endl;
    file << "     STRUK REKAP LAYANAN HARI INI" << endl;
    file << "       Barbershop Andre" << endl;
    file << "       Tanggal: " << tanggal << endl;
    file << "===============================" << endl;
    file << "Jenis Layanan        Pelanggan" << endl;
    file << "------------------------------" << endl;
    for (int i = 0; i < jumlahLayanan; ++i) {
        file << namaLayanan[i] << "\t\t" << jumlahPelanggan[i] << endl;
    }
    file << "------------------------------" << endl;
    file << "Total Pelanggan Hari Ini: " << totalPelanggan << endl;
    file.close();

    cout << endl;
    cout << "Rekap berhasil disimpan ke file: rekap_layanan_barbershop.txt" << endl;

    return 0;
}