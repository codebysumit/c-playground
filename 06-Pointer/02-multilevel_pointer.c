#include <stdio.h>

int main()
{
    /*
    ============================================================================
    MULTI-LEVEL POINTERS (POINTER TO POINTER)
    ----------------------------------------------------------------------------
    In C, a pointer is a variable that stores the address of another variable.
    A multi-level pointer (also called a pointer to pointer) stores the address
    of another pointer.

    Syntax:
        data_type     var;       // A normal variable
        data_type*    ptr;       // Pointer to data_type (level 1)
        data_type**   ptr2;      // Pointer to pointer to data_type (level 2)
        data_type***  ptr3;      // Pointer to pointer to pointer (level 3)
    ============================================================================ 
    */

    // Level 0: Normal integer variable
    int p = 6;

    // Level 1: Pointer to integer (stores address of p)
    int* ptr = &p;

    // Level 2: Pointer to pointer to integer (stores address of ptr)
    int** ptr2 = &ptr;

    // Printing values and addresses
    printf("Value of p: %d\n", p);                       // Prints: 6
    printf("Address of p: %p\n", (void*)&p);             // Address of p

    printf("\nValue of ptr (address of p): %p\n", (void*)ptr);       // Same as &p
    printf("Address of ptr: %p\n", (void*)&ptr);         // Address of ptr

    printf("\nValue of ptr2 (address of ptr): %p\n", (void*)ptr2);   // Same as &ptr
    printf("Address of ptr2: %p\n", (void*)&ptr2);       // Address of ptr2

    // Accessing the value of p through different levels of indirection
    printf("\n\nAccessing value of p through different levels of dereferencing:\n");
    printf("Direct access (p): %d\n", p);                // Level 0
    printf("Dereferenced once (*ptr): %d\n", *ptr);      // Level 1
    printf("Dereferenced twice (**ptr2): %d\n", **ptr2); // Level 2

    // Alternate ways to access value of p using address-of and dereference operators
    printf("\nUsing address-of (&) and dereference (*) operators:\n");
    printf("*(&p): %d\n", *(&p));                        // Equivalent to p
    printf("**(&ptr): %d\n", **(&ptr));                  // Same as *ptr
    printf("***(&ptr2): %d\n", ***(&ptr2));              // Same as **ptr2

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Value of p: 6
Address of p: 0x7ffdda5b0d6c

Value of ptr (address of p): 0x7ffdda5b0d6c
Address of ptr: 0x7ffdda5b0d60

Value of ptr2 (address of ptr): 0x7ffdda5b0d60
Address of ptr2: 0x7ffdda5b0d58


Accessing value of p through different levels of dereferencing:
Direct access (p): 6
Dereferenced once (*ptr): 6
Dereferenced twice (**ptr2): 6

Using address-of (&) and dereference (*) operators:
*(&p): 6
**(&ptr): 6
***(&ptr2): 6
=====================================
*/