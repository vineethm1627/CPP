/*
link to question on codeforces : https://codeforces.com/problemset/problem/808/D

    Vasya has an array a consisting of positive integer numbers. Vasya wants to divide this array into two non-empty
    consecutive parts (the prefix and the suffix) so that the sum of all elements in the first part equals to the sum of elements
    in the second part. It is not always possible, so Vasya will move some element before dividing the array (Vasya will erase some
    element and insert it into an arbitrary position).

    Inserting an element in the same position he was erased from is also considered moving.

    Can Vasya divide the array after choosing the right element to move and its new position?

    Input
    The first line contains single integer n (1 ≤ n ≤ 100000) — the size of the array.

    The second line contains n integers a1, a2... an (1 ≤ ai ≤ 109) — the elements of the array.

    Output
    Print YES if Vasya can divide the array after moving one element. Otherwise print NO.

    Examples
    input
    3
    1 3 2
    output
    YES

    input
    5
    1 2 3 4 5
    output
    NO

    input
    5
    2 2 3 4 5
    output
    YES

    Note:
    In the first example Vasya can move the second element to the end of the array.

    In the second example no move can make the division possible.

    In the third example Vasya can move the fourth element by one position to the left.
*/
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
    
    int n;
    cin >> n;
    
    vector<int> A(n + 1, 0);
    long long S = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        S += A[i];
    }
    
    if(S & 1) {
        cout << "NO\n";
        return 0;
    }
    
    map<long long, int> first, second;
    first[A[0]] = 1;
    
    for(int i = 1; i < n; i++) {
        second[A[i]]++;
    }
    
    long long sdash = 0;
    for(int i = 0; i < n; i++) {
        sdash += A[i]; // sum of first i numbers
        if(sdash == S / 2) {
            cout << "YES\n";
            return 0;
        }
        if(sdash < S / 2) {
            long long x = S / 2 - sdash;
            // delete element from the second half and insert it into the first half.
            if(second[x] > 0) {
                // the number x exists
                cout << "YES\n";
                return 0;
            }
        }
        else {
            // delete the element from the first half.
            long long y = sdash - S / 2;
            if(first[y] > 0) {
                cout << "YES\n";
                return 0;
            }
        }
        first[A[i + 1]]++; // the element now gets inserted into the first half.
        // initially we have one element in the first half and rest n - i elements in the second half.
        second[A[i + 1]]--;
    }
    
    cout << "NO" << endl;
    return 0;
}