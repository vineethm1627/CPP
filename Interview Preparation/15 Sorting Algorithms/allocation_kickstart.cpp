/*
    There are n houses for sale. The ith house costs ai dollars to buy. You have a budget of b dollars to spend.
    What is the max number of houses that you can buy ?

    Approach is to buy the cheapest houses first.

    input: 
    t
    n b
    (n integers indicating cost of ith house)
*/
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    
    int t;
    cin >> t;
    int tc = 1;
    while(t--) {
        int n, budget;
        cin >> n >> budget; 
        int prices[n];
        for(int i = 0; i < n; i++)
            cin >> prices[i];
        
        // sort in the ascending order of house price
        sort(prices, prices + n);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(prices[i] <= budget) {
                count++;
                budget -= prices[i];
            }
        }
        cout << "Case #" << tc++  << ": " << count << endl;
    }
    return 0;
}