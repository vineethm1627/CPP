#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10 ,12, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;

    bool present = binary_search(arr, arr + n, key);
    if(present) 
        cout << "element is present" << endl;
    else 
        cout << "element is absent" << endl;

    auto lb = lower_bound(arr, arr + n, key);
    auto ub = upper_bound(arr, arr + n, key);
    cout << "lower_bound : " << lb - arr << endl; // >=
    cout << "upper_bound : " << ub - arr << endl; // >

    cout << "freq of occurrence : " << ub - lb << endl;
    return 0;
}