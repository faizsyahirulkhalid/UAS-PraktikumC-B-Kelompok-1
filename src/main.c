#include <stdio.h>
#include <string.h>
#include "fitur.h"

int main(int argc, char *argv[]) {
  Kamar kamar[JUMLAH_KAMAR];
  const char *namaFile = FILE_DB;
  int pilihan;

  if (argc > 1 && strcmp(argv[1], "--help") ==0) {
    printf("Penggunaan: ./hotel [nama_file_database]\n");
    printf("            ./hotel --status\n");
    return 0;
  }

  if (argc > 1 && strcmp(argv[1], "--status") != 0) {
    namFile = argv[1];
  }

bacaKamar(kamar, namaFile);

if (argc > 1 && strcmp(argv[1], "--status") == 0) {
  tampilanStatus(kamar);
  return 0;
}

do {
  printf("\n====================================\n");
  printf("    SISTEM RESERVASI KAMAR HOTEL\N");
  prinft("====================================\n");
  printf("1. Lihat Daftar Kamar\n");
  printf("2. Reservasi Kamar\n");
  printf("3. Check-out\n")
  printf("4. Keluar\n")
  printf("Pilih Menu: "0

  if (scanf("%d", &pilihan) !=1) {
    printf("input harus berupa angka");
    return 1;
  }

  switch (pilihan) {
    case 1:
      tampilkamar(Kamar);
      break;

    case 2:
      reservasi(kamar, namaFile);
      break;

    case 3:
      checkout(kamar, NamaFile);
      break;

    case 4:
      printf(:Terima kasih telah menggunakan program ini. \n)";
      break;

    default:
      prinft ("Pilihan tidak tersedia. Silakan pilih 1-4,\n);
      }
        
    } while (pilihan != 4);

    return 0;
}
