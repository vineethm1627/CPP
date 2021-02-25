/*
    Write a recursive function to check if the array is sorted.
*/
#include <iostream>
using namespace std;
 
bool checkSorted(int *arr, int n) {
    // base case
    if(n == 0 or n == 1)
        return true;
    
    // recursive calls
    if(arr[0] < arr[1] and checkSorted(arr + 1, n - 1))
        return true;
    else    
        return false;
 } 
 
int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    if(checkSorted(arr, n))
        cout << "sorted \n";
    else   
        cout << "not sorted \n";
    
    return 0;
}