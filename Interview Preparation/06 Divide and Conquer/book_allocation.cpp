/*
    You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

    Input Format
    First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

    Constraints
    1 < t < 50
    1< n < 100
    1< m <= 50
    1 <= Ai <= 1000

    Output Format
    Print the maximum number of pages that can be assigned to students.

    Sample Input
    1
    4 2
    12 34 67 90
    Sample Output
    113 
    Explanation
    1st students : 12 , 34, 67 (total = 113)
    2nd students : 90 (total = 90)
    Print max(113, 90)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isPossible(int arr[], int n, int m, int cur_min) {
        int students = 1;
        int pages_read = 0;
        
        for(int i = 0; i < n; ) {
            if(pages_read + arr[i] <= cur_min) {
                pages_read += arr[i];
                i++;
            }
            else {
                students++;
                pages_read = 0;
                if(students > m)
                    return false;
            }
        }
        return true;
    }
    
    int findPages(int arr[], int n, int m) {
        // base case
        if(n < m) 
            return -1;
        
        int result = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        // monotonic search space
        int start = *max_element(arr, arr + n);
        int end = sum;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            // each student reads atmost mid number of pages [max_upper_bound]
            if(isPossible(arr, n, m, mid)) {
                result = min(result, mid);
                end = mid - 1;
            }
            else 
                start = mid + 1;
        }
        return result;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}