<?php
function hitungTotalHarga($jumlah, $kategori) {
  $hargaPerTiket = $kategori === "dewasa" ? 50000 : 30000;
  return $jumlah * $hargaPerTiket;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $nama = $_POST["nama"];
  $jumlah = intval($_POST["jumlah"]);
  $kategori = $_POST["kategori"];
  $total = hitungTotalHarga($jumlah, $kategori);

  echo "<h2>Detail Pemesanan</h2>";
  echo "Nama: $nama <br>";
  echo "Jumlah Tiket: $jumlah <br>";
  echo "Kategori: $kategori <br>";
  echo "Total Harga: Rp" . number_format($total, 0, ',', '.');
}
?>
