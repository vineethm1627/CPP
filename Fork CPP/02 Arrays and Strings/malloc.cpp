#include <iostream>
using namespace std;

int main() {
    /*
    syntax: ptr = (cast-type*) malloc(byte-size)
    example : int *ptr = (int*) malloc(100 * sizeof(int));
    explanation : Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.
    */
    int *ptr;
    int n = 5;
    // dynamically allocate memory using malloc
    ptr = (int*)malloc(n * sizeof(int));
    // check if memory is allocated successfully.
    if(ptr == NULL) {
        cout << "Memory not allocated" << endl;
        exit(0);
    }
    else {
        for(int i = 0; i < n; i++) {
            ptr[i] = i;
        }
        
        // print the array.
        for(int i = 0; i < n; i++) {
            cout << ptr[i] << " ";
        }
    }
    return 0;
}