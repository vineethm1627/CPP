#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int coinChange(vector<int> &coins, int amount) {
    vector<int> table(amount + 1, INT_MAX);
    // base case
    table[0] = 0;
    
    for(int i = 1; i <= amount; i++) {
        // go through all the coins with values lesser than i
        for(int j = 0; j < coins.size(); j++) {
            if(coins[j] <= i) {
                int result = table[i - coins[j]];
                if(result != INT_MAX)
                    table[i] = min(table[i], result + 1);
            }
        }
    }
    if(table[amount] == INT_MAX)
        return -1;
    else    
        return table[amount];
}
 
int main() {
 
    int amount;
    cin >> amount;

    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    
    cout << "min coins: " << coinChange(coins, amount) << '\n';

    return 0;
}