/*
    print true / false, to check if a subarray exists with zero sum.
*/
#include <iostream>
#include <unordered_set>
using namespace std;
 
bool zeroSum(int *arr, int n) {
    unordered_set<int> s;
    int prefix_sum = 0;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // check if the sum was already present in the set.
        if(prefix_sum == 0 or s.find(prefix_sum) != s.end()) 
            return true;

        s.insert(prefix_sum);
    }
    return false;
}
 
int main() {
 
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    if(zeroSum(arr, n)) 
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}