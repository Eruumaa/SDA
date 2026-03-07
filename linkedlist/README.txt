Nama : Muhammad Aqil Mubarak
NPM  : 250810701100003
Penjelasan tambahan :
Berdasarkan instruksi dan struktur data yang ditentukan, program ini berhasil mengimplementasikan solusi pengelompokan kata yang menggunakan kombinasi struktur data array dan single linked list. 
Daripada menggunakan satu linked list yang berpotensi akan sangat panjang, program ini mengoptimalkan proses dengan mendeklarasikan sebuah array bernama "LL" dengan ukuran 26, yang mana masing-masing elemen ini merepresentasikan abjad 'a' hingga 'z'. 
Saat program membaca file "dbterms.txt" yang berisi puluhan ribu kata, huruf pertama dari setiap kata diekstraksi dan dikonversi menjadi index numerik, di mana index 0 pertama menghimpun kata dengan awalan 'a', dan index 25 untuk kata yang berawalan 'z'. 
Cara ini mempercepat proses pengelompokan secara drastis karena sistem dapat langsung menempatkan kata ke dalam "wadah" linked list yang spesifik tanpa harus menelusuri seluruh data. 
Struktur data linked list pada program ini dibuat menggunakan struct bernama "Node", yang masing-masing simpulnya berfungsi seperti bulatan pada rantai besi yang saling terkait. 
Setiap 'Node' ini dirancang untuk menyimpan dua informasi yaitu: pointer ke string data yaitu "char *kata" dan pointer ke simpul selanjutnya yaitu "NodePtr next". 
kemudian proses penyisipan kata baru dalam fungsi 'addList' menggunakan metode penambahan di bagian paling depan atau yang paling dekat dengan 'head' pada list. 
Ketika kata baru masuk, simpul yang baru dibentuk akan diarahkan secara pointer menuju ke alamat yang saat ini dipegang oleh 'head', kemudian 'head' dari linked list tersebut diperbarui posisinya untuk memegang simpul yang baru. 
Setelah itu pada metode penyisipan, ini sangat penting untuk performa komputasi memori karena memiliki kompleksitas waktu konstan yaitu: "O(1)", sehingga memasukkan 25.988 kata secara berturut-turut dapat dilakukan dengan beban eksekusi yang sangat ringan.
Dimana jika divisualisasikan ketika program membaca dan memasukkan tiga kata berawalan huruf 'a' secara berurutan (misalnya: "autocard", "anshari", "abda"), maka bentuk rantainya di dalam memori akan terlihat seperti berikut ini:
LL[0].head ---> [ kata: "abda" | next: ---> ] [ kata: "anshari" | next: ---> ] [ kata: "autocard" | next: NULL ]
Lebih detail lagi saat operasi penyisipan (Add) ini, misalkan kondisi awal rantai adalah 
LL[0].head ---> [ kata: "anshari" | next: ---> ] [ kata: "autocard" | next: NULL ]. 
Saat proses penyisipan kata "abda" terjadi, simpul baru new_node ---> [ kata: "abda" | next: NULL ] diciptakan di memori. Pointer 'next' dari simpul "abda" tersebut kemudian dikaitkan ke alamat simpul "anshari", lalu status LL[0]. Maka head dipindah posisinya untuk menunjuk langsung ke "abda". 
Proses instan tanpa menelusuri ke belakang inilah yang membentuk hasil rantai akhir di atas, karena untuk menangani variasi panjang kata, program ini memanfaatkan alokasi memori dinamis melalui fungsi 'malloc', yaitu sebuah perintah yang meminta ruang memori secara spesifik dari alokasi 'heap' saat program sedang berjalan. 
Kemudian dalam implementasi penyisipannya, malloc dipanggil sebanyak dua kali secara bertahap, pemanggilan pertama ini digunakan untuk menciptakan ruang kosong bagi kerangka 'Node' itu sendiri. 
Sementara itu untuk pemanggilan kedua ditujukan untuk membuat ukuran memori yang spesifik bagi karakter string 'kata' yang akan disimpan (diukur dari panjang kata ditambah satu null-terminator). 
Adapaun teknik ini dilakukan untuk mencegah terjadinya "buffer overflow" yang fungsinya sekaligus menghemat alokasi memori secara signifikan dibandingkan menggunakan batas karakter statis pada setiap simpulnya. 
Selain itu, program ini juga telah dilengkapi dengan pengecekan memori, jika pemanggilan alokasi memori mengalami kegagalan dan 'malloc' akan mengembalikan nilai 'NULL', dimana program akan mendeteksinya dan melakukan pencegahan agar sistem tidak mengalami crash.
Dilanjutkan pada fitur penghapusan data melalui fungsi 'deleteNode', konsep dasar dari struktur memori "single linked list" terlihat di mana program tidak dapat mengakses posisi elemen secara langsung seperti index array, sehingga untuk pencarian posisi kata yang ingin dihapus harus selalu cari dari simpul terdepan "head" secara linier.
Sebagai gambaran operasi pencarian (Search) dari ilustrasi rantai yang sebelumnya, pencarian dimulai dengan langkah pertama yang menetapkan pointer pembantu 'current = LL[0].head' yang menunjuk ke simpul "abda". 
Karena "abda" bukan kata yang ingin dihapus, pencarian terus lanjut ke langkah kedua melalui perintah "current = current->next" sehingga pointer melompat dan sekarang berada di simpul "anshari".Namun, jika target penghapusannya adalah "anshari", maka kata dinyatakan ditemukan dan pencarian berhenti di posisi ini. 
Jadi, untuk menjalankan proses delete ini, program menerapkan logika dua pointer yang berjalan bersamaan yaitu: pointer "current" untuk mengevaluasi kata pada simpul saat ini, dan pointer "previous" untuk menyimpan alamat memori dari simpul tepat di belakangnya. 
Jika kata yang ditargetkan telah ditemukan, program mengeluarkan simpul tersebut dari barisan list dan menyambung kembali rantai pada linked list yang terputus, dengan cara mengaitkan pointer "next" dari "previous" ke arah node setelah "current" melalui eksekusi bypass 'previous->next = current->next'.
Setelah kaitan berhasil dilepas, memori simpul "anshari" dihapus dengan perintah "free(current->kata)" dan "free(current)", sehingga sisanya menyisakan kondisi akhir rantai menjadi 
LL[0].head ---> [abda] ---> [autocard] ---> NULL
Seluruh alur alokasi dinamis ini juga melakukan manajemen pembersihan memori untuk mencegah terjadinya memory leaks (kebocoran memori). Memory leaks ini terjadi jika memori yang sebelumnya dibuat melalui "malloc" tidak dikembalikan ke sistem setelah selesai digunakan, sehingga pada akhirnya akan menjadi sampah memori. 
Pada kode program ini, pembersihan memori dilakukan menggunakan fungsi 'freeList' yang mencari simpul ke simpul sampai tidak ada lagi yang tersisa. Secara khusus, memori yang dialokasikan untuk string teks dibebaskan terlebih dahulu, kemudian diikuti dengan pembebasan memori kerangka 'Node' itu sendiri. 
Keberhasilan cara mengelola sumber daya memori ini dibuktikan oleh laporan Valgrind pada keluaran terakhir program, yaitu berupa Log analisis yang mengonfirmasi angka 51.980 blok telah dialokasikan dan 51.980 blok memori telah berhasil di"free-kan" kembali. 
Dimana pesan "All heap blocks were freed -- no leaks are possible" telah memvalidasi bahwa program telah memenuhi kriteria pengelolaan memori dan terbebas sepenuhnya dari kebocoran memori (Memory leaks).

Memory Check memakai Valgrind:
┌──(eruma㉿kali)-[~/Downloads/SDA-main/project]
└─$ valgrind ./mylist                                   
==3751== Memcheck, a memory error detector
==3751== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==3751== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==3751== Command: ./mylist
==3751== 
Pembacaan isi file teks dan pengelompokkan selesai...

Menu Pilihan:
1) Menampilkan kata-kata sesuai huruf pertama yang ditentukan
2) Menghapus kata tertentu dalam linked list
3) Selesai

Pilihan anda: 3
Program selesai
==3751== 
==3751== HEAP SUMMARY:
==3751==     in use at exit: 0 bytes in 0 blocks
==3751==   total heap usage: 51,980 allocs, 51,980 frees, 642,129 bytes allocated
==3751== 
==3751== All heap blocks were freed -- no leaks are possible
==3751== 
==3751== For lists of detected and suppressed errors, rerun with: -s
==3751== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)