/*
===============================================================================
FILE OPENING MODES IN C (TEXT AND BINARY)
===============================================================================
In C, the `fopen()` function is used to open files for reading, writing,
or appending, in both text and binary modes.

------------------------------------------------------------------------------
SYNTAX:
    FILE *ptr = NULL;
    ptr = fopen(const char *filename, const char *mode);
------------------------------------------------------------------------------

This program demonstrates the use of all common file opening modes in C:

    TEXT MODES:
    --------------------------------------------------------------------------
    "r"   → Read (file must exist)
    "w"   → Write (overwrite or create new)
    "a"   → Append (add to end or create new)
    "r+"  → Read and Write (file must exist)
    "w+"  → Write and Read (overwrite or create new)
    "a+"  → Append and Read (create if not exist, append only)

    BINARY MODES:
    --------------------------------------------------------------------------
    "rb"   → Read binary (file must exist)
    "wb"   → Write binary (overwrite or create new)
    "ab"   → Append binary (create if not exist)
    "rb+"  → Read and write binary (file must exist)
    "wb+"  → Write and read binary (overwrite or create new)
    "ab+"  → Append and read binary (create if not exist, append only)

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h> // not necessary but recommended

int main() {
    FILE *file = NULL;

    /*
    ===========================================================================
    TEXT MODE ACCESS EXAMPLES
    ===========================================================================
    */

    // -------------------------------
    // Mode: "r" → Read (file must exist)
    // -------------------------------
    file = fopen("example_read.txt", "r");
    if (file == NULL) {
        printf("Failed to open file in 'r' mode. File may not exist.\n");
    } else {
        printf("File opened successfully in 'r' mode (read).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "w" → Write (overwrite or create)
    // -------------------------------
    file = fopen("example_write.txt", "w");
    if (file == NULL) {
        printf("Failed to open file in 'w' mode.\n");
    } else {
        fprintf(file, "Hello, world! (written in w mode)\n");
        printf("File opened successfully in 'w' mode (write).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "a" → Append (add to end or create)
    // -------------------------------
    file = fopen("example_append.txt", "a");
    if (file == NULL) {
        printf("Failed to open file in 'a' mode.\n");
    } else {
        fprintf(file, "Appending text...\n");
        printf("File opened successfully in 'a' mode (append).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "r+" → Read and Write (file must exist)
    // -------------------------------
    file = fopen("example_read_write.txt", "r+");
    if (file == NULL) {
        printf("Failed to open file in 'r+' mode. File may not exist.\n");
    } else {
        fprintf(file, "This is a text...\n");
        printf("File opened successfully in 'r+' mode (read and write).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "w+" → Write and Read (overwrite or create)
    // -------------------------------
    file = fopen("example_write_read.txt", "w+");
    if (file == NULL) {
        printf("Failed to open file in 'w+' mode.\n");
    } else {
        fprintf(file, "Write a text...\n");
        printf("File opened successfully in 'w+' mode (write and read).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "a+" → Append and Read (create if not exist)
    // -------------------------------
    file = fopen("example_a_plus.txt", "a+");
    if (file == NULL) {
        printf("Failed to open file in 'a+' mode.\n");
    } else {
        fprintf(file, "Appending and reading (a+ mode)...\n");
        printf("File opened in 'a+' mode (append + read).\n");
        fclose(file);
    }

    /*
    ===========================================================================
    BINARY MODE ACCESS EXAMPLES
    ===========================================================================
    */

    // -------------------------------
    // Mode: "rb" → Read binary (file must exist)
    // -------------------------------
    file = fopen("binary_read.dat", "rb");
    if (file == NULL) {
        printf("Failed to open binary file in 'rb' mode. File may not exist.\n");
    } else {
        printf("Binary file opened in 'rb' mode (read).\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "wb" → Write binary (overwrite or create)
    // -------------------------------
    file = fopen("binary_write.dat", "wb");
    if (file == NULL) {
        printf("Failed to open binary file in 'wb' mode.\n");
    } else {
        int data = 12345;
        fwrite(&data, sizeof(int), 1, file);
        printf("Binary file opened in 'wb' mode and data written.\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "ab" → Append binary (create if not exist)
    // -------------------------------
    file = fopen("binary_append.dat", "ab");
    if (file == NULL) {
        printf("Failed to open binary file in 'ab' mode.\n");
    } else {
        int data = 12345;
        fwrite(&data, sizeof(int), 1, file);
        printf("Binary file opened in 'ab' mode and data written.\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "rb+" or "r+b" → Read and write binary (file must exist)
    // -------------------------------
    file = fopen("binary_rw.dat", "rb+");
    if (file == NULL) {
        printf("Failed to open binary file in 'rb+' mode. File may not exist.\n");
    } else {
        int value;
        fread(&value, sizeof(int), 1, file);
        printf("Read binary data: %d\n", value);
        fclose(file);
    }

    // -------------------------------
    // Mode: "wb+" or "w+b" → Write and read binary (overwrite or create)
    // -------------------------------
    file = fopen("binary_rw2.dat", "wb+");
    if (file == NULL) {
        printf("Failed to open binary file in 'wb+' mode.\n");
    } else {
        int value = 2025;
        fwrite(&value, sizeof(int), 1, file);
        printf("Binary file opened in 'wb+' mode and data written.\n");
        fclose(file);
    }

    // -------------------------------
    // Mode: "ab+" or "a+b" → Append and read binary (create if not exist)
    // -------------------------------
    file = fopen("binary_append.dat", "ab+");
    if (file == NULL) {
        printf("Failed to open binary file in 'ab+' mode.\n");
    } else {
        int val = 42;
        fwrite(&val, sizeof(int), 1, file);
        printf("Binary file opened in 'ab+' mode and data appended.\n");
        fclose(file);
    }

    return 0;
}

/*
===============================================================================
NOTES:
-------------------------------------------------------------------------------
1. Always check if `fopen()` returns NULL before proceeding to use the file.
2. Text vs Binary Modes:
    - Text files are line-based and platform-dependent for newline.
    - Binary files store raw byte data, ideal for non-text data (images, etc.)
3. Use fclose(file) to close an open file and avoid resource leaks.
4. File permissions and path correctness are common causes of fopen() failure.
===============================================================================
*/
