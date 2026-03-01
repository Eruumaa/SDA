#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List * lptr) {
    lptr->head = NULL;
    lptr->size = 0;
}
int addList(List * lptr, char *kataBaru) {
    NodePtr new;
    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Error dalam membuat alokasi memori\n");
        return 0;
    }
    // function malloc kataBaru
    new->kata = malloc(strlen(kataBaru)+ 1);
    if (new->kata == NULL) {
        // Free alokasi memori secara dinamis
        free(new);
        return 0;
    }
    // Copy kataBaru
    strcpy(new->kata, kataBaru);
    new->next = lptr->head;
    lptr->head = new;   
    lptr->size++;
    return 1;
}
void displayList(List * lptr, char huruf) {
    int count = 0;
    NodePtr current = lptr->head;
    
    if (current == NULL) {
        printf("Kata dengan huruf awal %c tidak ditemukan\n", huruf);
        return;
    }
    printf("\n");
    while (current != NULL && count < 25) {
        printf("%s -> ", current->kata);
        current = current->next;
        count++;
    }
    printf("null\n");
}
void freeList(List * lptr) {
    NodePtr next=lptr->head;
    NodePtr current=next;
    while (current != NULL) {
        next = current->next;
        free(current->kata);
        free(current);
        current = next;
    }
    // Mereset metadata list
    lptr->head = NULL;
    lptr->size = 0;
}

int deleteNode(List * lptr, char *target) {
    if (lptr->head == NULL) {
        printf("Kata '%s' tidak ditemukan\n", target);
        return 0;
    }
    NodePtr current = lptr->head;
    NodePtr previous = NULL;

    while (current != NULL) {
        if (strcmp(current->kata, target) == 0) {
            if (previous == NULL) {
                lptr->head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current->kata);
            free(current);

            lptr->size--;
            printf("Kata '%s' berhasil dihapus\n", target);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    printf("Kata '%s' tidak ditemukan\n", target);
    return 0;
}