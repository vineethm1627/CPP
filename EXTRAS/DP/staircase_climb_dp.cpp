/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
*/
#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

int stairs(int n) {
    int st[n + 1];
    st[0] = 1;
    st[1] = 1;
    st[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        st[i] = (st[i - 1] + st[i - 2] + st[i - 3]) % M;
    }
    return st[n] % M;
}

int main(){
    
    int T;
    cin >> T;
    
    while(T--) {
        int n; 
        cin >> n;
        
        cout << stairs(n) << endl;
    }
    
   
    return 0;
}