#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Membuat list kosong
void createList(LinkedList *L) {
    L->head = NULL;
}

// Mengecek apakah list kosong
bool isEmpty(LinkedList L) {
    return L.head == NULL;
}

// Mengecek apakah list kosong
Node* allocate(const char *value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        strncpy(newNode->info, value, MAX_NAME_LENGTH-1);
        newNode->info[MAX_NAME_LENGTH-1] = '\0';
        newNode->next = NULL;
    } else {
        printf("ERROR: Alokasi memori gagal!\n");
    }
    return newNode;
}

// Menyisipkan di awal list
void insertFirst(LinkedList *L, const char *value) {
    Node *newNode = allocate(value);
    if (newNode != NULL) {
        newNode->next = L->head;
        L->head = newNode;
    }
}

// Menyisipkan di akhir list
void insertLast(LinkedList *L, const char *value) {
    Node *newNode = allocate(value);
    if (newNode != NULL) {
        if (L->head == NULL) {
            L->head = newNode;
        } else {
            Node *last = L->head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    }
}

//menyisipkan setelah nilai tertentu
void insertAfter(LinkedList *L, const char *value, const char *afterValue) {
    Node *newNode = allocate(value);
    if (newNode != NULL) {
        Node *temp = L->head;
        while (temp != NULL && strcmp(temp->info, afterValue) != 0) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("ERROR: Nilai '%s' tidak ditemukan!\n", afterValue);
            free(newNode);
        }
    }
}

//menghapus node pertama
void deleteFirst(LinkedList *L) {
    if (isEmpty(*L)) {
        printf("ERROR: List kosong!\n");
        return;
    }
    Node *temp = L->head;
    L->head = L->head->next;
    free(temp);
}

//menghapus node terakhir
void deleteLast(LinkedList *L) {
    if (isEmpty(*L)) {
        printf("ERROR: List kosong!\n");
        return;
    }
    Node *temp = L->head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        L->head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

//menghapus node tertentu
void deleteNode(LinkedList *L, const char *value) {
    if (isEmpty(*L)) {
        printf("ERROR: List kosong!\n");
        return;
    }
    Node *temp = L->head, *prev = NULL;
    while (temp != NULL && strcmp(temp->info, value) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            L->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    } else {
        printf("ERROR: Nilai '%s' tidak ditemukan!\n", value);
    }
}

//menghapus semua node
void deleteAll(LinkedList *L) {
    while (L->head != NULL) {
        Node *temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
}

//mencetak isi list
void printList(LinkedList L) {
    Node *temp = L.head;
    while (temp != NULL) {
        printf("%s", temp->info);
        temp = temp->next;
        if (temp != NULL) printf(" -> ");
    }
    printf("\n");
}