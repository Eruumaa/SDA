#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bstLL.h"

// Fungsi membuat list baru
void initList (List * lptr) {
    lptr->head = NULL;
    lptr->size = 0;
}

// Fungsi untuk mencetak semua huruf yang tersimpan dalam linked list
void displayList (List * lptr, char huruf) {
    int count = 0;
    NodePtr current = lptr->head;
    // Kondisi untuk pengecekan jika ada list yang kosong
    if (current == NULL) {
        printf("%c  -- (0)\n", huruf);
        return;
    }
    printf("%c  ", huruf);

    // Looping untuk membatasi output sebanyak 5
    while (current != NULL && count < 5) {
        printf("%s:%d", current->kata, current->nomor);
        // Perintah untuk memindahkan penunjuk  ke alamat node selanjutnya
        current = current->next;
        count++;

        if (current != NULL && count < 5) {
            printf (", ");
        }
    }
    printf(" (%d)\n", lptr->size);
}

// Fungsi yang memasukkan kata baru ke dalam linked list
int addList (List *lptr, char * kata, int nomor) {
    NodePtr new;

    // Membuat wadah node untuk di isi pointer ke kata dan ke node selanjutnya
    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Alokasi memori eror\n");
        return 0;
    }
    // Membuat ruang memori untuk menyimpan kata
    new->kata = malloc(strlen(kata)+1);
    if (new->kata == NULL) {
        // Mengalokasi memori untuk mencegah Memory Leak
        free(new);
        return 0;
    }
    // Menyalin string dari parameter 'kata' ke dalam alokasi memori node baru (new->kata)
    strcpy (new->kata, kata);
    new->nomor = nomor;
    // Menghubungkan node sehingga head berpindah ke node baru
    new->next = lptr->head;
    lptr->head = new;
    // Menghitung otomatis jumlah elemen yang ada dalam linked list
    lptr->size++;
    return 1;
}

// Fungsi freeList yang berguna untuk membersihkan memori pada Linked List
void freeList (List * lptr) {
    NodePtr next=lptr->head;
    NodePtr current=next;
    while (current != NULL) {
        next = current->next;
        // Penghapusan pertama yaitu menghapus isi dalam node
        free (current->kata);
        // Penghapusan kedua yaitu menghapus node
        free(current);
        // Pindah ke node selanjutnya
        current = next;
    }
    // Mereset list
    lptr->head = NULL;
    lptr->size =0;
}

// Fungsi deleteNode untuk melepas node dan menyambungkan kembali ke sisa node lainnya
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
            // Dilakukannya free memory agar tidak terjadi memory leak
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

// Fungsi untuk menginisialisasi BST agar kosong dan siap digunakan
int makeIntBst (intbstree * pBst) {
    pBst->root = NULL;
    pBst->size = 0;
    return EXIT_SUCCESS;
}

// Fungsi untuk memasukkan kata ke dalam BST berdasarkan huruf pertamanya
int insertBst (intbstree * pBST , char * kata, int nomor) {
    instbstNodePtr current, previous, newNode;
    previous = NULL;
    current = pBST->root;
    // Mengambil karakter pertama dari kata dan mengubahnya menjadi huruf kecil
    char hurufAwal = tolower(kata[0]);

    // Looping untuk mencari posisi simpul yang tepat atau mengecek apakah huruf sudah ada
    while(current != NULL) {
        previous = current;
        // Jika huruf awal lebih kecil dari huruf di simpul saat ini, telusuri cabang kiri
        if (hurufAwal < current->kata)
            current = current->left;
        // Jika huruf awal lebih besar dari huruf di simpul saat ini, telusuri cabang kanan
        else if (hurufAwal > current->kata)
            current = current->right;
        // Jika huruf awal sama dengan huruf di simpul saat ini
        else {
            // Tambahkan kata tersebut ke dalam Linked List pada simpul ini
            addList(&(current->list), kata, nomor);
            return EXIT_SUCCESS;
        }
    }
    // Jika simpul dengan huruf awal tersebut belum ada di tree maka buat simpul baru
    newNode = (instbstNodePtr) malloc(sizeof(intbstNode));
    if (newNode == NULL) return EXIT_FAILURE;

    newNode->kata = hurufAwal;
    newNode->left = newNode->right = NULL;

    // Inisialisasi Linked List di dalam simpul baru, lalu masukkan kata pertamanya
    initList(&(newNode->list));
    addList(&(newNode->list), kata, nomor);

    (pBST->size)++;
    // Proses penyambungan simpul baru ke dalam tree
    if (previous == NULL) {
        pBST->root = newNode;
    } else if (hurufAwal < previous->kata) {
        previous->left = newNode; 
    } else {
        previous->right = newNode;
    }

    return EXIT_SUCCESS;
}

// Fungsi untuk mencari simpul berdasarkan huruf awal dan menampilkan isi Linked Listnya
void searchBst (intbstree * pBst, char huruf) {
    char hurufAwal = tolower(huruf);
    instbstNodePtr current = pBst->root;

    // Melakukan penelusuran tree selama simpul belum NULL
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
    printf("%c  -- (0)\n", hurufAwal);
}

// Fungsi untuk menelusuri tree secara In-Order (Kiri - Cetak - Kanan)
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

// Fungsi rekursif untuk menghapus memori setiap simpul dari bawah ke atas
void freeNode (instbstNodePtr node) {
    if (node != NULL) {
        // Telusuri dan bersihkan seluruh cabang kiri terlebih dahulu
        freeNode (node->left);
        // Telusuri dan bersihkan seluruh cabang Kanan
        freeNode (node->right);
        // Setelah child tree bersih, bersihkan isi Linked List di dalam simpul ini
        freeList (&(node->list));
        // Free memori BST
        free(node);
    }
}

// Fungsi utama untuk mendelete seluruh tree dan mencegah memory leak
void freeBst (intbstree * pBst) {
    freeNode(pBst->root);
    pBst->root = NULL;
    pBst->size = 0;
}