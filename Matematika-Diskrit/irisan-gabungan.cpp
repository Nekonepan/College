#include <iostream>
using namespace std;

int main() {
  int A[100], B[100];
  int elemen_A, elemen_B;

  cout << "Jumlah elemen himpunan A: ";
  cin >> elemen_A;

  cout << "Masukkan elemen A: " << endl;
  for (int i = 0; i < elemen_A; i++) {
    cin >> A[i];
  }

  cout << "Jumlah elemen himpunan B: ";
  cin >> elemen_B;

  cout << "Masukkan elemen B: " << endl;
  for (int i = 0; i < elemen_B; i++) {
    cin >> B[i];
  }

  cout << "\nIrisan: ";
  for (int i = 0; i < elemen_A; i++) {
    for (int j = 0; j < elemen_B; j++) {
      if (A[i] == B[j]) {
        cout << A[i] << " ";
        break;
      }
    }
  }

  cout << "\nGabungan: ";

  for (int i = 0; i < elemen_A; i++) {
    cout << A[i] << " ";
  }

  for (int i = 0; i < elemen_B; i++) {
    bool ada = false;
    for (int j = 0; j < elemen_A; j++) {
      if (B[i] == A[j]) {
        ada = true;
        break;
      }
    }

    if (!ada) {
      cout << B[i] << " ";
    }
  }

  return 0;
}