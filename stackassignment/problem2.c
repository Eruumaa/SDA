#include "stacklinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fungsi priority untuk prioritas operator aritmatika
int priority(char operator) {
    int pick = 0;
    if (operator == '*' || operator == '/') {
        pick = 2;
    }
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

    for (i = 0; infix[i] != '\0'; i++) {
        ekspresi = infix[i];

        if (isalnum(ekspresi)) {
            postfix[j++] = ekspresi;
        }
        else if (ekspresi == '(') {
            push(&ps, ekspresi);
        }
        else if (ekspresi == ')') {
            while (!isEmpty(&ps) && get(&ps) != '(') {
                postfix[j++] = pop(&ps);
            }
            pop(&ps);
        }
        else {
            while (!isEmpty(&ps) && priority(get(&ps)) >= priority(ekspresi)) {
                postfix[j++] = pop(&ps);
            }
            push(&ps, ekspresi);
        }
    }
    while (!isEmpty(&ps)) {
        postfix[j++] = pop(&ps);
    }
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