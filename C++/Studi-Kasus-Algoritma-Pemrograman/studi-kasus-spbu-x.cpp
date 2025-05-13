#include <iostream>
using namespace std;

class SPBU {
private:
    string nama_pelanggan, jenis_bensin;
    int pilihan;
    float jumlah_liter, harga_perliter, total_harga;

public:
    void input_data() {
        cout << "==================================" << endl;
        cout << "||==          SPBU x          ==||" << endl;
        cout << "==================================" << endl;
        
        cout << "Masukkan nama pelanggan: ";
        getline(cin, nama_pelanggan);
        
        cout << "\nMasukkan jenis Bensin:\n";
        cout << "1. Pertalite\n";
        cout << "2. Pertamax\n";
        cout << "Pilihan (1/2) : ";
        cin >> pilihan;

        if (pilihan == 1) {
            jenis_bensin = "Pertalite";
            harga_perliter = 7000;
        } else if (pilihan == 2) {
            jenis_bensin = "Pertamax";
            harga_perliter = 9000;
        } else {
            cout << "Pilihan tidak valid!\n";
            return;
        }

        cout << "\nMasukkan jumlah liter: ";
        cin >> jumlah_liter;

        total_harga = jumlah_liter * harga_perliter;
    }

    void struk() {
        cout << "\n==================================" << endl;
        cout << "||==   STRUK PEMBELIAN SPBU   ==||" << endl;
        cout << "==================================" << endl;
        cout << "Nama Pelanggan  : " << nama_pelanggan << endl;
        cout << "Jenis Bensin    : " << jenis_bensin << endl;
        cout << "Jumlah Liter    : " << jumlah_liter << " L" << endl;
        cout << "total_harga     : Rp. " << total_harga << endl;
        cout << "==================================" << endl;
    }
};

int main() {
    SPBU transaksi;
    transaksi.input_data();
    transaksi.struk();
    return 0;
}
