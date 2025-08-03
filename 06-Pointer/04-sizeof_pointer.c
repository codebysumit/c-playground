#include <stdio.h>

/*
===============================================================================
STRUCTURE DEFINITION
-------------------------------------------------------------------------------
Defines a custom structure named `tuple` that contains two integer members.
This will be used to test the size of a pointer to a user-defined type.
===============================================================================
*/
typedef struct
{
    int a;
    int b;
} tuple;

int main()
{
    /*
    ============================================================================
    POINTER SIZES IN C
    ----------------------------------------------------------------------------
    In C, the size of any pointer type depends on the system architecture and 
    **not** on the data type it points to.

    On a typical:
        - 32-bit system: All pointers are usually 4 bytes (32 bits)
        - 64-bit system: All pointers are usually 8 bytes (64 bits)

    This program demonstrates that:
        sizeof(int*)   == sizeof(char*)   == sizeof(float*)   == sizeof(tuple*)

    Even though the underlying data types are different, all pointers hold 
    memory **addresses**, and address size is determined by the architecture.
    ============================================================================
    */

    // Pointers to different data types
    int* ptr1;
    char* ptr2;
    float* ptr3;
    tuple* ptr4;

    // Print the sizes of each pointer (in bytes)
    printf("int*    : %zu bytes\n", sizeof(ptr1));
    printf("char*   : %zu bytes\n", sizeof(ptr2));
    printf("float*  : %zu bytes\n", sizeof(ptr3));
    printf("tuple*  : %zu bytes\n", sizeof(ptr4));

    return 0;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
On a 64-bit system:
    int*    : 8 bytes
    char*   : 8 bytes
    float*  : 8 bytes
    tuple*  : 8 bytes

On a 32-bit system:
    int*    : 4 bytes
    char*   : 4 bytes
    float*  : 4 bytes
    tuple*  : 4 bytes
=====================================
*/
