#include <stdio.h>

// A iterative binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1
int binary_search(int n, int arr[], int key) {
    int start = 0;
    int end = n-1;
    while (start <= end) {
        int mid = (int) start + (end - start) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;

        // If key greater, ignore left half
        if (arr[mid] < key)
            start = mid + 1;

        // If key is smaller, ignore right half
        else
            end = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// A recursive binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1
int binary_search_recursive(int arr[], int start, int end, int key) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == key)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > key)
            return binary_search_recursive(arr, start, mid - 1, key);

        // Else the element can only be present
        // in right subarray
        return binary_search_recursive(arr, mid + 1, end, key);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 6, 10, 40, 500};
    int n, key, result;
    
    key = 500;
    n = sizeof(arr) / sizeof(arr[0]);
    
    result = binary_search(n, arr, key);
    
    // result =  binary_search_recursive(arr, 0, n-1, key);

    if(result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d",result);

}
