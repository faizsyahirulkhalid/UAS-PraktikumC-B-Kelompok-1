#ifndef FITUR_H
#define FITUR_H
#define JUMLAH_KAMAR 5
#define FILE_DB "data/kamar.bin"

typedef struct {
  int nomor;
  char tipe[20];
  int tarif;
  int terisi;
} kamar;

typedef struct {
  char nama[50];
  char nik[25];
  int nomorkamar;
  int lamaMenginap;
  int totalBayar;
} Tamu;

void isiKamar(kamar kamar[]);
void tampilKamar(Kamar kamar[]);

#define JUMLAH_TAMU 5

void tampilkanStatusKamar(kamar daftarKamar[]);
void tampilkanDataTamu(Tamu daftarTamu[], int jumlahTamu);
void menuAdmin(kamar daftarKamar[], Tamu daftarTamu[], int jumlahTamu);

#endif