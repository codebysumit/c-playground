#include <stdio.h>
#include <stdlib.h>

/*
===============================================================================
DYNAMIC MEMORY ALLOCATION USING CALLOC() IN C
-------------------------------------------------------------------------------
In C, `calloc()` is used to allocate memory dynamically like `malloc()`, but
with a key difference: it initializes all allocated memory bytes to **zero**.

Syntax:
    type* ptr = (type*) calloc(number_of_elements, size_of_each_element);

Key Differences from malloc():
    - malloc() allocates uninitialized memory (contains garbage).
    - calloc() allocates zero-initialized memory.
    - calloc() takes two arguments: count and size.

This program demonstrates:
    - Allocating memory using `calloc()`
    - Checking for allocation failure
    - Verifying automatic zero-initialization
    - Manually assigning values
===============================================================================
*/

int main()
{
    // Number of elements to allocate
    int n = 4;

    // Allocate memory for `n` integers (4 * sizeof(int) bytes)
    int* ptr = (int*)calloc(n, sizeof(int));

    // Error check: Ensure calloc succeeded
    if (ptr == NULL)
    {
        printf("Error: memory failed to allocate.\n");
        return 1; // Exit with error code
    }

    /*
    ----------------------------------------------------------------------------
    Step 1: Print zero-initialized memory
    ----------------------------------------------------------------------------
    calloc() automatically sets all bytes to zero.
    So ptr[i] will initially be 0.
    */
    printf("Memory initialized by calloc():\n");
    for (int i = 0; i < n; i++)
    {
        printf("  [%d] ptr (%p) = %d\n", i, (void*)&ptr[i], ptr[i]);
    }

    /*
    ----------------------------------------------------------------------------
    Step 2: Initialize values manually using array indexing
    ----------------------------------------------------------------------------
    */
    for (int i = 0; i < n; i++)
    {
        ptr[i] = i + 1; // Assign values: 1, 2, 3, 4
    }

    /*
    ----------------------------------------------------------------------------
    Step 3: Print the initialized values
    ----------------------------------------------------------------------------
    */
    printf("\nMemory after manual initialization:\n");
    for (int i = 0; i < n; i++)
    {
        printf("  ptr[%d] = %d\n", i, ptr[i]);
    }

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
Memory initialized by calloc():
  [0] ptr (0x55cd95eb4260) = 0
  [1] ptr (0x55cd95eb4264) = 0
  [2] ptr (0x55cd95eb4268) = 0
  [3] ptr (0x55cd95eb426c) = 0

Memory after manual initialization:
  ptr[0] = 1
  ptr[1] = 2
  ptr[2] = 3
  ptr[3] = 4
=====================================
*/
