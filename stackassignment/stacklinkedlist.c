#include "stacklinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Fungsi initStack untuk membersihkan stack
int initStack (Stack * ps) {
    ps->top = NULL;
    ps->size = 0;
    return 1;
}

// Fungsi isEmpty untuk membersihkan stack
int isEmpty(Stack * ps) {
    return ps->top == NULL;
}

// Fungsi push untuk menambah elemen stack
int push (Stack * ps, char elemen) {
    StackNodePtr newNode;
    newNode = malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return 0;
    }
    newNode->elemen = elemen;
    newNode->next = ps->top;
    ps->top = newNode;
    ps->size++;
    return 1;
}

// Fungsi pop untuk menghapus elemen paling atas stack
int pop (Stack *ps) {
    StackNodePtr temp;
    char item;
    if (ps->top == NULL) {
        return 0;
    }
    temp = ps->top;
    ps->top = ps->top->next;
    item = temp->elemen;
    free(temp);
    ps->size--;
    return item;
}

// Fungsi get untuk membaca nilai dari elemen paling atas stack
int get (Stack * ps) {
    if (ps->top == NULL) {
        return 0;
    }
    return ps->top->elemen;
}

