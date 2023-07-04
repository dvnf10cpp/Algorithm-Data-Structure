#include <stdio.h>

void printAddresses(int *array, int *n) { // passing array as pointer
    for (int i = 0; i < *n; i++) 
        printf("Value: %d, Address: %d\n", *(array+i), array+i);
    
    printf("----------------------------\n");
}

/**
 * 
*/
int sumOfArray(int A[]) {
    // int n = sizeof(A) / sizeof(A[0]); // this code
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    // integer array
    /**
     * declaring array will save n items in array as a block of n consecutive items
     * example:
    */
    int n; int A[n = 5]; A[0] = 0; A[1] = 1; A[2] = 2; A[3] = 3; A[4] = 4;
    /**
     * the above array will be saved into memory like this
     *                                   MEMORY
     * ------------------------------------------------------------------------------------------
     * | A[0] | A[1] | A[2] | A[3] | A[4] |                                                      -> value
     * ------------------------------------------------------------------------------------------
     *   216    220    224     228   332                                                         -> example memory address
     * notice the diff is 4 since we use integer, the size of integer is 4
    */ 
    printAddresses(A, &n);
    printf("Sum: %d\n", sumOfArray(A));
    return 0;
}