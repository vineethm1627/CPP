#include <iostream>
using namespace std;

int main() {
    /*
    syntax : ptr = (cast-type*)calloc(n, element-size)
    example : ptr = (float*) calloc(100, sizeof(float));
    explanation : This statement allocates contiguous space in memory for 25 elements each with the size of the float.
    */
   int *ptr;
   int n = 5;
   // dynamically allocate memory using calloc.
   ptr = (int*)calloc(n, sizeof(int));
   // check if the memory is allocated or not.
   if(ptr == NULL) {
       cout << "Memory is not allocated";
       exit(0); // 0 implies successful termination of the program.
   }
   else {
       cout << "Default values of the array :" << endl;
       for(int i = 0; i < n; i++) {
           cout << ptr[i] << " ";
       }
   }
   return 0;
}