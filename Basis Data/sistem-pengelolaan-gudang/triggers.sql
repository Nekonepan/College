-- Membuat TRIGGER ketika menambahkan stok pada transaksi_masuk
DELIMITER //
CREATE TRIGGER update_stok_transaksi_masuk
BEFORE INSERT ON transaksi_masuk
FOR EACH ROW
BEGIN
UPDATE barang
SET stok = stok + NEW.jumlah_masuk
WHERE barang_id = NEW.barang_id;
SET NEW.tanggal_masuk = NOW();
END //
DELIMITER ;

-- Membuat TRIGGER ketika mengurangi stok pada transaksi_keluar
DELIMITER //
CREATE TRIGGER update_stok_transaksi_keluar
BEFORE INSERT ON transaksi_keluar
FOR EACH ROW
BEGIN
DECLARE stok_barang INT;
SELECT stok INTO stok_barang 
FROM barang 
WHERE barang_id = NEW.barang_id;
IF stok_barang < NEW.jumlah_keluar THEN
SIGNAL SQLSTATE '45000'
SET MESSAGE_TEXT = 'Stok tidak cukup untuk transaksi keluar ini.';
END IF;
UPDATE barang
SET stok = stok - NEW.jumlah_keluar
WHERE barang_id = NEW.barang_id;
SET NEW.tanggal_keluar = NOW();
END //
DELIMITER ;

-- Membuat TRIGGER log_transaksi untuk mencatat aktivitas transaksi
CREATE TABLE log_transaksi(
  log_id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  aktivitas VARCHAR(225),
  tanggal TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DELIMITER //
CREATE TRIGGER log_transaksi_masuk
BEFORE INSERT ON transaksi_masuk
FOR EACH ROW
INSERT INTO log_transaksi(aktivitas)
VALUES (CONCAT('Transaksi Masuk : barang_id(', NEW.barang_id, ') masuk sebanyak ', NEW.jumlah_masuk));
END //
DELIMITER ;

DELIMITER //
CREATE TRIGGER log_transaksi_keluar
BEFORE INSERT ON transaksi_keluar
FOR EACH ROW
INSERT INTO log_transaksi(aktivitas)
VALUES (CONCAT('Transaksi Keluar : barang_id(', NEW.barang_id, ') keluar sebanyak ', NEW.jumlah_keluar));
END //
DELIMITER ;

-- Membuat TRIGGER untuk mencegah UPDATE jika barang_id tidak ada
DELIMITER //
CREATE TRIGGER cek_barang_saat_update_masuk
BEFORE UPDATE ON transaksi_masuk
FOR EACH ROW
BEGIN
DECLARE jumlah INT;
SELECT COUNT(*) INTO jumlah
FROM barang
WHERE barang_id = NEW.barang_id;
IF jumlah = 0 THEN
SIGNAL SQLSTATE '45000'
SET MESSAGE_TEXT = 'Barang dengan ID tersebut belum terdaftar.';
END IF;
END //
DELIMITER ;