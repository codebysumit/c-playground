#include <stdio.h>
#include <stdint.h> // for uintptr_t (used with %u)

/*
===============================================================================
POINTER ARITHMETIC: ADDITION AND SUBTRACTION WITH INTEGER OFFSETS
-------------------------------------------------------------------------------
In C, you can perform arithmetic operations on pointers:
    - Add an integer to move the pointer forward
    - Subtract an integer to move it backward

The pointer advances (or decreases) by:
    integer_offset × sizeof(data_type)

This example demonstrates pointer arithmetic using a `char*` pointer.
Since `char` is 1 byte, the pointer increases or decreases by exactly 1 byte
for each addition or subtraction.

We print addresses both as:
    - `%u` (using uintptr_t): Easy to see numeric change
    - `%p`: Proper pointer representation in hexadecimal
===============================================================================
*/

int main()
{
    // Declare and initialize a char variable
    char c = 'A';

    // Pointer to char
    char* c_ptr = &c;

    // Print the original address
    printf("Original c_ptr      = %u  (%p)\n",
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    /*
    ----------------------------------------------------------------------------
    ADDITION: Move pointer forward by 1 byte
    ----------------------------------------------------------------------------
    Equivalent to: c_ptr = c_ptr + 1;
    */
    c_ptr = c_ptr + 1;

    printf("After c_ptr + 1     = %u  (%p)\n",
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    /*
    ----------------------------------------------------------------------------
    SUBTRACTION: Move pointer back by 1 byte
    ----------------------------------------------------------------------------
    Equivalent to: c_ptr = c_ptr - 1;
    */
    c_ptr = c_ptr - 1;

    printf("After c_ptr - 1     = %u  (%p)\n",
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Original c_ptr      = 3212307899  (0x7ffe025c104b)
After c_ptr + 1     = 3212307900  (0x7ffe025c104c)
After c_ptr - 1     = 3212307899  (0x7ffe025c104b)
=====================================
*/