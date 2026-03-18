/* Program berikut disimpan dengan nama main.c. */
#include "stack.h" /* file header di-include-kan */
#include <stdlib.h>
#include <stdio.h>

int main(void){
Stack st;
makeStack(&st);
push(&st, 2);
push(&st, 4);
push(&st, 3);
while (!emptyStack(&st)){
printf("%d\n", get(&st));
pop(&st);
}
return EXIT_SUCCESS;
}