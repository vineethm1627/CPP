/* 
    Find the longest consecutive subsequence of elements.

    input: 10 4 20 1 3 3 2 19
    output: 4

    Here {1,2,3,4} is the longest consecutive array
*/
#include <iostream>
#include <unordered_map>
using namespace std;
 
int findLargestSeq(int *arr, int n) {
    unordered_map<int, int> m; // {number, streak length}

    for(int i = 0; i < n; i++) {
        int num = arr[i];
        // start a new streak
        if(m.count(num - 1) == 0 and m.count(num + 1) == 0)
            m[num] = 1;
        else if(m.count(num - 1) and m.count(num + 1)) {
            int len1 = m[num - 1];
            int len2 = m[num + 1];

            int streak_len = len1 + len2 + 1;
            m[num - len1] = streak_len;
            m[num + len2] = streak_len;
        }
        else if(m.count(num - 1) and !m.count(num + 1)) {
            int len = m[num - 1];
            m[num - len] = len + 1;
            m[num] = len + 1;
        }
        else {
            int len = m[num + 1];
            m[num + len] = len + 1;
            m[num] = len;
        }
    }

    int max_len = 0;
    for(auto p : m) 
        max_len = max(max_len, p.second);

    return max_len;
}
 
 
int main() {
    
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findLargestSeq(arr, n) << endl;

    return 0;
}