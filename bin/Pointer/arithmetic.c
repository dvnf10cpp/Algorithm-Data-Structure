#include <stdio.h>

// arithemetic in pointer

int main() {
    printf("----------------------\n");
    int a   = 10;
    int *ap = &a; // stores pointer of var a to var pointer ap

    printf("%d\n", ap); 
    printf("%d\n", ap+1);  
    printf("----------------------\n");
    /**
     * the diff will be 4 since integer size is 4
     * and we increment the address, not the value
     * since pointer is var that holds memory address of another variable
     * printf("%d\n", *ap); 
     * below is the one if we want to increment the value
     **/
    printf("%d\n", ++*ap);
    printf("%d\n", a);
    printf("----------------------\n");
    /**
     * note that if we use increment after the asterisk (*), it increment the value of the ap,
     * which is the memory address of a 
     * printf("%d\n", *++ap);
    **/
    printf("%d\n", *++ap);
    /***
     * this will make the value of memory address of the ap kinda unknown
    */
    printf("%d\n", *ap);
    printf("----------------------\n");
    *ap = 12; // assign new value 
    int b = *ap;
    printf("%d\n", b); // b will hold 12, since we assign the value of pointer ap to b
    return 0;
}