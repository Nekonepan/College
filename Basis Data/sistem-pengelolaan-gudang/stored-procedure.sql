-- STORED PROCEDURE untuk menambahkan transaksi masuk
DELIMITER //
CREATE PROCEDURE sp_transaksi_masuk(
IN p_jumlah_masuk INT,
IN p_barang_id INT,
IN p_supplier_id INT
)
BEGIN
INSERT INTO transaksi_masuk(jumlah_masuk, barang_id, supplier_id)
VALUES (p_jumlah_masuk, p_barang_id, p_supplier_id);
END //
DELIMITER ;

-- STORED PROCEDURE untuk menambahkan transaksi keluar
DELIMITER //
CREATE PROCEDURE sp_transaksi_keluar(
IN p_jumlah_keluar INT,
IN p_barang_id INT,
IN p_customer_id INT
)
BEGIN
INSERT INTO transaksi_keluar(jumlah_keluar, barang_id, customer_id)
VALUES (p_jumlah_keluar, p_barang_id, p_customer_id);
END //
DELIMITER ;

-- STORED PROCEDURE untuk menambah barang baru
DELIMITER //
CREATE PROCEDURE sp_tambah_barang(
IN p_kode_barang VARCHAR(20),
IN p_nama_barang VARCHAR(100),
IN p_stok INT,
IN p_harga_satuan INT
)
BEGIN
INSERT INTO barang(kode_barang, nama_barang, stok, harga_satuan)
VALUES (p_kode_barang, p_nama_barang, p_Stok, p_harga_satuan);
END //
DELIMITER ;

-- STORED PROCEDURE untuk mencari stok barang
DELIMITER //
CREATE PROCEDURE sp_get_stok_barang(
IN p_barang_id INT
)
BEGIN
SELECT barang_id, nama_barang, stok
FROM barang
WHERE barang_id = p_barang_id;
END //
DELIMITER ;

-- STORED PROCEDURE untuk mencari customer
DELIMITER //
CREATE PROCEDURE sp_cari_customer(
IN keyword VARCHAR(100)
)
BEGIN
SELECT * FROM customer
WHERE 
nama_customer LIKE CONCAT('%', keyword, '%')
OR customer_id = keyword;
END //
DELIMITER ;

-- STORED PROCEDURE untuk menambah customer baru
DELIMITER //
CREATE PROCEDURE sp_tambah_customer(
IN p_nama_customer VARCHAR(100),
IN p_alamat TEXT,
IN p_no_telp VARCHAR(20)
)
BEGIN
INSERT INTO customer (nama_customer, alamat, no_telepon)
VALUES (p_nama_customer, p_alamat, p_no_telp);
END //
DELIMITER ;