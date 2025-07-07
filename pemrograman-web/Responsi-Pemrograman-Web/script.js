document.addEventListener("DOMContentLoaded", function () {
  const jumlahInput = document.getElementById("jumlah");
  const kategoriSelect = document.getElementById("kategori");
  const totalHarga = document.getElementById("totalHarga");

  function hitungTotal() {
    const jumlah = parseInt(jumlahInput.value);
    const kategori = kategoriSelect.value;

    let hargaPerTiket = kategori === "dewasa" ? 50000 : 30000;
    let total = jumlah * hargaPerTiket;

    totalHarga.value = "Rp" + total.toLocaleString("id-ID");
  }

  jumlahInput.addEventListener("input", hitungTotal);
  kategoriSelect.addEventListener("change", hitungTotal);

  hitungTotal(); // hitung saat halaman pertama kali dibuka
});
