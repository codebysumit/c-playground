#include <stdio.h>
#include <stdint.h> // For uintptr_t (used with %u)

/*
===============================================================================
POINTER DIFFERENCE (SUBTRACTION) IN C
-------------------------------------------------------------------------------
In C, you can subtract two pointers **only if they point to elements within the 
same array or memory block** and are of the **same type**.

The result of pointer subtraction:
    ptr1 - ptr2 → gives the number of elements between the two pointers
    (not the byte difference, unless you multiply by sizeof(type))

⚠️ Pointer **addition** (ptr1 + ptr2) is **not allowed** — it’s meaningless
in pointer arithmetic and results in a compile-time error.

This example demonstrates pointer subtraction on two `char*` variables.

Note:
    - `%u` shows the address as an unsigned integer (human-readable)
    - `%p` shows the proper pointer format
===============================================================================
*/

int main()
{
    char a = 'A';
    char b = 'B';

    // Both pointers must be of the same data type
    char* ptr1 = &a;
    char* ptr2 = &b;

    // Print pointer values (as unsigned integers and hex)
    printf("ptr1 = %u, ptr2 = %u\n", 
        (unsigned int)(uintptr_t)ptr1, 
        (unsigned int)(uintptr_t)ptr2);

    printf("ptr1 = %p, ptr2 = %p\n", (void*)ptr1, (void*)ptr2);

    /*
    ----------------------------------------------------------------------------
    POINTER SUBTRACTION: ptr1 - ptr2
    ----------------------------------------------------------------------------
    Gives the number of elements of type `char` between ptr1 and ptr2.
    Since `sizeof(char)` = 1 byte, result equals the byte difference.
    */
    printf("\nptr1 - ptr2 = %u\n", (unsigned int)(ptr1 - ptr2)); // element difference
    printf("ptr1 - ptr2 = %p\n", (void*)(ptr1 - ptr2));          // cast to void* just for format

    /*
    ----------------------------------------------------------------------------
    POINTER ADDITION: INVALID
    ----------------------------------------------------------------------------
    ptr1 + ptr2 is NOT allowed in C because it’s logically meaningless.
    Uncommenting the below lines would result in a compiler error.
    */
    // printf("ptr1 + ptr2 = %u\n", ptr1 + ptr2); // ❌ Invalid
    // printf("ptr1 + ptr2 = %p\n", ptr1 + ptr2); // ❌ Invalid

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
ptr1 = 3212307899, ptr2 = 3212307898
ptr1 = 0x7ffe025c104b, ptr2 = 0x7ffe025c104a

ptr1 - ptr2 = 1
ptr1 - ptr2 = 0x1
=====================================
*/
