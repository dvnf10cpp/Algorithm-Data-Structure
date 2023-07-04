## Definisi
Variabel yang menyimpang alamat dari variabel lainnya

## Pointer Types
Variabel pointer adalah "strongly typed", maksud dari ini adalah jika kita memiliki variabel pointer integer,  
maka nilai yang disimpan haruslah merupakan alamat memory yang menuju ke pada variabel integer,  
begitu juga dengan data lainnya.  
Tipe pointer sangat penting saat ketika melakukan dereferencing atau melakukan pointer arithmetic

```
int* -> int
char* -> char
struct* -> stuct
```

## Contents
[1. Introduction](./intro.c)   
[2. Arithemtic](./arithmetic.c)   
[3. Strong Type](./strong.c)    
[4. Generic Type](./generic.c)    
[5. Argument](./argument.c)    
[6. PointerToPointer](./topointer.c)   
[7. Size of func](./size.c)    
[8. Array as Pointer](./array.c)   
[9. Character Array](./string.c)    
[10. Dynamic Memory](./dynamic.c)    
[11. Memory Leak](./leak.c%2B%2B)   
 
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

#### Memory Leak
Pengguanaan dynamic memory atau section heap yang tidak benar yang mengakibatkan konsumsi memori dari program   
kita meningkat selama berjalan. 

#### Malloc
Allocate block of memory, func implementation: ```void* malloc(size_t size)```

#### Free
Deallocate block of memory

