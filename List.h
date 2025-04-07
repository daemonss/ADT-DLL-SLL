#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Struktur Node untuk menyimpan data string
typedef struct Node {
    char info[MAX_NAME_LENGTH];  // Menyimpan nama orang
    struct Node *next;           // Pointer ke node berikutnya
} Node;

// Struktur LinkedList
typedef struct {
    Node *head;  // Pointer ke node pertama
} LinkedList;

// Fungsi membuat list kosong
void createList(LinkedList *L);

// Fungsi mengecek apakah list kosong
bool isEmpty(LinkedList L);

// Fungsi mengalokasikan node baru
Node* allocate(const char *value);

// Fungsi menyisipkan di awal list
void insertFirst(LinkedList *L, const char *value);

// Fungsi menyisipkan di akhir list
void insertLast(LinkedList *L, const char *value);

// Fungsi menyisipkan setelah nilai tertentu
void insertAfter(LinkedList *L, const char *value, const char *afterValue);

// Fungsi menghapus node pertama
void deleteFirst(LinkedList *L);

// Fungsi menghapus node terakhir
void deleteLast(LinkedList *L);

// Fungsi menghapus node tertentu
void deleteNode(LinkedList *L, const char *value);

// Fungsi menghapus semua node
void deleteAll(LinkedList *L);

// Fungsi mencetak isi list
void printList(LinkedList L);

#endif