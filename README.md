# UAS-Kelompok-1 (Program Reservasi Kamar Hotel (Bahasa C))
UAS Praktikum Pemrograman, Sistem Reservasi Kamar Hotel

Program sederhana berbasis terminal menggunakan bahasa C.

## Fitur
- Melihat daftar kamar dan statusnya.
- Reservasi kamar dan menghitung perkiraan biaya.
- Check-out dan membuat invoice.
- Menyimpan data kamar dalam file binary.
- Membuat invoice dalam file teks.
- Mendukung argumen `--help`, `--status`, dan nama file database.

## Struktur data
- `Kamar`: nomor, tipe, tarif, dan status terisi.
- `Tamu`: nama, NIK, nomor kamar, lama menginap, dan total pembayaran.

## Kompilasi
Dari folder utama proyek:

```bash
gcc src/main.c src/fitur.c -Iinclude -o hotel
```

## Menjalankan

```bash
./hotel
./hotel --help
./hotel --status
./hotel data/kamar.bin
```

Pada Windows, jalankan `hotel.exe` sebagai pengganti `./hotel`.
Database dibuat otomatis di folder `data` saat program pertama kali dijalankan. Invoice check-out ditambahkan ke `data/invoice.txt`.

## Anggota dan pembagian tugas
1. RAIHAN - Koordinator dan Program Utama
   - Menyusun alur program dan menu utama pada src/main.c.
   - Mengatur pembacaan argc dan argv (--help, --status, nama file database).
   - Menggabungkan seluruh bagian kode dan memastikan program dapat dijalankan.

2. NOVAL - Struktur Data dan Informasi Kamar
   - Menyusun typedef struct Kamar dan Tamu pada include/fitur.h.
   - Membuat data awal kamar, tipe kamar, tarif, dan status kamar.
   - Mengerjakan fungsi isiKamar() dan tampilKamar() pada src/fitur.c.

3. FAIS - Fitur Reservasi
   - Mengerjakan proses input data tamu dan pemilihan kamar.
   - Mengerjakan fungsi reservasi(), termasuk pengecekan kamar dan perhitungan biaya.
   - Menguji alur reservasi berhasil dan kamar yang sudah terisi.

4. NADIA - Check-out dan File Handling
   - Mengerjakan penyimpanan/pembacaan database binary dengan fwrite() dan fread().
   - Mengerjakan proses check-out dan pembuatan invoice teks dengan fprintf().
   - Menguji data agar status kamar tersimpan setelah program ditutup.

5. SARAH - Pengujian dan Dokumentasi
   - Menguji menu, input, reservasi, check-out, dan argumen command line.
   - Menyusun README.md dan petunjuk kompilasi/pemakaian.
   - Menyiapkan .gitignore serta membantu mencatat commit dan menggabungkan branch GitHub.