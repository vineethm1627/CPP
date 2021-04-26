/*
    Array indexing starts from 0 only.
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i) {
        // Your Code Here
        int left = 2 * i + 1;
        int right = left + 1;
        int largest = i;
        if(left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
        // child node needs to be swapped up
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  { 
        // Your Code Here
        // start from the last non-leaf node
        for(int i = (n - 2) / 2; i >= 0; i--)
            heapify(arr, n, i);
    }

    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n) {
        //code here
        buildHeap(arr, n);
        for(int i = n - 1; i > 0; i--) {
            // swap the largest element at the top of the heap with the last index in the array
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}