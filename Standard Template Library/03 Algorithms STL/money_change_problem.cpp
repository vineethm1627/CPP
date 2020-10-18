#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a <= b;
}

int main() {
    // indian money change problem.
    // make the change using the minimum number of coins.
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int money;
    cout << "Enter the amount of money : ";
    cin >> money;
    int n = sizeof(coins) / sizeof(coins[0]);
    int res = 0;
    while(money > 0) {
        // lower_bound gives a single element >= key element. 
        // we will use custom comparator to give <=. 
        int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
        int m = coins[lb];
        res += int(money / m);
        cout << "Note used : " << m << " x " << int(money / m) << endl;
        money = money % m;

    }

    cout << "Total number of notes used : " << res << endl;

    return 0;
}