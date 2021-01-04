#include <bits/stdc++.h>
using namespace std;

int countDistinct( int arr[], int n) {
    unordered_set<int> s(arr, arr + n);
    return s.size();
}

int main() {
	
    int arr[] = {1, 2, 3, 3, 2, 1, 1, 1, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "total number of elements: " << n << endl;
    cout << "number of unique elements: " << countDistinct(arr, n) << endl;
	return 0;
}