#include <iostream>
#include <unordered_set>
using namespace std;

// method of hashing

void printTriplets(int *arr, int n, int sum) {
    for(int i = 0; i < n - 1; i++) {
        unordered_set<int> s;
        for(int j = i + 1; j < n; j++) {
            int x = sum - (arr[i] + arr[j]);
            if(s.find(x) != s.end()) {
                cout << x << " " << arr[i] << " " << arr[j] << endl;
            }
            else {
                s.insert(arr[j]);
            }
        }
    }
}

int main() {

    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = -2;

    printTriplets(arr, n, sum);
    return 0;
}