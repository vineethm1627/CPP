/*
    Note: This approach assumes there are no duplicates.

    Input: 
    4
    4 5 2 5

    Output:
    5 5 -1 -1

    Correct output should be: 5 -1 5 -1
    

    Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

    Examples:

    For any array, rightmost element always has next greater element as -1.
    For an array which is sorted in decreasing order, all elements have next greater element as -1.

    For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
    Element       NGE
    4      -->   5
    5      -->   25
    2      -->   25
    25     -->   -1
    d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

    Element        NGE
    13      -->    -1
    7       -->     12
    6       -->     12
    12      -->     -1
*/
#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    stack<int> s;
    s.push(arr[0]);
    for(int i = 1; i < n; i++) {
        while(!s.empty() and s.top() < arr[i]) {
            cout << arr[i] << " ";
            s.pop();
        }
        s.push(arr[i]);
    }
    // for all the remaining elements, there are no greater elements
    while(!s.empty()) {
        cout << -1 << " ";
        s.pop();
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    printNGE(arr, n);

    return 0;
}