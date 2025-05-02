#include <iostream>
using namespace std;

int main(){
  int uang_saku, bulan;
  int pengeluaran[100];

  cout<<"---PROGRAM RINCIAN KEUANGAN---"<<endl;
  cout<<"Masukkan Jumlah Uang Saku :";
  cin>>uang_saku;
  cout<<"Masukkan Jumlah Bulan :";
  cin>>bulan;

  int total_uang_saku = 0;
  for (int i=0; i<bulan; i++){
    total_uang_saku += uang_saku;
  }

  int total_pengeluaran = 0;
  for (int i=0; i<bulan; i++){
    cout<<"Masukkan Pengeluaran Bulan ke-"<<i+1<<" : Rp. ";
    cin>>pengeluaran[i];
    total_pengeluaran += pengeluaran[i];
  }

  cout<<"----------------"<<endl;
  cout<<"RINCIAN KEUANGAN"<<endl;  
  cout<<"----------------"<<endl;
  cout<<"PEMASUKAN : "<<uang_saku<<endl;
  cout<<"PENGELUARAN : "<<endl;
  for (int i=0; i<bulan; i++){
    cout<<"Bulan ke-"<<i+1<<" : Rp. "<<pengeluaran[i]<<endl;
  }

  cout<<endl;
  cout<<"SISA PERBULAN"<<endl;
  int sisa = 0;
  for (int i=0; i<bulan; i++){
    sisa = uang_saku - pengeluaran[i];
    cout<<"Bulan ke-"<<i+1<<" : Rp. "<<sisa<<endl;
  }

  int tabungan = 0;
  for (int i=0; i<bulan; i++){
    tabungan = total_uang_saku - total_pengeluaran;
  }
  cout<<"----------------"<<endl;
  cout<<"UANG KELUAR : Rp. "<<total_pengeluaran<<endl;
  cout<<"TABUNGAN : Rp. "<<tabungan<<endl;
}