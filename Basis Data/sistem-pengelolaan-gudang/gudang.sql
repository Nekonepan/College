-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 07, 2025 at 11:47 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gudang`
--

-- --------------------------------------------------------

--
-- Table structure for table `barang`
--

CREATE TABLE `barang` (
  `barang_id` int(11) NOT NULL,
  `kode_barang` varchar(20) DEFAULT NULL,
  `nama_barang` varchar(100) DEFAULT NULL,
  `stok` int(11) DEFAULT NULL,
  `harga_satuan` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `barang`
--

INSERT INTO `barang` (`barang_id`, `kode_barang`, `nama_barang`, `stok`, `harga_satuan`) VALUES
(1, 'BRG-001', 'Semen Holcim', 300, 55000),
(2, 'BRG-002', 'Cat Dulux 5L', 120, 145000),
(3, 'BRG-003', 'Besi Beton 12mm', 110, 85000),
(4, 'BRG-004', 'Paku 2 inch', 500, 15000),
(5, 'BRG-005', 'Triplek 12mm', 300, 120000),
(6, 'BRG-006', 'Batu Bata', 950, 800),
(7, 'BRG-007', 'Keramik 40x40', 300, 65000),
(8, 'BRG-008', 'Cat Avian 1L', 250, 45000),
(9, 'BRG-009', 'Semen Tiga Roda', 300, 53000),
(10, 'BRG-010', 'Pipa PVC 1 inch', 200, 35000);

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `customer_id` int(11) NOT NULL,
  `nama_customer` varchar(100) DEFAULT NULL,
  `alamat` text DEFAULT NULL,
  `no_telepon` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`customer_id`, `nama_customer`, `alamat`, `no_telepon`) VALUES
(1, 'Andi Prasetyo', 'Yogyakarta', '081212345678'),
(2, 'Budi Santoso', 'Sleman', '081312345679'),
(3, 'Citra Dewi', 'Bantul', '081434567890'),
(4, 'Dedi Kurniawan', 'Kulon Progo', '081545678901'),
(5, 'Eka Saputra', 'Gunungkidul', '081656789012'),
(6, 'Fina Rahmawati', 'Yogyakarta', '081767890123'),
(7, 'Guntur Wibowo', 'Sleman', '081878901234'),
(8, 'Hana Putri', 'Bantul', '081989012345'),
(9, 'Irfan Maulana', 'Kulon Progo', '082090123456'),
(10, 'Joko Purnomo', 'Yogyakarta', '082101234567');

-- --------------------------------------------------------

--
-- Table structure for table `log_transaksi`
--

CREATE TABLE `log_transaksi` (
  `log_id` int(11) NOT NULL,
  `aktivitas` varchar(225) DEFAULT NULL,
  `tanggal` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `log_transaksi`
--

INSERT INTO `log_transaksi` (`log_id`, `aktivitas`, `tanggal`) VALUES
(1, 'Barang ID 1 masuk sebanyak 30', '2025-12-03 11:37:06'),
(2, 'Barang ID 1 keluar sebanyak 30', '2025-12-03 11:39:38'),
(3, 'Barang ID 6 keluar sebanyak 50', '2025-12-03 11:52:23'),
(4, 'Barang ID 5 keluar sebanyak 10', '2025-12-03 11:52:57'),
(5, 'Barang ID 5 keluar sebanyak 30', '2025-12-03 11:55:00'),
(6, 'Barang ID 5 masuk sebanyak 300', '2025-12-03 11:55:22'),
(7, 'Barang ID 3 masuk sebanyak 20', '2025-12-03 11:59:16');

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE `supplier` (
  `supplier_id` int(11) NOT NULL,
  `nama_supplier` varchar(100) DEFAULT NULL,
  `alamat` text DEFAULT NULL,
  `no_telepon` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`supplier_id`, `nama_supplier`, `alamat`, `no_telepon`) VALUES
(1, 'PT Bangun Jaya', 'Jakarta', '081234567890'),
(2, 'CV Sumber Rejeki', 'Bandung', '082345678901'),
(3, 'PT Maju Sentosa', 'Surabaya', '081356789012'),
(4, 'UD Cahaya Abadi', 'Semarang', '081467890123'),
(5, 'PT Indah Makmur', 'Bekasi', '081578901234'),
(6, 'CV Jaya Abadi', 'Yogyakarta', '081689012345'),
(7, 'PT Sinar Terang', 'Bogor', '081790123456'),
(8, 'CV Artha Mulia', 'Depok', '081801234567'),
(9, 'PT Makmur Sejahtera', 'Tangerang', '081912345678'),
(10, 'UD Rejeki Baru', 'Malang', '082012345789');

-- --------------------------------------------------------

--
-- Table structure for table `transaksi_keluar`
--

CREATE TABLE `transaksi_keluar` (
  `keluar_id` int(11) NOT NULL,
  `tanggal_keluar` date DEFAULT NULL,
  `jumlah_keluar` int(11) DEFAULT NULL,
  `barang_id` int(11) DEFAULT NULL,
  `customer_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `transaksi_keluar`
--

INSERT INTO `transaksi_keluar` (`keluar_id`, `tanggal_keluar`, `jumlah_keluar`, `barang_id`, `customer_id`) VALUES
(1, '2025-12-03', 30, 1, 1),
(2, '2025-01-16', 5, 2, 2),
(3, '2025-01-17', 8, 3, 3),
(4, '2025-01-18', 15, 4, 4),
(5, '2025-12-03', 30, 5, 5),
(6, '2025-12-03', 50, 6, 6),
(7, '2025-01-21', 12, 7, 7),
(8, '2025-01-22', 9, 8, 8),
(9, '2025-01-23', 6, 9, 9),
(10, '2025-01-24', 10, 10, 10);

--
-- Triggers `transaksi_keluar`
--
DELIMITER $$
CREATE TRIGGER `log_transaksi_keluar` AFTER UPDATE ON `transaksi_keluar` FOR EACH ROW INSERT INTO log_transaksi(aktivitas)
VALUES (CONCAT('Barang ID ', NEW.barang_id, ' keluar sebanyak ', NEW.jumlah_keluar))
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `update_stok_transaksi_keluar` BEFORE UPDATE ON `transaksi_keluar` FOR EACH ROW BEGIN
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
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `transaksi_masuk`
--

CREATE TABLE `transaksi_masuk` (
  `masuk_id` int(11) NOT NULL,
  `tanggal_masuk` date DEFAULT NULL,
  `jumlah_masuk` int(11) DEFAULT NULL,
  `barang_id` int(11) DEFAULT NULL,
  `supplier_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `transaksi_masuk`
--

INSERT INTO `transaksi_masuk` (`masuk_id`, `tanggal_masuk`, `jumlah_masuk`, `barang_id`, `supplier_id`) VALUES
(1, '2025-12-03', 30, 1, 1),
(2, '2025-01-06', 50, 2, 2),
(3, '2025-12-03', 20, 3, 10),
(4, '2025-01-08', 200, 4, 4),
(5, '2025-12-03', 300, 5, 5),
(6, '2025-01-10', 150, 6, 6),
(7, '2025-01-11', 120, 7, 7),
(8, '2025-01-12', 90, 8, 8),
(9, '2025-01-13', 100, 9, 9),
(10, '2025-01-14', 80, 10, 10);

--
-- Triggers `transaksi_masuk`
--
DELIMITER $$
CREATE TRIGGER `cek_barang_saat_update_masuk` BEFORE UPDATE ON `transaksi_masuk` FOR EACH ROW BEGIN
DECLARE jumlah INT;
SELECT COUNT(*) INTO jumlah
FROM barang
WHERE barang_id = NEW.barang_id;
IF jumlah = 0 THEN
SIGNAL SQLSTATE '45000'
SET MESSAGE_TEXT = 'Barang dengan ID tersebut belum terdaftar.';
END IF;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `log_transaksi_masuk` AFTER UPDATE ON `transaksi_masuk` FOR EACH ROW INSERT INTO log_transaksi(aktivitas)
VALUES (CONCAT('Barang ID ', NEW.barang_id, ' masuk sebanyak ', NEW.jumlah_masuk))
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `update_stok_transaksi_masuk` BEFORE UPDATE ON `transaksi_masuk` FOR EACH ROW BEGIN
UPDATE barang
SET stok = stok + NEW.jumlah_masuk
WHERE barang_id = NEW.barang_id;
SET NEW.tanggal_masuk = NOW();
END
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `barang`
--
ALTER TABLE `barang`
  ADD PRIMARY KEY (`barang_id`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `log_transaksi`
--
ALTER TABLE `log_transaksi`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `supplier`
--
ALTER TABLE `supplier`
  ADD PRIMARY KEY (`supplier_id`);

--
-- Indexes for table `transaksi_keluar`
--
ALTER TABLE `transaksi_keluar`
  ADD PRIMARY KEY (`keluar_id`),
  ADD KEY `barang_id` (`barang_id`),
  ADD KEY `customer_id` (`customer_id`);

--
-- Indexes for table `transaksi_masuk`
--
ALTER TABLE `transaksi_masuk`
  ADD PRIMARY KEY (`masuk_id`),
  ADD KEY `barang_id` (`barang_id`),
  ADD KEY `supplier_id` (`supplier_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `barang`
--
ALTER TABLE `barang`
  MODIFY `barang_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `customer_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `log_transaksi`
--
ALTER TABLE `log_transaksi`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `supplier`
--
ALTER TABLE `supplier`
  MODIFY `supplier_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `transaksi_keluar`
--
ALTER TABLE `transaksi_keluar`
  MODIFY `keluar_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `transaksi_masuk`
--
ALTER TABLE `transaksi_masuk`
  MODIFY `masuk_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `transaksi_keluar`
--
ALTER TABLE `transaksi_keluar`
  ADD CONSTRAINT `transaksi_keluar_ibfk_1` FOREIGN KEY (`barang_id`) REFERENCES `barang` (`barang_id`),
  ADD CONSTRAINT `transaksi_keluar_ibfk_2` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`);

--
-- Constraints for table `transaksi_masuk`
--
ALTER TABLE `transaksi_masuk`
  ADD CONSTRAINT `transaksi_masuk_ibfk_1` FOREIGN KEY (`barang_id`) REFERENCES `barang` (`barang_id`),
  ADD CONSTRAINT `transaksi_masuk_ibfk_2` FOREIGN KEY (`supplier_id`) REFERENCES `supplier` (`supplier_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
