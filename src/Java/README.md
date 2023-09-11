## Catatan Kuliah

## Materi
1. [LinkedList](#definisi-linkedlist)

### Definisi LinkedList
Linked List adalah salah satu bentuk implementasi ADT List.
Linked List merupakan struktur data yang dibangun dari satu atau lebih node yang menemapti alokasi memori secara dinamis.   
Node merupakan tempat penyimpanan data yang terdiri dari dua field
    1. Data, digunakan untuk menyimpan data/nilai
    2. Pointer, untuk menyimpan alamat tertentu
Penempatan Node dlm memori tidak berurutuan seperti array.

Jika linked list hanya berisi satu node, maka pointer tersebut akan menunjuk ke NULL.        
Jika linked list memiliki lebih dari satu node, maka pointer akan menyimpan alamat dari node berikutnya. Sehingga antara node satu dengan node yang lain, akan terhubung kecuali node paling ujung yang menunjuk ke NULL.      
Pointer disebut juga sebagai link.

Linked List ada dua jenis,
1. Single Linked List, dalam node memiliki 2 field.
2. Doubly Linked List, dalam node memiliki 3 field, tambahan terakhir adalah pointer previous.

Perbedaan array dan linked list : 
1. Pada Array, alokasi memorinya statis sedangkan linked list dinamis
2. Pada Array, penambahan / penghapusan data terbatas, sedangkan linked list tidak terbatas
3. Pada Array, diakses secara random sesuai keinginan, sedangkan linked list diakses secara sekuensial

Implementasi : [LinkedList](./my/datastructure/LinkedList.java)