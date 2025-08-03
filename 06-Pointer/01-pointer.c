#include <stdio.h>

int main()
{
    /*
    ============================================================================
    INTRODUCTION TO POINTERS IN C
    ----------------------------------------------------------------------------
    A pointer is a variable that stores the memory address of another variable.
    
    Why use pointers?
        - Indirectly access and modify variables
        - Dynamic memory allocation
        - Efficient function parameter passing
        - Building complex data structures (linked lists, trees, etc.)

    Basic Syntax:
        data_type     var;           // Normal variable
        data_type*    ptr = &var;    // Pointer to var (stores its address)

        Alternatively:
            data_type* ptr;
            ptr = &var;
    ============================================================================ 
    */

    // Declare and initialize an integer variable
    int p = 6;

    // Declare a pointer to int and store the address of variable 'p'
    int* ptr = &p;

    // Print the value stored in p
    printf("Value of p: %d\n", p);

    // Print the address of p in hexadecimal format using %p
    printf("Address of p: %p\n", (void*)&p);

    /*
        ⚠️ NOTE:
        If you want to see the address in the form of an integer instead of hexadecimal,
        you can use %u. But if you compile this with the -Wall flag, you will get a warning:
        warning: format '%u' expects argument of type 'unsigned int', but argument 2 has type 'int *' [-Wformat=]
    */
    printf("Address of p (as unsigned int): %u\n", &p);

    // Pointer details
    printf("\nValue of ptr (stored address): %p\n", (void*)ptr);      // Address of p
    printf("Address of ptr itself: %p\n", (void*)&ptr);               // Address of ptr

    // Dereferencing the pointer to access value at the stored address
    printf("\nValue at address stored in ptr (%p): %d\n", (void*)ptr, *ptr);

    // Using address-of (&) and dereference (*) directly on 'p'
    printf("\nValue at address of p (%p): %d\n", (void*)&p, *(&p));

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Value of p: 6
Address of p: 0x7ffcb0b71fdc
Address of p (as unsigned int): 2964791260

Value of ptr (stored address): 0x7ffcb0b71fdc
Address of ptr itself: 0x7ffcb0b71fd0

Value at address stored in ptr (0x7ffcb0b71fdc): 6

Value at address of p (0x7ffcb0b71fdc): 6
=====================================
*/