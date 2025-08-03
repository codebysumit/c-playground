#include <stdio.h>

/*
===============================================================================
FUNCTION DECLARATION
-------------------------------------------------------------------------------
Declares a function `add` that takes two integers as parameters and returns
their sum.
===============================================================================
*/
int add(int, int);

int main()
{
    /*
    ============================================================================
    FUNCTION POINTERS IN C
    ----------------------------------------------------------------------------
    A function pointer is a pointer that points to a function instead of a 
    data value. It allows:

        - Dynamic selection of functions at runtime
        - Passing functions as arguments
        - Callbacks and event-driven designs

    Syntax:
        return_type (*ptr_name)(parameter_list);

    In this example:
        - fun_ptr is declared as a pointer to a function that takes two integers
          and returns an integer.
        - It is assigned the address of the function `add`.
        - The function is invoked through the pointer.
    ============================================================================
    */

    int a = 10, b = 30;

    // Declare a function pointer for a function that takes two ints and returns an int
    int (*fun_ptr)(int, int);

    // Assign the function's address to the pointer
    fun_ptr = &add;

    // Call the function using the function pointer
    printf("%d + %d = %d\n", a, b, fun_ptr(a, b));

    return 0;
}

/*
===============================================================================
Function: add
-------------------------------------------------------------------------------
Takes two integers and returns their sum.

Parameters:
    int a : First number
    int b : Second number

Returns:
    int   : Sum of a and b
===============================================================================
*/
int add(int a, int b)
{
    return a + b;
}

/*
=====================================
Sample Output (will vary per system):
-------------------------------------
10 + 30 = 40
=====================================
*/
