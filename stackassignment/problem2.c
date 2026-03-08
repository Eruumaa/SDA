#include "stacklinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi priority untuk prioritas operator aritmatika
int priority(char operator) {
    int pick = 0;
    // Prioritas tinggi
    if (operator == '*' || operator == '/') {
        pick = 2;  
    }
    // Prioritas rendah
    else if (operator == '+' || operator == '-') {
        pick = 1;   
    }

    return pick;
}

// Fungsi infixTopostfix untuk mengonversi infix ke postfix
int infixTopostfix(char infix[], char postfix[]) {
    Stack ps;
    initStack(&ps);
    int i, j = 0;
    char ekspresi;

    // Perulangan yang menelusuri setiap karakter dalam infix dari awal ke akhir
    for (i = 0; infix[i] != '\0'; i++) {
        ekspresi = infix[i];

        // Kondisi untuk mengecek karakter operan atau angka yang sedang dibaca
        if (isalnum(ekspresi)) {
            postfix[j++] = ekspresi;
        }
        // Kondisi kurung terbuka maka akan di push
        else if (ekspresi == '(') {
            push(&ps, ekspresi);
        }
        // Kondisi kurung tertutup maka akan di pop
        else if (ekspresi == ')') {
            while (!isEmpty(&ps) && get(&ps) != '(') {
                postfix[j++] = pop(&ps);
            }
            // Menghapus kurung tutup tanpa di print
            pop(&ps);
        }
        else {
            // Memindahkan operator dari stack ke postfix jika prioritasnya lebih tinggi atau sama
            while (!isEmpty(&ps) && priority(get(&ps)) >= priority(ekspresi)) {
                postfix[j++] = pop(&ps);
            }
            // Mem-push operator baru ke dalam stack
            push(&ps, ekspresi);
        }
    }
    // Memindahkan semua sisa operator yang masih ada di dalam stack ke hasil postfix
    while (!isEmpty(&ps)) {
        postfix[j++] = pop(&ps);
    }
    // Hasil postfix;
    postfix[j] = '\0';

    return 1;
}

int main(void) {
    char infix[100];
    char postfix[100];

    printf("Masukkan ekspresi aritmatika infix: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;


    infixTopostfix(infix, postfix);

    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);

    return 0;
}