/*
    jumps of steps 1, 2, 3.
    Find the number of ways to reach the top taking different ordering of steps.
*/
#include <iostream>
using namespace std;

int ladder_ways(int n, int k) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += ladder_ways(n - i, k);
    
    return ans;
}
  
 
int main() {
    
    int n, k;
    cin >> n >> k;

    cout << ladder_ways(n, k) << endl;
 
    return 0;
}