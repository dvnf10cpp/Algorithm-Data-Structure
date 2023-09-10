#include <stdio.h>

// introduction to pointer

void info(int *pointer) { //function to print pointer integer information
    printf("Value  : %d\n", *pointer); // derefencing by using star/asterisk (*)
    printf("Adress : %d\n", pointer);  // printing memory address that the pointer holds
    printf("Holded : %d\n", &pointer); // printing memory address of the pointer
    printf("\n");
}

void modify(int *pointer, int value) { // function to modify the value of memory address that pointer holds
    *pointer = value; // dereferencing
}

int main() {
    int a;  // int variable
    int *ap; // pointer variable to integer

    ap = &a; // stores address of var a to p by using ampersand (&) 
    a=5;
    info(ap);
    modify(ap, 100); // will also modify the value of a, since p holds the memory address of var a
    info(&a);       // send pointer variabel to info func (&)
    // info(a);     // error, info func only accepts pointer variable

    char c = 'y';   // char variable
    char *cp; // pointer variable to char

    cp = &c;
    *cp = 'n';
    printf("Value : %c\n",c);

    // can also be used for struct    
    

    return 0;
}