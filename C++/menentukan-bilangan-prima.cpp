#include <iostream>
using namespace std;

int main() {
    int bilangan;
    int sisa_nol = 0;

    cout << "Masukkan bilangan: ";
    cin >> bilangan;

    for (int i = 1; i <= bilangan; i++) {
        if (bilangan % i == 0) {
            sisa_nol = sisa_nol + 1;
        }
    }

    if (sisa_nol == 2) {
        cout << "Bilangan adalah Prima" << endl;
    } else {
        cout << "Bilangan adalah bukan Prima" << endl;
    }

    return 0;
}

