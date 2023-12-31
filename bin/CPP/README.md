# Introduction to Data Structure
### [Resource in Use](https://www.youtube.com/watch?v=B31LgI4Y4DQ)

### What is Data Structure
Struktur data adalah cara kita menyimpan dan mengolah data dalam komputer untuk digunakan seefesien mungkin.     
### What is Abstract Data Types
Tipe data abstrak (ADT) merupakan entitas yang memiliki definisi data dan operasi tetapi tidak mempunyai implementasi.   
Contoh dari ini adalah list. List merupakan entitas dunia nyata yang umum. List merupakan koleksi dari object yang tipenya sama.       
Ketika kita mendefiniskan tipe data abstrak, kita hanya mendefinisikan tipe data yang disimpan dan operasinya. Kita tidak membahas bagaimana implementasinya.     
##### Contoh definisi list pertama :        
1. Menyimpan sejumlah n elemen tertentu dari tipe data yang diberikan
2. Menulis, membaca dan mengubah elemen dari list.
Contoh implementasi dari definisi ADT list pertama ini adalah array.        
##### Contoh definisi list kedua : 
1. List kosong hanya jika tidak ada elemen dalam list
2. Menambahkan elemen pada list dalam posisi index manapun   
3. Menghapus elemen dari list
4. Menghitung banyaknya elemen dari list
5. Membaca, dan mengubah elemen dari list
6. Dapat mendefinisikan tipe datanya, seperti string, integer dan lain-lainnya.
7. Tidak bersifat static seperti list pertama
Contoh implementasi dari definisi ADT list kedua ini adalah vector pada C++ atau ArrayList pada Java.
Kita bisa mengimplementasikan arraylist buatan kita sendiri di C++ maupun Java.    

### What is Linear Data Structure
Struktur Data Linear merupakan struktur data dimana element data disimpan dalam urutan linear.   
Contoh dari struktur data ini seperti array, linked list, stack, queue.

### What is Non Linear Data Structure
Struktur Data Non Linear merupakan struktur data dimana element data tidak disimpan dalam urutan linear, sehingga    
untuk mengunjungi semua elemen, tidak bisa dilakukan dalam sekali jalan seperti array, linked list, queue dan stack.    
Contoh dari struktur data ini seperti tree, graphs.

### How to Decide Which Data Structure to Use ?
1. Perhatikan apa yang akan disimpan pada struktur data. Sebuah struktur data bisa menjadi pilihan yang bagus untuk tipe  data tertentu.    
2. Perhatikan waktu dan ruang kompleksitas yang diperlukan dalam operasi pada struktur data tersebut.   
3. Perhatikan memory usagenya alias space complexity.

### Contents 
1. [ArrayList in CPP](./ArrayList.cpp)        
2. [LinkedList](./LinkedList.cpp)          
3. [Double Linked List](./DoubleLinkedList.cpp)
4. [Stack](./Stack.cpp)
5. [Queue](./Queue.cpp)
6. [Priority Queue](./PriorityQueue.cpp)
7. [Tree](./Tree.cpp)
8. [Binary Tree](./BinaryTree.cpp)
9. [Prefix Tree](./Trie.cpp)
10. [Binary Search Tree](./BinarySearchTree.cpp)
11. [Depth First and Breadth First Algorithm](./Algorithm.cpp)
12. [Graphs](./Graphs.cpp)
