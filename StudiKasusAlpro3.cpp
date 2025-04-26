#include <iostream>
using namespace std;

int total_harga_makanan;
int ongkir;
int jumlah_porsi[4] = {0};

void tampilan_menu() {										//|
	cout << "===== MENU RUMAH MAKAN =====" << endl;			//|
	cout << "1. AYAM NGAWI         : Rp. 25000" << endl;	//|
	cout << "2. BEKICOT MAGETAN    : Rp. 10000" << endl;	//|
	cout << "3. MIE AYAM WONOGIRI  : Rp. 8000" << endl;		//| FUNCTION UNTUK MENAMPILKAN MENU
	cout << "4. RENDANG PALEMBANG  : Rp. 20000" << endl;	//|
	cout << "5. SELESAI" << endl << endl;					//|
}															//|

void pilih_menu() {
	int pilihan;

	while (pilihan != 5) {	//MENGGUNAKAN PERULANGAN WHILE DENGAN KONDISI JIKA PILIHAN = 5 AKAN BEHENTI LOOP KARENA CONDITION = FALSE
		cout << "Pilih menu (1-5) : ";
		cin >> pilihan;
		
		if (pilihan >= 1 && pilihan <= 4){ // JIKA PILIHANNYA 5 MAKA TIDAK AKAN MENGEKSEKUSI BLOK CODE DI DALAMNYA
			int porsi;
			cout << "Jumlah porsi : ";
			cin >> porsi;

			jumlah_porsi[pilihan - 1] += porsi; // MEMBUAT ARRAY jumlah_porsi DENGAN INDEX [pilihan - 1] AGAR JIKA INPUT 1 MAKA AKAN DIAMBIL INDEX 0
												// NOTE : KENAPA PAKE += porsi KARENA KALAU MISAL INPUT MENU YANG SAMA 2 KALI NANTI NILAI PORSI NYA 
												// 		  DITAMBAH BUKAN DI OVERWRITE
												
			switch (pilihan) {									//|
				case 1: total_harga_makanan += 25000 * porsi;	//|
					break;										//|
				case 2: total_harga_makanan += 10000 * porsi;	//| MENGGUNAKAN SELECTION SWITCH CASE DENGAN VARIABEL AKAN DITAMBHAKAN DENGAN HARGA
					break;										//| DIKALI DENGAN JUMLAH PORSI
				case 3: total_harga_makanan += 8000 * porsi;	//| 
					break;										//| NOTE : ITU PAKAI OPERATOR += YANG ARTINYA NILAI YANG SEBELUMNYA AKAN DITAMBAHKAN
				case 4: total_harga_makanan += 20000 * porsi;	//|			BUKAN DI OVERWRITE DENGAN NILAI YANG BARU, JADI NILAI YANG SEBELUMNYA
					break;										//|			NGGAK KETIMPA SAMA YANG BARU
			}													//|
		}
	}
}

void input_jarak() {
	int jarak;
	cout << "Masukkan jarak (KM) : ";
	cin >> jarak;

	if (jarak <= 3) {		//|
		ongkir = 15000;		//| MENGGUNAKAN SELECTION JIKA JARAK KURANG DARI SAMA DENGAN 3 MAKA VARIBEL ONGKIR AKAN DIIS NILAI 15000
	} else {				//| JIKA LEBIH DARI 3 MAKA AKAN DIISI NILAI 25000
		ongkir = 25000;		//|
	}						//|
}

void slip_pembayaran() {
	int total_bayar = total_harga_makanan + ongkir; // VARIABEL UNTUK MENGITUNG JUMLAH PEMBAYARAN DENGAN MENJUMLAHKAN TOTAL HARGA MAKANAN DENGAN ONGKIR

	cout << endl << "========== SLIP PEMBAYARAN ==========" << endl;

	string nama_menu[] = {		//|
		"AYAM NGAWI",			//|
		"BEKICOT MAGETAN",		//| BUAT ARRAY YANG ISINYA MENU MAKANAN TADI BUAT DI PRINT DI SLIP PEMBAYARAN
		"MIE AYAM WONOGIRI",	//|
		"RENDANG PALEMBANG"		//|
	};							//|

	int harga_satuan[] = {25000, 10000, 8000, 20000}; // SAMA AJA BUAT ARRAY YANG ISINYA HARGA MENU TADI UNTUK DI PRINT DI SLIP PEMBAYARAN

	for (int i = 0; i < 4; i++) { //DI LOOP 4 KALI KARENA MENUNYA CUMA ADA 4
		if (jumlah_porsi[i] > 0) { // KENAPA > 0. AGAR MENU YANG NGGAK DIISI ATAU NILAI NYA 0 NGGAK IKUT KE PRINT KURANG LEBIH GITU
			cout << nama_menu[i] << " x " << jumlah_porsi[i] // MENAMPILKAN NAMA MENU DAN JUMLAH PORSI YANG DIPILIH TADI
			     << " : Rp. " << jumlah_porsi[i] * harga_satuan[i] << endl; // LALU JUMLAH PORSI SAMA HARGA SATUAN DI KALIKAN AGAR KETEMU TOTAL PESANAN
		}
	}

	cout << "ONGKIR                  : Rp. " << ongkir << endl;					// MENAMPILKAN NILAI VARIABEL ONGKIR
	cout << "TOTAL PESANAN           : Rp. " << total_harga_makanan << endl;	// MENAMPILKAN NILAI VARIABEL TOTAL HARGA MAKAN
	cout << "-------------------------------------" << endl;
	cout << "TOTAL BAYAR             : Rp. " << total_bayar << endl;			// MENAMPILKAN NILAI TOTAL BAYAR
	cout << "=====================================" << endl;
}

int main() {			//|
	input_jarak();		//|
	tampilan_menu();	//|
	pilih_menu();		//| MAIN CODE UNTUK MEMANGGIL SEMUA FUNCTION TADI
	slip_pembayaran();	//|
	return 0;			//|
}						//|
