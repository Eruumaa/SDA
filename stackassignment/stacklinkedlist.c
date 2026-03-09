#include "stacklinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Fungsi initStack untuk menyiapkan stack baru
int initStackLL(StackLL * ps) {
    ps->top = NULL;
    ps->size = 0;
    return 1;
}

// Fungsi isEmpty untuk mengecek stack kosong atau tidak
int isEmptyLL(StackLL * ps) {
    return ps->top == NULL;
}

// Fungsi push untuk menambah elemen stack ke paling atas top
int pushLL(StackLL * ps, char elemen) {
    StackNodePtr newNode;
    newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        // Alokasi memori gagal
        return 0; 
    }
    newNode->elemen = elemen;
    newNode->next = ps->top;
    ps->top = newNode;
    ps->size++;
    return 1;
}

// Fungsi pop untuk mengambil dan menghapus elemen paling atas top stack
int popLL(StackLL *ps) {
    StackNodePtr temp;
    char item;
    if (ps->top == NULL) {
        // Stack kosong
        return 0;
    }
    temp = ps->top;
    ps->top = ps->top->next;
    item = temp->elemen;
    // Menghapus node dari memori setiap data diambil
    free(temp);
    ps->size--;
    return item;
}

// Fungsi get untuk membaca nilai dari elemen paling atas stack top tanpa dihapus
int getLL(StackLL * ps) {
    if (ps->top == NULL) {
        return 0;
    }
    return ps->top->elemen;
}

