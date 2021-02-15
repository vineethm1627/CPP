/*
    sort the array in wave form.
    smaller, bigger, smaller, bigger ......
    T(n) = O(n)
*/
#include <iostream>
using namespace std;
 
void waveSort(int *arr, int n) {
    for(int i = 0; i < n; i += 2) {
        // comparison with prev element
        if(i > 0 and arr[i] < arr[i - 1])
            swap(arr[i], arr[i - 1]);
        // comparison with next element
        if(i < n - 1 and arr[i] < arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
}
 
int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    waveSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}