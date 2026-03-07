typedef struct node * NodePtr;
typedef struct node {
    // Pointer untuk menyimpan teks
    char *kata;
    // Penunjuk alamat memori ke node selanjutnya
    NodePtr next;
}Node;

typedef struct list {
    // Penunjuk ke awal elemen pertama dalam linked list
    NodePtr head;
    // Pencatat jumlah elemen yang aktif untuk efisiensi perhitungan
    unsigned size;
}List;

// Prototype fungsi untuk membuat list baru
void initList(List * lptr);
// Prototype fungsi untuk mencetak kata-kata dari list
void displayList(List * lptr, char huruf);
// Prototype fungsi untuk menghapus node dan meng-cleanup memori
void freeList(List * lptr);
// Prototype fungsi untuk penyisipan kata baru ke list
int addList(List *lptr, char *kataBaru);
// Prototype fungsi untuk penghapusan kata tertentu dari list
int deleteNode(List * lptr, char *target);