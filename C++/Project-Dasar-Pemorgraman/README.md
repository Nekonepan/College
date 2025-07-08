# 🎮 Tic Tac Toe Game (C++ Terminal Version)

## 📘 Deskripsi
Proyek ini adalah implementasi permainan **Tic Tac Toe (X dan O)** menggunakan **bahasa C++** berbasis **terminal/console**. Permainan dimainkan oleh dua pemain secara bergantian hingga ada yang menang atau hasil seri.

Permainan ini ditujukan sebagai studi kasus latihan logika dasar, penggunaan array 2 dimensi, kontrol alur (loop & kondisi), dan fungsi dalam C++.

---

## 🎯 Fitur Utama

- Pemain X dan O bermain secara bergantian
- Validasi input: tidak bisa mengisi kotak yang sudah terisi
- Deteksi otomatis siapa yang menang
- Deteksi kondisi seri
- Tampilan papan permainan setelah setiap giliran

---

## 🎮 Cara Bermain

1. Jalankan program di terminal.
2. Pemain akan diminta memasukkan angka dari 1 hingga 9.
3. Program akan menampilkan papan terbaru.
4. Permainan berakhir ketika:
   - Salah satu pemain membuat garis 3 simbol berurutan (horizontal, vertikal, atau diagonal)
   - Semua kotak terisi dan tidak ada pemenang (seri)

### 📌 Posisi papan berdasarkan input:
```bash
1 | 2 | 3
4 | 5 | 6
7 | 8 | 9
```

---

## 💻 Cara Menjalankan Program

1. Kompilasi menggunakan compiler C++ (misalnya `g++`):
```bash
g++ "PROJECT_TIC TAC TOE_V_1.cpp" -o tic_tac_toe
```

2. Jalanlankan program:
```bash
./tic_tac_toe
```

---

## 🧠 Konsep yang Dipelajari
- Array 2D sebagai representasi papan
- Manipulasi pointer untuk update papan
- Rekursi sederhana untuk input ulang
- Logika deteksi kemenangan dan seri
- Fungsi modular: input_pemain(), cek_menang(), cetak_papan(), dll.

---

## 🎓 Tujuan Edukasi
- Melatih pembuatan program berbasis game sederhana
- Memahami penggunaan array dan kontrol kondisi
- Implementasi struktur permainan dua pemain

---

## 👤 Author
Proyek ini merupakan bagian dari latihan/studi kasus Dasar Pemrograman.

---

### Jika kamu menyukai proyek ini, silakan bintangi ⭐ repository-nya atau modifikasi sesuai versimu sendiri!