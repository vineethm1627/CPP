/*  
    Leetcode Problem Link: https://leetcode.com/problems/next-permutation/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i, n = arr.size();
        // from the back, find the first number arr[i] < arr[i + 1]
        for(i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i + 1])
                break;
        }
        if(i == -1) {
           reverse(arr.begin(), arr.end());
           return arr;
        }        
        // from the back find the first greater element
        for(int j = n - 1; j > i; j--) {
            if(arr[j] > arr[i]) {
                swap(arr[j], arr[i]);
                break;
            }
        }
        // reverse the remaining part
        reverse(arr.begin() + i + 1, arr.end());
        return arr;
     }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends