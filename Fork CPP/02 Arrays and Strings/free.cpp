#include <iostream>
using namespace std;

int main() 
{ 
    // This pointer will hold the 
    // base address of the block created 
    int *ptrm, *ptrc; 
    int n = 5; 
    // Dynamically allocate memory using malloc 
    ptrm = (int*)malloc(n * sizeof(int)); 
  
    // Dynamically allocate memory using calloc 
    ptrc = (int*)calloc(n, sizeof(int)); 
  
    // Check if the memory has been allocated
    if (ptrm == NULL || ptrc == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n"); 
  
        // Free the memory 
        free(ptrm); 
        printf("Malloc Memory successfully freed.\n"); 
  
        // Memory has been successfully allocated 
        printf("\nMemory successfully allocated using calloc.\n"); 
  
        // Free the memory 
        free(ptrc); 
        printf("Calloc Memory successfully freed.\n"); 
    } 
  
    return 0; 
} 