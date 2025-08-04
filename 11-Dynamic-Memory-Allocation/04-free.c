#include <stdio.h>
#include <stdlib.h>

/*
===============================================================================
DYNAMIC MEMORY DEALLOCATION USING free() IN C
-------------------------------------------------------------------------------
In C, dynamically allocated memory (using malloc, calloc, or realloc) must be
freed manually using the `free()` function to avoid memory leaks.

Syntax:
    free(ptr);

Key Notes:
-----------
- After calling `free(ptr);`, the memory block is released back to the OS.
- The pointer still holds the same (now invalid) address.
- Accessing or dereferencing memory after free() results in **undefined behavior**.
- Compilers (with `-Wall`) may show warnings if you use the pointer after `free()`.

This program demonstrates:
    - Allocating memory using malloc()
    - Initializing and printing values
    - Freeing the memory with free()
    - Trying to access memory after free (unsafe)
===============================================================================
*/

int main()
{
    int n = 4;

    // Allocate memory for 4 integers
    int* ptr = (int*) malloc(sizeof(int) * n);

    // Check for allocation failure
    if (ptr == NULL)
    {
        printf("Error: memory failed to allocate.\n");
        return 1; // Exit with error code
    }

    // Initialize memory
    for (int i = 0; i < n; i++)
    {
        ptr[i] = i + 1;
    }

    // Print allocated values
    printf("Allocated values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("  ptr[%d] = %d\n", i, ptr[i]);
    }

    // Free the allocated memory
    free(ptr);

    /*
    ----------------------------------------------------------------------------
    WARNING: Accessing memory after it has been freed is undefined behavior.
    ----------------------------------------------------------------------------
    If compiled with `-Wall`, the compiler may emit a warning:

        warning: pointer 'ptr' may be used after 'free' [-Wuse-after-free]

    The output after `free()` may still print values (due to no immediate reuse),
    but it is NOT safe or guaranteed.
    */

    printf("\nAccessing memory after free (undefined behavior):\n");
    for (int i = 0; i < n; i++)
    {
        printf("  ptr[%d] = %d\n", i, ptr[i]);  // ⚠️ Unsafe access after free
    }

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Allocated values:
  ptr[0] = 1
  ptr[1] = 2
  ptr[2] = 3
  ptr[3] = 4

Accessing memory after free (undefined behavior):
  ptr[0] = 1637287684
  ptr[1] = 5
  ptr[2] = -297696171
  ptr[3] = 1513396893
-------------------------------------
⚠️ These values are garbage data from freed memory.
⚠️ Do NOT use memory after free.
=====================================
*/
