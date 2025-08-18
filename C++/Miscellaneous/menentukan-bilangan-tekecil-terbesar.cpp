#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 7, 28};

    // inisialisasi min dan max dengan elemen pertama
    int min = arr[0];
    int max = arr[0];

    // cek semua elemen mulai dari indeks ke-1
    for (int i = 0; i < 3; i++) {
        if (arr[i] < min) {
            min = arr[i]; // update min jika ketemu lebih kecil
        }
        if (arr[i] > max) {
            max = arr[i]; // update max jika ketemu lebih besar
        }
    }

    cout << "Nilai terkecil = " << min << endl;
    cout << "Nilai terbesar = " << max << endl;

    return 0;
}