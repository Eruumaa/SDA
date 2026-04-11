#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void) {
    IntBSTree ibst;
    MakeIntBST(&ibst);

    // Membangun pohon
    printf("--- Menambahkan Data (50, 30, 70, 20, 40, 60, 80) ---\n");
    InsertBST(&ibst, 50);
    InsertBST(&ibst, 30);
    InsertBST(&ibst, 70);
    InsertBST(&ibst, 20);
    InsertBST(&ibst, 40);
    InsertBST(&ibst, 60);
    InsertBST(&ibst, 80);

    // Menampilkan Traversals
    printf("Pre-Order  : "); preOrder(&ibst);
    printf("In-Order   : "); inOrder(&ibst);
    printf("Post-Order : "); postOrder(&ibst);
    printf("Total Node : %d\n\n", ibst.size);

    // Menghapus data
    printf("--- Menghapus Node 30 (Node dengan 2 anak) ---\n");
    deleteBST(&ibst, 30);
    
    printf("In-Order Setelah Delete: ");
    inOrder(&ibst);
    printf("Total Node Sekarang    : %d\n\n", ibst.size);

    // Membersihkan Memori
    printf("--- Membersihkan Pohon ---\n");
    freeBST(&ibst);
    printf("Pohon berhasil dibersihkan.\n");

    return EXIT_SUCCESS;
}