/*
     Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. Print the answer modulo 109+7.

        Example 1:

        Input:
        W = 3
        Output:
        3
        Explanation:
        We need 3 tiles to tile the board
        of size  2 x 3. 
        We can tile in following ways:
        1) Place all 3 tiles vertically. 
        2) Place first tile vertically.
        and remaining 2 tiles horizontally.
        3) Place first 2 tiles horizontally
        and remaining tiles vertically.  
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unsigned long long M = 1e9 + 7;
    
    long long numberOfWays(long long N) {
        
        // base case
        if(N <= 1)
            return 1;
        
        long long dp_2 = 0;
        long long dp_0 = 1, dp_1 = 1;
        
        for(int i = 2; i <= N; i++) {
            dp_2 = (dp_0 + dp_1) % M;
            dp_0 = dp_1;
            dp_1 = dp_2;
        }
        return dp_2 % M;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
} 