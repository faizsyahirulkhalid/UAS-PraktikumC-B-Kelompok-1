#ifndef FITUR_H
#define FITUR_H
#define JUMLAH_KAMAR 5
#define FILE_DB "data/kamar.bin"

typedef struct {
  int nomor;
  char tipe[20];
  int tarif;
  int terisi;
} Kamar;

typedef struct {
  char nama[50];
  char nik[25];
  int nomorKamar;
  int lamaMenginap;
  int totalBayar;
} Tamu;

void isiKamar(Kamar kamar[]);
void tampilKamar(Kamar kamar[]);
void tampilStatus(Kamar kamar[]);

#endif