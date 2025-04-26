#include <iostream>
using namespace std;

int total_harga_makanan;
int ongkir;
int jumlah_porsi[4] = {0};

void tampilan_menu() {
	cout << "===== MENU RUMAH MAKAN =====" << endl;
	cout << "1. AYAM NGAWI         : Rp. 25000" << endl;
	cout << "2. BEKICOT MAGETAN    : Rp. 10000" << endl;
	cout << "3. MIE AYAM WONOGIRI  : Rp. 8000" << endl;
	cout << "4. RENDANG PALEMBANG  : Rp. 20000" << endl;
	cout << "5. SELESAI" << endl << endl;
}

void pilih_menu() {
	int pilihan;

	while (pilihan != 5) {
		cout << "Pilih menu (1-5) : ";
		cin >> pilihan;
		
		if (pilihan >= 1 && pilihan <= 4){
			int porsi;
			cout << "Jumlah porsi : ";
			cin >> porsi;

			jumlah_porsi[pilihan - 1] += porsi;
			switch (pilihan) {
				case 1: total_harga_makanan += 25000 * porsi;
					break;
				case 2: total_harga_makanan += 10000 * porsi;
					break;
				case 3: total_harga_makanan += 8000 * porsi;
					break;
				case 4: total_harga_makanan += 20000 * porsi;
					break;
			}
		}
	}
}

void input_jarak() {
	int jarak;
	cout << "Masukkan jarak (KM) : ";
	cin >> jarak;

	if (jarak <= 3) {
		ongkir = 15000;
	} else {
		ongkir = 25000;
	}
}

void slip_pembayaran() {
	int total_bayar = total_harga_makanan + ongkir;
	cout << endl << "========== SLIP PEMBAYARAN ==========" << endl;

	string nama_menu[] = {
		"AYAM NGAWI",
		"BEKICOT MAGETAN",
		"MIE AYAM WONOGIRI",
		"RENDANG PALEMBANG"
	};

	int harga_satuan[] = {25000, 10000, 8000, 20000};

	for (int i = 0; i < 4; i++) {
		if (jumlah_porsi[i] > 0) {
			cout << nama_menu[i] << " x " << jumlah_porsi[i] << " : Rp. " << jumlah_porsi[i] * harga_satuan[i] << endl;
		}
	}

	cout << "ONGKIR                  : Rp. " << ongkir << endl;
	cout << "TOTAL PESANAN           : Rp. " << total_harga_makanan << endl;
	cout << "-------------------------------------" << endl;
	cout << "TOTAL BAYAR             : Rp. " << total_bayar << endl;
	cout << "=====================================" << endl;
}

int main() {
	input_jarak();
	tampilan_menu();
	pilih_menu();
	slip_pembayaran();
	return 0;
}
