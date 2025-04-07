#include "City.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Inisialisasi DLL kosong
void initDaftarKota(DaftarKota *dk) {
    dk->head = NULL;
    dk->tail = NULL;
    dk->jumlahKota = 0;
}

// Validasi nama (untuk kota atau penduduk)

bool isNamaValid(const char *nama, bool isKota) {
    int max_len = isKota ? MAX_CITY_NAME : MAX_NAME_LENGTH;
    
    if (strlen(nama) == 0 || strlen(nama) >= max_len) {
        printf("Error: Nama harus 1-%d karakter!\n", max_len - 1);
        return false;
    }

    for (int i = 0; nama[i] != '\0'; i++) {
        if (!isalpha(nama[i]) && nama[i] != ' ' && nama[i] != '\'') {
            printf("Error: Hanya boleh berisi huruf, spasi, atau apostrof!\n");
            return false;
        }
    }
    return true;
}

// Tambah kota baru ke DLL
void tambahKota(DaftarKota *dk, const char *namaKota) {
    if (!isNamaValid(namaKota, true)) return;

    // Cek duplikasi
    if (cariKota(dk, namaKota) != NULL) {
        printf("Error: Kota %s sudah ada!\n", namaKota);
        return;
    }

    // Buat node baru
    KotaNode *newNode = (KotaNode*)malloc(sizeof(KotaNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Alokasi memori gagal!\n");
        exit(EXIT_FAILURE);
    }

    // Isi data
    strncpy(newNode->data.nama, namaKota, MAX_CITY_NAME - 1);
    newNode->data.nama[MAX_CITY_NAME - 1] = '\0';
    createList(&newNode->data.penduduk);  // Inisialisasi SLL penduduk

    // Tambahkan ke akhir DLL
    newNode->prev = dk->tail;
    newNode->next = NULL;

    if (dk->tail != NULL) {
        dk->tail->next = newNode;
    } else {
        dk->head = newNode;  // Jika DLL kosong
    }
    dk->tail = newNode;
    dk->jumlahKota++;

    printf("Kota %s ditambahkan.\n", namaKota);
}

// Hapus kota dari DLL (beserta SLL penduduknya)
void hapusKota(DaftarKota *dk, const char *namaKota) {
    KotaNode *current = dk->head;
    while (current != NULL) {
        if (strcmp(current->data.nama, namaKota) == 0) {
            // Hapus semua penduduk (SLL)
            deleteAll(&current->data.penduduk);

            // Hapus node dari DLL
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                dk->head = current->next;  // Jika node pertama
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                dk->tail = current->prev;  // Jika node terakhir
            }

            free(current);
            dk->jumlahKota--;
            printf("Kota %s dihapus.\n", namaKota);
            return;
        }
        current = current->next;
    }
    printf("Error: Kota %s tidak ditemukan!\n", namaKota);
}

// Cari kota dalam DLL
Kota* cariKota(DaftarKota *dk, const char *namaKota) {
    KotaNode *current = dk->head;
    while (current != NULL) {
        if (strcasecmp(current->data.nama, namaKota) == 0) {
            return &(current->data);
        }
        current = current->next;
    }
    return NULL;
}

// Tambah penduduk ke SLL di kota tertentu
void tambahPenduduk(DaftarKota *dk, const char *namaKota, const char *namaPenduduk) {
    if (!isNamaValid(namaPenduduk, false)) return;

    Kota *kota = cariKota(dk, namaKota);
    if (kota == NULL) {
        printf("Error: Kota %s tidak ditemukan!\n", namaKota);
        return;
    }

    // Cek duplikasi penduduk
    Node *current = kota->penduduk.head;
    while (current != NULL) {
        if (strcmp(current->info, namaPenduduk) == 0) {
            printf("Error: Penduduk %s sudah ada!\n", namaPenduduk);
            return;
        }
        current = current->next;
    }

    insertLast(&kota->penduduk, namaPenduduk);
    printf("%s ditambahkan ke %s.\n", namaPenduduk, namaKota);
}

// Cari penduduk di semua kota (case-insensitive)
void cariPenduduk(DaftarKota *dk, const char *namaPenduduk) {
    bool ditemukan = false;
    KotaNode *currentKota = dk->head;
    
    while (currentKota != NULL) {
        Node *currentPenduduk = currentKota->data.penduduk.head;
        while (currentPenduduk != NULL) {
            if (strcasecmp(currentPenduduk->info, namaPenduduk) == 0) {
                printf("- %s (Kota: %s)\n", 
                    currentPenduduk->info, 
                    currentKota->data.nama);
                ditemukan = true;
            }
            currentPenduduk = currentPenduduk->next;
        }
        currentKota = currentKota->next;
    }
    
    if (!ditemukan) {
        printf("Penduduk '%s' tidak ditemukan.\n", namaPenduduk);
    }
}

// Tampilkan semua kota dan penduduk (traverse DLL + SLL)
void tampilkanSemuaKota(DaftarKota *dk) {
    if (dk->jumlahKota == 0) {
        printf("Belum ada data kota!\n");
        return;
    }

    KotaNode *current = dk->head;
    while (current != NULL) {
        printf("%s: ", current->data.nama);
        printList(current->data.penduduk);  // Gunakan fungsi dari List.c
        current = current->next;
    }
}

// Tampilkan statistik (total penduduk, kota terpadat)
void tampilkanStatistik(DaftarKota *dk) {
    if (dk->jumlahKota == 0) {
        printf("Belum ada data kota!\n");
        return;
    }

    int totalPenduduk = 0;
    int maxPenduduk = 0;
    const char *kotaTerpadat = dk->head->data.nama;

    printf("\nStatistik:\n");
    KotaNode *current = dk->head;
    while (current != NULL) {
        int jumlah = 0;
        Node *penduduk = current->data.penduduk.head;
        while (penduduk != NULL) {
            jumlah++;
            penduduk = penduduk->next;
        }

        printf("- %s: %d penduduk\n", current->data.nama, jumlah);
        totalPenduduk += jumlah;

        if (jumlah > maxPenduduk) {
            maxPenduduk = jumlah;
            kotaTerpadat = current->data.nama;
        }

        current = current->next;
    }

    printf("\nTotal: %d kota, %d penduduk\n", dk->jumlahKota, totalPenduduk);
    printf("Kota terpadat: %s (%d penduduk)\n", kotaTerpadat, maxPenduduk);
}

// Bebaskan semua memori (DLL + SLL)
void freeDaftarKota(DaftarKota *dk) {
    KotaNode *current = dk->head;
    while (current != NULL) {
        KotaNode *next = current->next;
        deleteAll(&current->data.penduduk);  // Hapus SLL penduduk
        free(current);  // Hapus node kota
        current = next;
    }
    dk->head = NULL;
    dk->tail = NULL;
    dk->jumlahKota = 0;
}