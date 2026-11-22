# UAS-Kelompok-1 (Program Reservasi Kamar Hotel (Bahasa C))
UAS Praktikum Pemrograman

Repositori proyek UAS Praktikum Pemrograman Bahasa C (**Kelompok 1**), berisi implementasi sistem pengelolaan kamar hotel, reservasi, check-out, pencetakan invoice, tampilan status kamar, data tamu, dan menu admin.

## Fitur
- Melihat daftar dan status lima kamar (*Kosong*/*Terisi*) serta jumlah kamar kosong dan terisi.
- Melakukan reservasi dan menghitung biaya berdasarkan tarif kamar dikali lama menginap.
- Melakukan check-out, memperbarui status kamar menjadi kosong, dan membuat invoice.
- Melihat data tamu serta mengakses menu admin (`menuAdmin`, `tampilkanStatusKamar`, `tampilkanDataTamu`).
- Menyimpan dan membaca data kamar (`FILE_DB` di `data/kamar.bin`) serta mencetak invoice ke `data/invoice.txt`.

## Pembagian Tugas Kelompok
- **Anggota 1 — NOVAL : Program Utama & Alur Program (`src/main.c`)**: Mengatur fungsi `main()`, menu utama, serta mengintegrasikan fitur antaranggota kelompok.
- **Anggota 2 — FAIS : Struct, Konstanta & Penyimpanan Data (`include/fitur.h` & bagian database `src/fitur.c`)**: Mendefinisikan konstanta (`JUMLAH_KAMAR`, `JUMLAH_TAMU`, `FILE_DB`), struktur data (`kamar`, `Tamu`), serta fungsi pengelolaan/penyimpanan data.
- **Anggota 3 — RAYHAN : Reservasi Kamar (bagian reservasi `src/fitur.c`)**: Mengelola proses reservasi kamar, input identitas tamu, pemilihan kamar, perhitungan biaya, dan pembaruan status kamar.
- **Anggota 4 — NADIA : Check-out & Invoice (bagian check-out `src/fitur.c`)**: Mengelola proses check-out, pembuatan invoice menggunakan `fprintf()`, dan pengembalian status kamar menjadi kosong.
- **Anggota 5 — SARAH : Status Kamar, Data Tamu, Menu Admin & Dokumentasi**:
  - **`tampilkanStatusKamar()`**: Menampilkan nomor, tipe, tarif, status kamar, serta jumlah kamar kosong dan terisi.
  - **`tampilkanDataTamu()`**: Menampilkan data tamu meliputi nama, NIK, nomor kamar, lama menginap, dan total bayar.
  - **`menuAdmin()`**: Menyediakan menu administrasi interaktif untuk menampilkan status kamar dan data tamu.
  - **Dokumentasi `README.md`**: Menyusun dan menyesuaikan dokumentasi proyek serta memeriksa hasil integrasi.

## Struktur Folder
- `include/fitur.h`: Deklarasi konstanta (`JUMLAH_KAMAR`, `JUMLAH_TAMU`, `FILE_DB`), struct (`kamar`, `Tamu`), dan prototipe fungsi.
- `src/fitur.c`: Implementasi fungsi pengelolaan kamar, reservasi, invoice, check-out, status kamar, data tamu, dan menu admin.
- `src/main.c`: Titik masuk program (`main()`), alur menu utama, dan integrasi seluruh fitur.
- `data/`: Penyimpanan data kamar (`data/kamar.bin`) dan file invoice (`data/invoice.txt`).
- `.gitignore`: Mengabaikan file hasil kompilasi dan artefak lokal.

## Cara Kompilasi
Jalankan dari folder utama repositori (`UAS-PraktikumC-B-Kelompok-1`):

```bash
gcc -Iinclude src/main.c src/fitur.c -o hotel
```

Di Windows:

```bash
gcc -Iinclude src/main.c src/fitur.c -o hotel.exe
```

## Cara Menjalankan
```bash
./hotel
```

Pada Windows, ganti `./hotel` dengan `hotel.exe`.

## Catatan 
- Kapasitas kamar diatur pada `JUMLAH_KAMAR` (5 kamar) dan `JUMLAH_TAMU` (5).
- Tarif kamar pada inisialisasi awal: Standard Rp250.000, Deluxe Rp400.000, dan Suite Rp650.000.
- Program ini dibuat untuk keperluan praktikum UAS pemrograman bahasa C.