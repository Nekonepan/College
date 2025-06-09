#include <iostream>
#include <fstream>
using namespace std;

struct akun {
	string username;
	long int password;
};

akun akun_terdaftar[10];
int jumlah_akun = 0;
int index_login = -1;
int total_saldo = 0;
int total_harga_keseluruhan = 0;
int ongkir = 0;
int diskon = 0;
string alamat;
string nama_ekspedisi;
bool pakai_voucher = false;
bool gratis_ongkir = false;
bool pakai_cargo = false;

//===== REGISTRASI DAN LOGIN =====//
void registrasi() {
	if (jumlah_akun >= 10) {
		cout << "Maksimum akun tercapai. Tidak bisa registrasi lagi." << endl;
		return;
	}

	cout << "===== REGISTRASI =====" << endl;
	cout << "Username : ";
	cin >> akun_terdaftar[jumlah_akun].username;
	cout << "Password : ";
	cin >> akun_terdaftar[jumlah_akun].password;
	jumlah_akun++;
	cout << "Registrasi Berhasil, Selamat datang " << endl;
}

bool login() {
	string user;
	long pass;

	cout << "===== LOGIN =====" << endl;
	cout << "Masukkan username : ";
	cin >> user;
	cout << "Masukkan password : ";
	cin >> pass;

	for (int i = 0; i < jumlah_akun; i++) {
		if (akun_terdaftar[i].username == user && akun_terdaftar[i].password == pass) {
			index_login = i;
			return true;
		}
	}
	return false;
}
//+++++ REGISTRASI DAN LOGIN +++++//

//===== HOME PAGE =====//
void home() {
	system("cls");
	cout << endl;
	cout << "==============================" << endl;
	cout << "Selamat Datang " << akun_terdaftar[index_login].username << endl;
	cout << "Saldo = Rp. " << total_saldo << endl;
	cout << "==============================" << endl;
}
//+++++ HOME PAGE +++++//

//===== LIST BARANG DAN PILIH BARANG =====//
void list_barang() {
	system("cls");

	int pilihan = 0;

	cout << "=============================" << endl;
	cout << "1. Kaos : Rp. 75.000" << endl;
	cout << "2. Kemeja : Rp. 175.000" << endl;
	cout << "3. Celana : Rp. 70.000" << endl;
	cout << "4. Jaket : Rp. 200.000" << endl;
	cout << "5. Sepatu : Rp. 150.000" << endl;
	cout << "-----------------------------" << endl;
	cout << "6. Selesai" << endl;
	cout << "=============================" << endl;

	while (pilihan != 6) {
		cout << "Masukkan pilihan : ";
		cin >> pilihan;
			
		switch (pilihan) {
			case 1: {
				total_harga_keseluruhan += 75000;
				break;
			}
			case 2: {
				total_harga_keseluruhan += 175000;
				break;
			}
			case 3: {
				total_harga_keseluruhan += 70000;
				break;
			}
			case 4: {
				total_harga_keseluruhan += 200000;
				break;
			}
			case 5: {
				total_harga_keseluruhan += 150000;
				break;
			}
		}
	}

	//----- IF DISKON T/F -----//
	if (total_harga_keseluruhan >= 200000) {
		float persen = (25000.0 / total_harga_keseluruhan) * 100;
		char jawab;

		cout << "Kamu bisa memakai voucher diskon sebesar Rp. 25.000 (" << persen << "%). Gunakan? (y/n) : ";
		cin >> jawab;

		if (jawab == 'y' || jawab == 'Y') {
			pakai_voucher = true;
			diskon = 25000;
		}
	}
	//------------------------//
}
//+++++ LIST BARANG DAN PILIH BARANG +++++//

//===== INPUT ALAMAT =====//
void input_alamat(){
	cin.ignore();
	cout << "Masukkan alamat yang akan dituju : ";
	getline(cin, alamat);
}
//+++++ INPUT ALAMAT +++++//

//===== ISI SALDO =====//
void tambah_saldo(){
	int isi_saldo;

	cout << "Masukkan jumlah saldo : ";
	cin >> isi_saldo;

	total_saldo += isi_saldo;
}
//+++++ ISI SALDO +++++//

//===== MENU EKSPEDISI =====//
void pilih_ekspedisi(){
	//----- PILIH EKSPEDISI -----//
	int pilihan;
	cout << endl;
	cout << "===== PILIH EKSPEDISI =====" << endl;
	cout << "1. JNE : Rp. 14.000" << endl;
	cout << "2. JNT : Rp. 15.000" << endl;
	cout << "3. SiCepat : Rp. 13.000" << endl;
	cout << "===========================" << endl;
	cout << "Pilih Ekspedisi : ";
	cin >> pilihan;
	//----------------------------//

	//----- PILIH TIPE EKSPEDISI -----//
	int tipe;
	cout << endl;
	cout << "===== TIPE EKSPEDISI =====" << endl;
	cout << "1. Reguler" << endl;
	cout << "2. Cargo [+Rp. 10.000]" << endl;
	cout << "==========================" << endl;
	cout << "Pilih tipe ekspedisi : ";
	cin >> tipe;
	//--------------------------------//

	pakai_cargo = (tipe == 2);
	
	switch(pilihan) {
		case 1: {
			nama_ekspedisi = "JNE";
			ongkir = 14000;
			break;
		}
		case 2: {
			nama_ekspedisi = "JNT";
			ongkir = 15000;
			break;
		}
		case 3: {
			nama_ekspedisi = "SiCepat";
			ongkir = 13000;
			break;
		}
	}

	if (pakai_cargo) {
		ongkir += 10000;
	}
	
	//----- IF GRATIS ONGKIR -----//
	if (total_harga_keseluruhan >= 50000) {
		cout << "Kamu mendapatkan gratis ongkir. Gunakan ? (y/n) : ";
		char jawab;
		cin >> jawab;

		if (jawab == 'y' || jawab == 'Y') {
			gratis_ongkir = true;
			ongkir = 0;
		}
	}
	//----------------------------//

	total_harga_keseluruhan = total_harga_keseluruhan - diskon + ongkir;
}
//+++++ MENU EKSPEDISI +++++//

//===== CHECKOUT =====//
void checkout() {
	if (total_saldo >= total_harga_keseluruhan) {
		total_saldo -= total_harga_keseluruhan;
		cout << "Chekout berhasil ! Saldo tersisa : Rp. " << total_saldo << endl;
	} else {
		cout << "Saldo anda tidak cukup untuk checkout!" << endl;
	}
}
//+++++ CHECKOUT +++++//

//===== INVOICE =====//
void invoice() {
	ofstream struk("invoice.txt");
	cout << endl;
	struk << "===== INVOICE =====" << endl;
	struk << "Username : " << akun_terdaftar[index_login].username << endl;
	struk << "Alamat : " << alamat;
	struk << "Ekspedisi : " << nama_ekspedisi << (pakai_cargo ? " (Cargo)" : " (Reguler)") << endl;
	struk << "Diskon Voucher : Rp. " << diskon;
	struk << "Ongkir : Rp. " << ongkir;
	struk << "Total Bayar : Rp. " << total_harga_keseluruhan;
	struk << "===================" << endl;
	struk.close();
	cout << "Invoice telah dicetak";
}
//+++++ INVOICE +++++//

//============================= MAIN =============================//
int main(){
	bool sudah_login = false;

	while (!sudah_login) {
		int pilihan;

		cout << "===== MENU UTAMA =====" << endl;
		cout << "1. Login" << endl;
		cout << "2. Registrasi" << endl;
		cout << "3. Keluar" << endl;
		cout << "======================" << endl;
		cout << "Pilih : ";
		cin >> pilihan;
		cin.ignore();

		switch (pilihan) {
			case 1: {
				if (login()) {
					sudah_login = true;
				} else {
					cout << "Login gagal! Coba lagi." << endl;
				}
				break;
			}
			case 2: {
				registrasi();
				index_login = jumlah_akun - 1;
				sudah_login = true;
				cout << "Login sebagai " << akun_terdaftar[index_login].username << " berhasil" << endl;
				system("pause");
				break;
			}
			case 3: {
				return 0;
			}
		}
	}

	home();

	int menu;

	do {
		cout << "================" << endl;
		cout << "1. Belanja" << endl;
		cout << "2. Isi saldo" << endl;
		cout << "3. Keluar" << endl;
		cout << "================" << endl;
		cout << "Pilih : ";
		cin >> menu;
		cin.ignore();

		switch (menu) {
			case 1: {
				list_barang();
				input_alamat();
				pilih_ekspedisi();
				checkout();
				invoice();
				break;
			}
			case 2: {
				tambah_saldo();
				break;
			}
		}
	} while (menu != 3);
}