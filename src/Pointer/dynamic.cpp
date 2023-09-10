#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5; // goes on stack
    int *p;
    p = new int; // goes on heap
    *p = 10;    
    printf("%d\n", *p);
    delete p;
    p = new int[10];
    delete p;
    return 0;
}