#include <iostream>
using namespace std;

// Fungsi untuk menghitung total uang saku
int hitung_total_uang_saku(int uang_saku, int bulan) {
    return uang_saku * bulan;
}

// Fungsi untuk memasukkan pengeluaran per bulan
void input_pengeluaran(int pengeluaran[], int bulan, int &total_pengeluaran) {
    total_pengeluaran = 0;
    for (int i = 0; i < bulan; i++) {
        cout << "Masukkan Pengeluaran Bulan ke-" << i + 1 << " : Rp. ";
        cin >> pengeluaran[i];
        total_pengeluaran += pengeluaran[i];
    }
}

// Fungsi untuk menampilkan rincian keuangan
void tampilkan_rincian_keuangan(int uang_saku, int pengeluaran[], int bulan) {
    cout << "----------------" << endl;
    cout << "RINCIAN KEUANGAN" << endl;
    cout << "----------------" << endl;
    cout << "PEMASUKAN : Rp. " << uang_saku << endl;
    cout << "PENGELUARAN : " << endl;
    for (int i = 0; i < bulan; i++) {
        cout << "Bulan ke-" << i + 1 << " : Rp. " << pengeluaran[i] << endl;
    }
}

// Fungsi untuk menghitung dan menampilkan sisa uang per bulan
void tampilkan_sisa_perbulan(int uang_saku, int pengeluaran[], int bulan) {
    cout << endl;
    cout << "SISA PERBULAN" << endl;
    for (int i = 0; i < bulan; i++) {
        int sisa = uang_saku - pengeluaran[i];
        cout << "Bulan ke-" << i + 1 << " : Rp. " << sisa << endl;
    }
}

// Fungsi untuk menghitung tabungan
int hitung_tabungan(int total_uang_saku, int total_pengeluaran) {
    return total_uang_saku - total_pengeluaran;
}

int main() {
    int uang_saku, bulan;
    int pengeluaran[100];

    cout << "---PROGRAM RINCIAN KEUANGAN---" << endl;
    cout << "Masukkan Jumlah Uang Saku : Rp. ";
    cin >> uang_saku;
    cout << "Masukkan Jumlah Bulan : ";
    cin >> bulan;

    int total_uang_saku = hitung_total_uang_saku(uang_saku, bulan);

    int total_pengeluaran;
    input_pengeluaran(pengeluaran, bulan, total_pengeluaran);

    tampilkan_rincian_keuangan(uang_saku, pengeluaran, bulan);
    tampilkan_sisa_perbulan(uang_saku, pengeluaran, bulan);

    int tabungan = hitung_tabungan(total_uang_saku, total_pengeluaran);

    cout << "----------------" << endl;
    cout << "UANG KELUAR : Rp. " << total_pengeluaran << endl;
    cout << "TABUNGAN : Rp. " << tabungan << endl;

    return 0;
}