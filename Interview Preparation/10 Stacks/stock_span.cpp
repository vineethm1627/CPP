/*
    stack span is the max consecutive days for which the current stock is of the highest value till date.
*/
#include <iostream>
#include <stack>
using namespace std;

int* stockSpan(int *prices, int n) {
    stack<pair<int, int>> s; 
    int *span = new int[n];
    span[0] = 1; // starting day will be highest by default.
    s.push({prices[0], 0});

    for(int i = 1; i < n; i++) {
        int curr_price = prices[i];
        while(!s.empty() and s.top().first <= curr_price)
            s.pop();

        span[i] = s.empty() ? i + 1 : i - s.top().second;

        // push current element onto the stack
        s.push({prices[i], i});
    }
    return span;
}

int main() {

    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    int *arr = stockSpan(prices, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}