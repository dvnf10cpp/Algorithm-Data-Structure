#include <stdio.h>

// demo generic pointer, aka void pointer
// doesnt correspond to one particular data type
int main() {
    int a   = 1025;
    int *ap = &a;

    // void pointer
    void *vp = ap; // wont give compilation error
    // printf("Address: %d, Value: %d\n", vp, *vp); cannot dereference since its not mapped to particular datatype
    // printf("Address: %d \n", vp+1); will also give compilation error
    printf("Address: %d \n", vp);

    return 0;
}