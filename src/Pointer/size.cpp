#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ll long long
#define lli long long int
#define ull unsigned long long

struct Student {
    char name[100];
    char id[16];
    int age;
};

// demo sizeof func
int main() {
    printf("Size of Long Long datatype : %d\n", sizeof(ll));
    printf("Size of Char datatype      : %d\n", sizeof(char));
    printf("Size of Double datatype    : %d\n", sizeof(double));
    printf("Size of Integer datatype   : %d\n", sizeof(int));

    // arrays
    int arr[5] = {1,2,3,4,5}; 
    printf("Size of array: %d\n", sizeof(arr) / sizeof(arr[0]));
    // sizeof arr will return the total size of array depends the data types
    // int    = 4 bytes
    // char   = 1 byte
    // double = 8 bytes
    // so arr = arr = 20 bytes, since it has 5 integers allocated in the array
    // arr[0] = 4 bytes, since the datatype is int
    
    // for struct pointer, use arror (->) to access the members instead of dot (.)
    struct Student* student1 = (struct Student*)malloc(sizeof(struct Student)); // allocating memory first
    strcpy(student1->name, "Budi\0");
    strcpy(student1->id, "22515\0");
    student1->age = 18;

    printf("Size of Student datatype   : %d\n", sizeof(*student1));

    free(student1);
    return 0;
}