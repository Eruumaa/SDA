#include "stacklinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int priority(char operator) {
    if (operator == '^') return 1;
    if (operator == '*' || operator == '/') return 1;
    if (operator == '+' || operator == '-') return 1;
    return 0;
}

int infixToposfix(char infix[], char postfix[]) {
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
    char infix[] = "(A+B)*C-D/E";
    char postfix[100];

    infixToposfix(infix, postfix);

    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);

    return 0;
}