/* 
    Find the longest consecutive subsequence of elements.

    input: 10 4 20 1 3 3 2 19
    output: 4

    Here {1,2,3,4} is the longest consecutive array
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int findLargestSeq(int *arr, int n) {
    unordered_set<int> s (arr, arr + n);
    int max_len = 0;
    for(int i = 0; i < n; i++) {
        if(s.find(arr[i] - 1) == s.end()) {
            // arr[i] is the starting point of the streak
            int next_num = arr[i] + 1, streak_len = 1;
            while(s.find(next_num) != s.end()) {
                next_num++;
                streak_len++;
            }
            max_len = max(max_len, streak_len);
        }
    }
    return max_len;
}

int main() {
    
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findLargestSeq(arr, n) << endl;

    return 0;
}