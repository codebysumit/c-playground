#include <stdio.h>

/*
===============================================================================
POINTER COMPARISONS IN C
-------------------------------------------------------------------------------
In C, pointers can be compared using relational operators just like integers.

Valid comparisons include:
    - Equality      : ptr1 == ptr2
    - Inequality    : ptr1 != ptr2
    - Greater Than  : ptr1 > ptr2
    - Less Than     : ptr1 < ptr2
    - Greater Equal : ptr1 >= ptr2
    - Less Equal    : ptr1 <= ptr2

⚠️ Important Rules:
    - Comparing a pointer with NULL is valid.
    - Relational comparisons (<, >, <=, >=) are only **defined** if the pointers
      point into the **same array or memory block**.
===============================================================================
*/

int main()
{
    // -------------------------------
    // NULL pointer comparison
    // -------------------------------

    int* ptr_null = NULL;

    // Check if pointer is equal to NULL
    printf("ptr_null == NULL ? %s\n", ptr_null == NULL ? "TRUE" : "FALSE");

    // Check if pointer is not equal to NULL
    printf("ptr_null != NULL ? %s\n", ptr_null != NULL ? "TRUE" : "FALSE");

    // -------------------------------
    // Pointer relational comparisons
    // -------------------------------

    int a = 10;

    // Base pointer
    int* ptr = &a;

    // Offset pointer (10 ints ahead)
    int* ptr2 = ptr + 10;

    // ptr2 > ptr
    printf("\nptr + 10 > ptr  ? %s\n", ptr2 > ptr ? "TRUE" : "FALSE");

    // ptr2 >= ptr
    printf("ptr + 10 >= ptr ? %s\n", ptr2 >= ptr ? "TRUE" : "FALSE");

    // ptr2 < ptr
    printf("ptr + 10 < ptr  ? %s\n", ptr2 < ptr ? "TRUE" : "FALSE");

    // ptr2 <= ptr
    printf("ptr + 10 <= ptr ? %s\n", ptr2 <= ptr ? "TRUE" : "FALSE");

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
ptr_null == NULL ? TRUE
ptr_null != NULL ? FALSE

ptr + 10 > ptr  ? TRUE
ptr + 10 >= ptr ? TRUE
ptr + 10 < ptr  ? FALSE
ptr + 10 <= ptr ? FALSE
=====================================
*/
