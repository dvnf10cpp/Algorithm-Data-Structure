#include <stdio.h>
#include <string.h>

void print(char *str, int choice) { // passing char array to function
    int i = 0;
    if (choice==1)
        while (str[i] != '\0') 
            printf("%c", str[i++]);
    
    // below code will also work
    else
        while (*str != '\0') 
            printf("%c",*(str++));

    /** why it works?
     * remember that *str holds memory address of the first one, lets look up bellow
     * Visualize: 
     *    0   1   2   3   4   5   6   7   8   9  10  11  12  13    -> index
     *  ---------------------------------------------------------- 
     *  | A | l | g | o | r | i | t | h | m | \0 |   |   |   |   |  -> value
     *  ----------------------------------------------------------
     *   204 205 206 207 208 209 210 211 212 213                    -> memory address 
     * 
     * *str holds the memory address of 204
     * first we dereference the value of the memory address at 204, which is A by using asterisk sign (*)
     * then after that, we use arithmetic pointer to move to another memory address
     * since its a char, it moves by 1 bytes if we use post increment opeartor, therefore it moves to 205 memory address
     * and repeat again until the value that the memory address holds is a null character which is '\0'
     *
     * 
    */
    printf("\n");
}

// demo character array (strings)
int main() {
    /**
     * 1. Size of array >= n of characters in string + 1 to allocate null terminating char
     * 2. Arrays are always passed to function by reference (base address)
     **/ 
    char name[13] = "Algorithm"; // by default, if we declare string like this, C will add null character automatically
    char test1[5]; // unlike this one, you have to add null character manually or else you can print the string
    test1[0] = 'A';
    test1[1] = 'l';
    test1[2] = 'g';
    test1[3] = 'o';

    /***
     * Visualize: 
     *    0   1   2   3   4   5   6   7   8   9  10  11  12  13    -> index
     *  --------------------------------------------------------- 
     *  | A | l | g | o | r | i | t | h | m | \0 |   |   |   |   |  -> value
     *  ---------------------------------------------------------
     * at the end after m, theres a \0 char (null character), saying this is the end of the string in C
    */

    // uncommenct below code to test the consistency
    // for (int i = 0; i < 3; i++) {
    //     printf("Value: %s\n", name);
    //     printf("Value: %s\n", test1);
    // }
    printf("Value: %s\n", name);
    printf("Value: %s\n", test1);

    test1[4] = '\0';
    printf("Value: %s\n", test1);

    int len = strlen(name);
    printf("Length of var name: %d\n", len);

    // character array pointer
    char *pName = name; // valid
    // name = *pName; // not valid
    // pName[3] = 'A' will give error, cannot changes contant string pointer
    printf("%s\n",pName);
    char *pUni = "Universitas Brawijaya";
    char uni[23];
    strcpy(uni, pUni);

    printf("%s\n",pUni);
    printf("%c\n",pUni[4]);
    char replace[] = "Indonesia";
    for (int i = 0; i < strlen(replace); i++) {
        uni[i+12] = replace[i];
    }
    printf("%s\n",pUni);
    printf("%s\n",uni);

    print(uni,1);
    print(uni,2);

    print(name,2);
    return 0;
}