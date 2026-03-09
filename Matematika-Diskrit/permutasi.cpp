#include <iostream>
using namespace std;

int main() {
  int n;
  long long faktorial = 1;

  cout << "Jumlah orang: ";
  cin >> n;

  for (int i = 1; i <= n; i++){
    faktorial = faktorial * i;
  }

  cout << "Jumlah cara duduk: " << faktorial;

  return 0;
}