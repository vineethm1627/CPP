/*
    CodeChef problem: https://www.codechef.com/problems/TACHSTCK
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

int main() {
    int n;
    ll d;
    cin >> n >> d;

    ll arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    sort(arr, arr+n);
    int count = 0;
    for(int i = 0; i < n - 1; ) {
        if(arr[i+1] - arr[i] <= d) {
            count++;
            i += 2;
        }
        else 
            i++;
    }
    cout << count << '\n';

    return 0;
}
