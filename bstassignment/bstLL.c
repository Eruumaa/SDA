#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bstLL.h"

void initList (List * lptr) {
    lptr->head = NULL;
    lptr->size = 0;
}

void displayList (List * lptr, char huruf) {
    int count = 0;
    NodePtr current = lptr->head;
    // Kondisi untuk pengecekan jika ada list yang kosong
    if (current == NULL) {
        printf("%c -- (0)\n", huruf);
        return;
    }
    printf("%c  ", huruf);

    while (current != NULL && count < 5) {
        printf("%s:%d", current->kata, current->nomor);
        // Perintah untuk memindahkan penunjuk  ke alamat node selanjutnya
        current = current->next;
        count++;

        if (current != NULL && count < 5) {
            printf (",");
        }
    }
    printf(" (%d)\n", lptr->size);
}

int addList (List *lptr, char * kata, int nomor) {
    NodePtr new;

    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Alokasi memori eror\n");
        return 0;
    }
    new->kata = malloc(strlen(kata)+1);
    if (new->kata == NULL) {
        free(new);
        return 0;
    }
    strcpy (new->kata, kata);
    new->nomor = nomor;
    new->next = lptr->head;
    lptr->head = new;
    lptr->size++;
    return 1;
}

void freeList (List * lptr) {
    NodePtr next=lptr->head;
    NodePtr current=next;
    while (current != NULL) {
        next = current->next;
        free (current->kata);
        free(current);
        current = next;
    }
    lptr->head = NULL;
    lptr->size =0;
}

int deleteNode (List * lptr, char * kata) {
    // Kondisi untuk mengecek jika ada list yang kosong
    if (lptr->head == NULL) {
        printf("Kata '%s' tidak ditemukan\n", kata);
        return 0;
    }
    NodePtr current = lptr->head;
    NodePtr previous = NULL;

    // Looping untuk mencari dalam list selama belum sampai NULL
    while (current != NULL) {
        // Kondisi untuk mencocokkan kata di node
        if (strcmp(current->kata, kata) == 0) {
            // Kondisi untuk menghapus node pertama jika kata yang dihapus di posisi paling depan
            if (previous == NULL) {
                lptr->head = current->next;
            }
            // Kondisi untuk menghapus node di tengah atau paling belakang
            else {
                previous->next = current->next;
            }
            // Dilakukannya memory cleanup agar tidak terjadi memory leak
            free(current->kata); 
            free(current); 
            // Karena satu kata sudah terbuang, jumlah total kata dalam list dikurang satu
            lptr->size--;
            printf("Kata '%s' berhasil dihapus\n", kata);
            return 1;
        }
        // Menggeser kedua pointer maju satu langkah untuk memeriksa node selanjutnya
        previous = current;
        current = current->next;
    }
    printf("Kata '%s' tidak ditemukan\n", kata);
    return 0;
}

int makeIntBst (intbstree * pBst) {
    pBst->root = NULL;
    pBst->size = 0;
    return EXIT_SUCCESS;
}

int insertBst (intbstree * pBST , char * kata, int nomor) {
    instbstNodePtr current, previous, newNode;
    previous = NULL;
    current = pBST->root;
    char hurufAwal = tolower(kata[0]);

    while(current != NULL) {
        previous = current;
        if (hurufAwal < current->kata)
            current = current->left;
        else if (hurufAwal > current->kata)
            current = current->right;
        else {
            addList(&(current->list), kata, nomor);
            return EXIT_SUCCESS; // Abaikan duplikat
        }
    }

    newNode = (instbstNodePtr) malloc(sizeof(intbstNode));
    if (newNode == NULL) return EXIT_FAILURE;

    newNode->kata = hurufAwal;
    newNode->left = newNode->right = NULL;

    initList(&(newNode->list));
    addList(&(newNode->list), kata, nomor);

    (pBST->size)++;
    if (previous == NULL) pBST->root = newNode;
    else if (hurufAwal < previous->kata) previous->left = newNode;
    else previous->right = newNode;

    return EXIT_SUCCESS;
}

void searchBst (intbstree * pBst, char huruf) {
    char hurufAwal = tolower(huruf);
    instbstNodePtr current = pBst->root;

    while (current != NULL) {
        if (hurufAwal < current->kata) {
            current = current->left;
        }
        else if (hurufAwal > current->kata) {
            current = current->right;
        }
        else {
            displayList(&(current->list), hurufAwal);
            return;
        }
    }
    printf("%c -- (0)\n", hurufAwal);
}

void inOrder (intbstree * pBst) {
    if (pBst->root == NULL) return;
    instbstNodePtr stack[100];
    int top = -1;
    instbstNodePtr curr = pBst->root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%c   %d\n", curr->kata, curr->list.size);
        curr = curr->right;
    }
}

void freeNode (instbstNodePtr node) {
    if (node != NULL) {
        freeNode (node->left);
        freeNode (node->right);
        freeList (&(node->list));
        free(node);
    }
}

void freeBst (intbstree * pBst) {
    freeNode(pBst->root);
    pBst->root = NULL;
    pBst->size = 0;
}
