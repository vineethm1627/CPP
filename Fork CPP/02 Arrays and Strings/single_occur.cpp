/*
    Find the element that appears once in an array where every other element appears twice.
    All numbers occur twice except one number which occurs once. Find the number in O(n) time & constant extra space.

    Input:  ar[] = {7, 3, 5, 4, 5, 3, 4}
    Output: 7 
    Explanation : only 7 occurs exactly once.

    The best solution is to use XOR. XOR of all array elements gives us the number with a single occurrence. The idea is based on the following two facts.
        a) XOR of a number with itself is 0.
        b) XOR of a number with 0 is number itself.
    
    Solution :
        ans = 7^3^5^4^5^3^4
        ans = 7^(3^3)^(4^4)^(5^5)
        ans = 7^0^0^0
        ans = 7^0 --> 7 x ~0 + ~7 x 0 = 7
        
        Hence the answer is 7.
*/

#include <iostream>
using namespace std;

int findSingle(int arr[], int n) {
    int res = arr[0];
    for(int i = 1; i < n; i++) {
        res = res ^ arr[i];
    }
    return res;
}
int main() {
    int arr[] = {1, 2, 3, 5, 5, 4, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Single occuring element : " << findSingle(arr, n);
    return 0;
}