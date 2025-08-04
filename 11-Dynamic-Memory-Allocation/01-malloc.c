#include <stdio.h>
#include <stdlib.h>

/*
===============================================================================
DYNAMIC MEMORY ALLOCATION USING MALLOC() IN C
-------------------------------------------------------------------------------
In C, dynamic memory allocation allows us to allocate memory during runtime.
The `malloc()` function allocates a specified number of bytes and returns a
pointer to the beginning of the block.

Syntax:
    type* ptr = (type*) malloc(size_in_bytes);

This program demonstrates:
    - Allocating memory for an integer array using malloc
    - Validating the success of malloc
    - Initializing memory using both pointer and array notation
    - Accessing values using pointer and index-based traversal

Note:
    malloc() does NOT initialize memory to 0 by default. Values may be garbage.
===============================================================================
*/

int main()
{
    // -------------------------------
    // Memory allocation
    // -------------------------------

    int size = 4;

    // Allocate memory for 4 integers (4 * 4 = 16 bytes on most systems)
    int* ptr = (int*)malloc(sizeof(int) * size);

    // Error check: Ensure malloc was successful
    if (ptr == NULL)
    {
        printf("Error: memory failed to allocate.\n");
        // exit(0); // or
        return 1; // Exit with error
    }

    /*
    ----------------------------------------------------------------------------
    Optional: Print uninitialized memory (may contain garbage or zeros)
    ----------------------------------------------------------------------------
    int* temp_ptr = ptr;
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ptr (%p) = %d\n", i, (void*)temp_ptr, *temp_ptr);
        temp_ptr++;
    }
    */

    /*
    ----------------------------------------------------------------------------
    Print uninitialized values using array indexing (ptr[i])
    ----------------------------------------------------------------------------
    */
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ptr (%p) = %d\n", i, (void*)&ptr[i], ptr[i]);
    }

    /*
    ----------------------------------------------------------------------------
    Method 1: Initialize memory using a temporary pointer and dereferencing
    ----------------------------------------------------------------------------
    int* temp_ptr = ptr;
    for (int i = 0; i < size; i++)
    {
        *temp_ptr = i + 1;  // Store values 1, 2, 3, 4
        temp_ptr++;
    }
    */

    /*
    ----------------------------------------------------------------------------
    Method 2: Initialize using index-based access
    ----------------------------------------------------------------------------
    */
    for (int i = 0; i < size; i++)
    {
        ptr[i] = i + 1;
    }

    /*
    ----------------------------------------------------------------------------
    Print initialized values
    ----------------------------------------------------------------------------
    */
    for (int i = 0; i < size; i++)
    {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
[0] ptr (0x55fbf2a5d260) = 0
[1] ptr (0x55fbf2a5d264) = 0
[2] ptr (0x55fbf2a5d268) = 0
[3] ptr (0x55fbf2a5d26c) = 0

ptr[0] = 1
ptr[1] = 2
ptr[2] = 3
ptr[3] = 4
=====================================
*/
