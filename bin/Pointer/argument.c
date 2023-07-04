#include <stdio.h>

void increment(int x) { // function pass by value, it creates another copy of new var that got passed into parameter
    x = x + 1;
    printf("--------\nAddress: %d\n---------\n", &x);
    // different memory address 
}

void increment(int *x) { // function pass by reference in C
    *x = *x + 1;
    printf("--------\nAddress: %d\n---------\n", x);
    // same memory address 
}

int main() {
    int x;
    x = 10;
    increment(x);
    printf("Value: %d\n", x);
    printf("Address: %d\n", &x); 

    increment(&x); // now it changes the value
    printf("Value: %d\n", x);
    printf("Address: %d\n", &x); 
    return 0;
}