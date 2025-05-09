#include <iostream>
using namespace std;

long long nim;
int matkul, total_sks = 0;
string nama;
string nama_matkul[100];
int sks[100];

void input() {
    cout << "===== Universitas Ahmad Dahlan =====" << endl;

    cout << "NIM : ";
    cin >> nim;

    cout << "Nama : ";
    cin >> nama;

    cout << endl;
    cout << "Jumlah mata kuliah : ";
    cin >> matkul;
    cout << endl;
}

void jumlah_sks(int i) {
    if (i > matkul) {
        return;
    }

    cout << "Mata kuliah ke-" << i << " : ";
    cin >> nama_matkul[i];
    cout << "Jumlah SKS : ";
    cin >> sks[i];
    total_sks += sks[i];
    cout << endl;

    jumlah_sks(i + 1);
}

int main() {
    input();

    cout << "===== Input Mata Kuliah =====" << endl;
    jumlah_sks(1);

    cout << "===== Struk Pembayaran =====" << endl;
    for (int i = 1; i <= matkul; i++) {
        cout << "-" << nama_matkul[i] << " (" << sks[i] << " SKS)" << endl;
    }

    int harga_biaya_sks = total_sks * 125000;
    int total_diskon = harga_biaya_sks * 15 / 100;
    int total_bayar = harga_biaya_sks - total_diskon;

    cout << "----------------------------" << endl;
    cout << "NIM : " << nim << endl;
    cout << "Nama Mahasiswa : " << nama << endl;
    cout << "----------------------------" << endl;
    cout << "Total SKS : " << total_sks << endl;
    cout << "Total biaya SKS : " << harga_biaya_sks << endl;
    cout << "Diskon 15% : " << total_diskon << endl;
    cout << "Total bayar : " << total_bayar << endl;
    cout << "----------------------------" << endl;

    return 0;
}
