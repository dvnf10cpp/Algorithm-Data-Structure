#include <stdio.h>

void increment(int x) { // function pass by value, it creates another copy of new var that got passed into parameter
    x = x + 1;
}

void increment(int *x) {
    *x = *x + 1;
}

int main() {
    int x;
    x = 10;
    increment(x);
    printf("%d\n\n", x);
    increment(&x);
    printf("%d\n", x);
    return 0;
}