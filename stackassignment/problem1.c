#include "stackarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fungsi untuk membuat validasi ekspresi tanda kurung
int isMatch(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;

    return 0;
}

int main(void) {
    Stackarr st;
    char ekspresi[MAX];

    printf("Masukkan ekspresi tanda kurung: ");
    fgets(ekspresi, sizeof(ekspresi), stdin);
    ekspresi[strcspn(ekspresi, "\n")] = 0;

    int panjang = strlen(ekspresi);
    // Kondisi untuk input yang tidak boleh kosong
    if (panjang == 1 && ekspresi[0] == '\n') {
        printf("Input tidak boleh kosong\n");
        return 0;
    }
    initStackArr(&st);

    // Perulangan untuk mengecek tiap ekspresi open-close tanda kurung 
    for (int i = 0; i < panjang; i++) {
        if (ekspresi[i] == '(' || ekspresi[i] == '{' || ekspresi[i] == '[' ) {
            pushArr(&st, ekspresi[i]);
        }
        else if (ekspresi[i] == ')' || ekspresi[i] == '}' || ekspresi[i] == ']') {
            // Kondisi jika tanda kurung tidak lengkap pada bagian close
            if (isEmptyArr(st)) {
                printf("Ekspresi salah, tanda kurung tutup tidak ada\n");
                return 0;
            }
            char open = popArr(&st);

            // Kondisi jika ekspresi tanda kurung berlebih 
            if (!isMatch(open, ekspresi[i])) {
                printf("Ekspresi salah, kurung tidak seimbang\n");
                return 0;
            }
        }
    }
    // Validasi akhir eksrepsi seimbang atau tidak
    if (isEmptyArr(st)) {
        printf("Ekspresi benar, tanda kurung seimbang\n");
    } else {
        printf("Ekspresi salah, tanda kurung tidak seimbang\n");
    }

    return EXIT_SUCCESS;
}