#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b; 
}

// function as parameter in another function
void bubble_sort(int arr[], int n, bool (&cmp)(int a, int b)) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= (n - i - 1); j++) {
            //if(arr[j] > arr[j + 1]) 
            if(cmp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]); //inplace swapping.
            }
        }
    }
}

int main() {

    int n, key;
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elements of the array !";

    int arr[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    // sort the array in ascending order.
    bubble_sort(arr, n, compare);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}