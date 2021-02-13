/*
    used when keys lie between a specific range.
    It works by counting number of objects having distinct keys (kind of hashing).
    Then doing some arithmetic to calculate the position of each object in the output sequence.

    T(n) = O(n + range)
*/
#include <iostream>
using namespace std;

void countingSort(int *arr, int n) {
    int largest = -1;
    for(int i = 0; i < n; i++) 
        largest = max(largest, arr[i]);

    int *freq = new int[largest + 1]{0};

    for(int i = 0; i < n; i++) 
        freq[arr[i]]++;
    
    // put the elements back into the array
    int j = 0;
    for(int i = 0; i <= largest; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
}
 
 
int main() {
    
    // 1 to 97
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}