#include <stdio.h>

// demo strong type
int main() {
    int a   = 1025;
    int *ap = &a;

    // printing the address that ap holds and the value that the memory address hold
    printf("Address : %d, Value : %d\n", ap, *ap); // *ap => dereferencing pointer
    printf("------------------\n");

    char *cp;
    // cp = ap; => will give compile error, cp is pointer to character, ap is pointer to integer
    // instead we will try to type casting to character pointer
    cp = (char*)ap;

    printf("Adress : %d, Value : %d\n", cp, *cp);
    printf("------------------\n");
    /**
     * value of *cp is one since char is one byte size (using sizeof func)
     * and the computer will only look for one byte from these binary representation of 1025
     * 00000000 00000000 00000100 00000001      (the rightmost one)
     *    1        1        1         1         = total : 4 bytes
     * these are integer binary representation since integer size is 4 bytes
     * and since the value of the rightmost one is one by binary, it prints one 
    */

    // another arithmetic
    printf("Adress : %d, Value : %d\n", cp+1, *(cp+1)); // derefernce use closing bracket if we want to move to diff memory address
    /**
     * will print value of 4 sinze now, it referes to the third one in 1025 binary representation in integer
     * 00000000 00000000 00000100 00000001
    */
    return 0;
}