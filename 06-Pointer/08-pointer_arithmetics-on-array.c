#include <stdio.h>

/*
===============================================================================
ARRAY TRAVERSAL USING POINTERS IN C
-------------------------------------------------------------------------------
This program demonstrates how arrays can be accessed using:

    1. Array indexing (e.g., arr[i])
    2. Integer pointer arithmetic (e.g., *(ptr + i))
    3. `void*` with typecasting (e.g., *((int*)ptr))

Key Concepts:
-------------
- The name of the array (`arr`) is a constant pointer to the first element.
- Pointer arithmetic lets you traverse the array without using indexing.
- `void*` cannot be dereferenced directly — must be cast to proper type.

Also shown:
    - `sizeof(arr) / sizeof(arr[0])` gives total elements in the array.
    - Pointer increment `ptr++` moves by `sizeof(data_type)` bytes.
===============================================================================
*/

int main()
{
    // Integer array of 6 elements
    int arr[] = {1, 2, 3, 4, 5, 6};

    // Print the address of the array (same as &arr[0])
    printf("arr --> %p\n\n", (void*)arr);

    /*
    ----------------------------------------------------------------------------
    VERSION 1: Using integer pointer
    ----------------------------------------------------------------------------
    Declare an int pointer and point it to the beginning of the array.
    Traverse the array using pointer dereferencing and incrementing.
    */
    int* ptr = arr;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        // You can also use this single-line pointer dereference and increment:
        // printf("arr[%d] = %d\n", i, *(ptr++));

        printf("arr[%d] = %d\n", i, *ptr);
        ptr++;  // move to the next element (4 bytes ahead on most systems)
    }

    /*
    ----------------------------------------------------------------------------
    VERSION 2: Using void* (commented out)
    ----------------------------------------------------------------------------
    A `void*` pointer is generic but cannot be dereferenced directly.
    You must cast it to the correct type before dereferencing.

    Uncomment below to test this version.

    void* ptr = arr;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("arr[%d] = %d\n", i, *((int*)ptr));
        ptr += sizeof(arr[0]);  // move forward by 4 bytes (size of int)
    }
    */

    /*
    ----------------------------------------------------------------------------
    VERSION 3: Using array indexing (commented out)
    ----------------------------------------------------------------------------
    Classic method of accessing array elements.

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    */

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
arr --> 0x7ffee9cbb190

arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5
arr[5] = 6
=====================================
*/
