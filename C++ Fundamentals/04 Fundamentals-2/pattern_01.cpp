/*
    pattern of 0s and 1s

    input:
    n

    output:
    0
    10
    010
    1010
    01010

    explanation:
        - ith line contains i numbers 
        - odd line starts with 0
        - even line starts with 1
        - print n lines

*/

#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int value = (i % 2 == 0)? 1 : 0;
        for(int j = 1; j <= i; j++) {
            cout << value;
            value = 1 - value;
        }
        cout << endl;
    }
}