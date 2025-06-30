#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAKS_BARANG = 5;
// Array 2 dimensi untuk menyimpan data barang:
// Kolom 0: nama, 1: harga, 2: stok
string barang[MAKS_BARANG][3];
int jumlahBarang = 0; // Menyimpan jumlah barang yang diinput

// Fungsi untuk input data barang dari user
void inputBarang() {
  cout << "Masukkan jumlah barang yang ingin diinput (maksimal 5): ";
  cin >> jumlahBarang;
  cin.ignore(); // Membersihkan buffer newline

  for (int i = 0; i < jumlahBarang; i++) {
    cout << "Barang ke-" << i + 1 << ": " << endl;
    cout << "Nama  : "; getline(cin, barang[i][0]);     // Input nama
    cout << "Harga : "; getline(cin, barang[i][1]);     // Input harga (disimpan sebagai string)
    cout << "Stok  : "; getline(cin, barang[i][2]);     // Input stok (disimpan sebagai string)
  }
}

// Fungsi untuk menampilkan semua barang yang sudah diinput
void cekBarang() {
  cout << endl;
  cout << "== DAFTAR BARANG ==" << endl;
  for (int i = 0; i < jumlahBarang; i++) {
    cout << i + 1 << ". " << barang[i][0] // Nama barang
     << " (Harga: " << barang[i][1]     // Harga
     << ", Stok: " << barang[i][2] << ")" << endl; // Stok
  }
}

// Fungsi bubble sort untuk mengurutkan barang berdasarkan harga
// Jika ascending = true, maka dari murah ke mahal
void sortingHarga(bool ascending = true) {
  for (int i = 0; i < jumlahBarang - 1; i++) {
    for (int j = 0; j < jumlahBarang - i - 1; j++) {
      // Konversi string ke integer untuk perbandingan harga
      int harga1 = stoi(barang[j][1]);
      int harga2 = stoi(barang[j + 1][1]);

      // Tukar data jika urutan salah (tergantung ascending/descending)
      if ((ascending && harga1 > harga2) || (!ascending && harga1 < harga2)) {
          // Tukar seluruh data satu baris
        for (int k = 0; k < 3; k++) {
          swap(barang[j][k], barang[j + 1][k]);
        }
      }
    }
  }
  cout << "Data berhasil diurutkan berdasarkan harga." << endl;
}

// Fungsi untuk mencari barang berdasarkan nama menggunakan linear search
void cariBarang() {
  string cari;
  cin.ignore(); // Membersihkan buffer newline sebelum getline
  cout << "Masukkan nama barang yang dicari: ";
  getline(cin, cari);

  bool ditemukan = false;
  for (int i = 0; i < jumlahBarang; i++) {
    // Cek apakah nama barang sama persis dengan yang dicari
    if (barang[i][0] == cari) {
      cout << "Barang ditemukan:" << endl;
      cout << "Nama: " << barang[i][0]    // Nama
       << ", Harga: " << barang[i][1] // Harga
       << ", Stok: " << barang[i][2] << endl; // Stok
      ditemukan = true;
      break; // Hentikan pencarian jika sudah ketemu
    }
  }

  if (!ditemukan) {
    cout << "Barang tidak ditemukan." << endl;
  }
}

int main() {
  int pilihan;
  do {
    // Tampilkan menu utama
    cout << endl;
    cout << "=== MENU SUPERMARKET ===" << endl;
    cout << "1. Input Barang" << endl;
    cout << "2. Cek Barang" << endl;
    cout << "3. Sorting Berdasarkan Harga" << endl;
    cout << "4. Cari Barang" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    // Jalankan fitur sesuai pilihan user
    switch (pilihan) {
      case 1: {
        inputBarang();
        break;
      }
      case 2: {
        cekBarang();
        break;
      }
      case 3: {
        sortingHarga(true); // Sorting dari harga rendah ke tinggi
        break;
      }
      case 4: {
        cariBarang();
        break;
      }
      case 5: {
        cout << "Terima kasih!" << endl;
        break;
      }
      default: {
        cout << "Pilihan tidak valid!" << endl;
      }
    }

  } while (pilihan != 5); // Ulangi selama user belum pilih keluar

  return 0;
}