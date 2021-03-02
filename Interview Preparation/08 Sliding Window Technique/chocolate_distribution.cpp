/*
    Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 
        1. Each student gets one packet.
        2. The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.

        Efficient Approach:
            sort the array.
            find subarray of size m using sliding window 
            select the one with least difference.
*/
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define ppi pair<int, pair<int, int>> 

ppi minDiffAllocation(int *arr, int n, int m) {
    sort(arr, arr + n);

    ppi p;
    if(m == 0 or n == 0) {
        p = make_pair(0, make_pair(-1, -1));
        return p;
    }
    if(n < m)
        cout << "not possible \n";
    
    int min_diff = INT_MAX;
    for(int i = 0; i + m < n + 1; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if(diff < min_diff)
            p = make_pair(diff, make_pair(i, i + m - 1));
    }
    return p;
}

int main() {
    
    int n;
    cin >> n;

    int arr[n]; 
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    cout << "Enter the number of students: ";
    int m;
    cin >> m;

    ppi result = minDiffAllocation(arr, n, m);
    cout << "min difference: " << result.first << '\n';
    cout << "packets allocated: ";
    for(int i = result.second.first; i <= result.second.second; i++)
        cout << arr[i] << " "; 
    
    return 0;
}