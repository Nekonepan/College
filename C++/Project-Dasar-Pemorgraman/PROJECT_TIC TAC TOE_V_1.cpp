#include <iostream>
using namespace std;

char papan[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; //ELEMENT ARRAY 2D UNTUK PAPAN TTT
char nama_pemain = 'X'; //PERMAINAN SELALU DIMULAI DENGAN PEMAIN X

// FUNCTION UNTUK CETAK PAPAN TTT
void cetak_papan() {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << papan[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// FUNCTION UNTUK INPUT
void input_pemain() {
    int pilihan;
    cout << "Pemain " << nama_pemain << ", Masukkan angka (1-9): " ;
    cin >> pilihan;

    // MENGGUNAKAN POINTER UNTUK UPDATE PAPAN
    int baris = (pilihan - 1) / 3;
    int kolom = (pilihan - 1) % 3;
    char *cell = &papan[baris][kolom];

    if (*cell != 'X' && *cell != 'O') {
        *cell = nama_pemain; // UPDATE PAPAN
    } else {
        cout << "Kotak sudah diisi! Coba lagi."<< endl;
        input_pemain(); // REKURSI UNTUK INPUT ULANG JIKA PAPAN SUDAH TERISI
    }
}

// FUNCTION UNTUK MEMERIKSA JIKA ADA PEMENANG
bool cek_menang() {

    // CEK BARIS DAN KOLOM
    for (int i = 0; i < 3; i++) {
        if ((papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) || (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i])) {
            return true;
        }
    }

    // CEK DIAGONAL
    if ((papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) || (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0])) {
        return true;
    }
    return false;
}

// FUNCTION UNTUK MEMERIKSA APAKAH PERMAINAN SERI
bool cek_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] != 'X' && papan[i][j] != 'O') {
                return false; //JIKA PAPAN MASIH KOSONG
            }
        }
    }
    return true;
}

// FUNCTION UNTUK GANTI PEMAIN BERIKUTNYA
void ganti_pemain() {
    nama_pemain = (nama_pemain == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Selamat datang di Tic Tac Toe!" << endl;

    cetak_papan();

    while (true) {

        input_pemain();
        cetak_papan(); //CETAK PAPAN YANG SUDAH DIUPDATE

        // MEMERIKSA KONDISI APAKAH MENANG ATAU SERI
        if (cek_menang()) {
            cout << "Pemain " << nama_pemain << " menang!" << endl;
            break;
        } else if (cek_draw()) {
            cout << "Permainan seri!" << endl;
            break;
        }

        ganti_pemain();
    }

    return 0;
}
