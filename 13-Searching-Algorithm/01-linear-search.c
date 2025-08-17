#include <stdio.h>

int linear_search(int n, int arr[], int key) {
    
    // Iterate over the array in order to
    // find the key x
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


int main(void) {
    int arr[] = { 30, 60, 2, 3, 4, 10, 40 };
    int key = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = linear_search(n, arr, key);
    
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
        
    return 0;
}
