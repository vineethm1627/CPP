#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNGE(int arr[], int n) {
    vector<int> result(n);
    stack<int> s; // store the indices of the elements.
    // for the last element
    result[n - 1] = -1;
    s.push(n - 1);

    for(int i = n - 2; i >= 0; i--) {
        while(!s.empty() and arr[i] >= arr[s.top()]) {
            s.pop();
        }
        result[i] = s.empty() ? -1 : arr[s.top()];
        s.push(i);
    }
    return result;
}


int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> result;
    result = findNGE(arr, n);    
    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}