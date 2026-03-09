#include "stackarray.h"
#include "stacklinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Fungsi operation untuk menentukan tiap eksekusi operator numerik
int operation(int a, int b, char operation) {
    switch (operation) {
        case '+': 
        return a + b;
        case '-': 
        return a - b;
        case '*': 
        return a * b;
        case '/': 
        return a / b;
        default:

        return 0;
    }
}


// Fungsi untuk menggunakan stack Array dan Linkedlist
int evaluation(char postfix[], int choice) {
    char temp[100];
    strcpy(temp, postfix);
    char *token = strtok(temp, " ");
    int op1, op2;

    // Kondisi pertama implementasi stack Array
    if (choice == 1) {
        Stackarr ps;
        initStackArr(&ps);
        // Looping untuk memproses setiap karakter dalam string postfix dengan implementasi stack array
        while (token != NULL) {
            if (isdigit(token[0])) {
                pushArr(&ps, atoi(token));
            }
            else if (strchr("+-*/", token[0])) {
                op2 = popArr(&ps); 
                op1 = popArr(&ps);
                pushArr(&ps, operation(op1, op2, token[0]));
            }
            token = strtok(NULL, " ");
        }
        return popArr(&ps);
    }
    // Kondisi kedua implementasi stack linkedlist
    else {
        StackLL ps;
        initStackLL(&ps);
        // Looping untuk memproses setiap karakter dalam string postfix dengan implementasi stack linkedlist
        while (token != NULL) {
            if (isdigit(token[0])) {
                pushLL(&ps, atoi(token));
            }
            else if (strchr("+-*/", token[0])) {
                op2 = popLL(&ps);
                op1 = popLL(&ps);
                pushLL(&ps, operation(op1, op2, token[0]));
            }
            token = strtok(NULL, " ");
        }
        return popLL(&ps);
    }
}


int main(void) {
    char postfix[100];
    double time;
    int choose;
    int result;
    clock_t start, end;

    printf("Masukkan ekspresi postfix: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = 0;

    printf("Pilih Implementasi Stack: \n");
    printf("1. Array\n");
    printf("2. LinkedList\n");
    scanf("%d", &choose);

    // Pengukuran durasi untuk membandingkan speed dari implementasi stack array dengan stack linkedlist
    start = clock();
    result = evaluation(postfix, choose);
    end = clock();

    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("=== Hasil Evaluasi ===\n");
    printf("Postfix  : %s\n", postfix);
    printf("Hasil    ; %d\n", result);
    printf("Waktu    : %f\n", time);

    return 0;
}