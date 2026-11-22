#include <stdio.h>
#include <string.h>
#include "fitur.h"

void isiKamar(Kamar kamar[]) {
    int i;
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        kamar[i].nomor = i + 101;
        kamar[i].terisi = 0;
        if (i < 2) {
            strcpy(kamar[i].tipe, "Standard");
            kamar[i].tarif = 250000;
        } else if (i < 4) {
            strcpy(kamar[i].tipe, "Deluxe");
            kamar[i].tarif = 400000;
        } else {
            strcpy(kamar[i].tipe, "Suite");
            kamar[i].tarif = 650000;
        }
    }
}

void tampilKamar(Kamar kamar[]) {
    int i;
    printf("\nDAFTAR KAMAR HOTEL\n");
    printf("No.\tTipe\t\tTarif\t\tStatus\n");
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        printf("%d\t%-10s\tRp%d\t%s\n", kamar[i].nomor,
               kamar[i].tipe, kamar[i].tarif,
               kamar[i].terisi ? "Terisi" : "Kosong");
    }
}

void simpanKamar(Kamar kamar[], const char *namaFile) {
    FILE *fp = fopen(namaFile, "wb");
    if (fp == NULL) {
        printf("Gagal menyimpan database.\n");
        return;
    }
    fwrite(kamar, sizeof(Kamar), JUMLAH_KAMAR, fp);
    fclose(fp);
}

void bacaKamar(Kamar kamar[], const char *namaFile) {
    FILE *fp = fopen(namaFile, "rb");
    if (fp == NULL) {
        isiKamar(kamar);
        simpanKamar(kamar, namaFile);
        return;
    }
    if (fread(kamar, sizeof(Kamar), JUMLAH_KAMAR, fp) != JUMLAH_KAMAR)
        isiKamar(kamar);
    fclose(fp);
}

void reservasi(Kamar kamar[], const char *namaFile) {
    Tamu tamu;
    int nomor, i, ditemukan = 0;
    tampilKamar(kamar);
    printf("\nNama tamu: ");
    scanf(" %49[^\n]", tamu.nama);
    printf("NIK: ");
    scanf(" %24s", tamu.nik);
    printf("Nomor kamar yang dipilih: ");
    scanf("%d", &nomor);
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        if (kamar[i].nomor == nomor) {
            ditemukan = 1;
            if (kamar[i].terisi) {
                printf("Maaf, kamar sudah terisi.\n");
                return;
            }
            printf("Lama menginap (malam): ");
            scanf("%d", &tamu.lamaMenginap);
            if (tamu.lamaMenginap < 1) {
                printf("Lama menginap minimal 1 malam.\n");
                return;
            }
            kamar[i].terisi = 1;
            tamu.nomorKamar = nomor;
            tamu.totalBayar = kamar[i].tarif * tamu.lamaMenginap;
            simpanKamar(kamar, namaFile);
            printf("Reservasi berhasil. Perkiraan biaya: Rp%d\n", tamu.totalBayar);
            return;
        }
    }
    if (!ditemukan) printf("Nomor kamar tidak ditemukan.\n");
}

void buatInvoice(Tamu tamu) {
    FILE *fp = fopen("data/invoice.txt", "a");
    if (fp == NULL) {
        printf("Gagal membuat invoice.\n");
        return;
    }
    fprintf(fp, "===== INVOICE HOTEL =====\nNama: %s\nNIK: %s\nKamar: %d\nLama: %d malam\nTotal: Rp%d\n\n",
            tamu.nama, tamu.nik, tamu.nomorKamar,
            tamu.lamaMenginap, tamu.totalBayar);
    fclose(fp);
}

void checkout(Kamar kamar[], const char *namaFile) {
    Tamu tamu;
    int nomor, i;
    printf("Nomor kamar untuk check-out: ");
    scanf("%d", &nomor);
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        if (kamar[i].nomor == nomor && kamar[i].terisi) {
            printf("Nama tamu: ");
            scanf(" %49[^\n]", tamu.nama);
            printf("NIK: ");
            scanf(" %24s", tamu.nik);
            printf("Lama menginap (malam): ");
            scanf("%d", &tamu.lamaMenginap);
            if (tamu.lamaMenginap < 1) {
                printf("Lama menginap tidak valid.\n");
                return;
            }
            tamu.nomorKamar = nomor;
            tamu.totalBayar = kamar[i].tarif * tamu.lamaMenginap;
            buatInvoice(tamu);
            kamar[i].terisi = 0;
            simpanKamar(kamar, namaFile);
            printf("Check-out berhasil. Total pembayaran: Rp%d\n", tamu.totalBayar);
            return;
        }
    }
    printf("Kamar tidak ditemukan atau sedang kosong.\n");
}

void tampilStatus(Kamar kamar[]) {
    int i, kosong = 0;
    printf("Kamar yang tersedia: ");
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        if (!kamar[i].terisi) {
            printf("%d ", kamar[i].nomor);
            kosong++;
        }
    }
    printf("\nJumlah kamar kosong: %d\n", kosong);
}

void tampilkanStatusKamar(kamar daftarKamar[]) {
    int i;
    int kosong = 0;
    int terisi = 0;

    printf("\n==================== STATUS KAMAR ====================\n");
    printf("No.\tTipe\t\tTarif\t\tStatus\n");
    printf("--------------------------------------------------------\n");

    for (i = 0; i < JUMLAH_KAMAR; i++) {
        printf("%d\t%-10s\tRp%d\t%s\n",
               daftarKamar[i].nomor,
               daftarKamar[i].tipe,
               daftarKamar[i].tarif,
               daftarKamar[i].terisi ? "Terisi" : "Kosong");

        if (daftarKamar[i].terisi) {
            terisi++;
        } else {
            kosong++;
        }
    }

    printf("--------------------------------------------------------\n");
    printf("Kosong: %d | Terisi: %d\n", kosong, terisi);
}