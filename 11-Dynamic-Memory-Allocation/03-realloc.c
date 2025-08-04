#include <stdio.h>
#include <stdlib.h>

/*
===============================================================================
DYNAMIC MEMORY RESIZING USING REALLOC() IN C
-------------------------------------------------------------------------------
In C, `realloc()` is used to resize a previously allocated memory block
(made using `malloc()` or `calloc()`).

Syntax:
    type* ptr = (type*) realloc(existing_ptr, new_size_in_bytes);

Key Points:
------------
- If `realloc()` succeeds, it may move the memory block to a new location.
- If `realloc()` fails, it returns `NULL`, and the original block remains valid.
- Always reassign `ptr = realloc(ptr, ...)` carefully — or use a temp pointer.

This program demonstrates:
    - Allocating initial memory using `calloc()`
    - Resizing memory using `realloc()`
    - Performing error checks after each allocation
===============================================================================
*/

int main()
{
    int n = 4;  // Initial number of elements

    // Allocate memory for 4 integers, initialized to 0
    int* ptr = (int*)calloc(n, sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL)
    {
        printf("Error: memory failed to allocate.\n");
        return 1; // Exit with error code
    }

    /*
    ----------------------------------------------------------------------------
    Resize the allocated memory to hold 8 integers
    ----------------------------------------------------------------------------
    realloc() tries to extend the memory block.
    If not possible in-place, it allocates a new block and copies old data.
    */

    n = 8; // Update number of elements

    ptr = (int*)realloc(ptr, sizeof(int) * n);  // Resize to 8 integers

    // Check if reallocation was successful
    if (ptr == NULL)
    {
        printf("Error: memory failed to reallocate.\n");
        return 1; // Exit with error code
    }

    return 0;
}

/*
=====================================
Sample Output (if error occurs):
-------------------------------------
Error: memory failed to allocate.
-------------------------------------
(No visible output if allocation succeeds)
=====================================
*/
