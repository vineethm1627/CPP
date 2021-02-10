#include <iostream>
#include <vector>
using namespace std;
 
/*
    heapify the array.
    exchange the max element with the last element.
    here the largest element gets fixed.

    now call heapify with the remaining array with decreased size.

    we are sorting the array by inserting the max element in each iteration at its right position.
*/

void heapify(vector<int> &v, int index, int size) {
    int left = 2 * index;
    int right = left + 1;

    int last = size - 1;
    int min_index = index;
    // condition for maxHeap
    if(left <= last and v[left] > v[index])
        min_index = left;
    if(right <= last and v[right] > v[min_index])
        min_index = right;
    
    if(min_index != index) {
        swap(v[min_index], v[index]);
        heapify(v, min_index, size);
    }
}
 
void buildHeap(vector<int> &v) {
     // n / 2 is the first non-leaf node
    for(int i = (v.size() - 1) / 2; i > 0; i--)
        heapify(v, i, v.size());
}

void heapSort(vector<int> &arr) {
    buildHeap(arr);
    int n = arr.size();

    // pop n - 1 elements from the heap
    while(n > 1) {
        // swap first and last node
        swap(arr[1], arr[n - 1]);
        // remove the current largest element from the heap
        n--;
        // call heapify on first node to restore the heap
        heapify(arr, 1, n);
    }
}

void print(vector<int> v) {
    for(int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    v[0] = -1;

    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    heapSort(v);
    print(v);
 
    return 0;
}