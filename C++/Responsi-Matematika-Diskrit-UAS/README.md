# Responsi Matematika Diskrit – UAS

## 📘 Deskripsi
Program ini digunakan untuk menganalisis **sifat-sifat relasi biner** menggunakan representasi matriks. Program akan mengecek apakah relasi tersebut bersifat **refleksif**, **simetris**, dan **transitif** konsep penting dalam Matematika Diskrit.

## 🎯 Fitur Utama
- Input daftar pengguna (maks 10, 1 karakter per pengguna)
- Input relasi antar pengguna (misal: `AB` berarti A ke B)
- Menyusun dan menampilkan matriks relasi
- Analisis otomatis terhadap:
  1. Refleksivitas
  2. Simetri
  3. Transitivitas

## 📌 Cara Penggunaan
1. Masukkan jumlah pengguna
2. Masukkan nama pengguna (huruf satuan)
3. Masukkan jumlah dan isi relasi (misal: `AB`)
4. Program menampilkan matriks & analisis sifat

## 🧪 Contoh Input
```bash
Masukkan jumlah pengguna (maks 10): 3
Masukkan nama pengguna (1 karakter per orang):
Pengguna ke-1 : A
Pengguna ke-2 : B
Pengguna ke-3 : C
Masukkan jumlah relasi (misal: A follow B): 3
Masukkan relasi (format: AB artinya A follow B) :
Relasi ke-1: AA
Relasi ke-2: BB
Relasi ke-3: CC
```

## 📊 Contoh Output
```bash
Matriks Relasi:
    A B C
A | 1 0 0
B | 0 1 0
C | 0 0 1

Analisis Sifat Relasi :
- Refleksif : Ya
- Simetris  : Ya
- Transitif : Ya
```

## 🎓 Tujuan Pembelajaran
Memahami konsep relasi dan penerapannya melalui logika pemrograman serta representasi matriks.
