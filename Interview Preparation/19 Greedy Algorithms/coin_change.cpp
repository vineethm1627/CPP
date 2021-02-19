#include <iostream>
#include <algorithm>
using namespace std;

int make_change(int *coins, int n, int money) {
    int count = 0;
    while(money > 0) {
        int idx = upper_bound(coins, coins + n, money) - coins - 1;   
        //cout << coins[idx] << " + ";
        money -= coins[idx];
        count++;
    }
    return count;
}
 
 
int main() {
    
    int money;
    cin >> money;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);

    cout << make_change(coins, n, money) << '\n';
 
    return 0;
}