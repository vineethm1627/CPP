#include <iostream>
using namespace std;

void bubbleSort_iter(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        bool flag = true;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                flag = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        // one iteration is over
        if(flag) 
            break;
    }
}

void bubbleSort(int *arr, int n) {
    // base case
    if(n == 1)
        return;
    
    // recursive calls
    for(int j = 0; j < n - 1; j++) {
        if(arr[j] > arr[j + 1])
            swap(arr[j], arr[j + 1]);
    } 
    bubbleSort(arr, n - 1);
}

void bubbleSort_rec(int *arr, int j, int n) {
    // base case
    if(n == 1)
        return;
    // corner edge case, end of one iteration
    if(j == n - 1)
        return bubbleSort_rec(arr, 0, n - 1);
    
    if(arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    // call for the next swap in the same iteration
    bubbleSort_rec(arr, j + 1, n);
}   

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort_rec(arr, 0, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
