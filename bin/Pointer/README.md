## Definisi
Variabel yang menyimpang alamat dari variabel lainnya

## Pointer Types
Variabel pointer adalah "strongly typed", maksud dari ini adalah jika kita memiliki variabel pointer integer,  
maka nilai yang disimpan haruslah merupakan alamat memory yang menuju ke pada variabel integer,  
begitu juga dengan data lainnya
```
int* -> int
char* -> char
struct* -> stuct
```

## Keywords
#### Dereferencing
Untuk mengakses nilai dari pointer dengan menggunakan tanda bintang (*)
Code :  
```
int *p = &a;
printf("Value: %d\n", *p);
```
#### Generic Pointer
Pointer yang memiliki tipe data void, tidak terikat dengan tipe data manaput

