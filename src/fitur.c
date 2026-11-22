
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

    fprintf(fp, "===== INVOICE HOTEL =====\n");
    fprintf(fp, "Nama Tamu : %s\n", tamu.nama);
    fprintf(fp, "NIK : %s\n", tamu.nik);
    fprintf(fp, "Nomor Kamar : %d\n", tamu.nomorKamar);
    fprintf(fp, "Lama Menginap : %d malam\n", tamu.lamaMenginap);
    fprintf(fp, "Total Pembayaran : Rp%d\n", tamu.totalBayar);
    fprintf(fp, "=========================\n\n");

    fclose(fp);
    printf("Invoice berhasil dibuat.\n");
}

void checkout(Kamar kamar[], const char *namaFile) {
    Tamu tamu;
    int nomor, i;

    printf("\n===== CHECK OUT HOTEL =====\n");
    printf("Nomor kamar: ");
    scanf("%d", &nomor);

    for (i = 0; i < JUMLAH_KAMAR; i++) {
        if (kamar[i].nomor == nomor && kamar[i].terisi == 1) {
            printf("Nama tamu: ");
            scanf(" %49[^\n]", tamu.nama);

            printf("NIK: ");
            scanf(" %24s", tamu.nik);

            printf("Lama menginap: ");
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

            printf("\nCheck-out berhasil!\n");
            printf("Total pembayaran: Rp%d\n", tamu.totalBayar);
            return;
        }
    }

    printf("Kamar kosong atau nomor tidak ditemukan.\n");
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
