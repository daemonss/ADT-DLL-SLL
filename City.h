#ifndef CITY_H
#define CITY_H

#include "List.h"  // Untuk SLL penduduk

#define MAX_CITY_NAME 50
#define MAX_NAME_LENGTH 50

/**
 * Struktur data untuk menyimpan informasi kota
 * - nama: Nama kota (string)
 * - penduduk: Singly Linked List (SLL) dari List.h untuk menyimpan nama penduduk
 */
typedef struct {
    char nama[MAX_CITY_NAME];
    LinkedList penduduk;  // SLL untuk data penduduk
} Kota;

/**
 * Node untuk Doubly Linked List (DLL) kota
 * - data: Data kota (nama + SLL penduduk)
 * - prev: Pointer ke node sebelumnya
 * - next: Pointer ke node berikutnya
 */
typedef struct KotaNode {
    Kota data;
    struct KotaNode *prev;
    struct KotaNode *next;
} KotaNode;

/**
 * Struktur utama untuk manajemen DLL kota
 * - head: Pointer ke node pertama
 * - tail: Pointer ke node terakhir
 * - jumlahKota: Total kota yang tersimpan
 */
typedef struct {
    KotaNode *head;
    KotaNode *tail;
    int jumlahKota;
} DaftarKota;

// Fungsi Inisialisasi
void initDaftarKota(DaftarKota *dk);

// Operasi Kota (DLL)
void tambahKota(DaftarKota *dk, const char *namaKota);
void hapusKota(DaftarKota *dk, const char *namaKota);
Kota* cariKota(DaftarKota *dk, const char *namaKota);

// Operasi Penduduk (SLL)
void tambahPenduduk(DaftarKota *dk, const char *namaKota, const char *namaPenduduk);
void cariPenduduk(DaftarKota *dk, const char *namaPenduduk);

// Tampilan Data
void tampilkanSemuaKota(DaftarKota *dk);
void tampilkanStatistik(DaftarKota *dk);

// Manajemen Memori
void freeDaftarKota(DaftarKota *dk);

// Validasi Input
bool isNamaValid(const char *nama, bool isKota);

#endif