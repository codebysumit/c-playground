#include <stdio.h>
#include <stdint.h>  // For uintptr_t

int main()
{
    /*
    ============================================================================
    POINTER ARITHMETIC IN C (USING BOTH %u AND %p)
    ----------------------------------------------------------------------------
    When you increment or decrement a pointer, it moves by the size of the
    data type it points to:

        - int*   → 4 bytes (typically)
        - char*  → 1 byte

    This program demonstrates pointer arithmetic and prints both:
        - Pointer as an unsigned int (%u): easy to see numeric change
        - Pointer as a hexadecimal address (%p): standard representation

    - Casting pointers to `uintptr_t` ensures safe conversion to unsigned int.
    - Always use %p with (void*) cast to print pointer addresses safely.
    ============================================================================
    */

    // ========================== INT POINTER =============================

    int p = 22;
    int* ptr = &p;

    // Original address
    printf("int ptr (original)       = %u  (%p)\n", 
        (unsigned int)(uintptr_t)ptr, (void*)ptr);

    // Increment pointer (moves by sizeof(int) bytes)
    ptr++;

    // Address after increment
    printf("int ptr after ptr++      = %u  (%p)\n", 
        (unsigned int)(uintptr_t)ptr, (void*)ptr);

    // Decrement pointer (back to original)
    ptr--;

    // Address after decrement
    printf("int ptr after ptr--      = %u  (%p)\n", 
        (unsigned int)(uintptr_t)ptr, (void*)ptr);

    printf("===============================================\n");

    // ========================== CHAR POINTER =============================

    char c = 'A';
    char* c_ptr = &c;

    // Original address
    printf("char c_ptr (original)    = %u  (%p)\n", 
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    // Increment pointer (moves by 1 byte)
    c_ptr++;

    // Address after increment
    printf("char c_ptr after c_ptr++ = %u  (%p)\n", 
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    // Decrement pointer (back to original)
    c_ptr--;

    // Address after decrement
    printf("char c_ptr after c_ptr-- = %u  (%p)\n", 
        (unsigned int)(uintptr_t)c_ptr, (void*)c_ptr);

    printf("===============================================\n");

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
int ptr (original)       = 3212307900  (0x7ffe025c104c)
int ptr after ptr++      = 3212307904  (0x7ffe025c1050)
int ptr after ptr--      = 3212307900  (0x7ffe025c104c)
===============================================
char c_ptr (original)    = 3212307899  (0x7ffe025c104b)
char c_ptr after c_ptr++ = 3212307900  (0x7ffe025c104c)
char c_ptr after c_ptr-- = 3212307899  (0x7ffe025c104b)
===============================================
*/
