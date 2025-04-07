#include "City.h"
#include <stdio.h>
#include <string.h>

// Tampilkan menu utama
void tampilkanMenu() {
    printf("\nMenu:\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Penduduk\n");
    printf("3. Hapus Kota\n");
    printf("4. Tampilkan Semua Data\n");
    printf("5. Cari Penduduk\n");
    printf("6. Tampilkan Statistik\n");
    printf("7. Keluar\n");
    printf("Pilihan: ");
}

// Dapatkan input angka dengan validasi
int inputPilihan() {
    int pilihan;
    while (1) {
        if (scanf("%d", &pilihan) != 1) {
            printf("Error: Input harus angka!\n");
            while (getchar() != '\n');  // Bersihkan buffer
            continue;
        }
        getchar();  // Hapus newline
        if (pilihan < 1 || pilihan > 7) {
            printf("Error: Pilihan tidak valid!\n");
            continue;
        }
        return pilihan;
    }
}

// Jalankan menu
void jalankanMenu() {
    DaftarKota dk;
    initDaftarKota(&dk);

    int pilihan;
    char namaKota[MAX_CITY_NAME];
    char namaPenduduk[MAX_NAME_LENGTH];

    do {
        tampilkanMenu();
        pilihan = inputPilihan();

        switch (pilihan) {
            case 1:  // Tambah kota
                printf("Nama Kota: ");
                fgets(namaKota, MAX_CITY_NAME, stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tambahKota(&dk, namaKota);
                break;

            case 2:  // Tambah penduduk
                printf("Nama Kota: ");
                fgets(namaKota, MAX_CITY_NAME, stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Nama Penduduk: ");
                fgets(namaPenduduk, MAX_NAME_LENGTH, stdin);
                namaPenduduk[strcspn(namaPenduduk, "\n")] = '\0';
                tambahPenduduk(&dk, namaKota, namaPenduduk);
                break;

            case 3:  // Hapus kota
                printf("Nama Kota yang Dihapus: ");
                fgets(namaKota, MAX_CITY_NAME, stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(&dk, namaKota);
                break;

            case 4:  // Tampilkan semua
                tampilkanSemuaKota(&dk);
                break;

            case 5:  // Cari penduduk
                printf("Nama Penduduk yang Dicari: ");
                fgets(namaPenduduk, MAX_NAME_LENGTH, stdin);
                namaPenduduk[strcspn(namaPenduduk, "\n")] = '\0';
                cariPenduduk(&dk, namaPenduduk);
                break;

            case 6:  // Statistik
                tampilkanStatistik(&dk);
                break;

            case 7:  // Keluar
                printf("Program selesai.\n");
                break;
        }
    } while (pilihan != 7);

    freeDaftarKota(&dk);
}