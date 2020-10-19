#include <iostream>
using namespace std;

void pairSum(int arr[], int n, int key) {
    int cur_sum, i = 0, j = n - 1;
    while(i < j) {
        cur_sum = arr[i] + arr[j];
        if(cur_sum > key) {
            j--;
        }
        else if(cur_sum < key) {
            i++;
        }
        else {
            cout << arr[i++] << " and " << arr[j--] << endl;
        }
    }
}

int main() {
    // given a sorted array in ascending order, find pair of elements that sum to k(given).
    // naive approach using 2 for loops would easily solve it [bruteforce].
    // given 1 element, find the other element using binary search.
    // so the time complexity now becomes n times O(logn), ie. O(nlogn).

    // here, we will use two pointer approach.
    // each one at the two ends and based on condition decide which pointer to update.
    // this method will take O(n) ie. linear time.

    int arr[] = {1, 3, 5, 7, 10, 11, 12, 13};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int sum = 16;

    pairSum(arr, n, sum);


    return 0;
}