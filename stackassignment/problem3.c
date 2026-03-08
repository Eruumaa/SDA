#include "stackarray.h"
#include "stacklinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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

int evaluation(char postfix[], int choice) {
    int i, op1, op2;

    if (choice == 1) {
        Stackarr ps;
        initStackArr(&ps);

        for (i = 0; postfix[i] != '\0'; i++) {
            if (isdigit(postfix[i])) pushArr(&ps, postfix[i] - '0');
            else if (strchr("+-*/", postfix[i])) {
                op2 = popArr(&ps); 
                op1 = popArr(&ps);
                pushArr(&ps, operation(op1, op2, postfix[i]));
            }
        }
        return popArr(&ps);
    }
    else {
        StackLL ps;
        initStackLL(&ps);

        for (int i = 0; postfix[i] != '\0'; i++) {
            if (isdigit(postfix[i])) pushLL(&ps, postfix[i] - '0');
            else if (strchr("+-*/", postfix[i])) {
                op2 = popLL(&ps);
                op1 = popLL(&ps);
                pushLL(&ps, operation(op1, op2, postfix[i]));
            }
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