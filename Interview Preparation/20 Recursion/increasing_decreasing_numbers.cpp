/*
    Write 2 functions to print first n numbers in:
        increasing order
        decreasing order
*/
#include <iostream>
using namespace std;
 
void increasing(int n) {
    // base case
    if(n == 0)
        return;
    
    // recursive calls
    increasing(n - 1);
    cout << n << " ";
} 

void decreasing(int n) {
    // base case
    if(n == 0)
        return;
    
    // recursive calls
    cout << n << " ";
    decreasing(n - 1);
}

int main() {
    
    int n;
    cin >> n;

    cout << "Increasing order: \n";
    increasing(n);
    cout << "\nDecreasing order: \n";
    decreasing(n);
 
    return 0;
}