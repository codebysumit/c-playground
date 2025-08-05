/*
===============================================================================
FILE I/O IN C USING fputs() AND fopen()
===============================================================================
This program demonstrates writing text data to a file using `fopen()` and 
`fputs()` in C.

Topics Covered:
---------------
1. Opening a file in `w+` mode (read/write, truncates or creates file)
2. Using `fputs()` to write multiple lines and strings into the file
3. Writing to standard output (`stdout`)
4. Demonstrating a misuse of `fputs()` on `stdin` for educational purposes
5. Error handling using `NULL` check and `perror()`

===============================================================================
File Mode Used:
---------------
    "w+" → Write + Read mode
         - Truncates existing file or creates new one.
         - Allows both writing and reading.
         - File pointer is at the beginning.

===============================================================================
Functions Used:
---------------
- FILE* fopen(const char* filename, const char* mode)
- int fputs(const char* str, FILE* stream)
- void perror(const char* msg)
- void exit(int status)

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ------------------------------------------------------------
    // Declare a file pointer
    FILE* ptr;

    // ------------------------------------------------------------
    // Open file in w+ mode (write + read)
    ptr = fopen("./Hello.txt", "w+");

    // ------------------------------------------------------------
    // Handle error if file fails to open
    if (ptr == NULL) {
        printf("Error occurred while writing to a text file!\n");
        exit(1);  // Abort the program
    }

    // ------------------------------------------------------------
    // Write string literals directly to file using fputs()
    fputs("ABCD\n1234\n", ptr);

    // ------------------------------------------------------------
    // Write another string stored in an array
    char str[] = "String 1, "
                 "String 2 "
                 "String 3";
    fputs(str, ptr);

    // ------------------------------------------------------------
    // Write yet another line using a new string
    char str2[] = "\nThis is a string\n";
    fputs(str2, ptr);

    // ------------------------------------------------------------
    // Write to the terminal (standard output)
    fputs("Output text in terminal.\n", stdout);

    // ------------------------------------------------------------
    // ERROR DEMO: Trying to write to stdin (invalid use of fputs)
    // fputs expects a writable stream, and stdin is read-only.
    if (fputs("Try to write stdin", stdin) == EOF)
    {
        printf("fputs() Error.\n");
        perror("ERROR");
        return 1;
    }

    // ------------------------------------------------------------
    // Close the file after writing
    fclose(ptr);

    // ------------------------------------------------------------
    // Confirm success
    printf("Data written inside the file.\n\n");

    return 0;
}

/*
===============================================================================
EXPECTED OUTPUT ON TERMINAL:

Output text in terminal.
fputs() Error.
ERROR: Bad file descriptor
Data written inside the file.

===============================================================================
HELLO.TXT CONTENT AFTER EXECUTION:

ABCD
1234
String 1, String 2 String 3
This is a string

===============================================================================
NOTES:
-----
- `fputs()` does not automatically append newline `\n`. You must add it manually.
- `stdin` is an input-only stream, so writing to it causes an error.
- Always close the file using `fclose()` to ensure data is flushed to disk.
===============================================================================
*/
