#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    ============================================================================
    TYPES OF POINTERS IN C
    ----------------------------------------------------------------------------
    Pointers are a core concept in C, allowing direct memory access and manipulation.
    Based on how and where they are used or initialized, pointers can be categorized 
    into various types.

    This program demonstrates the following pointer types:

        1. NULL Pointer
        2. Void Pointer
        3. Wild Pointer
        4. Dangling Pointer
        5. Const Pointer

    ⚠️ Note:
    Most of these pointers are conceptual and do not produce output,
    but understanding them is crucial to writing safe and efficient C code.
    ============================================================================ 
    */

    /*
    ----------------------------------------------------------------------------
    1. NULL POINTER
    ----------------------------------------------------------------------------
    A NULL pointer is explicitly assigned the value NULL.
    It represents a pointer that doesn't point to any valid memory location.
    */
    int* ptr_null = NULL;  // Initialized to NULL, safe to check before use

    /*
    ----------------------------------------------------------------------------
    2. VOID POINTER
    ----------------------------------------------------------------------------
    A void pointer (generic pointer) can hold the address of any data type.

    Characteristics:
        - Cannot be dereferenced directly.
        - Must be typecast before accessing the value.
    */
    void* ptr_void;  // Needs casting for use

    /*
    ----------------------------------------------------------------------------
    3. WILD POINTER
    ----------------------------------------------------------------------------
    A wild pointer is declared but not initialized.
    It contains a garbage address, leading to undefined behavior if accessed.

    ⚠️ Never use a wild pointer without proper initialization.
    */
    int* ptr_wild;  // Uninitialized pointer — avoid using

    /*
    ----------------------------------------------------------------------------
    4. DANGLING POINTER
    ----------------------------------------------------------------------------
    A dangling pointer points to memory that has already been freed.

    Example:
        - Allocate dynamic memory using malloc.
        - Free the memory.
        - Pointer still holds the address (invalid).

    Safe Practice:
        - Always set the pointer to NULL after free().
    */
    int* ptr = (int*)malloc(4 * sizeof(int));  // Allocate dynamic memory

    free(ptr);  // Memory deallocated — ptr is now dangling

    ptr = NULL; // Resetting to NULL to avoid accidental use

    /*
    ----------------------------------------------------------------------------
    5. CONST POINTER
    ----------------------------------------------------------------------------
    A const pointer is a pointer that cannot be changed to point to another
    memory location after initialization. However, the value it points to can
    still be modified (unless the value itself is const).

    Syntax:
        int* const ptr = &var;

    Meaning:
        - You can change the value *ptr, but not what ptr points to.
    */
    int p = 10;
    int* const ptr_const = &p;  // const pointer: address is fixed

    *ptr_const = 20;  // Allowed: modifying value at the location

    // ptr_const = &other_var; // Not allowed: cannot change address

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
(No output — this program demonstrates types of pointers only)
=====================================
*/
