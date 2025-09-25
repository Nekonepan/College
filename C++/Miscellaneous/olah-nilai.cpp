// Diketahui N mahasiswa dengan nilai [0 - 100] bilagnan real. Hitung rata-rata nilai, nilai tertinggi dan terkecil, hitung berapa
// mahasiswa yang memiliki nilai > 70

#include <iostream>
using namespace std;

void hitung_rata_rata() {
  float n, nilai, rata_rata;
  float jumlah = 0;
  cout << "Masukkan jumlah mahasiswa : ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    cout << "Masukkan nilai mahasiswa ke-" << i << " : ";
    cin >> nilai;
    jumlah += nilai;
  }

  rata_rata = jumlah / n;
  cout << "Rata-rata : " << rata_rata;
}

int main() {
  hitung_rata_rata();
}