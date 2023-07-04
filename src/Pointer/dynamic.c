#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5; // goes on stack
    int *p;
    p = (int*)malloc(sizeof(int)); // goes on heap, in C++, use new for malloc and delete for free
    *p = 10;    
    printf("%d\n", *p);
    free(p);
    return 0;
}