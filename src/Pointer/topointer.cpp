#include <stdio.h>

int main() {
    int x   = 5;
    int *px = &x;

    *px = 6;
    /**
     * to store a variable of pointer to integer, we have to use a pointer variable to another pointer
     * use double astreisk sign
    */
    int **ppx   = &px;  // ppx will store the address of px
    int ***pppx = &ppx; // and so on
    /**
     * Illustration : 
     *                                          MEMORY
     *                205          215        225     230                                              -> example address
     * -----------------------------------------------------------------------------------------------
     *                215          225         6      205                                              -> value
     * -----------------------------------------------------------------------------------------------
     *                ppx          px          x     ppppx
     *                int**        int*       int    int***
    */
    // Dereferencing
    printf("%d\n", *px);         // val -> 6
    printf("%d\n", *ppx);        // val -> 225
    printf("%d\n", *pppx);       // val -> 215
    printf("%d\n", *(*pppx));    // val -> 225
    printf("%d\n", *(*(*pppx))); // val -> 225, dereferencing pointer to pointer

    ***pppx = 10;
    printf("%d\n", x);

    **ppx = *px + 2; 
    printf("%d\n", x); // guess the output
    return 0;
}