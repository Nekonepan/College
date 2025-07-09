# Responsi Pemrograman Web

Aplikasi web sederhana untuk simulasi pemesanan tiket berbasis HTML, CSS, JavaScript, dan PHP. Proyek ini dibuat sebagai tugas responsi mata kuliah Pemrograman Web.

---

## 🎯 Deskripsi

Aplikasi ini memungkinkan pengguna untuk melakukan pemesanan tiket secara online dengan fitur perhitungan harga otomatis berdasarkan kategori tiket yang dipilih. Data pemesanan akan diproses dan ditampilkan menggunakan PHP.

---

## 🛠️ Fitur Utama

- **Form Pemesanan Interaktif:**  
  Pengguna dapat mengisi nama, jumlah tiket, dan memilih kategori tiket (Dewasa/Anak).
- **Perhitungan Harga Otomatis:**  
  Total harga tiket langsung dihitung dan ditampilkan saat pengguna mengubah jumlah atau kategori tiket.
- **Validasi Input:**  
  Semua field wajib diisi, jumlah tiket minimal 1.
- **Desain Modern & Responsif:**  
  Menggunakan Google Fonts dan CSS modern untuk tampilan yang menarik di berbagai perangkat.
- **Proses Backend dengan PHP:**  
  Setelah form dikirim, detail pemesanan akan diproses dan ditampilkan oleh file PHP.

---

## 📂 Struktur File

- `index.html`  
  Halaman utama berisi form pemesanan tiket.
- `style.css`  
  File CSS untuk styling halaman agar lebih menarik dan responsif.
- `script.js`  
  Script JavaScript untuk menghitung total harga tiket secara otomatis.
- `proses.php`  
  File PHP untuk memproses data pemesanan dan menampilkan hasilnya.

---

## 💻 Cara Menjalankan Aplikasi

1. **Siapkan Web Server Lokal:**  
   Gunakan XAMPP, Laragon, atau aplikasi serupa yang mendukung PHP.
2. **Letakkan Folder Proyek:**  
   Salin folder `Responsi-Pemrograman-Web` ke dalam direktori `htdocs` (XAMPP) atau `www` (Laragon).
3. **Akses Melalui Browser:**  
   Buka browser dan akses:  
   ```bash
   http://localhost/pemrograman-web/Responsi-Pemrograman-Web/
   ```
4. **Gunakan Aplikasi:**  
   - Isi nama, jumlah tiket, dan pilih kategori.
   - Total harga akan otomatis muncul.
   - Klik **Pesan** untuk melihat detail pemesanan.

---

## 💡 Informasi Tambahan

- **Harga Tiket:**  
  - Dewasa: Rp50.000  
  - Anak: Rp30.000
- **Perhitungan Harga:**  
  Total harga = jumlah tiket × harga per tiket (berdasarkan kategori).
- **Teknologi yang Digunakan:**  
  - HTML5
  - CSS3 (dengan Google Fonts)
  - JavaScript (DOM Manipulation)
  - PHP (Form Processing)

---

> Proyek ini dibuat untuk memenuhi tugas responsi Pemrograman Web.