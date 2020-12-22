/*
    square root of a number upto p decimal places using binary search

    monotonic search space :
        non-decreasing
        non-increasing
    
    find a search space for finding the square root of a number and apply binary search 
    on this search space.

    given a number 'n'
        - square root of a number lies from 0 to n.
        - now apply binary search on this range.
        - at mid point make a decision of either going left or right.
        - make a function to find the mid point can be a square root of the function or not.
*/
#include <iostream>
using namespace std;

float square_root(int n, int p) {
    int start = 0, end = n;
    float ans = -1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(mid*mid == n) 
            return mid;
        else if(mid*mid < n) {
            ans = mid; // store the result and move ahead
            start = mid + 1;
        }
        else 
            end = mid - 1;
    }

    // floating part using bruteforce
    float increment = 0.1;
    for(int times = 1; times <= p; times++) {
        while(ans*ans <= n) {
            ans += increment;
        }
        ans -= increment; // break case from while
        increment /= 10;
    }
    return ans;
}

int main() {
    int n, p;
    cin >> n >> p;

    cout << square_root(n, p);

    return 0;
}