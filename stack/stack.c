/* Program berikut disimpan dalam file stack.c. File ini
* memiliki beberapa fungsi yang terkait dengan stack yang
* prototipenya telah dideklarasi dalam file header */
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/* fungsi untuk menginisialisasi stack */
int makeStack(Stack *ps){
ps->top = NULL;
ps->size = 0;
return 1; /* sukses */
}
/* fungsi untuk mengecek apakah stack berisi atau kosong */
int emptyStack(Stack * ps){
return ps->top == NULL;
}

/* fungsi untuk memasukkan data dalam stack */
int push(Stack * ps, int elemen){
StackNodePtr new;
new = malloc(sizeof(StackNode));
if(new==NULL){
return 0; /* alokasi memori gagal */
}
new->elemen = elemen;
new->next = ps->top;
ps->top = new;
ps->size++;
return 1; /* sukses */
}

int pop(Stack * ps){
StackNodePtr temp;
if(ps->top == NULL){
return 0; /* stack kosong */
}
temp = ps->top;
ps->top = ps->top->next;
free(temp);
ps->size--;
return 1; /* sukses */
}

/* fungsi untuk mengambil data dalam stact */
int get(Stack * ps){
return ps->top->elemen;
}