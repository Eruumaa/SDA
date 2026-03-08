#include "stackarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Fungsi isEmpty untuk mengecek isi stack jika kosong
int isEmptyArr(Stack queue){
    return queue.top == -1;
}

// Fungsi Push untuk menambah elemen stack
int pushArr(Stack *ps, int elemen) {
    if (ps->top == MAX -1) {
        printf("Stack penuh, gagal menambah %d\n", elemen);
        return 0;
    }
    ps->top++;
    ps->data[ps->top] = elemen;

    return 1;
}

// Fungsi pop untuk menghapus elemen paling atas stack
int popArr(Stack *ps) {
    int nilai;
    if (isEmptyArr(*ps)) {
        printf("Stack kosong\n");
        return 0;
    } 
    nilai = ps->data[ps->top];
    ps->top = ps->top -1;

    return nilai;
}

// Fungsi get untuk membaca nilai dari elemen paling atas stack
int getArr(Stack  *ps) {
    return ps->data[ps->top];
}

// Fungsi initStack untuk membersihkan stack
int initStackArr(Stack *ps) {
    ps->top = -1;
    return 1;
}