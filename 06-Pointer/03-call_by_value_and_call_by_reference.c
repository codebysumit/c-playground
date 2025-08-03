#include <stdio.h>

void swap_by_value(int, int);
void swap_by_ref(int*, int*);

int main()
{
    /*
    ============================================================================
    SWAPPING VALUES IN C: CALL BY VALUE VS CALL BY REFERENCE
    ----------------------------------------------------------------------------
    In C, function arguments can be passed in two main ways:
    
    1. Call by Value:
        - A copy of the actual parameters is passed to the function.
        - Changes made inside the function do not affect the original values.

    2. Call by Reference:
        - The address (reference) of the actual parameters is passed.
        - Changes made inside the function directly modify the original variables.

    This program demonstrates both techniques using a simple swap operation.

    Functions Used:
        swap_by_value(int a, int b)
            - Swaps values locally using call by value (has no effect outside).
        
        swap_by_ref(int* a, int* b)
            - Swaps values using pointers (call by reference).
    ============================================================================ 
    */

    int a = 10, b = 20;

    // Demonstrating Call by Value
    printf("Call by Value:\n");
    printf("Original Values:\n");
    printf("\ta: %d, b: %d\n", a, b);

    swap_by_value(a, b);  // This won't actually swap the original a and b

    printf("After swapping (by value):\n");
    printf("\ta: %d, b: %d\n", a, b);  // Values remain unchanged

    // Demonstrating Call by Reference
    printf("\nCall by Reference:\n");
    printf("Original Values:\n");
    printf("\ta: %d, b: %d\n", a, b);

    swap_by_ref(&a, &b);  // This will swap the original a and b

    printf("After swapping (by reference):\n");
    printf("\ta: %d, b: %d\n", a, b);  // Values are now swapped

    return 0;
}

/*
===============================================================================
Function: swap_by_value
-------------------------------------------------------------------------------
This function receives two integer values as arguments.
It performs a swap operation locally, but does not affect the original values 
from the calling function.
===============================================================================
*/
void swap_by_value(int a, int b)
{
    const int TEMP = a;
    a = b;
    b = TEMP;
}

/*
===============================================================================
Function: swap_by_ref
-------------------------------------------------------------------------------
This function receives two integer *pointers* as arguments.
It performs a swap operation using the memory addresses, modifying the original
values from the calling function.

Parameters:
    int* a : Pointer to the first variable
    int* b : Pointer to the second variable
===============================================================================
*/
void swap_by_ref(int* a, int* b)
{
    const int TEMP = *a;
    *a = *b;
    *b = TEMP;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Call by Value:
Original Values:
        a: 10, b: 20
After swapping (by value):
        a: 10, b: 20

Call by Reference:
Original Values:
        a: 10, b: 20
After swapping (by reference):
        a: 20, b: 10
=====================================
*/
