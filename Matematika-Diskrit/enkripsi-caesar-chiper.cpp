#include <iostream>
using namespace std;

int main() {
  char teks[100];
  int k = 5;

  cout << "Masukkan kalimat: ";
  cin.getline(teks,100);

  cout << "Enkripsi: ";

  for (int i = 0; teks[i] != '\0'; i++) {

      char c = teks[i];

      if (c >= 'A' && c <= 'Z') {
          c = c + k;
          if (c > 'Z') {
            c = c - 26;
          }
      }

      else if (c >= 'a' && c <= 'z') {
          c = c + k;
          if (c > 'z') {
            c = c - 26;
          }
      }

      cout << c;
  }

  cout << "\nDekripsi: ";

  for (int i = 0; teks[i] != '\0'; i++) {

    char c = teks[i];

    if (c >= 'A' && c <= 'Z') {
        c = c - k;
        if (c < 'A') {
          c = c + 26;
        }
    }

    else if (c >= 'a' && c <= 'z') {
        c = c - k;
        if (c < 'a') {
          c = c + 26;
        }
    }

    cout << c;
    }

    return 0;
}