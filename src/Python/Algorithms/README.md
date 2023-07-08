# Introduction to Algorithm

### What is Algorithm ?
Algoritma adalah langkah atau instruksi untuk menyelesaikan suatu masalah.      
Dalam ilmu komputer, algoritma adalah kumpulan langkah yang diperlukan oleh program untuk menyelesaikan suatu tugas.   
Langkah pertama yang penting dalam mendefiniskan algoritma adalah masalah yang kita ingin selesaikan.   

### Algorithm Guideline
1. Harus mempunyai pernyataan masalah yang jelas, input dan output
2. Harus mempunyai instruksi dalam urutan tertentu
3. Harus membuahkan output atau hasil
4. Harus selesai dan tidak memakan waktu yang tidak terbatas

### Time Complexity
Kompleksitas waktu adalah suatu alat ukur untuk mengukur berapa lama waktu yang dibutuhkan algoritma untuk berjalan.   
Ada 3 cara, kita bisa mengukur runtime algoritma:    
1. Periksa sebarapa baik suatu algoritma berjalan dalam best case scenario 
2. Periksa sebarapa baik suatu algoritma berjalan dalam average case scenario
3. Periksa sebarapa baik suatu algoritma berjalan dalam worst case scenario            
Untuk lebih jelasnya, lihat file [linear_search](./linear_search.py) dan [binary_search](./binary_search.py)

### Space Complexity
Kompleksitas ruang adalah suatu alat ukur untuk mengukur jumlah memori yang dibutuhkan/dikonsumsi oleh algoritma.

### Big O Notation    
Dalam ilmu komputer, big o adalah definisi teoretis dari kompleksitas suatu algoritma sebagai fungsi dari ukuran.  
Lebih simpelnya, big o adalah notasi yang digunakan untuk mendeskripsikan kompleksitas.   
Notasi yang dimaksud adalah notasi yang menyederhanakan semuanya dalam satu variabel.   
Contoh kompleksitas yang ditulis dalam big o :    
```
O(n) 
```
Dimulai dari huruf gede O karena yaa namanya Big O. Maksud dari O adalah "Order of Magnitude of Complexity".   
Lalu dalam tanda kurung, ada n yang menandakan variabel yang mempengaruhi kompleksitas. Variabel ini bisa lebih dari 1.  
Big O merupakan notasi yang berguna dalam memahami kompleksitas waktu dan ruang, hanya dalam membandingkan macam -macam algoritma yang menyelesaikan satu masalah yang sama.   
#### Runtime
Definisikan ukuran input sebagai n :   
1. Constant Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma tidak dipengaruhi oleh ukuran input (besar / kecil), selalu sama. Dalam notasi Big O, direpresentasikan sebagai ```O(1)```.
2. Logarithmic Time (Sublinear) : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara logaritmik seiring ukuran input bertambah besar. Dalam notasi Big O, direpresentasikan sebagai ```O(log n)```.
3. Linear Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara linear seiring ukuran input bertambah besar. Dalam notasi Big O, direpresentasikan sebagai ```O(n)```.
4. Quadratic Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara kuadratik dengan 
pertumbuhan ukuran input. Dalam notasi Big O, direpresentasikan sebagai ```O(n^2)```
5. Cubic Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara kubik dengan pertumbuhan ukuran input. Dalam notasi Big O, direpresentasikan sebagai ```O(n^3)```
6. Exponential Time : Quadratic Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara eksponensial dengan pertumbuhan ukuran input. Dalam notasi Big O, direpresentasikan sebagai ```O(2^n)``` atau ```O(3^n)```
7. Polinomial Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara polinomial dengan pertumbuhan ukuran input. Dalam notasi Big O, direpresentasikan sebagai ```O(n^k)```
8. Factorial Time : Waktu yang dibutuhkan dalam melakukan suatu instruksi algoritma meningkat secara faktorial dengan pertumbuhan ukuran input. Dalam notasi Big O, direpresentasikan sebagai ```O(n!)```
9. Quasalinear Time : Waktu yang dibutuhkan merupakan gabungan antara linear time dengan logarithmic. Dalam notasi Big O , direpresentasikan sebagai ```O n log n```

Kontent PDF online dalam menganalisa kompleksitas algoritma : [TLX-Analisas Kompleksitas](https://raw.githubusercontent.com/ia-toki/training-gate-id-pdf/master/pemrograman-dasar-cpp_08-analisis-kompleksitas.pdf)

### Contents
[1. Linear Search](./linear_search.py)          
[2. Binary Search](./binary_search.py)                    
[3. Recursive Binary Search](./recursive_binary_search.py)            
[4. Bubble Sort](./bubble_sort.py)                
[5. Merge Sort](./merge_sort.py)               
