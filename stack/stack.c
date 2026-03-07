#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main (void) {
    Stack st;
    makeStack(&st);
    push(&st, 2);
    push(&st, 4);
    push(&st, 3);
    while (!emptyStack(&st)) {
        printf ("%d\n", get(&st));
        pop(&st);
    }
    free(&st);
    return EXIT_SUCCESS;
}

int makeStack(Stack * ps) {

}