/*
    given a string, replace all occurrences of "pi" with 3.14

    input: xpighpi
    output: x3.14gh3.14

    changes should be made inplace.
*/
#include <iostream>
using namespace std;
 
void replacePi(char *arr, int i) {
    // base case
    if(arr[i] == '\0' or arr[i + 1] == '\0')
        return;
    
    // look for pi at the current location
    if(arr[i] == 'p' and arr[i + 1] == 'i') {
        // shifting followed by replacement with 3.14
        int j = i + 2;
        // take j to the end of the array
        while(arr[j])
            j++;
        
        // shift elements from right to left
        while(j >= i + 2) {
            arr[j + 2] = arr[j];
            j--;
        }

        // replacement by 3.14
        arr[i] = '3';
        arr[i + 1] = '.';
        arr[i + 2] = '1';
        arr[i + 3] = '4';

        // recursive call
        replacePi(arr, i + 4);
    }
    else 
        replacePi(arr, i + 1);
}
 
int main() {
    
    char a[1000];
    cin >> a;
    replacePi(a, 0);
    cout << a << endl;
 
    return 0;
}