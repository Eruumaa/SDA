#include "stacklinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int initStack (Stack * ps) {
    ps->top = NULL;
    ps->size = 0;
    return 1;
}

int isEmpty(Stack * ps) {
    return ps->top == NULL;
}

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

int get (Stack * ps) {
    if (ps->top == NULL) {
        return 0;
    }
    return ps->top->elemen;
}

