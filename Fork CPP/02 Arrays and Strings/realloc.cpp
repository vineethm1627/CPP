#include <iostream>
using namespace std;

int main() 
{ 
    int *ptr; 
    int n = 5, i;
    // Dynamically allocate memory using calloc
    ptr = (int*)calloc(n, sizeof(int)); 
  
    // Check if the memory has been allocated
    if (ptr == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using calloc.\n"); 
  
        // Get the elements of the array 
        for (i = 0; i < n; ++i) { 
            ptr[i] = i + 1; 
        } 
  
        // Print the elements of the array 
        printf("The elements of the array are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
  
        // Get the new size for the array 
        n = 10; 
        printf("\n\nEnter the new size of the array: %d\n", n); 
  
        // Dynamically re-allocate memory using realloc() 
        ptr = (int*)realloc(ptr, n * sizeof(int)); 
  
        // Memory has been successfully allocated 
        printf("Memory successfully re-allocated using realloc.\n"); 
  
        // Get the new elements of the array 
        for (i = 5; i < n; ++i) { 
            ptr[i] = i + 1; 
        } 
  
        // Print the elements of the array 
        printf("The elements of the array are: "); 
        for (i = 0; i < n; ++i) { 
            printf("%d, ", ptr[i]); 
        } 
  
        free(ptr); 
    } 
  
    return 0; 
} 