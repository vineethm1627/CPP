#include <iostream>
#include <string>
using namespace std;

// linear search to work on all datatypes : float, char, int, double, custom classes like array of Books etc.
template<class T>
int search(T arr[], int n, T key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return n; // return size if element not found
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int ans = search(arr, n, 4);
    cout << ans << endl;
    ans = search(arr, n, 8);
    cout << ans << endl;
    
    float b[] = {1.1, 1.2, 1.3, 1.4, 1.5};
    // by default the numbers are treated as double.
    //ans = search(b, n, 1.5); --> will lead to error
    float k = 1.5;
    ans = search(b, n, k);
    cout << ans << endl;
    return 0;
}