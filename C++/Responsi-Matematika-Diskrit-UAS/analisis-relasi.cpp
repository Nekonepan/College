#include <iostream>
using namespace std;

const int MAKS = 10;
char pengguna[MAKS];
int matriks[MAKS][MAKS];

int cari_indeks(char nama, int n) {
    for (int i = 0; i < n; i++) {
        if (pengguna[i] == nama) {
          return i;
        }
    }
    return -1;
}

void tampilkan_matriks(int n) {
    cout << endl << "Matriks Relasi: " << endl;
    for (int i = 0; i < n; i++) {
      cout << "    " << pengguna[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << pengguna[i] << " | ";
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

bool cek_refleksif(int n) {
    for (int i = 0; i < n; i++) {
      if (matriks[i][i] != 1) {
        return false;
      }
    }
    return true;
}

bool cek_simteris(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matriks[i][j] != matriks[j][i])
            return false;
      }
    }
    return true;
}

bool cek_transitif(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matriks[i][j] == 1) {
          for (int k = 0; k < n; k++) {
            if (matriks[j][k] == 1 && matriks[i][k] == 0)
                return false;
          }
        }
      }
    }
    return true;
}

int main() {
    int n, m;
    cout << "Masukkan jumlah pengguna (maks 10): ";
    cin >> n;

    cout << "Masukkan nama pengguna (1 karakter per orang): " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Pengguna ke-" << i + 1 << " : ";
        cin >> pengguna[i];
    }

    // Inisialisasi matriks ke 0
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        matriks[i][j] = 0;
      }
    }

    cout << "Masukkan jumlah relasi (misal: A follow B): ";
    cin >> m;

    cout << "Masukkan relasi (format: AB artinya A follow B) :" << endl;
    for (int i = 0; i < m; i++) {
        char dari, ke;
        cout << "Relasi ke-" << i + 1 << ": ";
        cin >> dari >> ke;
        int a = cari_indeks(dari, n);
        int b = cari_indeks(ke, n);
        if (a != -1 && b != -1) {
            matriks[a][b] = 1;
        } else {
            cout << "Nama tidak ditemukan!" << endl;
            i--; // ulangi input
        }
    }

    tampilkan_matriks(n);

    cout << endl << "Analisis Sifat Relasi : " << endl;
    cout << "- Refleksif : " << (cek_refleksif(n) ? "Ya" : "Tidak") << endl;
    cout << "- Simetris  : " << (cek_simteris(n) ? "Ya" : "Tidak") << endl;
    cout << "- Transitif : " << (cek_transitif(n) ? "Ya" : "Tidak") << endl;

    return 0;
}
