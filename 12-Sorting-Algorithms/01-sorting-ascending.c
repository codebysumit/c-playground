#include <stdio.h>
#include <stdbool.h>
#include <time.h>


void printarr(int n, int arr[]);
void randarr(int N, int arr[]);

void bubble_sort(int n, int arr[]);
void selection_sort(int n, int arr[]);
void insertion_sort(int n, int arr[]);

// merge sort
void merge(int arr[], int start, int mid, int end);
void merge_sort(int arr[], int start, int end);

// quick sort
void swap(int* a, int* b);
void quick_sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);


void printarr(int n, int arr[])
{
    int i;
    printf("Array[%d] => {", n);
    for(i = 0; i < n; i++)
    {
        if(i != n-1)
            printf("%d, ", arr[i]);
        else
            printf("%d", arr[i]);
    }
    printf("}\n");
}


// Sources: https://stackoverflow.com/q/4173610/18003955
void randarr(int size, int arr[])
{
    int i;

    // inizialize
    for (i = 0; i < size; ++i)
      arr[i] = i;

    for (i = size - 1; i > 0; --i) {
      // generate random index
      int w = rand()%i;
      // swap items
      int t = arr[i];
      arr[i] = arr[w];
      arr[w] = t;
    }
}


void bubble_sort(int n, int arr[])
{
    int i, j, temp;
    bool isswap;
    
    for(i = 0; i < n-1; i++)
    {
    
        isswap = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                isswap = true;
            }
        }
        
        if(isswap == false)
            break;
    }
}


void selection_sort(int n, int arr[])
{
    int i, j, minind, temp;
    
    for(i = 0; i < n-1; i++)
    {
        minind = i;
        
        for(j = i+1; j < n; j++)
        {
            if(arr[minind] > arr[j])
                minind = j;
        }
        
        temp = arr[i];
        arr[i] = arr[minind];
        arr[minind] = temp;
    }
}


void insertion_sort(int n, int arr[])
{
    int i, curr, prevind;
    for(i = 1; i < n; i++)
    {
        curr = arr[i];
        prevind = i-1;
        
        while(arr[prevind] > curr && prevind >= 0)
        {
            arr[prevind+1] = arr[prevind];
            prevind--;
        }
        
        arr[prevind+1] = curr;
    }
}


// merge sort
void merge(int arr[], int start, int mid, int end) {
    int temp[end-start+1], k = 0, p;
    int i = start, j = mid+1;
    while(i <= mid && j <= end) {    
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (p = 0; p < (end - start + 1); p++) {
        arr[start + p] = temp[p];
    }
}

void merge_sort(int arr[], int start, int end)
{
    int mid;
    
    if(start < end)
    {
        // mid = (start + end)/2
        mid = (int)start + (end - start)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    else
        return;
}


// quick sort
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int start, int end)
{
    int pivot_index;

    if(start < end) {
        pivot_index = partition(arr, start, end);
        quick_sort(arr, start, pivot_index-1);
        quick_sort(arr, pivot_index+1, end);
    }
    else {
        return;
    }
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end], i = start-1, j;

    for(j = start; j <= end-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);

    return i;
}

int main()
{
    int SIZE = 60000;
    
    clock_t t;
    double time_taken;
    
    int arr1[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE], arr5[SIZE];
    // get random array
    randarr(SIZE, arr1);
    
    memcpy(arr2, arr1, sizeof(arr1));
    memcpy(arr3, arr1, sizeof(arr1));
    memcpy(arr4, arr1, sizeof(arr1));
    memcpy(arr5, arr1, sizeof(arr1));

    
    int n = SIZE;
    // int n = sizeof(arr)/sizeof(arr[0]);
    //printf("%i", sizeof(arr)/sizeof(arr[0]));
    
    
    // printarr(n, arr4);
    // printf("\n");
    
    
    t = clock(); 
    bubble_sort(n, arr1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("bubble_sort() took %f seconds to execute \n", time_taken); 
    printf("\n");
    
    
    t = clock(); 
    selection_sort(n, arr2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("selection_sort() took %f seconds to execute \n", time_taken); 
    printf("\n");
    
    
    t = clock(); 
    insertion_sort(n, arr3);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("insertion_sort() took %f seconds to execute \n", time_taken); 
    printf("\n");
    
    t = clock(); 
    merge_sort(arr4, 0, n-1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("merge_sort() took %f seconds to execute \n", time_taken); 
    printf("\n");

    t = clock(); 
    quick_sort(arr5, 0, n-1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("quick_sort() took %f seconds to execute \n", time_taken); 
    printf("\n");
    
    // printarr(n, arr5);
    // printf("%i", arr5[SIZE-1]);
    
    return 0;
}
